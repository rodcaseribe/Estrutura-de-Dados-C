#include <stdlib.h> //fun��es malloc() e free()
#include<stdio.h> //padrao
#include <string.h>
#include <locale.h>

int gravarDadosTXT(){	
	system("netsh interface ip show config name=\"Ethernet\" | findstr \"IP Address\" > IPV4.txt");
}


int imprimirIP(char buff[]){
	setlocale(LC_ALL, "Portuguese");
	int i,len;
	len = strlen(buff);
	printf("Seu n�mero de IPV4 eh:");
	for (i=0; i<len; i++){
		if(buff[i]!=' ' && buff[i]!='I' && buff[i]!='P' && buff[i]!=':'){
			printf("%c",buff[i]);
		}
    	
  	}
}

int lerTXT(){
	FILE *fp;
    char buff[255];
    int i;
    fp = fopen("IPV4.txt", "r");
    fscanf(fp, "%s", buff);
    fgets(buff, 255, (FILE*)fp);
    imprimirIP(buff);
    fclose(fp);
}


int main(int argc, char* argv[])
{

   gravarDadosTXT();
   lerTXT();
   return 0;
}
