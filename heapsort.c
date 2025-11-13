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

void refazHeapMaximo(Lista* lista, int tamanho, int i){
    int filhoesq = 2*i + 1; //Calcula qual é o filho esquerdo através da formula
    int filhodir = 2*i + 2; //Calcula qual é o filho direito através da formula
    int maior = i; //Assume que o maior nó é o pai
    tipo temp;

    if(filhoesq < tamanho && lista->a[filhoesq] > lista->a[i]) //Verifica se existe o filho e se ele é maior que o pai
        maior = filhoesq; //Se for maior, agora o maior é o filho (por enquanto, o indice)
    
    if(filhodir < tamanho && lista->a[filhodir] > lista->a[maior]) //Verifica se existe o filho e se ele é maior o maior, podendo ser o pai ou o irmão
        maior = filhodir; //Se for maior, agora o maior é o filho (por enquanto, o indice)

    if(maior != i){ //Se o maior, não for o pai, troca com o filho maior
        temp = lista->a[i];
        lista->a[i] = lista->a[maior];
        lista->a[maior] = temp;

        refazHeapMaximo(lista, tamanho, maior); //Refaz o heap para o menor que foi trocado para inserir na posição correta
    }
}

void construirHeapMaximo(Lista* lista, int tamanho){
    for(int i = tamanho/2 - 1; i >= 0; i--)
        refazHeapMaximo(lista, tamanho, i); //Construindo o heap percorrendo todos os nós que podem ser pais
}

void heapSort(Lista* lista, int tamanho){
    construirHeapMaximo(lista, tamanho); //Constroi o heap
    tipo temp;

    //Como o maior valor de um heap maximo sempre é o indice 0, troca ele com o ultimo índice e diminui o tamanho da lista
    //Assim, irá organizar todos os elementos em ordem crescente
    for(int i = tamanho - 1; i > 0; i--){
        temp = lista->a[0];
        lista->a[0] = lista->a[i];
        lista->a[i] = temp;
        refazHeapMaximo(lista, i, 0);
    }
} 

int main(){
    Lista* lista;
    lista = criarLista();
    adicionarElementos(lista);
    imprimirLista(lista);
    printf("\n");
    heapSort(lista, lista->tamanho);
    imprimirLista(lista);
}
