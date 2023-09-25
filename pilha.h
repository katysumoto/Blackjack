#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define TAMANHO 52
#include "carta.h"

struct Pilha
{
    int topo;
    Carta elementos[TAMANHO];

    void criar();
    void empilhar(Carta elemento);
    Carta desempilhar();
    void exibir();
    bool cheia();
    bool vazia();

};




#endif // PILHA_H_INCLUDED
