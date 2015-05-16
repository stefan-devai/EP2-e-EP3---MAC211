#include <stdio.h>

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
