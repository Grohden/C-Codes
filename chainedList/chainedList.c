#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../utils.h"
#include "chainedList.h"

//Private
ChainedList *getChainAt(ChainedList *chainHead, int chainAt);
ChainedList *getLastChain(ChainedList *chainHead);

ChainedList *getLastRef(ChainedList *chainHead)
{
    return getChainAt(chainHead, getChainLength(chainHead) - 1);
}

ChainedList *getChainAt(ChainedList *chainHead, int chainAt)
{
    if (isChainEmpty(chainHead))
    {
        return chainHead;
    }

    if ((getChainLength(chainHead) - 1) > chainAt || chainAt < 0)
    {
        println("Index out of bounds: %d", chainAt);
    }

    //Next pois o head nao � contado
    ChainedList *nextRef = (ChainedList *)chainHead->next;
    int index = 0;

    //Enquanto n�o achar o ultimo
    while (nextRef->next != 0 && index != chainAt)
    {
        //ALERT: Nao printar nada aqui hehe
        nextRef = (ChainedList *)nextRef->next;
        index++;
    }

    //Retorna referencia ao ultimo
    return nextRef;
}

//Public

ChainedList *initChain()
{
    ChainedList *head = (ChainedList *)calloc(1, sizeof(ChainedList));
    head->next = NULL;

    //O tamanho da lista encadeada vai estar no primeiro elo da lista
    head->data = calloc(1, sizeof(int)); //Aloca espa�o para o contador do tamanho
    int *size = (int *)(head->data);     //Pega o ponteiro para o espa�o alocado
    *size = 0;                           //Seta o valor na memoria

    return head;
}

//inicio, procurar

void *getChainDataAt(ChainedList *chainHead, int elementAt)
{

    if (elementAt > getChainLength(chainHead) - 1)
    {
        println("Nao e possivel pegar o item, index fora dos limites");
        return NULL;
    }

    if (isChainEmpty(chainHead))
    {
        println("Nao e possivel pegar o item, lista vazia");
        return NULL;
    }

    //Next pois o primeiro elo nao � contado
    ChainedList *chainRef = (ChainedList *)chainHead->next;

    int count = 0;

    //Enquanto existir proximo e o contador n�o for igual ao index
    while (chainRef->next != 0 && count != elementAt)
    {
        chainRef = (ChainedList *)chainRef->next;
        count++;
    }

    //Se achou o item o retorna
    if (count == elementAt)
    {
        return chainRef->data;
    }

    //Em teoria nao vai cair aqui nunca pelo primeiro if, so se a index for negativa
    println("Item no index %d nao foi achado", elementAt);
    return NULL;
}

void addToChain(ChainedList *chainHead, void *data)
{
    addToChainAt(chainHead, data, getChainLength(chainHead));
}

void addToChainAt(ChainedList *chainHead, void *data, int index)
{
    if (getChainLength(chainHead) < index)
    {
        println("Nao e possivel adicionar, index %d fora dos limites", index);
        return;
    }
    //Cria um novo elo (ALERT: nao usar o inicializar aqui, nao sao o mesmo tipo de elo)
    ChainedList *newChain = (ChainedList *)calloc(1, sizeof(ChainedList));
    //Coloca o dado fornecido
    newChain->data = data;

    ChainedList *previous;
    //Anterior ao elemento do index
    if (isChainEmpty(chainHead) || index == 0)
    {
        previous = chainHead;
    }
    else
    {
        previous = (getChainAt(chainHead, index));
    }

    //Elemento que esta no index requisitado
    ChainedList *oldElementAtIndex = (ChainedList *)previous->next;

    //O anterior recebe o novo elo
    previous->next = newChain;

    //Aponta para o elemento que estava antes no lugar
    newChain->next = oldElementAtIndex;

    //de-referenciando ponteiro para inteiro com cast e somando +1
    (*(int *)chainHead->data)++; //Lembrando que guardo o tamanho da lista encadeada no primeiro elo
}

void removeFromChain(ChainedList *chainHead, int index)
{
    if (isChainEmpty(chainHead))
    {
        println("Nao e possivel remover, lista encadeada vazia");
        return;
    }

    int chainLength = getChainLength(chainHead);

    if (index > chainLength - 1)
    {
        println("Index fora dos limites");
        return;
    }

    //Next pois o primeiro elo nao � contado
    ChainedList *actualRef = (ChainedList *)chainHead->next;
    ChainedList *prevRef = chainHead;

    int count = 0;

    //Enquanto existir proximo e o contador n�o for igual ao index
    while (actualRef->next != 0 && count != index)
    {
        //Referencia anterior recebe a atual
        prevRef = actualRef;
        //Atual recebe a proxima
        actualRef = (ChainedList *)actualRef->next;
        count++;
    }

    //A referencia do anterior ao elo procurado recebe a referencia do 'proximo-proximo'
    prevRef->next = actualRef->next;

    //Libera a memoria
    free(actualRef);

    //de-referenciando ponteiro para inteiro e tirando 1
    (*(int *)chainHead->data)--; //Lembrando que guardo o tamanho da lista encadeada no primeiro elo
}

int getChainLength(ChainedList *chainHead)
{
    if (isChainEmpty(chainHead))
    {
        return 0;
    }

    //de-referenciando ponteiro para inteiro (em teoria, aqui deve sempre no minimo retornar 1)
    return (*(int *)chainHead->data);
}

bool isChainEmpty(ChainedList *chainHead)
{
    return chainHead->next == 0;
}