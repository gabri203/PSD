#include <stdio.h>
#include "utils.h"
#define N 100

int prodotto(int *arr1, int *arr2, int n){
	int i, somma=0;
	for(i=0; i<n; i++)
		somma += arr1[i]*arr2[i];
	return somma;	
}


int somma_v(int *arr1, int n1, int *arr2, int n2, int *result){
	int i;
	if(n1<=n2){
		for(i=0; i<n1; i++)
			result[i] = arr1[i]+arr2[i];
		for(i=n1; i<n2; i++)
			result[i] = arr2[i];
		return n2;
	}
	else{
		for(i=0; i<n2; i++)
			result[i] = arr1[i]+arr2[i];
		for(i=n2; i<n1; i++)
			result[i] = arr1[i];		
		return n1;
	}
}

int somma(int *arr, int n){
	int i, somma=0;
	for(i=0; i<n; i++)
		somma += arr[i];
	return somma;	
}
	

int elimina_el(int *arr, int *n, int pos){
	int i;
	for(i=pos; i<*n; i++)
		arr[i]=arr[i+1];
	(*n)--;
}


void shuffle(int *arr, int n){
	int i, r;
	srand(time(NULL));
	for(i=n-1; i>0; i--){
		r = rand() % (i+1);
		swap(&arr[r], &arr[i]);
	}
}

void aggiungi_el (int a[], int* n, int el, int pos)
{
	int i=*n-1;
	for(;i>=pos;i--){
		a[i+1]=a[i];
	}
	a[pos]=el;
	*n=*n+1;
}

void aggiungi_el_sort (int a[], int* n, int el)
{
	int i=*n-1;
	for(;a[i]>=el && i >= 0;i--){
		a[i+1]=a[i];
	}
	a[i+1]=el;
	*n=*n+1;
}		

void insertion_sort (int a [], int n)
{
	int i = 1;
	while (i < n)
		aggiungi_el_sort (a, &i, a[i]);
}

int minimo(int *a, int n) {   
	int min = 0, i;
	
	for(i=1; i<n; i++)
		if (a[i] < a[min]) 
			min=i;
		
    return min;	
}

void selection_sort(int a[], int n) {
	int i = 0,
		min;
	
	for(; i < n - 1; i++) {
		min = minimo(a + i, n - i);
		
		swap(&a[i], &a[min + i]);
	}
}

void bubble_sort(int a[], int n)
{
	int i, j;
	for(i=1; i<n; i++)
		for(j=0; j<n-i; j++)
			if(a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
}


void bubble_sort_adattivo(int a[], int n)
{
	int i, j, ordinato = 0;
	for(i=1; i<n && !ordinato; i++){
		ordinato = 1;
		for(j=0; j<n-i; j++)
			if(a[j] > a[j+1]){
				swap(&a[j], &a[j+1]);
				ordinato = 0;
			}
	}
}

int confronta_array(int a [], int b [],int  n1, int n2){
		int i;
		if(n1!=n2)
			return 0;
		for(i=0; i<n1 ;i++)
			if(a[i]!= b[i])
				return 0;
		return 1;
}

int input_array_str(int *arr,char* line){
	int i=0,n=0;
	while(sscanf(line,"%d%n",&arr[i],&n)==1){
		line+=n;
		i++;
	}	
	return i;
}

void input_array(int a[], int n) {
	int i=0;
	
	for (; i<n; i++)
		scanf("%d", &a[i]);
}

void output_array(int *a, int n) {
	int i;
	
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	
	printf("\n");
}

