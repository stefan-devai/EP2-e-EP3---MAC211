#ifndef DISPAROS_H
#define DISPAROS_H

#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

int sorteia(int k);
tiro coordenadas_tiro(char** mapa, int M, int N);
void dispara_tiros(char** mapa, int M, int N, FILE* f);
void identifica_alvo_atingido(char** mapa, int M, int N, tiro t);
void proxima_posicao(int M, int N, tiro t, int *l, int *c, int *contador);
void afunda_destroyer(char** mapa, int M, int N, tiro t);
void afunda_portaaviao(char** mapa, int M, int N, tiro t);
void afunda_cruzador(char** mapa, int M, int N, tiro t);
void afunda_hidroaviao(char** mapa, int M, int N, tiro t);

#endif
