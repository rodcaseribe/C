#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
   
    enum semana{dom,seg,ter,qua,qui,sex,sab}; //lista em ordem crescente, sendo a primeira variável 0

    int diasemana=sab;  //1 é segunda feira

    if(diasemana==dom || diasemana==sab){//0 é domingo  - 6 é sábado
        printf("\n\nDia de folga\n\n");
    }
    else{
        printf("\n\nDia de Trabalho\n\n");
    }
    

    system("pause");
    return 0;
}
