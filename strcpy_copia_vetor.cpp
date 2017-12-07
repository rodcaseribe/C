#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome1[100], nome2[100];
    

    printf("Digite o nome: ");
    gets(nome1);
    setbuf(stdin,NULL);
    strcpy(nome2,nome1); //strcpy(onde será copiado, o que será copiado);

    printf("Vetor 2: %s\n\n", nome2);

    printf("Nome tem %d letras", strlen(nome1)); //STRLEN retorna o TAMANHO DO VETOR


    system("pause");
    return 0;
}
