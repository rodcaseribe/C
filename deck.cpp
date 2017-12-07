#include "stdio.h"
#include "stdlib.h"

struct No
{
    int Id;
    int Valor;
    struct No *Anterior;
    struct No *Proximo;
};

int main()
{
    struct No *Primeiro = (struct No*) NULL;
    struct No *Ultimo = (struct No*) NULL;    
    struct No *Atual = (struct No*) NULL;
    
    int Opt;
    do
    {
        system("cls");
        printf("1 - Consultar Valor\n");
        printf("2 - Listar Tudo\n");
        printf("3 - Substituir\n");
        printf("4 - Inserir\n");      
        printf("5 - Remover\n");
        printf("0 - Sair\n");        
        scanf("%d", &Opt);  
                                      
        if (Opt == 1)
        {
            Atual = Primeiro;
            int Valor;
            
            printf("Informe o Valor: ");
            scanf("%d", &Valor);
            
            while (Atual != (struct No*) NULL)
            {
                if (Atual-> Valor == Valor)
                {
                    printf("ID: %d\n", Atual-> Id);
                }
                Atual = Atual-> Proximo;
            }   
                     
            system("pause");
        }
        else if (Opt == 2)
        {
            Atual = Primeiro;
            while (Atual != (struct No*) NULL)
            {
                printf("ID: %d | Valor %d\n", Atual-> Id, Atual-> Valor);
                Atual = Atual-> Proximo;
            }            
            system("pause");            
        }
        else if (Opt == 3)
        {
            Atual = Primeiro;
            int Id, Valor;
            
            printf("Informe o Id e o Novo Valor: ");
            scanf("%d %d", &Id, &Valor);
            
            while (Atual != (struct No*) NULL)
            {
                if (Atual-> Id == Id)
                {
                    Atual-> Valor = Valor;
                    break;
                }
                Atual = Atual-> Proximo;
            }            
            system("pause");            
        }
        else if (Opt == 4)
        {
            int Valor;
            printf("Informe o Valor: ");
            scanf("%d", &Valor);  
            // Valor -85
            if (Primeiro == (struct No*) NULL)
            {
                Primeiro = Ultimo = Atual = (struct No*) malloc(sizeof(struct No));
                Atual-> Id = 1;
                Atual-> Valor = Valor;                
                Atual-> Anterior = (struct No*) NULL;
                Atual-> Proximo = (struct No*) NULL;
            }
            else
            {
                Atual = (struct No*) malloc(sizeof(struct No));
                Atual-> Id = Primeiro-> Id + 1;
                Atual-> Valor = Valor;
                Atual-> Anterior = (struct No*) NULL;
                Atual-> Proximo = Primeiro;
                
                Primeiro-> Anterior = Atual;
                Primeiro = Atual;
            }
        }
        else if (Opt == 5)
        {
            if (Primeiro == (struct No*) NULL)
                continue;

            if (Primeiro == Ultimo)
            {
                Atual = Primeiro;
                free(Atual);
                Atual = Primeiro = Ultimo = (struct No*) NULL;
                continue;
            }

            Atual = Primeiro;
            Primeiro-> Proximo-> Anterior = (struct No*) NULL;
            Primeiro = Primeiro-> Proximo;
            
            free(Atual);
        }

    } while (Opt != 0);
    system("Pause");
    return 0;
}
