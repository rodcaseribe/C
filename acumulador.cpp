#include <stdio.h>
 
int main ()
{
    int idade,i,somaid=0,pfm=0;
    float peso,media;
 
    for(i=1;i<=10;i++)
    {
 
    printf("DADOS DA PESSOA %i:\n\n",i);
    printf("Digite a idade: ");
    scanf("%i",&idade);
    somaid+=idade;
    printf("Digite o peso: ");
    scanf("%f",&peso);
    printf("\n\n=======================\n\n");
    if(peso>=90)
    {
    pfm++;
    }
    }
    printf("%i PESSOAS PESAM MAIS DE 90kg.\n\n",pfm);
    media=somaid/10;
    printf("A media de idade e: %.2f\n",media);
    return 0;
    system ("pause");
}
