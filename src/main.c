#include "imports.h"
#include "janela.h"
#include "teclas.h"

int main() {
	buffer = initArrayListStrings();
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
