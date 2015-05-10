#include <stdio.h>
#include "defs.h"
// recebe o mapa MxN
// insere o barco no mapa de acordo com a entrada padrão
// retorna a struct barco atualizada
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