#include <stdio.h>

void escreva_mapa_arquivo(const char *dir_do_arquivo, char **map, int w, int h)
{
	int i, j;
	FILE *arq_saida;
	arq_saida = fopen(dir_do_arquivo, "a");

	for(i = 1; i <= w; ++i)
		fprintf(arq_saida, " %d", i);
	fprintf(arq_saida, "\n");

	for(i = 0; i < h; ++i)
	{
		fprintf(arq_saida, "%d ", i+1);
		for(j = 0; j < w; ++j)
		{
			if(map[i][j] == 'T' || map[i][j] == 'B' || map[i][j] == '=' || map[i][j] == '*' || map[i][j] == '+' || map[i][j] == '!')
			{
				fprintf(arq_saida, "%c ", map[i][j]);
			}
			else
			{
				fprintf(arq_saida, "%c ", '-');
			}
		}
		fprintf(arq_saida, "\n");
	}
	fprintf(arq_saida, "\n");

	fclose(arq_saida);
}
