#include "defs.h"


void afunda_hidroaviao(char** mapa, int M, int N, tiro t) {
	int linha = t.tiro_linha;
	int coluna = t.tiro_coluna;
	int contador = 0;
	tiro x;
	mapa[t.tiro_linha][t.tiro_coluna] = '*';
	while(contador < 7 ){
		proxima_posicao(M, N, t, &linha, &coluna, &contador);
		if(mapa[linha][coluna] = 'H') {
			x.tiro_linha = linha;
			x.tiro_coluna = coluna;
			afunda_hidroaviao(mapa, M, N, x);
		}
	}
}
