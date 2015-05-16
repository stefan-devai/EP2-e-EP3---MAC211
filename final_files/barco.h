#ifndef BARCO_H
#define BARCO_H

#include <stdio.h>
#include "defs.h"

barco posiciona_barco(char** mapa, int M, int N);
int rema_barco(char** mapa, int M, int N, barco* b0);

#endif
