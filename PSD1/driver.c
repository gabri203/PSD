#include<stdio.h>
#include<stdlib.h>
#include "vettore.h"

#define N 50

int main(void)
{
FILE *fp_input, *fp_oracolo, *fp_output;

if((fp_input=fopen("input.txt", "r")) == NULL) {
//viene assegnato un puntatore al file
fprintf(stderr, "Errore apertura file input.txt\n");
exit(EXIT_FAILURE);
}
if((fp_oracolo=fopen("oracolo.txt", "r") ) == NULL) {
//viene assegnato un puntatore al file
fprintf(stderr, "Errore apertura file oracolo.txt\n");
exit (EXIT_FAILURE);
}
if((fp_output=fopen("output.txt", "w") ) == NULL) {
//viene assegnato un puntatore al file output che verrà creato o sovrascritto
printf("Errore apertura file output.txt\n");
exit (EXIT_FAILURE);

}
char line[N]; // buffer per contenere i caratteri letti nel file
int arr_input [N]; //arr_input
int arr_oracolo[N]; //arr_oracolo -> contiene una linea del file .. oracolo.xt
int n_input; // la dimensione di arr_input[]
int n_oracolo; // la dimensione di arr_oracolo[]
int test; // è usata per esprimere il risultato del testing:
int i;

for(i=1; fgets(line, N, fp_input) != NULL; i++){
//La funzione fgets() legge una linea dallo stream immagazzinandola nel buffer puntato da line

n_input=input_array_str (arr_input, line);
//input_array_str estrapola i dati dal buffer puntato da line

fgets(line, N, fp_oracolo);
n_oracolo=input_array_str(arr_oracolo, line);

bubble_sort(arr_input, n_input);
//ordina vettore in input.txt

test = compare_arrays(arr_input, arr_oracolo, n_input, n_oracolo);
//confronta vettore in input. txt e oracolo.txt

fprintf(fp_output, "Test case %d: %d\n", i, test);
//scrive il risultato sul file di output
}
fclose(fp_input);
fclose(fp_output);
fclose(fp oracolo):
}