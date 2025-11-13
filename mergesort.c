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

void conquistarMergeSort(Lista* lista, int ini, int meio, int fim){
    int tamanhoSeq1 = meio - ini + 1; //O tamanho relativo a parte esquerda do vetor, tem mais um para incluir o meio
    int tamanhoSeq2 = fim - meio; //O tamanho relativo para a parte direita do vetor, não tem o mais um para não incluir o meio

    //Alocando a struct da lista
    Lista* seq1 = (Lista*) malloc(sizeof(Lista));
    Lista* seq2 = (Lista*) malloc(sizeof(Lista));

    //Alocando o vetor de valores de cada lista
    seq1->a = (tipo*) malloc(tamanhoSeq1 * sizeof(tipo));
    seq2->a = (tipo*) malloc(tamanhoSeq2 * sizeof(tipo));

    //Copiando a parte esquerda da lista principal para o subvetor esquerdo
    for(int i = 0; i < tamanhoSeq1; i++){
        seq1->a[i] = lista->a[ini + i];
    }
    
    //Copiando a parte direita da lista principal para o subvetor direito
    for(int i = 0; i < tamanhoSeq2; i++){
        seq2->a[i] = lista->a[i + meio + 1];
    }

    //Inicializando variáveis que irão ajudar no merge embaixo
    //i é o indice atual da lista esquerda, j da lista direita e k é a posição disponivel no vetor principal
    int i = 0, j = 0, k = ini;

    while(i < tamanhoSeq1 && j < tamanhoSeq2){ //Esse parâmetro é para colocar enquanto existem comparações para ser feitas em relação ao tamanho de cada um subvetor
        if(seq1->a[i] <= seq2->a[j]){ //Se o elemento do indice i da esquerda for menor que o da direita, ele entra primeiro no vetor principal
            lista->a[k] = seq1->a[i]; //Fazendo a inserção
            i++; //Atualiza o i para o proximo elemento do subvetor esquerdo
        }else{ //Senão, o da direita entra
            lista->a[k] = seq2->a[j]; //Fazendo a inserção
            j++;//Atualiza o j para o proximo elemento do subvetor direito
        }
        k++; //Atualiza a próxima posição disponível
    }

    while(i < tamanhoSeq1){ //Caso o j acabou primeiro que o i, aproveitamos que o i ja está ordenado e colocamos ele direto na parte disponivel da lista principal
        lista->a[k] = seq1->a[i]; //Fazendo a inserção
        i++; //Atualiza o i para o proximo elemento do subvetor esquerdo
        k++; //Atualiza a próxima posição disponível
    }

    while(j < tamanhoSeq2){ //Caso o i acabou primeiro que o j, aproveitamos que o j ja está ordenado e colocamos ele direto na parte disponivel da lista principal
        lista->a[k] = seq2->a[j]; //Fazendo a inserção
        j++; //Atualiza o j para o proximo elemento do subvetor direito
        k++; //Atualiza a próxima posição disponível
    }

    //Dando free na memória
    free(seq1->a);
    free(seq2->a);
    free(seq1);
    free(seq2);
}

void MergeSort(Lista* lista, int ini, int fim){
    //Essa parte do mergeSort é o dividir, ele divide o vetor no meio uma série de vezes até o caso base de tamanho n = 1
    if(fim > ini){ //Essa é a condição para continuar a divisão
        int meio = (ini+fim)/2; //Aqui pega o meio do vetor
        MergeSort(lista, ini, meio); //Aqui faz a divisão novamente com a parte esquerda
        MergeSort(lista, meio + 1, fim); //Aqui faz a divisão novamente com a parte direita
        conquistarMergeSort(lista, ini, meio, fim); //Aqui é o coração, aqui coloca qual a posição certa de cada elemento do vetor
    }
}

int main(){
    Lista* lista;

    lista = criarLista();
    adicionarElementos(lista);
    imprimirLista(lista);
    printf("\n");
    MergeSort(lista, 0, lista->tamanho - 1); //tamanho-1 porque quer o ultimo indice disponivel
    imprimirLista(lista);
}