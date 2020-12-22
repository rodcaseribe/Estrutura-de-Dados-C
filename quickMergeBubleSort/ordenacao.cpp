#include <stdlib.h> //funções malloc() e free()
#include<stdio.h> //padrao
#include <time.h> //calculando tempo

//merge
void merge(int vetor[], int tamanho) { 
	    int meio = tamanho / 2;
	    int i = 0, j = meio, k = 0;
	    int aux[tamanho];
	
	  	while( i < meio && j < tamanho ){
	    	if( vetor[i] <= vetor[j] )
	      		aux[k] = vetor[i++];
	    	else
	      		aux[k] = vetor[j++];
	    	k++;
	  	}
	 
	  	if( i == meio )
	    	while( j < tamanho )
	      		aux[k++] = vetor[j++];
	  	else
	    	while( i < meio )
	      		aux[k++] = vetor[i++];
	 
	  	for( i = 0; i < tamanho; i++ )
	    	vetor[i] = aux[i];
}
 
//mergeSort
int mergeSort(int vetor[], int tamanho){ 
		int meio = tamanho / 2;
		if( tamanho > 1 ){
			mergeSort(vetor, meio);
			mergeSort(vetor + meio, tamanho - meio);
			merge(vetor, tamanho);
		}

}

//QuickSort
void quickSort(int *a, int left, int right) { 
	    int i, j, x, y;
	    i = left;
	    j = right;
	    x = a[(left + right) / 2];
	    while(i <= j) {
	        while(a[i] < x && i < right) {
	            i++;
	        }
	        while(a[j] > x && j > left) {
	            j--;
	        }
	        if(i <= j) {
	            y = a[i];
	            a[i] = a[j];
	            a[j] = y;
	            i++;
	            j--;
	        }
	    }
	    if(j > left) {
	        quickSort(a, left, j);
	    }
	    if(i < right) {
	        quickSort(a, i, right);
	    }
}

//bubbleSort
void bubbleSort (int vetor[], int n) { 
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
}
//insertionSort
void insertionSort(int arr[], int n){  
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
} 

//selectionSort
void selectionSort(int num[], int tam) { 
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
}


int MENU1(int tamanhoVetor){
		printf("Digite o tamanho do vetor: ");
  		scanf("%d", &tamanhoVetor);
  		return tamanhoVetor;
}

int MENU2(int menu1){
		printf ("\nDigite 1 p/ valores ordenados\n");
  		printf ("Digite 2 p/ valores randomicos\n");
  		scanf("%d", &menu1);
  		return menu1;
}

int MENU3(int menu2){
		printf ("\nDigite 1 p/ Bubble Sort\n");
		printf ("Digite 2 p/ Insertion Sort\n");
		printf ("Digite 3 p/ Selection Sort\n");
		printf ("Digite 4 p/ Quick Sort\n");
		printf ("Digite 5 p/ Merge Sort\n");
		scanf("%d", &menu2);
		return menu2;
}

int popularVetor(int retornoMenu2, int retornoMenu1, int Vetor[], int i){
	switch ( retornoMenu2 )
	  {
	    case 1 :
		    for (i = 0; i < retornoMenu1; i++)
		  	{
			    Vetor[i]=i+1;
			    //printf("posicao [%d] com valor %d\n",i,Vetor[i]); //imprimindo vetor em ordem
		  	}
	    	break;
	    case 2 :
		    for (i = 0; i < retornoMenu1; i++)
		  	{
			    Vetor[i] = rand(); 		 //randomizando
			    //printf("posicao [%d] com valor %d\n",i,Vetor[i]); //imprimindo vetor randomico
		  	}
	  }
}

int ordenamentos(int Vetor[], int retornoMenu1, int retornoMenu3){
	 switch ( retornoMenu3 )
	  {
	  	clock_t t;
	    case 1 :
	  		t = clock();
	    	bubbleSort(Vetor,retornoMenu1 ); //chamada bubbleSort
	    	t = clock() - t;
	    	printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 
	    	break;
	    case 2 :
	  		t = clock();
	    	insertionSort(Vetor,retornoMenu1 ); //chamada insertionSort
	    	t = clock() - t;
	    	printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 
	    	break;
	    case 3 :
	  		t = clock();
	    	selectionSort(Vetor,retornoMenu1 ); //chamada selectionSort
	    	t = clock() - t;
	    	printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); 
	    	break;
	    case 4 :
	  		t = clock();
	    	quickSort(Vetor,0,retornoMenu1-1); //chamada quickSort
	    	t = clock() - t;
	    	printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));   //mergeSort(vetor, TAM_VETOR);
	    	break;
	    case 5 :
	    	t = clock();
	    	mergeSort(Vetor, retornoMenu1);; //chamada mergeSort
	    	t = clock() - t;
	    	printf("Tempo de execucao em ms: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));   
	    	break;
	    default :
	    	printf ("Valor invalido!\n");
	  }
}

int main(void)
{
	  clock_t t;
	  int menu2,menu1, terceiroMenu,menuImpressao, retornoMenu1, retornoMenu2, retTeste,retornoMenu3;
	  int *Vetor; //definindo o ponteiro v
	  int i, tamanhoVetor;
	  retornoMenu1 = MENU1(tamanhoVetor);
	  Vetor = (int *) malloc(retornoMenu1 * sizeof(int)); //Armazenando os dados em um vetor 
	  retornoMenu2 = MENU2(retTeste);
	  popularVetor(retornoMenu2, retornoMenu1, Vetor, i);
	  retornoMenu3 = MENU3(menu2);
	  ordenamentos(Vetor, retornoMenu1, retornoMenu3);
	 
	  printf ("\nDigite 1 p/ Imprimir Valores\n");
	  scanf("%d", &terceiroMenu);
	  if(terceiroMenu==1 ){ 
		  for (i = 0;i < retornoMenu1; i++) //Impressao dos Metodos
			{
				if(Vetor[i]<0){
					return 0;
				}
				printf("%d\n",Vetor[i]);
			}
	  }
	  else{
	  	printf("erro!");
	  	return 0;
	  }
	  printf("\n Rodolfo Casemiro Ribeiro - LUZ 2020 \n");
	  free(Vetor); //liberando o espaço de memória alocado 
	  return 0;
}
