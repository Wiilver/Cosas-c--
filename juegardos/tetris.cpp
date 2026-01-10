#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <array>
#include <unordered_map>

void menu()
{
    std::chrono::milliseconds periodo = std::chrono::milliseconds(500);
    std::this_thread::sleep_for(periodo);
}

void llenar(std::array<std::array<char, 10>, 20>& juego)
{
    for(int i = 0; i <= juego.size(); i++)
    {
        for(int j = 0; j <= juego[0].size(); j++) juego[i][j] = ' ';
    }
}

void impresion(const std::array<std::array<char, 10>, 20>& juego)
{
    for(int i = 0; i <= juego.size(); i++)
    {
        for(int j = 0; j <= juego[0].size(); j++) std::cout<<juego[i][j];
        std::cout<<'\n';
    }
}
//Necesito pensar en como rotar las piezas
int main()
{
    int tecla, x, y;
    std::array<>
    std::array<std::array<char, 10>, 20> juego;
    std::cout<<"Presione esc para salir...";
    while (true)
    {
        if(_kbhit())
        {
            tecla = _getch();
            std::cout<<"Tecla presionada "<<tecla<<"\n";
            if (tecla==27) break;
        }
    }
    return 0;
}