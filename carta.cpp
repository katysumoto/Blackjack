#include <iostream>
#include <cstdlib>
#include "carta.h"

using namespace std;

void Carta::criar(int numero, char naipe)
{
    this->numero = numero;
    this->naipe = naipe;
}

void Carta::desenhar()
{
    cout << this->numero << "/" << this->naipe;
}
