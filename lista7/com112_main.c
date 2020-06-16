#include <stdio.h>
#include "com112_arvoreAVL.h"

int menu(){
    int opcao;

    printf("\n\nMenu de opções");
    printf("\n1 - Criar árvore");
    printf("\n2 - Liberar árvore");
    printf("\n3 - Inserir elemento");
    printf("\n4 - Remover elemento");
    printf("\n5 - Consultar elemento");
    printf("\n6 - Imprimir percurso pré-ordem");
    printf("\n7 - Imprimir percurso em-ordem");
    printf("\n8 - Imprimir percurso pós-ordem");
    printf("\n9 - Altura da árvore");
    printf("\n10 - Total de elementos");
    printf("\n11 - Sair");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    return opcao;
}
int main(void) {

  ArvAVL *raiz;
  int opcao, valor, ok, pos;

  do
  {
    opcao = menu();

    switch(opcao){

      case 1: 

        // criar arvore binaria
        raiz = cria_ArvAVL();

        if(raiz != NULL){
          printf("\n Árvore criada com sucesso!");
        }else{
          printf("\n Árvore não criada!");
        }
        break;


      case 2: 
        
        // liberar arvore binaria
        ok = libera_ArvAVL(raiz);

        if(ok){
          printf("\n Árvore liberada com sucesso!");
        }else{
          printf("\n Árvore não liberada!");
        }
        break;

      case 3:

        // inserir nó na árvore binária  
        printf("\n Valor a ser inserido: ");
        scanf("%d", &valor);      

        ok = insere_ArvAVL(raiz, valor);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // remover nó com determinado valor
        printf("\n Valor a ser removido: ");
        scanf("%d", &valor); 

        ok = remove_ArvAVL(raiz, valor);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }

        break;

      case 5:

        // busca elemento pelo valor
        printf("\n Valor a ser buscado: ");
        scanf("%d", &valor); 

        ok = consulta_ArvAVL(raiz, valor);

        if(ok == 1){
          printf("\n Busca realizada com sucesso!");
        }else{
          printf("\n Valor não encontrado na árvore!");
        }


        break;

      case 6:    
        // imprime percurso pré-ordem
        preOrdem_ArvAVL(raiz);
        break;

      case 7:   
        // imprime percurso em-ordem 
        emOrdem_ArvAVL(raiz);
        break;

      case 8:    
        // imprime percurso pós-ordem
        posOrdem_ArvAVL(raiz);    
        break;


      case 9:
        // imprime a altura da árvore binária
        printf("%d\n", altura_ArvAVL(raiz));
        break;
      
        break;

      case 10:
        // imprime o número total de nós na árvore binária
        printf("%d\n", totalNO_ArvAVL(raiz));
        break;
              
      case 11:

        // libera memória e finaliza programa
        libera_ArvAVL(raiz);
        printf("\nFinalizando...\n");
        break;

      default: 
        printf("\nOpção inválida!\n");
        break;
    }

  }while(opcao != 11);

  return 0;
}