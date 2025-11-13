#include <stdio.h>
#include <stdlib.h>

typedef int tipo;

typedef struct{
    tipo* a;
    int tamanho;
} Lista;

Lista* criarLista(){
    Lista* lista;
    lista = (Lista*)malloc(sizeof(Lista));
    
    scanf("%d", &lista->tamanho);
    lista->a = (tipo*) malloc(lista->tamanho * sizeof(tipo));

    return lista;
}

void adicionarElementos(Lista* lista){
    for(int i = 0; i < lista->tamanho ; i++){
        scanf("%d", &lista->a[i]);
    }
}

void imprimirLista(Lista* lista){
    for(int i = 0; i < lista->tamanho ; i++){
        printf("%d ", lista->a[i]);
    }
}

int main(){
    Lista* lista;

    lista = criarLista();
    adicionarElementos(lista);
    imprimirLista(lista);
}