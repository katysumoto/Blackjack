#include <iostream>
#include "pilha.h"
#include "carta.h"
#include <time.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void embaralhar(Pilha *baralho);
void mostrar_mesa(Carta jogador[], Carta mesa[], int n_jogador, int n_mesa, int total_jogador, int total_mesa, bool jogo);

int main()
{
    Pilha baralho;
    char opcao;
    Carta jogador[10], mesa[10];
    int n_jogador, n_mesa, total_jogador, total_mesa;
    bool jogo = true;
    bool estourou = false;
    baralho.criar();
    embaralhar(&baralho);
    //baralho.exibir();
    total_jogador = total_mesa = 0;
    for(int i=0; i<2; i++)
    {
        mesa[i] = baralho.desempilhar();
        jogador[i] = baralho.desempilhar();
        if(jogador[i].numero<10)
            total_jogador+=jogador[i].numero;
        else
            total_jogador+=10;
        if(mesa[i].numero<10)
            total_mesa+=mesa[i].numero;
        else
            total_mesa+=10;
    }
    n_mesa = n_jogador = 2;
    while(jogo)
    {
        system("cls");
        mostrar_mesa(jogador, mesa, n_jogador, n_mesa, total_jogador, total_mesa, jogo);
        cout << "Deseja outra carta?(S/N)" << endl;
        cin >> opcao;
        if(opcao == 'N')
            jogo = false;
        else if(opcao == 'S')
        {
            jogador[n_jogador]=baralho.desempilhar();
            if(jogador[n_jogador].numero<10)
                total_jogador+=jogador[n_jogador].numero;
            else
                total_jogador+=10;
            n_jogador++;
        }
        else
        {
            cout << "Opcao incorreta" << endl;
            system("pause");
        }

        if(total_jogador>21)
        {
            system("cls");
            mostrar_mesa(jogador, mesa, n_jogador, n_mesa, total_jogador, total_mesa, jogo);
            cout << "YOU LOSE" << endl;
            return 0;
        }
        else if(total_jogador == 21)
        {
            system("cls");
            mostrar_mesa(jogador, mesa, n_jogador, n_mesa, total_jogador, total_mesa, jogo);
            cout << "YOU WIN" << endl;
            return 0;
        }
    }


    while(!jogo)
    {
        system("cls");
        mostrar_mesa(jogador, mesa, n_jogador, n_mesa, total_jogador, total_mesa, jogo);
        Sleep(1000);
        if(total_mesa > 21)
        {
            cout << "YOU WIN" << endl;
            return 0;
        }
        if(total_mesa > total_jogador)
        {
            cout << "YOU LOSE" << endl;
            return 0;
        }
        else
        {
            mesa[n_mesa]=baralho.desempilhar();
            if(mesa[n_mesa].numero<10)
                total_mesa+=mesa[n_mesa].numero;
            else
                total_mesa+=10;
            n_mesa++;
        }
    }
    return 0;
}

void embaralhar(Pilha *baralho)
{
    srand(time(NULL));
    bool v_aux[52], teste;
    Carta aux;
    int aleatorio;
    for(int i=0; i<52; i++)
    {
            v_aux[i] = true;
            teste = true;
        while(teste==true)
        {
            aleatorio = rand()%52;
            if(v_aux[aleatorio] == true)
            {
                if(aleatorio/13==0)
                {
                    aux.criar(aleatorio%13+1, 'O');
                    baralho->empilhar(aux);
                }
                else if(aleatorio/13==1)
                {
                    aux.criar(aleatorio%13+1, 'E');
                    baralho->empilhar(aux);
                }
                else if(aleatorio/13==2)
                {
                    aux.criar(aleatorio%13+1, 'C');
                    baralho->empilhar(aux);
                }
                else if(aleatorio/13==3)
                {
                    aux.criar(aleatorio%13+1, 'P');
                    baralho->empilhar(aux);
                }
                v_aux[aleatorio] = false;
                teste = false;
            }
            else if(aleatorio == 51)
                aleatorio = 0;
            else
                aleatorio++;
        }
    }
}

void mostrar_mesa(Carta jogador[], Carta mesa[], int n_jogador, int n_mesa, int total_jogador, int total_mesa, bool jogo)
{
    int total;
    cout << "Mesa: " << endl;
    if(jogo)
    {
        cout << "???\t";

        for(int i=1; i<n_mesa; i++)
        {
            mesa[i].desenhar();
            cout << "\t";
        }
        cout << endl;
        cout << "Total: ???" << endl << endl;
    }
    else
    {
        mesa[0].desenhar();
        cout << "\t";
        for(int i=1; i<n_mesa; i++)
        {
            mesa[i].desenhar();
            cout << "\t";
        }
        cout << endl;
        cout << "Total: "<< total_mesa << endl << endl;
    }


    cout << "Jogador: " << endl;
    for(int i=0; i<n_jogador; i++)
    {
        jogador[i].desenhar();
        cout << "\t";
    }
    cout << endl;
    cout << "Total: "<< total_jogador << endl << endl;

}


