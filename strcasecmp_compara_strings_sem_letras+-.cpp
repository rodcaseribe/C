#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome1[100], nome2[100];
    
    printf("Digite o nome 1: ");
    gets(nome1);
    setbuf(stdin,NULL);

    printf("Digite o nome 2: ");
    gets(nome2);
	
	if(strcasecmp(nome1,nome2)==0){
		printf("nomes iguais");
		}
		else{
		printf("nomes diferentes");
		}

    system("pause");
    return 0;
}
