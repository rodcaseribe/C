/*




*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char banco[3][10]={
        "cavalo",
        "cachorro",
        "papagaio"
		};
    int palavra=1;
    int i;
    //imprimir linha da matriz
    for(i=0;i<10;i++){
        printf("%c", banco[palavra][i]);
    }

    

    system("pause");
    return 0;
}
