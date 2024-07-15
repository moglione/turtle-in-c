# turtle-in-c
tortuga.h is a "header only" library that adds turtle graphics functions (LOGO type) to the C and C++ languages. It was developed to teach programming to teenagers transitioning from visual programming languages ​​(Scratch, mBlock) to text-based languages.

This library has no dependencies, it only needs to be linked through the linker to the **gdi32** Windows library.

This library works perfectly with the MinGW compiler and was developed and tested on Bloodshed's DeV C++ and its derivatives (Embarcadero, CodeBlocks, Orwell, etc.)

You must configure the IDE to include the link to the gdi32 library, to do this in Dev C++ you must go to the **Tools** next to **Compiler Options** and in the box that says **Add these commands to the linker command line** add this flag: ** -lgdi32 **

## go to the "Tools" next to "Compiler Options"
![square1](https://github.com/moglione/turtle-in-c/blob/main/images/menu.png)


![square1](https://github.com/moglione/turtle-in-c/blob/main/images/compiler_options.png)


### For example: the following program will draw a square 1000 steps in size per side on the screen

![square1](https://github.com/moglione/turtle-in-c/blob/main/images/square1.jpg)


### Functions can also be written in abbreviated form, for example **forward()** can be written as **fw()**. and **rightTurn()** in this other way **rt()**.

![square2](https://github.com/moglione/turtle-in-c/blob/main/images/square2.jpg)
