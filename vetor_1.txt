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
        "papagaio"};

    char PALAVRA[10];
    int palavra=0;
    int i;
    
    for(i=0;i<10;i++){
        PALAVRA[i]=banco[palavra][i];
    }
    printf("\n\n\n%s\n\n",PALAVRA);

    printf("\n _ _ _ _ _ \n\n");

    system("pause");
    return 0;
}
