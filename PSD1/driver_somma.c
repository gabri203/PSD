#include<stdio.h>
#include<stdlib.h>
#include "vettore.h"

#define N 50

int main( int argc, char *argv[])
{
	FILE *fp_input, *fp_oracolo, *fp_output;
	
	if((fp_input=fopen(argv[1], "r"))==NULL){
		fprintf(stderr, "Errore apertura file input.txt\n");
		exit(EXIT_FAILURE);
	}
	
	if((fp_oracolo=fopen(argv[2], "r"))==NULL){
		fprintf(stderr, "Errore apertura file oracolo.txt\n");
		exit(EXIT_FAILURE);
	}
	
	if((fp_output=fopen(argv[3], "w"))==NULL){
		printf("Errore apertura file output.txt\n");
		exit(EXIT_FAILURE);
	}
	
	char line[N];
	int arr_input[N], arr_oracolo[N];
	int n_input, n_oracolo, test, i, somma;
	
	for(i=1; fgets(line, N, fp_input)!=NULL; i++){
		n_input=input_array_str (arr_input, line);
		fgets(line, N, fp_oracolo);
		n_oracolo=input_array_str(arr_oracolo, line);
		
		somma = somma_vet(arr_input, n_input);
		printf("\n%d", somma);
		test = (somma == arr_oracolo[0]);
		
		fprintf(fp_output, "Test case %d: %d\n", i, test);
				
	}	
	
	fclose(fp_input);
	fclose(fp_output);
	fclose(fp_oracolo);
	
	return 0;
		
}