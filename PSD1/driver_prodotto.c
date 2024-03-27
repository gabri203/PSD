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
	int arr_input1[N], arr_input2[N], arr_oracolo[N];
	int n_input1, n_input2, n_oracolo, prod, test, i;
	
	for(i=1; fgets(line, N, fp_input)!=NULL; i++){
		n_input1=input_array_str(arr_input1, line);
		fgets(line, N, fp_input);
		n_input2=input_array_str(arr_input2, line);
		fgets(line, N, fp_oracolo);
		n_oracolo=input_array_str(arr_oracolo, line);
		
		prod = prodotto(arr_input1, arr_input2, n_input2);
		test = (prod == arr_oracolo[0]);
		
		fprintf(fp_output, "Test case %d: %d\n", i, test);
				
	}	
	
	fclose(fp_input);
	fclose(fp_output);
	fclose(fp_oracolo);
	
	return 0;
		
}