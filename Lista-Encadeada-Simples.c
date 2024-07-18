#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

No *cria_no(int valor);
void imprime(No *inicio);

int main()
{
    No *inicio = NULL;
    inicio = cria_no(10);

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

void imprime(No *inicio)
{

    while(inicio != NULL)
    {
        printf("valor: %d\n", inicio->valor);
        inicio = inicio->proximo;
    }
}