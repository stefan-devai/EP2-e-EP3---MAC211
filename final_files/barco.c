#include "barco.h"

barco posiciona_barco(char** mapa, int M, int N) {
	barco b;
	b.barco_linha = 0;
	scanf("%d", &b.barco_coluna);
	b.barco_coluna --; //converter de (1,k) para (0,k-1)
	while (b.barco_coluna < 0 || b.barco_coluna >= N || mapa[b.barco_linha][b.barco_coluna] != '-') {
		printf("Valor incompatível para coluna inicial do barco!\nTente novamente: ");
		scanf("%d", &b.barco_coluna);
		b.barco_coluna --;
	}
	mapa[b.barco_linha][b.barco_coluna] = 'B';
	return b;
}

int rema_barco(char** mapa, int M, int N, barco* b0) {
	char movimento;
	int movimento_atualizado = 0; //variável booleana;

	mapa[b0.barco_linha][b0.barco_coluna] = 'T';

	scanf("%c", &movimento);
	while (!movimento_atualizado) {
		if (movimento == 'b') {
			if (b0.barco_linha + 1 >= M) {
				printf("Movimento para fora da tabela!\nTente novamente:");
				scanf("%c", &movimento);
			}
			else {
				b0.barco_linha += 1;
				movimento_atualizado = 1;
			}
		}
		else if (movimento == 'c') {
			if (b0.barco_linha - 1 < 0) {
				printf("Movimento para fora da tabela!\nTente novamente:");
				scanf("%c", &movimento);
			}
			else {
				b0.barco_linha -= 1;
				movimento_atualizado = 1;
			}
		}
		else if (movimento == 'e') {
			if (b0.barco_coluna - 1 < 0) {
				printf("Movimento para fora da tabela!\nTente novamente:");
				scanf("%c", &movimento);
			}
			else {
				b0.barco_coluna -= 1;
				movimento_atualizado = 1;
			}
		}
		else if (movimento == 'd') {
			if (b0.barco_coluna + 1 >= N) {
				printf("Movimento para fora da tabela!\nTente novamente:");
				scanf("%c", &movimento);
			}
			else {
				b0.barco_coluna += 1;
				movimento_atualizado = 1;
			}
		}
		else {
			printf("Caractere incompatível com movimento!\nTente novamente:");
			scanf("%c", &movimento);
		}
	}
	if (mapa[b0.barco_linha][b0.barco_coluna] == 'S' ||  mapa[b0.barco_linha][b0.barco_coluna] == 'D' ||
		mapa[b0.barco_linha][b0.barco_coluna] == 'C' || mapa[b0.barco_linha][b0.barco_coluna] == 'P' ||
		mapa[b0.barco_linha][b0.barco_coluna] == 'H') return 0; //houve colisão
	mapa[b0.barco_linha][b0.barco_coluna] = 'B';
	return 1;
}
