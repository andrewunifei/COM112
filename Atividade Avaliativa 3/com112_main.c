#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "com112_hash.h"

int menu()
{
    int op;

    printf("\nMenu de opções\n");
    printf("1- Criar tabela hash\n");
    printf("2- Liberar tabela hash\n");
    printf("3- Inserir elemento\n");
    printf("4- Consultar elemento\n");
    printf("5- Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &op);

    return op;
}

int main() 
{
  Hash *has;
  struct aluno *al;
  int op, valor, a, tamanho;

    printf("Entre com o tamanho do vetor");
    scanf("%d", &tamanho);

    do
    {
        op = menu();
        switch(op){

            case 1: 
                has = criaHash(tamanho);

                if(has != NULL)
                {
                printf("\n Tabela hash criada com sucesso");
                }
                else
                {
                printf("\n Tabela hash não foi criada");
                }
                break;


            case 2: 
                liberaHash(has);

                printf("\n Tabela hash liberada");
                break;

            case 3:
                printf("\n Digite o valor a ser inserido: ");
                scanf("%d", &valor);      

                a = insereHash_SemColisao(has, *al);

                if(a == 1)
                {
                printf("\n Inserção realizada");
                }
                else
                {
                printf("\n Inserção não realizada");
                }
                break;

            case 4:
                printf("\n Digite o valor a ser buscado: ");
                scanf("%d", &valor); 

                a = buscaHash_SemColisao(has, valor, al);

                if(a == 1)
                {
                printf("\n Busca realizada");
                }
                else
                {
                printf("\n Valor não encontrado");
                }
                break;
                    
            case 5:
                liberaHash(has);
                printf("\nFinalizando...\n");
                break;

            default: 
                printf("\nOpção inválida!\n");
                break;
        }

    }
    while(op != 5);

  return 0;
}