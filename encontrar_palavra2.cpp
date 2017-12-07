#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* pos(char* C,char* S)
{
    return strstr(C, S);
}

int main(void)
{
    char palavra[] = "JOAO";
    char texto[] = "blableaJOAOblablaJOAOBLABLA";
    char *posicao = texto;
    char qtdEncontrada = 0;

    while(1)
    {
        posicao = pos(posicao, palavra);
        if (posicao == NULL)
            break;

        qtdEncontrada++;
        posicao = &posicao[strlen(palavra)];
    }

    printf("Palavra encontrada %d veze(s)\n", qtdEncontrada);

    return (0);
}
