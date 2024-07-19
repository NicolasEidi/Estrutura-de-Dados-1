#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No *cria_no(int valor);
void insere_novo(No **novo, int valor);

void imprime(No *inicio);



int main()
{
    No *inicio = NULL;

    insere_novo(&inicio, 2999);
    insere_novo(&inicio, 23);
    insere_novo(&inicio, 24);
    imprime(inicio);

    return 0;
}

No *cria_no(int valor)
{
    No *novo = NULL; 
    novo = malloc(sizeof(No));
    
    if (novo == NULL)
        return NULL;

    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

void insere_novo(No **inicio, int valor)
{
    No *novo = cria_no(valor);
    if (novo == NULL)
        return;
    
    if (*inicio == NULL)
    {
        *inicio = novo;
        return;
    }
    
    No *aux = *inicio;
    while (aux->proximo != NULL)
        aux = aux->proximo;
    
    aux->proximo = cria_no(valor);

}


void imprime(No *inicio)
{
    int i=1;

    while(inicio != NULL)
    {
        printf("Valor %d: %d\n", i, inicio->valor);
        inicio = inicio->proximo;
        i += 1;
    }
}