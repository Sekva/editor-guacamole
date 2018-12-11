typedef struct {
	char estilo;
	int coluna;
	int linha;
} SCursor;

SCursor* criarCursor() {
	SCursor* cursor = malloc(sizeof(SCursor));
	cursor->estilo = 2230;
	cursor->coluna = 0;
	cursor->linha = 0;
	return cursor;
}

void subir(SCursor* cursor) {
	cursor->linha--;
}
void descer(SCursor* cursor) {
	cursor->linha++;
}
void esquerda(SCursor* cursor) {
	cursor->coluna--;
}
void direita(SCursor* cursor) {
	cursor->coluna++;
}
