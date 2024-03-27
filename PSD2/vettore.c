#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define TRUE 1
#define FALSE 0

void input_array(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
}

void output_array(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int minimo(int *a, int n)
{
	int i;
	int min = 0;
	for(i=1; i<n; i++)
	{
		if (a[i]<a[min])
			min = i;
	}
	return min;
}

void selection_sort(int *a, int n)
{
	int i, min;
	for(i=0; i<n-1; i++)
	{
		min = minimo(a+i, n-i)+i;
		swap(&a[min], &a[i]);
	}
}

void insert_sorted_array(int *a, int *n, int val)
{
    int i;
    for (i=*n;i>0 && val<a[i-1];i--)
        a[i]=a[i-1];
    a[i]=val;
    (*n)++;
}

void insertion_sort(int *a, int n)
{
	for (int i=1;i<n;)
		insert_sorted_array(a,&i,a[i]);
}

void bubble_sort(int *a, int n)
{
	for (int i=1;i<n;i++)
		for (int j=0;j<(n-i);j++)
			if (a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}

int adaptive_bubble_sort(int *a, int n)
{
	int ordinato=FALSE;
	int operazioni=0;
	for (int i=1;i<n && !ordinato;i++)
	{
		ordinato=TRUE;
		for (int j=0;j<(n-i);j++)
		{
			operazioni++;
			if (a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				ordinato=FALSE;
			}
		}
	}
	return operazioni;
}

int binary_search(int *a, int n, int elem)
{
	int begin = 0, end = n-1, center;
	while(end >= begin)
	{
		center = (end + begin)/2;
		if(elem == a[center])
				return center;
		else if(elem < a[center])
			end = center - 1;
		else
			begin = center + 1;
	}
	return -1;
}

int input_array_str(int *a, char *line)
{
	int i=0, n=0;
	while(sscanf(line, "%d%n", &a[i], &n)==1)
	{
		line+=n;
		i++;
	}
	return i;
}

int somma(int *a, int n)
{
	int i, sum=0;
	for(i=0; i<n; i++)
		sum = sum + a[i];
	return sum;
}

void somma_vettori(int *a, int *b, int *c, int n)
{
	int i;
	for(i=0; i<n; i++)
		c[i] = a[i] + b[i];
}

int prodotto_scalare(int *a, int *b, int n)
{
	int i, prod=0;
	for(i=0; i<n; i++)
		prod = prod + (a[i]*b[i]);
	return prod;
}

int compare_arrays(int *a, int *b, int n, int m)
{
	int i=0, j=0;
	while(i<n && j<m)
	{
		if(a[i]!=b[j])
			return 0;
		i++;
		j++;
	}
	return 1;
}
int *input_array_dyn(int *size, char *line){
	int i;
	int a=0;
	int flag=0;//false
	for(i=0;line[i]!='\0';i++){//ciclo che arriva fino al terminatore
		
		
		
		if(line[i]==' '){//questa condizione mi permette di dire che se nella linea di comando ci sono spazi  allora al flag sarà assegnato il valore 0
		flag=0;	
			
		}else //altrimenti     flag==0 è già di per se falso poichè 0==0 è falso e quindi serve per poter entrare nel blocco
			if(line[i]!=' '&& flag==0){//questa condizione mi permette di dire che se nella linea di comando ci sono spazi  allora al flag sarà assegnato il valore 0
			                      //con questa condizione andiamo a verificare se gli interi 
		                         //inseriti dall'utente sono diversi dallo spazio e se il flag è uguale a 0 mi conta le volte in qui nella linea di comando è stato inserito solo i numeri e non gli spazi               
			
			a++;
			flag=1;//flag viene impostato a 1 all'interno del blocco di codice condizionale if, questo modifica lo stato del flag da 0 a 1. Quindi, successivamente, quando viene verificata la condizione flag == 0, questa sarà valutata come falsa, poiché flag non è più uguale a 0.

//In altre parole, l'impostazione di flag = 1 serve a segnalare che è stato trovato il primo carattere non spaziato, e ciò influenzerà il comportamento delle condizioni successive nel programma, rendendo la condizione flag == 0 falsa dopo che il primo carattere non spaziato è stato trovato. 1==0 falso
		}
			
	}
	int *arr; 
	*size=a;//viene dato al punytatore zise "a" che avrebbe contato le volte in cui è stato trovato  i numeri
    arr=(int*) malloc(*size * sizeof(int));//buffer dove vengono allocati gli interi di size  
	input_array_str(arr,line);//richiamiamo la funzione dentro questa funzione *input_array_dyn
	
	return arr;
}

int *concatena_vet(int *a, int *b, int j, int k)
{
	int *arr;//"c"
	int i, z=0;
	
	arr=(int *) malloc((j+k) * sizeof(int));//vengono allocati nel buffer j+k che sarebbè la dimensione totale di vet 1 e vet 2 che permette di contenere in "c" tutti i vettori
	//è praticamente la stessa cosa che viene fatto nel primo malloc  della funzione input_array_dyn.
	for(i=0; i<j; i++){//in questo ciclo  parte da 0 fino ad arrivare a j che contiene le dimensioni del primo vettore
		arr[i]=a[i];//viene assegnato all'array dalla posizione 0 fino alla pozione finale il valore del vettore di "a"
	}
	
	for(i=j; i<(j+k); i++){/*i=j  che sarebbe i=dimensione del primo vettore e poi i<(j+k) i che va dalla dimensione del primo vettore fino quando
	si arriva alle dimensione totale di j e k*/
		arr[i]=b[z];/*pure qua facciamo la stessa cosa che abbiamo fatto nel primo ciclo for del vettore "a"
             viene assegnato all'array dalla posizione 0 fino alla pozione finale il valore del vettore di "b"		*/
		z++;
	}
	
	
	
	return arr;
}