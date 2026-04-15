#include <stdio.h>
#include <stdlib.h>


//estrutura

typedef struct No
{
    int info;
    struct No *esq;
    struct No *dir;
} No;

//CriarNo

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->info= valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

//inserção
//verificar se a arvore ta vazia
//se for menor -> esq
//se for maior -> dir

No* inserir (No* raiz, int info){
    if (raiz == NULL){
        return criarNo;
    }
    if (info <raiz->info){
        raiz->esq = inserir(raiz->esq,info);
    }
    else (info > raiz->info)
        raiz->dir = inserir (raiz->dir,info);
}

//busca
//para buscar primeiro verifica se a arvore etá vazia OU o valor buscado é igual a raiz
//se for menor ->esq
//se for maior->dir

No* buscar(No*raiz,int info){
    if (raiz== NULL|| info == raiz->info){
        return raiz;
    } 
    if (info > raiz->info){
        return buscar(raiz->esq,info);
    } 
    else 
    return buscar(raiz->dir,info);
}

//remoção

//FUnção de econtrar o menor nó para o Caso 3 em uso de sucessor.
No* menorNo (No*raiz, int info){
    No* atual = raiz;
    while (atual &&  atual->esq != NULL){
        atual = atual->esq;
        return atual;
    }
}
//Funçao econtrar maior no para Caso 3 em uso de predecessor.
No* maiorNo(No* raiz, int info){
    No* atual = raiz;
    while (atual && atual->dir != NULL){
        atual = atual->dir;
        return atual;
    }
}



No* remover(No*raiz, int info){
    //verificar se stá vazio
    if (raiz==NULL){
        return raiz;
    }   //localizadores de nó   
    if (info<raiz->info){
        raiz->esq = remover(raiz->esq,info);
    }
    else if (info >raiz->info){
        raiz->dir= remover(raiz->dir,info);
    } //casos de remoção
    //caso 1 - Arvore não tem filhos, somente folhas.
    if (raiz->esq ==  NULL && raiz->dir == NULL){
        free(raiz);
        return NULL;
    }
    //caso 2 - A arvore tem somente um filho.
    else if (raiz->esq ==  NULL){
        No *temp = raiz->dir;
        free(raiz);
        return temp;
    }
    else if (raiz->dir == NULL){
        No *temp = raiz->esq;
        free(raiz);
        return temp;
    }
    //caso 3 - 
    else{
        No* temp = menorNo(raiz->dir);
        raiz->info = temp->info;
        raiz->dir = remover(raiz-> dir, temp->info);
    }

}
