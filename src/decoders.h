char decodar(int charCode) {

	switch(charCode) {


		case 24:
			return 'q';
		case 25:
			return 'w';
		case 26:
			return 'e';
		case 27:
			return 'r';
		case 28:
			return 't';
		case 29:
			return 'y';
		case 30:
			return 'u';
		case 31:
			return 'i';
		case 32:
			return 'o';
		case 33:
			return 'p';

		case 38:
			return 'a';
		case 39:
			return 's';
		case 40:
			return 'd';
		case 41:
			return 'f';
		case 42:
			return 'g';
		case 43:
			return 'h';
		case 44:
			return 'j';
		case 45:
			return 'k';
		case 46:
			return 'l';
		case 47:
			return 231;

		case 52:
			return 'z';
		case 53:
			return 'x';
		case 54:
			return 'c';
		case 55:
			return 'v';
		case 56:
			return 'b';
		case 57:
			return 'n';
		case 58:
			return 'm';


		case 65:
			return ' ';


		default:
			return '\0';
	}
}

char decodarShift(int charCode) {

	switch(charCode) {


		case 24:
			return 'Q';
		case 25:
			return 'W';
		case 26:
			return 'E';
		case 27:
			return 'R';
		case 28:
			return 'T';
		case 29:
			return 'Y';
		case 30:
			return 'U';
		case 31:
			return 'I';
		case 32:
			return 'O';
		case 33:
			return 'P';

		case 38:
			return 'A';
		case 39:
			return 'S';
		case 40:
			return 'D';
		case 41:
			return 'F';
		case 42:
			return 'G';
		case 43:
			return 'H';
		case 44:
			return 'J';
		case 45:
			return 'K';
		case 46:
			return 'L';
		case 47:
			return 199;

		case 52:
			return 'Z';
		case 53:
			return 'X';
		case 54:
			return 'C';
		case 55:
			return 'V';
		case 56:
			return 'B';
		case 57:
			return 'N';
		case 58:
			return 'M';


		case 65:
			return ' ';


		default:
			return '\0';
	}
}
