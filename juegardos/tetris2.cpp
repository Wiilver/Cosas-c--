#include <iostream>
#include <array>
#include <chrono>
#include <conio.h>
#include <cstdlib>

//Futuro: Debo de usar un using en ves de hardcodear las dimensiones del arreglo
//Deberia de checar lo de hacer que no parpadee
//Checar las funciones que no ocupan las referencias como tal
//Debo de pasarlo a steady clock
//De momento solo sirve para windows

//Este codigo sera mas chiquito

void rellenar(std::array<std::array<char,10>,15>& mapa)
{
    for(int i = 0; i < mapa.size(); i ++) for (int j = 0; j < mapa[0].size(); j++) mapa[i][j] = ' ';
}

void imprimir(const std::array<std::array<char,10>,15>& mapa)
{
    for(int i = 0; i < mapa.size(); i ++)
    {
        for(int j = 0; j < mapa[0].size(); j ++) std::cout<<mapa[i][j];
        std::cout<<'\n';
    }
}

void conseguir_tecla(char& tecla)
{
    int input = _getch();
    
    if((input == 0)||(input == 224)) input = _getch();

    switch(input)
    {
        case 119:
        case 87:
        case 72:
            tecla = 'w';
            break;

        case 97:
        case 65:
        case 75:
            tecla = 'a';
            break;
        
        case 115:
        case 83:
        case 80:
            tecla = 's';
            break;

        case 100:
        case 68:
        case 77:
            tecla = 'd';
            break;
    }
}

void cambiar_x(const int& y, int& x, const std::array<std::array<char, 10>, 15>& mapa, const char& tecla)
{
    std::cout<<tecla;
    if((tecla == 'a')&&(x > 0))
    {
        if(mapa[y][x-1]==' ') x--;
    }
    else if((tecla == 'd')&&(x < mapa[0].size()-1))
    {
        if(mapa[y][x+1]) x++;
    }
}

void cambiar_y(int& y, const int& x, bool& piso, const std::array<std::array<char, 10>, 15>& mapa)
{
    if (y < mapa.size()-1)
    {
        if(mapa[y+1][x] == ' ') y++;
        else piso = true;
    }
    else piso = true;
}

void checar_linea(const int& y, bool& linea, const std::array<std::array<char, 10>, 15>& mapa)
{
    linea = true;
    for(int i = 0; i < mapa[0].size(); i++) 
    {
        if(mapa[y][i] == ' ')
        {
            linea = false;
            break;
        }
    }
}

void completo_linea(const int& y, bool& linea, std::array<std::array<char,10>,15>& mapa)
{
    linea = false;
    for(int i = y; i > 0; i --)
    {
        mapa[i] = mapa[i-1];
    }
    for(int i = 0; i < mapa[0].size(); i ++) mapa [0][i] = ' ';
}

int main()
{
    int x, y, tiempo;
    bool piso, linea;
    char tecla;

    std::array<std::array<char, 10>, 15> mapa;
    std::chrono::system_clock::time_point inicio, actual;
    std::chrono::duration<double, std::milli> lapso;
    
    linea = piso = false;

    y = 0;
    x = 5;
    tiempo = 1000;

    rellenar(mapa);
    imprimir(mapa);
    
    inicio = std::chrono::system_clock::now();
    
    while(true)
    {
        if(_kbhit())
        {
            conseguir_tecla(tecla);
            
            switch(tecla)
            {
                case 'a':
                case 'd':
                    mapa[y][x] = ' ';
                    cambiar_x(y, x, mapa, tecla);
                    mapa[y][x] = '#';

                    system("cls");
                    imprimir(mapa);
                    break;
                    
                case 's':
                    tiempo = 100;
                    break;
            }
        }

        actual = std::chrono::system_clock::now();
        lapso = actual-inicio;
        if(lapso.count() > tiempo)
        {
            system("cls");
            mapa[y][x] = ' ';
            cambiar_y(y, x, piso, mapa);
            if(piso)
            {   
                mapa[y][x] = '#';
                checar_linea(y,linea,mapa);
                if(linea)completo_linea(y, linea, mapa);
                y = 0;
                x = 5;
                piso = false;
            }
            mapa[y][x] = '#';
            imprimir(mapa);
            
            inicio = std::chrono::system_clock::now();
        }
        tiempo = 1000;
    }
    
    
    
    return 0;
}