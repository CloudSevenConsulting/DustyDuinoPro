*************************
Dusty Quick Start Library
*************************

The Quick Start Library (QSL) from Dusty is essential for this project.

Source Code
===========

Clone the repository with ``git``

.. code-block:: bash

   $ git clone https://github.com/dustcloud/QSL-for-sm_clib.git

Enter the repository:

.. code-block:: bash

   $ cd QSL-for-sm_clib

Initialize and update the necessary C Library submodule:

.. code-block:: bash

   $ git submodule init
   $ git submodule update

Pulling the QSL
===============

A small Python 3.x package is provided to automate QSL updates.

.. code-block:: bash

   $ cd c7c-atamo-dusty/src/
   $ cd C7C.Atamo.Dusty.PullQSL
   $ python -m PullQSL.main

Configure the ``settings.ini`` in ``C7C.Atamo.Dusty.PullQSL.resources``
