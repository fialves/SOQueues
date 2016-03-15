#include <stdio.h>
#include "fila2.h"

#define ERROR_EMPTY_QUEUE -1
#define ERROR_CREATION -1

int	CreateFila2(PFILA2 pFila){
    pFila = (FILA2*) calloc(sizeof(PFILA2));
    if(pFila == NULL){
        return ERROR_CREATION;
    }

    pFila->first = NULL;
    pFila->last = NULL;
    pFila->it = NULL;

    return 0;
}

int	FirstFila2(PFILA2 pFila){
    if(pFila == NULL) {
        return ERROR_EMPTY_QUEUE;
    }
    pFila->it = pFila->first;
    return 0;
}

int	LastFila2(PFILA2 pFila){
    if(pFila == NULL){
        return ERROR_EMPTY_QUEUE;
    }
    pFila->it = pFila->last;
    return 0;
}

int	NextFila2(PFILA2 pFila){
    return 0;
}

void 	*GetAtIteratorFila2(PFILA2 pFila){
    return pFila->it;
}

int	AppendFila2(PFILA2 pFila, void *content){
    pFila->last->next = (NODE2*) malloc(sizeof(NODE2));
    pFila->last->next->ant = pFila->last;
    if(!FirstFila2(pFila)){
        pFila->first = pFila->last;
    }
    pFila->last = pFila->last->next;
    pFila->last->node = content;

    return 0;
}

int	InsertAfterIteratorFila2(PFILA2 pFila, void *content){
    return 0;
}

int	DeleteAtIteratorFila2(PFILA2 pFila){
    return 0;
}
