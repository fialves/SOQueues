#include <stdio.h>
#include "../include/fila2.h"

#define ERROR_EMPTY_QUEUE -1
#define ERROR_CREATION -1
#define ERROR_INVALID_IT -2

PFILA2 globalQueue;

int     CreateFila2(PFILA2 pFila){
    globalQueue = (PFILA2) malloc(sizeof(FILA2));
    if(pFila == NULL){
        return ERROR_CREATION;
    }

    pFila->first = NULL;
    pFila->last = NULL;
    pFila->it = NULL;

    pFila = globalQueue;

    return 0;
}

int     FirstFila2(PFILA2 pFila){
    if(pFila->first == NULL) {
        return ERROR_EMPTY_QUEUE;
    }
    pFila->it = pFila->first;
    return 0;
}

int     LastFila2(PFILA2 pFila){
    if(pFila->last == NULL){
        return ERROR_EMPTY_QUEUE;
    }
    pFila->it = pFila->last;
    return 0;
}

int     NextFila2(PFILA2 pFila){
    pFila->it = pFila->it->next;
    return 0;
}

void    *GetAtIteratorFila2(PFILA2 pFila){
    if(pFila != NULL){
        return pFila->it->node;
    }
    return NULL;
}

int     AppendFila2(PFILA2 pFila, void *content){
    if(pFila->first == NULL){
        pFila->first = (PNODE2) malloc(sizeof(NODE2));
        pFila->first->node = content;
        pFila->first->ant = NULL;
        pFila->first->next = NULL;
        pFila->last = pFila->first;
        pFila->it = pFila->first;
    }
    else {
        pFila->last->next = (PNODE2) malloc(sizeof(NODE2));
        pFila->last->next->ant = pFila->last;
        pFila->last = pFila->last->next;
        pFila->last->node = content;
    }

    return 0;
}

int     InsertAfterIteratorFila2(PFILA2 pFila, void *content){
    if(pFila->it == NULL){
        return ERROR_EMPTY_QUEUE;
    }

    if(pFila->it == pFila->last){
        return AppendFila2(pFila,content);
    }

    pFila->it->next->ant = (PNODE2) malloc(sizeof(NODE2));
    pFila->it->next->ant->ant = pFila->it;
    pFila->it->next->ant->next = pFila->it->next;
    pFila->it->next = pFila->it->next->ant;
    pFila->it->next->node = content;

    return 0;
}

int     DeleteAtIteratorFila2(PFILA2 pFila){
    if(pFila == NULL){
        return ERROR_EMPTY_QUEUE;
    }
    else if(pFila->it == NULL){
        return ERROR_INVALID_IT;
    }
    else if(pFila->first == pFila->last){
        pFila->it = NULL;
        pFila->first = NULL;
        pFila->last = NULL;
    }
    else if(pFila->it == pFila->last){
        pFila->it = pFila->it->ant;
        free(pFila->it->next);
        pFila->last = pFila->it;
    }
    else if(pFila->it == pFila->first){
        pFila->it = pFila->it->next;
        free(pFila->it->ant);
        pFila->first = pFila->it;
    }
    else {
        pFila->it = pFila->it->next;
        pFila->it->ant->ant->next = pFila->it;
        free(pFila->it->ant);
        pFila->it->ant = pFila->it->ant->ant;
    }
    return 0;
}
