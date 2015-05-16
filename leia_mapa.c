#include <stdio.h>
#include <stdlib.h>

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
