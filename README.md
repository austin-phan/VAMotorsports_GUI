# VA Motorsports GUI
## Overview
The VAMotorsports GUI is an early-stage project aimed at developing a graphical interface to process, visualize, and manage telemetry data from a Formula SAE vehicle's CAN bus. The current progress includes CAN data handling, LoRa data transmission, and a MongoDB atlas database to store raw and decoded CAN data from the car.
## Features 
- **LoRa Data Transmission**
    - Splitting data into packets and periodic transmission via LoRa
    - Base station setup for receiving LoRa packets
- **CAN Data Handling**
    - Decoding CAN data using `.dbc` files via the `cantools` python module
    - Scripts to read and process CAN messages are under development
- **Data Logging into MongoDB Atlas**
    - Logging raw data into the cloud DB for any debugging
    - Logging decoede data into a separate DB to obtain from later 
## Work in Progress
1. **Hardware Integration**
    - Uploading, verifying, and debudding scripts to the LoRa transmitter
    - Refining CAN message decoding and validation
3. **Creating an API**
    - Set up an API for multiple clients to access in the future(GUI, Website, etc)
## Future Plans
- **Web Interface**
    - Real time live display and visualation of data for public view.
- **GPS/Vector Nav Integration**
    - Real time track GPS display
- **WiFi Data Transmission**
    - Adding WiFi support for higher throughput transmission.
