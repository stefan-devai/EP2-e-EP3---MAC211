#include "defs.h"


char identifica_alvo_atingido(char** mapa, int M, int N, tiro t, int* status) {
	char c = mapa[t.tiro_linha][t.tiro_coluna];
	if(c == 'D') afunda_destroyer(char** mapa, int M, int N, tiro t);
	if(c == 'P') afunda_portaaviao(char** mapa, int M, int N, tiro t);
	if(c == 'C') afunda_cruzador(char** mapa, int M, int N, tiro t);
	if(c == 'H') afunda_hidroaviao(char** mapa, int M, int N, tiro t);
	if(c == 'S') mapa[t.tiro_linha][t.tiro_coluna] = '*';
	if(c == '.') mapa[t.tiro_linha][t.tiro_coluna] = '=';
	if(c == ' ') mapa[t.tiro_linha][t.tiro_coluna] = '=';
	if(c == 'T') mapa[t.tiro_linha][t.tiro_coluna] = '+';
	if(c == 'B') {
		mapa[t.tiro_linha][t.tiro_coluna] = '!';
		*status = 0;
	}
