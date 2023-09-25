#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

struct Carta
{
    int numero;
    char naipe;

    void criar(int numero, char naipe);
    void desenhar();
};
#endif // CARTA_H_INCLUDED
