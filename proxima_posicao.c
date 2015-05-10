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
