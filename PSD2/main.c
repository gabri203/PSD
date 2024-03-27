#include <stdio.h>
#include "vettore.h"

int main(){

int j,k;
char ch;
char line[100]; 
int *a;
int *b;
int *c;

printf("Inserisci il primo vettore = ");//primo inserimento degli interi dentro il vettore 1
    scanf("%[^\n]",line);
   a = input_array_dyn(&j,line);
   
  
    line[0] = '\0';//serve per svuotare il vettore dopo averlo inserito perchè cosi lo posso usare nel secondo vettore
	
	ch = getchar();/*La funzione getchar() viene utilizzata per consumare il carattere di nuova riga ('\n') rimasto nel buffer di input dopo la chiamata precedente a scanf(). 
	Questo assicura che la successiva chiamata a scanf() legga l'input correttamente, 
	senza essere influenzata dal carattere di nuova riga rimasto nel buffer. 
	In altre parole, getchar() "pulisce" il buffer di input, consentendo a scanf() di leggere l'input successivo senza problemi*/
	
	printf("Inserisci il secondo vettore = ");//verrà inserito il secondo vettore da parte dell'utente
	scanf("%[^\n]", line);
	b = input_array_dyn(&k,line);
	
	
	c = concatena_vet(a,b,j,k);//questa funzione viene richiamata per  unificare il primo e il secondo vettore con j e k che mi permette la concatenazione nella funzione
	
	printf("\n L'Array concatenato e' = ");
	output_array(c,j+k);//richiamo della funzione output_array,così da stampare "c" che sarebbe il vettore finale che contine il primo e il secondo concatenati
	
      /* bubble_sort(a,n);*/
     

return 0;
}
