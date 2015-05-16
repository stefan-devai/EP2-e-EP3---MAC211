#include "disparos.h"


int sorteia(int k) {
	return (int)(1 + (rand()/(RAND_MAX+1.0))*k);
}

tiro coordenadas_tiro(char** mapa, int M, int N) { //a função não utiliza a própria matriz, mas preferi manter o padrão
	tiro t;
	t.tiro_linha = sorteia(M) - 1;
	t.tiro_coluna = sorteia(N) - 1;
	return t;
}

void dispara_tiros(char** mapa, int M, int N, const char *dir_do_arquivo) {
	tiro t;
	int i;
	for (i = 0; i < 3; i++) {
		t = coordenadas_tiro(mapa, M, N);
		identifica_alvo_atingido(mapa, M, N, t);
	}
	escreve_mapa_tela(mapa, M, N);
	escreve_mapa_arquivo(dir_do_arquivo, mapa, M, N);
}

void identifica_alvo_atingido(char** mapa, int M, int N, tiro t) {
	char c = mapa[t.tiro_linha][t.tiro_coluna];
	if(c == 'D') afunda_destroyer(char** mapa, int M, int N, tiro t);
	if(c == 'P') afunda_portaaviao(char** mapa, int M, int N, tiro t);
	if(c == 'C') afunda_cruzador(char** mapa, int M, int N, tiro t);
	if(c == 'H') afunda_hidroaviao(char** mapa, int M, int N, tiro t);
	if(c == 'S') mapa[t.tiro_linha][t.tiro_coluna] = '*';
	if(c == '.') mapa[t.tiro_linha][t.tiro_coluna] = '=';
	if(c == ' ') mapa[t.tiro_linha][t.tiro_coluna] = '=';
	if(c == 'T') mapa[t.tiro_linha][t.tiro_coluna] = '+';
	if(c == 'B') mapa[t.tiro_linha][t.tiro_coluna] = '!';
}

void proxima_posicao(int M, int N, tiro t, int *l, int *c, int *contador) {
	int linha = t.tiro_linha;
	int coluna = t.tiro_coluna;
	if(*contador == 0){
		if(linha + 1 < M) {
			*l = linha + 1;
		}
		*contador = 1;
	}
	else if(*contador == 1) {
		if(linha - 1 >= 0) {
			*l = linha - 1;
		}
		*contador = 2;
	}
	else if(*contador == 2) {
		if(coluna + 1 < N) {
			*c = coluna + 1;
		}
		*contador = 3;
	}
	else if(*contador == 3) {
		if(coluna - 1 >= 0) {
			*c = coluna -1;
		}
		*contador = 4;
	}
	else if(*contador == 4){
		if(linha + 1 < M && coluna + 1 < N) {
			*l = linha + 1;
			*c = coluna + 1;
		}
		*contador = 5;
	}
	else if(*contador == 5){
		if(linha + 1 < M && coluna - 1 >= 0){
			*l = linha + 1;
			*c = coluna - 1;
		}
		*contador = 6;

	}
	else if(*contador == 6){
		if(linha - 1 <= 0 && coluna + 1 > N){
			*l = linha - 1;
			*c = coluna + 1;
		}
		*contador = 7;
	}
	else (*contador == 7){
		if(linha - 1 <= 0 && coluna - 1 <= 0){
			*l = linha - 1;
			*c = coluna - 1;
		}
		*contador = 8;
	}
}


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

void afunda_portaaviao(char** mapa, int M, int N, tiro t) {
	int linha = t.tiro_linha;
	int coluna = t.tiro_coluna;
	int contador = 0;
	tiro x;
	mapa[t.tiro_linha][t.tiro_coluna] = '*';
	while(contador < 7 ){
		proxima_posicao(M, N, t, &linha, &coluna, &contador);
		if(mapa[linha][coluna] = 'P') {
			x.tiro_linha = linha;
			x.tiro_coluna = coluna;
			afunda_portaaviao(mapa, M, N, x);
		}
	}
}

void afunda_cruzador(char** mapa, int M, int N, tiro t) {
	int linha = t.tiro_linha;
	int coluna = t.tiro_coluna;
	int contador = 0;
	tiro x;
	mapa[t.tiro_linha][t.tiro_coluna] = '*';
	while(contador < 7 ){
		proxima_posicao(M, N, t, &linha, &coluna, &contador);
		if(mapa[linha][coluna] = 'C') {
			x.tiro_linha = linha;
			x.tiro_coluna = coluna;
			afunda_cruzador(mapa, M, N, x);
		}
	}
}

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
