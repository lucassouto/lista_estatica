//os tipos de dados
//implementação das funções
#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

struct lista{
    int quantidade;
    struct aluno dados [MAX];
};

Lista* cria_Lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof (struct lista));
        if(li != NULL)
            li->quantidade = 0;

    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int tam_Lista(Lista* li){
    if (li == NULL)
        return -1;
    else
        return li->quantidade;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;

    return (li->quantidade == 0);
}

int lista_cheia(Lista* li){
    if (li == NULL)
        return -1;

    return (li->quantidade == MAX);
}

int insere_final(Lista* li, struct aluno elemtento){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    li->dados[li->quantidade] = elemtento;// a posição do vetor dados apontada pela quantidade, recebe os dados da variável elemento
    li->quantidade++;//incrementa a quantidade para ir para a próxima posição da lista

    return 1;
}

int insere_inicio(Lista* li, struct aluno elemento){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;

    int i;
        for(i=li->quantidade-1; i >=0; i--)//quantidade indica a ultima posição válida, quantidade-1 indica o ultimo elemento inserido
            li->dados[i+1] = li->dados[i]; //a próxima posição vaga recebe os dados da ultima posição inserida

    li->dados[0] = elemento;//o inicio da lista recebe o valor a ser inserido
    li->quantidade++;//incrementa para a próxima posição

    return 1;
}

int insere_ordenado(Lista* li, struct aluno elemento){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    if(lista_vazia(li)){
        insere_inicio(li,elemento);
        return 1;
    }

    int i,j=0;

        while(i < li->quantidade && li->dados[i].matricula < elemento.matricula)//procura o maior elemento que o que está sendo inserido para ordenar na posição
            i++;

        for(j=li->quantidade-1; j>=i; j--)//desloca os elementos da lista para frente para que possa ser inserido o novo elemento no meio
            li->dados[j+1] = li->dados[j];

    li->dados[i] = elemento;//a posição que foi ordenada recebe o elemento a ser inserido
    li->quantidade++;//incrementa para a próxima posição

    return 1;
}

int remove_final(Lista* li){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;

     li->quantidade--;

     return 0;
}

int remove_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;

    int i;
        for(i=0; i<li->quantidade-1; i++)
            li->dados[i] = li->dados[i+1];

    li->quantidade--;

    return 0;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(lista_vazia(li))
        return 0;

    int i,j;
        while(j<li->quantidade && li->dados[j]. matricula != mat){
            j++;
            if(j == li->quantidade)//elemento não encontrado
                return 0;
        }

        for(i=j; i<li->quantidade-1; i++)
            li->dados[i] = li->dados[i+1];

    li->quantidade--;

    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *elemento){
    if(li == NULL || pos <= 0 ||  pos > li->quantidade)
        return 0;
    *elemento = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *elemento){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->quantidade && li->dados[i].matricula != mat)
        i++;
    if(i == li->quantidade)//elemento nao encontrado
        return 0;

    *elemento= li->dados[i];
    return 1;
}

struct aluno cadastro(Lista* li){
  struct aluno elemento;
  char opc;

   system("cls");
     printf("\nNome:");
      scanf(" %80[^\n]", elemento.nome);
       fflush(stdin);
     printf("\nMatricula:");
      scanf("%d", &elemento.matricula);
      fflush(stdin);
     printf("\nNota 1:");
      scanf("%f", &elemento.n1);
      fflush(stdin);
     printf("\nNota 2:");
      scanf("%f", &elemento.n2);
      fflush(stdin);
     printf("\nNota 3:");
      scanf("%f", &elemento.n3);
      fflush(stdin);

     printf("\n--------------------------------------------------------------------------------\n");
     printf("\nNome: %s",     elemento.nome);
     printf("\nMatricula: %d",elemento.matricula);
     printf("\nNota 1: %.2f", elemento.n1);
     printf("\nNota 2: %.2f", elemento.n2);
     printf("\nNota 3: %.2f", elemento.n3);
     printf("\n--------------------------------------------------------------------------------");
     do{
        printf("\n\t\tClick |S| SALVAR ou |N| NAO SALVAR.\n");
        scanf(" %c", &opc);
        fflush(stdin);
        system("cls");
            if(opc=='N' || opc=='n')
                menu(li);
            else if(opc=='S' || opc=='s')
                return elemento;
     }while(opc!='N' || opc!='n' || opc!='S' || opc!='s');
     return 1;
}

void exibirCadastro(struct aluno elemento){
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\nNome: %s",        elemento.nome);
    printf("\nMatricula: %d", elemento.matricula);
    printf("\nNota 1: %.2f", elemento.n1);
    printf("\nNota 2: %.2f", elemento.n2);
    printf("\nNota 3: %.2f", elemento.n3);
    printf("\n--------------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\n\n\n\n\n");
    system("pause");
}

void menu(Lista* li){
    int opcao;

    printf("-------------------------------------\n");
    printf("\t           LISTA ESTÁTICA          \n");
    printf("-------------------------------------\n");

    printf("\n\n");
    printf("[1] - Insere na Lista\n");
    printf("[2] - Remove da Lista\n");
    printf("[3] - Procura na Lista\n");
    printf("[4] - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    system("cls");

    escolha(li,opcao);

}

void escolha(Lista* li, int opcao){

    int opc;
    int pos;
    int mat;
    struct aluno elemento;

    switch(opcao){

    case 1:
        printf("-------------------------------------\n");
        printf("\t            INSERIR                \n");
        printf("-------------------------------------\n");

        printf("\n\n");
        printf("[1] - Inserir no Inicio\n");
        printf("[2] - Inserir no Final\n");
        printf("[3] - Inserir na posicão desejada\n");
        printf("[4] - Voltar para o menu\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opc);
            switch(opc){
                case 1:
                    elemento=cadastro(li);
                    insere_inicio(li, elemento);
                    //arquivo_binario(li,elemento);
                    system("cls");
                    menu(li);
                    break;
                case 2:
                    elemento=cadastro(li);
                    insere_final(li, elemento);
                    //arquivo_binario(li,elemento);
                    system("cls");
                    menu(li);
                    break;
                case 3:
                    elemento=cadastro(li);
                    insere_ordenado(li, elemento);
                    //arquivo_binario(li,elemento);
                    system("cls");
                    menu(li);
                    break;
                case 4:
                    menu(li);
                    system("cls");
                    break;
            }
        system("cls");
        break;

    case 2:
        printf("-------------------------------------\n");
        printf("\t            REMOVER                \n");
        printf("-------------------------------------\n");

        printf("\n\n");
        printf("[1] - Remover no Inicio\n");
        printf("[2] - Remover no Final\n");
        printf("[3] - Remover na posicão desejada\n");
        printf("[4] - Voltar para o menu\n");
        scanf("%d", &opc);
            switch(opc){
                case 1:
                    remove_inicio(li);
                    //arquivo_binario(li,elemento);
                    system("cls");
                    menu(li);
                    break;
                case 2:
                    remove_final(li);
                    system("cls");
                    menu(li);
                    break;
                case 3:
                    printf("\tDigite a matricula: ");
                    scanf("%d", &mat);
                    remove_lista(li,mat);
                    system("cls");
                    menu(li);
                    break;
                case 4:
                    menu(li);
                    system("cls");
                    break;
            }
        system("cls");
        break;
    case 3:
        printf("-------------------------------------\n");
        printf("\t            PROCURAR               \n");
        printf("-------------------------------------\n");

        printf("\n\n");
        printf("[1] - Procurar por posição\n");
        printf("[2] - Procurar por matrícula\n");
        printf("[3] - Voltar para o menu\n");
        scanf("%d", &opc);
            switch(opc){
                case 1:
                    printf("\tDigite a posição: ");
                    scanf("%d", &pos);
                    consulta_lista_pos(li,pos,&elemento);
                    exibirCadastro(elemento);
                    system("cls");
                    menu(li);
                    break;
                case 2:
                    printf("\tDigite a matricula: ");
                    scanf("%d", &mat);
                    consulta_lista_mat(li,mat,&elemento);
                    exibirCadastro(elemento);
                    system("cls");
                    menu(li);
                    break;
                case 3:
                    menu(li);
                    system("cls");
                    break;
            }
        system("cls");
        break;

    }

}

