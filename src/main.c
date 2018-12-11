#include "imports.h"

int main() {
	buffer = initArrayListStrings();
	cursor = criarCursor();
	setupOneScreen();

	while (1) {
		XNextEvent(display, &event);
		handleEvent(event);
		limpar();
		drawBuffer();
	}

	XCloseDisplay(display);
	return 0;
}
