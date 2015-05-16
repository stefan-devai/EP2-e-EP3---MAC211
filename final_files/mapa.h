#ifndef MAPA_H
#define MAPA_H

#include <stdio.h>
#include <stdlib.h>

char **leia_mapa(const char *dir_do_arquivo, int *w, int *h);
void destroi_mapa(char **map, int w);
void escreva_mapa_tela(char **map, int w, int h);
void escreva_mapa_arquivo(const char *dir_do_arquivo, char **map, int w, int h);

#endif