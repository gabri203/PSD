driver_somma_v.exe : utils.o vettore.o driver_somma_v.o
	gcc utils.o vettore.o driver_somma_v.o -o driver_somma_v.exe

driver_somma.exe :	utils.o vettore.o driver_somma.o
	gcc utils.o vettore.o driver_somma.o -o driver_somma.exe

driver_prodotto.exe :	utils.o vettore.o driver_prodotto.o
	gcc utils.o vettore.o driver_prodotto.o -o driver_prodotto.exe
	
utils.o :
	gcc -c utils.c
	
vettore.o :
	gcc -c vettore.c
	
driver_prodotto.o :
	gcc -c driver_prodotto.c
	
driver_somma.o :
	gcc -c driver_somma.c

driver_somma.o :
	gcc -c driver_somma_v.c
	
clean: 
	rm -f *.o *.exe