#include "mapa.h"

char **leia_mapa(const char *dir_do_arquivo, int *w, int *h)
{
	int i, j;
	char ch, **map;
	FILE *map_file;

	map_file = fopen(dir_do_arquivo, "rt");

	fscanf(map_file, "%d", w);
	fscanf(map_file, "%d", h);

	map = malloc(*h * sizeof(char*));
	for(i = 0; i < *h; ++i)
		map[i] = malloc(*w * sizeof(char));

	ch = fgetc(map_file);
	for(i = 0; i < *h; ++i)
	{
		for(j = 0; j < *w; ++j)
		{
			ch = fgetc(map_file);

			if(ch == '\n')
				ch = fgetc(map_file);

			map[i][j] = ch;
		}
	}

	fclose(map_file);
	return map;
}

void destroi_mapa(char **map, int w)
{
	int i;
	for(i = 0; i < w; ++i)
		free(map[i]);
	free(map);
}

void escreva_mapa_tela(char **map, int w, int h)
{
	int i, j;
	for(i = 1; i <= w; ++i)
		printf(" %d", i);
	printf("\n");

	for(i = 0; i < h; ++i)
	{
		printf("%d ", i+1);
		for(j = 0; j < w; ++j)
		{
			if(map[i][j] == 'T' || map[i][j] == 'B' || map[i][j] == '=' || map[i][j] == '*' || map[i][j] == '+' || map[i][j] == '!')
				printf("%c ", map[i][j]);
			else
				printf("- ");
		}
		printf("\n");
	}
}

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
