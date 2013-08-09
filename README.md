TiLDA-source
============

Source code for TiLDA badges during EMF.

For schematics and libraries, please see the main [TiLDA repository](http://github.com/emfcamp/TiLDA).

Preparation
===========

On Linux/OS X:

    export ARDUINODIR=<Location of directory that contains 'hardware' directory>
    # for Mac OS X this is likely '/Applications/Arduino.app/Contents/Resources/Java/'
    # for Linux, this will be ~/Downloads/arduino-1.0.1 or similar

    for i in $PWD/../libraries/*; do if test -d $i; then ln -s $i $ARDUINODIR/libraries/; fi; done

On Windows:
* Copy everything in libraries to the libraries subfolder of arduino-1.0.1.

Building with Arduino IDE
=========================

* Run Arduino IDE
* Open TiLDA.ino
* Select correct port under Tools, Serial Port
* Choose Arduino Leonardo under Tools, Board
* Hit File, Upload


Building wth Makefiles
======================

To use some of the the make files you'll need [Crosspack-AVR](http://www.obdev.at/products/crosspack/index.html)
Otherwise, copy one of the arduino.mk files.

On Linux/OS X:

    cd <project>
    export SERIALDEV=/dev/ttyACM1 # optional
    make
    sudo ARDUINODIR=$ARDUINODIR make upload

Makefiles are not supported on Windows.


Getting the IRLED to transmit
=============================

The IR LED is apparently underpowerd. A reasonable hack to get it to power such 
that you can send and receive using the shirriff example code (IRsendDemo and IRrecvDemo)
is to hold pin 4 HIGH and use a physical jumper to connect the two.
