.. _usage-duinoPro-arduino-integration:

***********************************
DuinoPro and ArduinoIDE integration
***********************************

To develop with the `ArduinoIDE <https://www.arduino.cc/en/Main/Software>`_:

1. Download the DuinoPro installation ``.zip``

.. note::
   Waiting for Client approval to publish these files. CSC please refer to
   folder# ``03.11``

2. From the installation ``.zip`` copy files into your computer as follows:

.. figure:: imgs/installation.png
   :scale: 60%

3. Modify the ``package_duinopro_index.json`` file as follows:

.. code-block:: json

    {
        "packages": [
            {
                "platforms": [
                    {
                    "version": "1.0.1",
                    }
                ]
            }
        ],
    }

4. Open the Arduino IDE and open your preferences (``Ctrl+,``). Modify the *Additional Boards Manager URL* field to: ``http://10.0.0.156/mediawiki/images/1/1c/package_duinopro_index.json``

.. figure:: imgs/installation02.png
   :scale: 60%

5. Select your board in ``Tools``

.. figure:: imgs/installation03.png
   :scale: 50%

Testing
=======

With your board set in step 4 above, use the following sketch to test your build:

.. code-block:: cpp

    //These are required for the DuinoPRO library
    #include <Wire.h>
    #include <SPI.h>

    #include <duinoPRO.h>

    void setup() {
      // Testing the DuinoPRO library
      duinoPRO myBaseBoard;
      myBaseBoard.setLed(true);

    }

    void loop() {
      // We don't need this
    }

.. note::

   Some warnings will appear, JP yet to debug these
