char* appendCharArray(char* array, char a) {
	size_t len = strlen(array);
	char* ret = malloc(sizeof(char)*(len + 2));
	strcpy(ret, array);
	ret[len] = a;
	ret[len+1] = '\0';

	return ret;
}

char* removeFisrtChar(char* array) {
	size_t len = strlen(array);

	if(len < 2) {
		char* ret = malloc(sizeof(char));
		ret[0] = '\0';
		return ret;
	}

	char* ret = malloc(sizeof(char)*(len-1));

	for(int i = 1; i < len; i++) {
		ret[i-1] = array[i];
	}

	return ret;

}

typedef struct {
	char* array;
	size_t tamanho;
	size_t capacidade;
} String;

String* initString() {
	String* a = malloc(sizeof(String));
	a->array = (char*)malloc(sizeof(char));
	a->tamanho = 0;
	a->capacidade = 1;
	return a;
}

void insertString(String *a, char element) {

	if (a->tamanho == a->capacidade) {
		a->capacidade *= 2;
		a->array = (char*)realloc(a->array, a->capacidade * sizeof(char));
	}
	a->array[a->tamanho++] = element;
}

void freeString(String *a) {
  free(a->array);
  a->array = NULL;
  a->tamanho = a->capacidade = 0;
}

typedef struct {
	String** strings;
	size_t tamanho;
	size_t capacidade;
} ArrayListStrings;

ArrayListStrings* initArrayListStrings() {
	ArrayListStrings* arrs = malloc(sizeof(ArrayListStrings));
	arrs->strings = (String**) malloc(sizeof(String*));
	arrs->tamanho = 0;
	arrs->capacidade = 1;
	return arrs;
}

void insertArrayListStrings(ArrayListStrings* arrs, String* element) {
	if(arrs->tamanho == arrs->capacidade) {
		arrs->capacidade *= 2;
		arrs->strings = (String**) realloc(arrs->strings, arrs->capacidade * sizeof(String*));
	}
	arrs->strings[arrs->tamanho++] = element;
}

void freeArrayListStrings(ArrayListStrings* arrs) {
	free(arrs->strings);
	arrs->strings = NULL;
	arrs->capacidade = arrs->tamanho = 0;
}

void removerUltimoChar(ArrayListStrings* buffer) {

		if(buffer->tamanho == 0) {
			return;
		}

		String* ultimaLinha = buffer->strings[buffer->tamanho - 1];

		if(ultimaLinha->tamanho == 0) {
			buffer->tamanho--;
			removerUltimoChar(buffer);
		} else {
			ultimaLinha->tamanho--;
		}


}
