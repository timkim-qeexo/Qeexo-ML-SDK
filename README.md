Qeexo SDK Development Specifications
The SDK aims to read various types of sensor data, fill the sensor buffer, and deliver it to multiple registered applications. Each application processes the sensor data in an independent task. The SDK should be capable of running on an MCU by default and be designed to support models ranging from Coretex-M0 to M4.
The project name is Qeexo-ML-SDK and it should be registered with a repository in Git.
System Hierarchy Structure:
1. HAL Structure
    1. Overview
        1. All HAL codes should be implemented in C language.
        2. The prefix "Qx" is used, and in case the module name is attached, for example, HAL source code related to OS will be QxOS.c and QxOS.h files.
        3. Function names should also use the same prefix.
        4. Create a folder named "Hal" and design the structure and files as outlined below.
    2. QxOS.h, QxOS.c
        1. Provide OS-related APIs.
        2. The files should include the following functions:
            1. BSP initialization function
            2. Thread creation and termination, suspend, resume functions
            3. Mutex creation, termination, lock, unlock functions
            4. Mailbox related functions
            5. Timer related functions
    3. QxSensorHal.c, QxSensorHal.h
        1. A module that manages and registers sensors.
        2. Each sensor should implement the following functions and register function pointers in a structure so that the upper framework can load and execute each function:
            1. init function
            2. enable function with odr and fsr as parameters
            3. disable function
            4. read function
            5. read_fifo function
            6. get_odrs function, providing a list of supported ODRs
            7. get_fsrs function, providing a list of supported FSRs
    4. QxTransceiverHal.c, QxTransceiverHal.h
        1. A module that registers and manages communication media such as USB, BLE, and WiFi, which should be implemented as sub-drivers and registered.
        2. Each transceiver should be implemented with common functionality and connected through function pointers, managed by QxTransceiverHAL, and callable by upper applications:
            1. Open function
            2. write function
            3. read function
