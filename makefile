coordenadas_tiro.o: coordenadas_tiro.c sorteia.o defs.h
	gcc -c coordenadas_tiro.c 
posiciona_barco.o: posiciona_barco.c defs.h
	gcc -c posiciona_barco.c
rema_barco.o: rema_barco.c defs.h
	gcc -c rema_barco.c
sorteia.o: sorteia.c
	gcc -c rema_barco.c
