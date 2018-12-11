#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charArray.h"
#include "cursor.h"

Display* display;
Window window;
XEvent event;
char *msg = "Hello, World!";
int screenN;
ArrayListStrings* buffer;
SCursor* cursor;

#include "janela.h"
#include "teclas.h"
