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

int particaoQuickSort(Lista* lista, int ini, int fim){
    tipo pivo = lista->a[fim]; //O pivô escolhido é o último elemento do array
    int indicePivo = ini-1; //Por enquanto vazia porque não encontramos nenhum termo <= ao pivo
    tipo temp; //Variável temporária para realizar o swap
    int i = ini; //Variável para iterar

    while(i <= fim-1){ //Iterando pelo subvetor, fim-1 para não contar com o próprio pivô
        if(lista->a[i] <= pivo){ //Encontrou um valor para ficar nas posições dos valores menores ou iguais ao pivo
            indicePivo++; //Incrementa o índice da nova posição para inserior nos valores menores ou iguais ao pivo
            temp = lista->a[i]; //Realizando o swap
            lista->a[i] = lista->a[indicePivo];
            lista->a[indicePivo] = temp;
        }
        i++; //Incrementa o contador do while
    }
    //Após a iteração, temos os menores em ini até indicePivo e os maiores em indicePivo+1 até fim-1
    //Dessa forma, precisamos colocar o pivo entre eles, fazendo o swap entre o indicePivo+1 e o fim
    temp = lista->a[indicePivo+1];
    lista->a[indicePivo+1] = lista->a[fim]; //Note que lista->a[fim] e pivô são a mesma coisa
    lista->a[fim] = temp;

    return indicePivo+1; //Retorna o índice onde o pivô está localizado para partições posteriores
}

void quickSort(Lista* lista, int ini, int fim){
    if(!(ini>=fim)){ //Somente ordena caso o vetor seja válido (sem índices negativos) e posição > 0, isso porque um vetor com um elemento já está ordenado
        int indicePivo;
        indicePivo = particaoQuickSort(lista, ini, fim); //Inicia a partição para encontrar o indice do pivô do subvetor da chamada recursiva
        quickSort(lista, indicePivo + 1, fim); //Chama recursivamente a mesma função para realizar as partições da região dos maiores
        quickSort(lista, ini, indicePivo - 1); //Chama recursivamente a mesma função para realizar as partições da região dos menores
    }
}

int main(){
    Lista* lista;

    lista = criarLista();
    adicionarElementos(lista);
    imprimirLista(lista);
    quickSort(lista, 0, lista->tamanho - 1);
    printf("\n");
    imprimirLista(lista);
}