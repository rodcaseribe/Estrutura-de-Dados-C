#include <stdlib.h> //funções malloc() e free()
#include<stdio.h> //padrao
#include <string.h>
#include <locale.h>

int gravarDadosIPV4(){	
	system("netsh interface ip show config name=\"Ethernet\" | findstr \"IP Address\" > IPV4.txt");
}

int gravarGateway(){
	system("netsh interface ip show config name=\"Ethernet\" | findstr \"Padr\" > GATEWAY.txt");
}

int imprimirIP(char buff[]){
	setlocale(LC_ALL, "Portuguese");
	int i,len;
	len = strlen(buff);
	printf("Seu número de IPV4 eh:");
	for (i=0; i<len; i++){
		if(buff[i]!=' ' && buff[i]!='I' && buff[i]!='P' && buff[i]!=':'){
			printf("%c",buff[i]);
		}
    	
  	}
}


int imprimirGateway(char buff[]){
	setlocale(LC_ALL, "Portuguese");
	int i,len;
	len = strlen(buff);
	printf("Seu número de Gateway eh:");
	for (i=0; i<len; i++){
		if(buff[i]!=' ' && buff[i]!='I' && buff[i]!='Æ' && buff[i]!='P' && buff[i]!='a' && buff[i]!='d' && buff[i]!=':' && buff[i]!='o' && buff[i]!='r'){
			printf("%c",buff[i]);
		}
    	
  	}
}

int lerIPV4(){
	FILE *fp;
    char buff[255];
    int i;
    fp = fopen("IPV4.txt", "r");
    fscanf(fp, "%s", buff);
    fgets(buff, 255, (FILE*)fp);
    imprimirIP(buff);
    fclose(fp);
}

int lerGateway(){
	FILE *fp;
    char buff[255];
    int i;
    fp = fopen("GATEWAY.txt", "r");
    fscanf(fp, "%s", buff);
    fgets(buff, 255, (FILE*)fp);
    imprimirGateway(buff);
    fclose(fp);
}

int main(int argc, char* argv[])
{
   gravarDadosIPV4();
   gravarGateway();
   lerIPV4();
   lerGateway();
   return 0;
}
