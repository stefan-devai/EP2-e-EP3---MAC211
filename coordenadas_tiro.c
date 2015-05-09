#include "defs.h"
tiro coordenadas_tiro(char** mapa, int M, int N) { //a função não utiliza a própria matriz, mas preferi manter o padrão
	tiro t;
	t.tiro_linha = sorteia(M) - 1;
	t.tiro_coluna = sorteia(N) - 1;
	return t;
}