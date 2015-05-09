#include <stdio.h>
#include "defs.h"

barco rema_barco(char** mapa, int M, int N, barco b0) {
	char movimento;
	int movimento_atualizado = 0; //variável booleana

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

	mapa[b0.barco_linha][b0.barco_coluna] = 'B';
	return b0;
}