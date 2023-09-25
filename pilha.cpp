#include <iostream>
#include <cstdlib>
#include "pilha.h"
#include "carta.h"

using namespace std;

void Pilha::criar()
{
    this->topo = -1;
}

void Pilha::empilhar(Carta elemento)
{
    if(!cheia())
    {
        this->elementos[++topo] = elemento;
        //cout << "empilhar" << elemento <<  endl;
    }
    else
        cout << "A pilha esta cheia" << endl;
}

Carta Pilha::desempilhar()
{
    if(!vazia())
    {
        //cout << "desempilhar" << endl;
        return this->elementos[topo--];
    }
    else
        cout << "A pilha esta vazia" << endl;
}

void Pilha::exibir()
{
    for (int i=TAMANHO-1; i>-1; i--)
    {
        if(i>topo)
            cout << "["<< i << "]\t"<<"---"<< endl;
        else if(i == topo)
        {
            cout << "["<< i << "]\t";
            this->elementos[i].desenhar();
            cout << "<- TOPO" << endl;
        }

        else
        {
            cout << "["<< i << "]\t";
            this->elementos[i].desenhar();
            cout << endl;
        }
    }
    cout << endl << endl;

}

bool Pilha::cheia()
{
    return (topo == TAMANHO-1) ? true : false;
}

bool Pilha::vazia()
{
    return (topo == -1) ? true : false;
}






