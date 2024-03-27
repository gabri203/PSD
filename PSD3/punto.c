#include <math.h>
#include <stdlib.h>
#include "punto.h"
/*Estendere l'ADT Punto in modo da includere le seguenti funzionalità
1. Spostamento del punti dati due numeri reali destaX e destaY
2.Calcolo del centroide(posizione media) di un insieme di punti*/

struct point{
	float x;
	float y;
}; 

point creaPunto(float x, float y){
	point p = malloc(sizeof(struct point));
	p->x = x;
	p->y = y;
	return p;
}

float ascissa(point p){
	return p->x;
}

float ordinata(point p){
	return p->y;
}

float distanza(point p1, point p2){//distanza dei punti 
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	return sqrt((dx*dx)+(dy*dy));
}

point centroide(point punti[], int n){
	float somma_X=0, somma_Y=0;// bisogna creare dei contatori per somma x e sommay
	int i;
	for(i=0; i<n;i++){
		somma_X += punti[i]->x;//così può scorre i punti in x 
		somma_Y += punti[i]->y;//invece cosi scorre i punti di y
	}
	return creaPunto(somma_X/n, somma_Y/n);//mi ritorna la funzione di creaPunto di sommax/fratto n e anche sommay/fratto n
}/*La funzione centroide calcola il centroide di un insieme di punti forniti come array punti[] e il numero totale di punti n.
 Essa somma tutte le coordinate x e y dei punti e poi calcola la media di queste somme dividendo per il numero di punti n. Infine,
 restituisce un nuovo punto che rappresenta il centroide calcolato.*/




void sposta(point p, float delta_X, float delta_Y){//void che serve per spostare quindi muovermi 
	p->x += delta_X;
	p->y += delta_Y;
}/*La funzione sposta modifica le coordinate di un punto p, spostandolo di una quantità delta_X lungo l'asse x 
e di una quantità delta_Y lungo l'asse y. 

Questa funzione prende in input il punto da spostare p, 
i valori di spostamento delta_X e delta_Y. All'interno della funzione, le coordinate x e y del punto 
vengono aggiornate aggiungendo i valori di spostamento alle rispettive coordinate attuali. 
Questo significa che il punto p viene modificato direttamente e non viene restituito alcun nuovo punto.*/