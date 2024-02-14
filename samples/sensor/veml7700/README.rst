.. _hts221:

HTS221: Temperature and Humidity Monitor
########################################

Overview
********
This sample periodically reads light from the VELM7700
Ambient Light Sensor and displays it on the console


Requirements
************

This sample uses the VELM7700 sensor controlled using the I2C interface.

References
**********

 - VELM7700: 

Building and Running
********************

 This project outputs sensor data to the console. It requires an 
 sensor, which is present on the b_u585i_iot02a board.

.. zephyr-app-commands::
   :zephyr-app: samples/sensor/velm7700
   :board: b_u585i_iot02a
   :goals: build
   :compact:

Sample Output
=============

 .. code-block:: console

    count:2
    value of sensor_value:0
    successfully set the ambient light sensor data :178.0
    successfully get the ambient light sensor data :772.0
    count:2
    value of sensor_value:0
    successfully set the ambient light sensor data :178.0
    successfully get the ambient light sensor data :772.0
    count:3
    value of sensor_value:0
    successfully set the ambient light sensor data :178.0
    successfully get the ambient light sensor data :772.0
    count:4


    <repeats endlessly every 2 seconds>
