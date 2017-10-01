*************************
TU_SH_Dusty_AfterFlash_Op
*************************

Goals
=====
To verify the Dusty module is operational after flashing.

Procedure
=========
1. Connect the Dusty module the ``DC9004A`` header using the appropriate ribbon cable.
2. Connect the ``DC9004A`` header to the ``DC9006A`` module
3. Connect the ``DC9006A`` module to a computer (Windows used in example). Ensure only one USB device is connected to the computer.
4. Determine the COM port used:

     a) Open Device Manager (``Ctrl+x, m``)
     b) Expand the "Ports (COM&LPT)" section.
     c) There should be 4 listed items with a unique COM port
     d) Note the third listed COM port number (referenced as [x])

f. Connect to the Dusty module using it's CLI interface

     a) Use a Serial Terminal Program (such as Putty) to connect to the device
     b) Use the following settings:

        * Serial line: COM[x]
        * Bits per second: 9600
        * Data bits: 8
        * Parity: None
        * Stop bits: 1
        * Flow Control: None

g. In the terminal, enter the command ``info``

Expected
========

.. code-block:: bash

    info

    IP Mote: 1.4.1.8
    Join state: n/a
    Bandwidth Allocated: 0
    Serial mode: M4
    Serial Baud Rate: 115200
    Radio Test: off

    >


