#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charArray.h"

Display* display;
Window window;
XEvent event;
char *msg = "Hello, World!";
int screenN;
ArrayListStrings* buffer;
