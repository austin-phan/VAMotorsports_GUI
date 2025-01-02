#pragma once

#ifndef __wav_file_reader_h__
#define __wav_file_reader_h__

#include <SPIFFS.h>
#include <FS.h>
#include "I2SOutput.h"

class WAVFileSampler : public SampleSource {
private:
    #pragma pack(push, 1)
    struct WAVHeader {  // Format description found in https://docs.fileformat.com/audio/wav/
        char  stamp[4];           // 1 - 4	“RIFF”	Marks the file as a riff file. Characters are each 1 byte long.
        U32   fileSize;           // 5 - 8	File size (integer)	Size of the overall file - 8 bytes, in bytes (32-bit integer). Typically, you’d fill this in after creation.
        char  fileTypeHeader[4];  // 9 -12	“WAVE”	File Type Header. For our purposes, it always equals “WAVE”.
        char  chunkFormat[4];     // 13-16	“fmt "	Format chunk marker. Includes trailing null
        U32   chunkSizeFormat;    // 17-20	16	Length of format data as listed above
        U16   formatType;         // 21-22	1	Type of format (1 is PCM) - 2 byte integer
        U16   channelsCount;      // 23-24	2	Number of Channels - 2 byte integer
        U32   sampleRate;         // 25-28	44100	Sample Rate - 32 byte integer. Common values are 44100 (CD), 48000 (DAT). Sample Rate = Number of Samples per second, or Hertz.
        U32   bitRate;            // 29-32	176400	(Sample Rate * BitsPerSample * Channels) / 8.
        U16   bytesPerSample;     // 33-34	4	(BitsPerSample * Channels) / 8. 1 = 8 bit mono; 2 = 8 bit stereo/16 bit mono; 4 = 16 bit stereo
        U16   bitsPerMonoSample;  // 35-36	16	Bits per sample
        char  chunkData[4];       // 37-40	“data”	“data” chunk header. Marks the beginning of the data section.
        U32   chunkSizeData;      // 41-44	File size (data)	Size of the data section.
    };
    #pragma pack(pop)

public:
    File    m_file;
    U8      m_channelsCount;
    U32     m_samplingRate;
    U32     m_samplesCount;
    U32     m_sampleIndex;

    U8*     m_fileContent;

    // Volume settings
    float   m_volume;
    S32     m_volumeInt;

    // For debug purpose only
    Frame_t m_frameMin;
    Frame_t m_frameMax;

public:
    WAVFileSampler();
    ~WAVFileSampler();

    bool    Init( const char* _fileName, bool _preLoadFile=false );

    void    SetVolume( float _volume ) { m_volume = _volume; m_volumeInt = S32(m_volume * 65536); }

    virtual uint32_t sampleRate() { return m_samplingRate; }
    virtual void getFrames( Frame_t* _frames, int _framesCount );
};

#endif