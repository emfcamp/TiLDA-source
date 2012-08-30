TiLDA-source
============

Source code for TiLDA badges during EMF.

For preparation instructions, please see superproject.

To use the make file you'll need Crosspack-AVR [http://www.obdev.at/products/crosspack/index.html]

== Building on Linux/OS X ==

    export ARDUINODIR=<Location of directory that contains 'hardware' directory>
    *for Mac OS X this is likely '/Applications/Arduino.app/Contents/Resources/Java/' 
    export BOARD=leonardo
    make && make upload

== Getting the IRLED to transmit ==

The IR LED is apparently underpowerd. A reasonable hack to get it to power such 
that you can send and receive using the shirriff example code (IRsendDemo and IRrecvDemo)
is to hold pin 4 HIGH and use a physical jumper to connect the two.