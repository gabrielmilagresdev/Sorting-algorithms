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

void insertionSort(Lista* lista){ //Minha versão do insertion sort
    for(int i = 1; i < lista->tamanho; i++){ //Começa do segundo valor da lista porque o primeiro já está ordenado
        tipo chave = lista->a[i]; //Pega o valor referente ao índice i para fazer as operações
        int j = i-1; //A variável j é para observar os valores antes de i
        while(j >= 0 && chave < lista->a[j]){ //Esse while é para encontrar onde esse valor deve ser trocado ( o j>=0 primeiro é para evitar segmentation fault )
            j--; //Vai diminuindo o j até achar
        }
        j = j+1; //Soma mais um no j porque o j atual é aquele que não caiu nos parâmetros do while
        for(int z = i ; z>j ; z--){ //Iteração para fazer o deslocamento de todos os elementos até a posição correta (igual tampar o buraco de uma remoção)
            lista->a[z] = lista->a[z-1];//Fazendo a substituição
        }
        lista->a[j] = chave;//Insere a chave no local correto
    }
}

void insertionSortClassica(Lista* lista) { //Versão clássica do insertion sort
    for (int i = 1; i < lista->tamanho; i++) {
        tipo chave = lista->a[i];
        int j = i - 1;

        //A diferença é que no while já faz a troca direto, o resto é tudo igual
        while (j >= 0 && lista->a[j] > chave) {
            lista->a[j + 1] = lista->a[j];
            j--;
        }

        //É j+1 porque a iteração vai fazer o j diminuir um e nao entrar no while mais, mas queremos o ultimo j valido
        lista->a[j + 1] = chave;
    }
}


int main(){
    Lista* lista;

    lista = criarLista();
    adicionarElementos(lista);
    imprimirLista(lista);
    insertionSortClassica(lista);
    printf("\n");
    imprimirLista(lista);
}