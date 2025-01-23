Prompt 1)

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

Feedback)
Generating project files according to the overall design is done very well. However, there is a lack of detail regarding the parameters and return values of the functions.



Prompt 2)
https://github.com/1und0/ShakeTrack/blob/master/dataset/01/user1/1A.csv and https://github.com/1und0/ShakeTrack/blob/master/dataset/01/user1/1B. After reading the csv data and learning the gbm model with cmsis nn, QxModel.c and QxModel.h files are created so that the user can use new input data. Generate code to infer whether A or B is used using QxML.c and QxML.h.

Feedback)
When asked to provide data links from the web and create functions related to ML training and inference, the basic structure and functions are well-generated. However, the code related to actual GBM training is not generated, and the user is asked to create the code themselves.



Prompt 3) 
Please make Makefile to build source codes to a static library with name 'libQxModel.a'

Feedback) 
The creation of the Makefile is done very well.


Prompt 4) 
in Makefile, download cmsis source codes to build a library.

Feedback)
The creation of the Makefile is done very well, and the addition of necessary features to the Makefile is also well-handled.


Prompt 5)
Create comments with doxygen format.

Feedback) Comments are generated very well too.
