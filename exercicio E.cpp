#include <stdio.h>
#include <stdlib.h>
int qtd_maxima=10;
int inserir( int *x, int *pos, int *fim,int valor){
    int i;
    if (*pos<0 || *pos>qtd_maxima)
    {
    printf("\nelemento nao foi inserido\n");
        return 0;
        }
    else {
 
        for (i=*fim; i>=*pos; i--)
         x[i+1]=x[i];
         *fim=*fim+1;
         x[*pos]=valor;
         printf("\n Elemento foi inserido posicao: %d \n valor: %d",*pos,valor);
         printf("\n Valor de fim : %d \n",*fim);  
         *pos=*pos+1;
         return 1;
        }   
    return 1;        
}
int acessar (int *x,int k,int *fim ){
 int valor;   
 printf("\n Valor de k : %d \n",k);
 printf("\n Valor de fim : %d \n",*fim);    
 if (k<0 || k>*fim)
    {
     printf("\n Nao Encontrado");
    return(0);
    }
 else
  {
    valor=x[k];
    printf("\n Encontrado : %d ",valor);
    return(1);
  }
  system("pause");
}
int alterar(int *x,int k, int *fim){
    int valor;
    printf("\n Digite a posiçao do valor a ser alterado.... \n");
    scanf("%d",&k);
    if (k<0 || k>*fim)
    return(0);
  else
   {    
    printf("\n Valor : %d \n",x[k]);
    printf("\n Digite o novo valor . . . . . \n");
    scanf("%d",&valor);         
    x[k]=valor;
    printf(" Novo valor gravado com sucesso : %d ..... posicao : %d -----",x[k],k); 
    return(1);
   }
   system("pause");
 }  
int remover(int *x ,int *fim,int pos)
{  
 int i=0; 
     if (pos<0 || pos>*fim || *fim==0)
         {
          return(0);
         }
     else
      {
       for(i=pos;i<=*fim-1;i++)
       {              
       x[i]=x[i+1];
       }
       *fim=*fim-1;
       return (1);
       }
       }      
int imprimir(int *x,int *fim)
{
int i;
   printf("O fim da lista e \n%d",*fim);
   printf("\n\n\n\n");
   printf(" Valores da lista ...........\n\n");
   for (i=0; i<*fim; i++)
    printf("\n%d",x[i]);  
    system("pause");
return 1;  
}                  
int x[10];
int op =1;
int fim=0, sinal,pos=0,k,val;
int main(int argc, char *argv[])
{
     while (op!=6){
      printf("\n\n ----------------------- ");
      printf("\n 1 - Incluir ");
      printf("\n 2 - Listar ");
      printf("\n 3 - Alterar ");
      printf("\n 4 - Excluir ");
      printf("\n 5 - Consultar ");
      printf("\n 6 - Sair ");
      printf("\n\n Escolha uma opcao: ");
      scanf("%d",&op);
      system("cls");
switch (op){
        case 1:{ 
     printf("\n Digite o  valor a ser inserido \n " );
     printf("\n");
     scanf("%d",&val);        
     inserir(x,&pos,&fim,val);
      break;
      }
   case 2:{
      imprimir(x,&fim);  
      break;
      }
   case 3:{
      alterar(x,k,&fim);
      printf("\n"); 
      break;
      } 
   case 4:{
        printf("\n Digite a posicao do valor a ser removido\n");
        printf("\n");
        scanf("%d",&pos);
        remover(x,&fim,pos);
     break;
     }     
   case 5:{
       printf ("\n Digite a posição do valor \n");
       scanf("%d",&k); 
       acessar(x,k,&fim);
      break;
      }
   case 6:{ 
      printf("\nSaindo...\n");
      system("\n\npause");   
      break;
      } 
      }
      }  
}
