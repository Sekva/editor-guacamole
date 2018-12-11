#include "decoders.h"

char selecionarPorEstado(int keycode, int state) {
	// printf("state %d\n", state);

		switch(state) {
			case 0:
					return decodar(keycode);
			case 16:
					return decodar(keycode);
			case 32:
					return decodar(keycode);
			case 34:
				return decodarShift(keycode);
			case 48:
					return decodar(keycode);
			case 2:
					return decodarShift(keycode);
			case 17:
					return decodarShift(keycode);
			case 18:
					return decodarShift(keycode);
			default:
					return decodar(keycode);
		}
}

void handleEvent(XEvent event) {
	if (event.type == KeyPress) {
		printf( "KeyPress: %d\n", event.xkey.keycode );
		/* exit on ESC key press */
		if ( event.xkey.keycode == 0x09 ) {
			exit(0);
		}

		if(event.xkey.keycode == 0x24) {
			addToBuffer('\n');
		}

		if(event.xkey.keycode == 22) {
			removerUltimoChar(buffer);
		} else {
			char tecla = selecionarPorEstado(event.xkey.keycode, event.xkey.state);
			if(tecla != '\0') {
				addToBuffer(tecla);
			}
		}
	} //else if (event.type == KeyRelease) {
		//printf( "KeyRelease: %x\n", event.xkey.keycode );
	//}
}
