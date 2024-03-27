#include <stdio.h>
#include "punto.h"

void inputPunti(point punti[], int n){
	int i;
	float x, y;
	for(i=0; i<n; i++){
		printf("Inserisci le coordinate: ");
		scanf("%f%f", &x, &y);
		punti[i] = creaPunto(x, y);
	}
}

void outputPunti(point p){
	printf("(%.1f, %.1f)", ascissa(p), ordinata(p));
}

int calcolaCoppie(point punti[], int n, int d){/*calcola i numeri di coppie m hanno una distanza minore di d*/
	int i, j, cont = 0;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if (distanza(punti[i], punti[j]) <= d){
				outputPunti(punti[i]);//richiamo della funzione outuput di i
				printf(" e ");
				outputPunti(punti[j]);//richiamo della funzione di j che servirà insieme ad i a metterlo in questo caso nel int main
				printf("sono a distanza %.1f\n", distanza(punti[i], punti[j]));//stampiamo ogni volta sono nella la distaza
				cont++;
			}
		}
	}
	return cont;
}

float distMax(point punti[], int n){/*calcolo distanza massima che confronta i punti e mi trova la ditanza maggiore tra i putin quindi mi servono due cicli per il controllo*/
	int i, j;
	
	float d, max = 0;//contatore di max di tipo float
	
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			
			d = distanza(punti[i], punti[j]);//assegniamo la distanza alla chiamata della funzione così potremo fare il confronto
			
			if (d > max){//se la distanza è maggiore di max che sarebbe il contatore alloraa assegna max a d
				max = d;//max si prende il valore dei punti ogni volta che d è maggiore di max
			}
		}
	}
	return max;//ritorna max
}

int main(){
	int n, i, j;
	float d;
	
	printf("quanti punti? ");
	scanf("%d", &n);
	
	point punti[n];
	inputPunti(punti, n);
	
	printf("quale distanza: ");
	scanf("%f", &d);

	printf("Il numero di coppie e' %d",calcolaCoppie(punti, n, d));//calcoli il numero di m coppie di punti che hanno distanza minore di uin numero d
	printf("\nLa distanza massima e' %.1f",distMax(punti, n));
}