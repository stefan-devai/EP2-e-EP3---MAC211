#include "defs.h"


void afunda_destroyer(char** mapa, int M, int N, tiro t) {
	int linha = t.tiro_linha;
	int coluna = t.tiro_coluna;
	int contador = 0;
	int acertou = 0;
	mapa[t.tiro_linha][t.tiro_coluna] = '*';
	while(contador < 7 || !acertou ){
		proxima_posicao(M, N, t, &linha, &coluna, &contador);
		if(mapa[linha][coluna] = 'D') {
			 mapa[linha][coluna] = '*';
			 acertou = 1;
		}
	}
}
