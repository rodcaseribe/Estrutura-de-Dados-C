#include <stdlib.h> //funções malloc() e free()
#include<stdio.h>
#include <conio.h>
#include <time.h> //calculando tempo

//bubbleSort
void bubbleSort (int vetor[], int n) {
		clock_t t;
		t = clock();
	    int k, j, aux,i ;
	    for (k = 0; k < n; k++) {
	        for (j = 0; j < n - k; j++) {
	            if (vetor[j] > vetor[j + 1]) {
	                aux          = vetor[j];
	                vetor[j]     = vetor[j + 1];
	                vetor[j + 1] = aux;
	            }
	        }
	    }
	    t = clock() - t; 
	    printf("\n-> Metodo BubleSort\n\n"); //Imprimindo Elementos
		for (i = 0;i < n; i++)
		{
			printf("%d\n",vetor[i]);
		}
		printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 
}

//insertionSort
void insertionSort(int arr[], int n) 
{ 
		clock_t t;
		t = clock();
	    int i, key, j,tam; 
	    for (i = 1; i < n; i++) { 
	        key = arr[i]; 
	        j = i - 1; 
	        while (j >= 0 && arr[j] > key) { 
	            arr[j + 1] = arr[j]; 
	            j = j - 1; 
	        } 
	        arr[j + 1] = key; 
	    } 
	    t = clock() - t; 
	    printf("\n-> Metodo InsertSort\n\n"); //Imprimindo Elementos
		for (tam = 0;tam < n; tam++)
		{
			printf("%d\n",arr[tam]);
		}
		printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 
} 

//selectionSort
void selectionSort(int num[], int tam) { 
	  	clock_t t;
	  	t = clock();
	  	int i, j, min, aux, tamanho;
	  	for (i = 0; i < (tam-1); i++) {
	     	min = i;
	     	for (j = (i+1); j < tam; j++) {
	       	if(num[j] < num[min]) 
	         	min = j;
	     	}
	     	if (num[i] != num[min]) {
	       	aux = num[i];
	       	num[i] = num[min];
	       	num[min] = aux;
	     	}
	  	}
	  	t = clock() - t;
	  	printf("\n-> Metodo Select Sort\n\n"); //Imprimindo Elementos
		for (tamanho = 0;tamanho < tam; tamanho++)
		{
			printf("%d\n",num[tamanho]);
		}
		printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 
}


int tamanhoVetor(int num_componentes){
		printf("Digite o tamanho do vetor: ");
		scanf("%d", &num_componentes);
		return num_componentes;
}

int tipoVetores(int menu1){
		printf ("\nDigite 1 p/ valores ordenados\n");
		printf ("Digite 2 p/ valores randomicos\n");
		scanf("%d", &menu1);
		return menu1;
}

int tipoOrdenacao(int menu2){
		printf ("\nDigite 1 p/ Bubble Sort\n");
		printf ("Digite 2 p/ Insertion Sort\n");
		printf ("Digite 3 p/ Selection Sort\n");
		scanf("%d", &menu2);
		return menu2;
}

int impressaoVetorInicial(int v[], int tipoVetor, int inputPrimario){
		switch ( tipoVetor )
			{
			case 1 :
				for (int i = 0; i < inputPrimario; i++){
				    v[i]=i+1;
				    printf("posicao [%d] com valor %d\n",i,v[i]); //imprimindo vetor em ordem
			  	}
			    break;
			case 2 :
				for (int i = 0; i < inputPrimario; i++){
					v[i] = rand(); 		 //randomizando
					printf("posicao [%d] com valor %d\n",i,v[i]); //imprimindo vetor randomico
				}
			}
}



int main(void){
	  	clock_t t;
		int menu2,menu1;
		int *v; //definindo o ponteiro v
		int i, num_componentes, inputPrimario, tipoVetor, tipoDeOrdenacao;
		inputPrimario = tamanhoVetor(num_componentes);
		v = (int *) malloc(inputPrimario * sizeof(int)); //Armazenando os dados em um vetor 
		tipoVetor = tipoVetores(menu1);
		impressaoVetorInicial(v,tipoVetor,inputPrimario);
		tipoDeOrdenacao = tipoOrdenacao(menu2);
	  	switch ( tipoDeOrdenacao )
  		{
		    case 1 :
		    	bubbleSort(v,inputPrimario ); //chamada bubbleSort
		    	break;
		    case 2 :
		    	insertionSort(v,inputPrimario ); //chamada insertionSort
		    	break;
		    case 3 :
		    	selectionSort(v,inputPrimario ); //chamada selectionSort
		    	break;
		    default :
		    	printf ("Valor invalido!\n");
		}


		printf("\n Rodolfo Casemiro Ribeiro - LUZ 2020 \n");
		free(v); //liberando o espaço de memória alocado
		getch(); 
		return 0;
}
