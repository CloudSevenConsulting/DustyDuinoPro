*********************
Project Documentation
*********************

Project documentation can be found in ``c7c-atamo-dusty/docs/``

The directory tree should be as follows:

.. code-block:: bash

   Mode                LastWriteTime         Length Name
   ----                -------------         ------ ----
   d-----       2017-09-05     17:46                build
   d-----       2017-09-06     12:00                source
   -a----       2017-09-05     17:40            815 make.bat
   -a----       2017-09-05     17:40            617 Makefile

The git repository **does not** ship the ``build/`` files, they must be built using
Python Sphinx (see below for installation):

.. code-block:: bash

   #for *nix
   $ ./make clean
   $ ./make html

   #for DOS
   PS> ./make.bat clean
   PS> ./make.bat html


To open the HTML files (or just open it with a file explorer...):

.. code-block:: bash

   #for dos
   PS> Invoke-Item build/html/index.html

   #for *nix
   $ xdg-open build/html/index.html


Installing Python Sphinx
========================

Python Sphinx_ is a tool that helps build documentation out of reStructured Text (rst)
marked-up files.

.. _Sphinx: http://www.sphinx-doc.org/en/stable/

You must have Python installed (we recommend `Python 3.x <https://www.python.org/downloads/>`_).

Once Python is installed, you should have the ``pip`` utility installed natively (if not, `go here <https://pip.pypa.io/en/stable/installing/>`_). To check if you have ``pip``:

.. code-block:: bash

   $ python -m pip --version
   pip 9.0.1 from C:\...\Python\Python36-32\lib\site-packages (python 3.6)

Once you checked ``pip`` is installed, run the command to install Sphinx:

.. code-block:: bash

   $ python -m pip install Sphinx

We will also need the ``sphinx_rtd_theme`` for our docs:

   $ python -m pip install sphinx_rtd_theme
