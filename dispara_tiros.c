#include <stdio.h>
#include "defs.h"

void dispara_tiros(char** mapa, int M, int N, FILE* f) {
	tiro t;
	int i;
	for (i = 0; i < 3; i++) {
		t = coordenadas_tiro(mapa, M, N);
		identifica_alvo_atingido(mapa, M, N, t);
	}
	escreve_mapa_tela(mapa, M, N);
	escreve_mapa_arquivo(mapa, M, N, f);
}