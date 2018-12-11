void setupOneScreen() {

	display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "Cannot open display\n");
		exit(1);
	}

	screenN = DefaultScreen(display);
	//window = XCreateSimpleWindow(display, RootWindow(display, screenN), 10, 10, 600, 400, 1, BlackPixel(display, screenN), WhitePixel(display, screenN));
	window = XCreateSimpleWindow(display, RootWindow(display, screenN), 10, 10, 600, 400, 1, WhitePixel(display, screenN), BlackPixel(display, screenN));
	XSelectInput(display, window, ExposureMask | KeyPressMask);
	XMapWindow(display, window);

}

void drawCoisas() {
	XFillRectangle(display, window, DefaultGC(display, screenN), 20, 20, 10, 10);
	XDrawString(display, window, DefaultGC(display, screenN), 10, 100, msg, strlen(msg));
}

void limpar() {
	XClearWindow(display, window);
}

void drawBuffer() {
	GC gContexto = DefaultGC(display, screenN);
	XSetForeground(display, gContexto, WhitePixel(display, screenN));
	XSetBackground(display, gContexto, BlackPixel(display, screenN));

	// Font f = XLoadFont(display, "-*-helvetica-bold-r-*-*-*-120-100-100-*-*-iso8859-1");
	// XSetFont(display,gContexto,f);
	// http://csweb.cs.wfu.edu/~torgerse/Kokua/Irix_6.5.21_doc_cd/usr/share/Insight/library/SGI_bookshelves/SGI_Developer/books/XLib_PG/sgi_html/apa.html

	for(int i = 0; i < buffer->tamanho; i++) {
		String* linhaLida = buffer->strings[i];
		if(linhaLida->array[0] == '\n') {
			char* semBarraN = removeFisrtChar(linhaLida->array);
			XDrawString(display, window, gContexto, 10, (i+1) * 10, semBarraN, linhaLida->tamanho-1);
			free(semBarraN);
		} else {
			char* linha = linhaLida->array;
			char* linhaCursor = malloc((sizeof(char)*linhaLida->tamanho)+1);
			strcpy(linhaCursor, linha);
			linhaCursor[linhaLida->tamanho] = cursor->estilo;
			XDrawString(display, window, DefaultGC(display, screenN), 10, (i+1) * 10, linhaCursor, linhaLida->tamanho+1);
			free(linhaCursor);
		}
	}
}

void addToBuffer(char c) {

	if(c == '\n') {
		String* novaLinha = initString();
		insertString(novaLinha, c);
		insertArrayListStrings(buffer, novaLinha);
	} else {

		if(buffer->tamanho == 0) {
			String* primeiraLinha = initString();
			insertArrayListStrings(buffer, primeiraLinha);
		}

		String* ultimaLinha = buffer->strings[buffer->tamanho - 1];
		insertString(ultimaLinha, c);
	}
}
