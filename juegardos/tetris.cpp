#include <iostream>
#include <conio.h>
#include <chrono>
#include <array>

//Tambien necesitas acabar la rotacion y posiblemente cambiar el rellenar
//Creo que se necesita 
//En pendientes mas largos ocupamos una funcion que al fin de cada loop vea si hay filas, que las borre y que cambie el contenido de todas las superiores
//Necesitamos una funcion que imprima las siguientes piezas en la parte derecha
//Como mucho futuro estaria bien poder guardar la siguiente pieza con la 'c'

/*
Debo de ver logica para imprimir estas cosas
| ##  | #### | # | ### | ## |   # | #   | ### |   # | #   | ## | #  |  ## |  # | ##  |
| ##  |      | # | #   |  # | ### | #   |   # |   # | ### | #  | ## | ##  | ## |  ## |
|     |      | # |     |  # |     | ##  |     |  ## |     | #  |  # |     | #  |     |
|     |      | # |     |    |     |     |     |     |     |    |    |     |    |     |
*/

void rellenar_figura(const int& x, const int& y, std::array<std::array<char, 10>, 20>& juego, const std::array<int, 4>& figura, const char& relleno)
{
    int contador = 0;
    
    if(figura[contador]==1)
    {
        juego[y][x] = relleno;
        contador++;
    } 
    if(figura[contador]==2) juego[y][x] = relleno;
    {
        juego[y][x+1] = relleno;
        contador++;
    }
    if(figura[contador]==3) juego[y][x] = relleno;
    {
        juego[y][x+2] = relleno;
        contador++;
    }
    if(figura[contador]==4) juego[y][x] = relleno;
    {
        juego[y+1][x] = relleno;
        contador++;
    }
    if(figura[contador]==5) juego[y][x] = relleno;
    {
        juego[y+1][x+1] = relleno;
        contador++;
    }
    if(figura[contador]==6) juego[y][x] = relleno;
    {
        juego[y+1][x+2] = relleno;
        contador++;
    }
    if(figura[contador]==7) juego[y][x] = relleno;
    {
        juego[y+2][x] = relleno;
        contador++;
    }
    if(figura[contador]==8) juego[y][x] = relleno;
    {
        juego[y+2][x+1] = relleno;
        contador++;
    }
    if(figura[contador]==9) juego[y][x] = relleno;
    {
        juego[y][x+3] = relleno;
        contador++;
    }
    if(figura[contador]==0) juego[y][x] = relleno;
    {
        juego[y+3][x] = relleno;
        contador++;
    }
}

void rotacion(int& x, const int& y, std::array<int, 4>& figura, const std::array<std::array<char, 10>, 20> juego)
{   
    if(figura == std::array{1,2,3,9})
    {
        if(x>4) x = 4;
    }
    if(figura == std::array{1,4,7,0})
    {
        if(juego[y-3][x]!=' ')
        {
        }
    }
    if(figura == std::array {1,2,4,5})
}

void conseguir_tecla(char& tecla)
{
    int input;
    input = _getch();

    if ((tecla == 0)||(tecla == 224)) input = _getch();

    switch(input)
    {
        case 119:
        case 87:
        case 72:
            tecla = 'w';

        case 97:
        case 65:
        case 75:
            tecla = 'a';
        
        case 115:
        case 83:
        case 80:
            tecla = 's';

        case 100:
        case 68:
        case 77:
            tecla = 'd';
    }
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

int main()
{
    int input, x, y;
    char tecla;
    std::array<int, 4> figura;
    std::array<std::array<char, 10>, 20> juego;
    std::chrono::duration<float, std::milli> lapso;
    auto inicio = std::chrono::system_clock::now();
    while(true)
    {
        if(_kbhit)
        {
            conseguir_tecla(tecla);
            
            switch(tecla)
            {
                case 'w'
                    //Aqui es para rotar, necesitas hacer que se cambie la x o la y para que no salgan errores
                    break;
                case 'a'
                    break;
                case 's'
                    //En este caso tienes que hacer que pueda bajar mas rapido, puedes intentar cambiado lo largo del timer
                    break;
                case 'd'
                    //En ambos casos checar una vez mas para no salirse de la pantalla
                    break;        
            }
        }


        auto ahora = std::chrono::system_clock::now();
        lapso = ahora-inicio;
        if (lapso.count() > 500)
        {
            y++;

        }
        rellenar_figura(x,y,juego,figura,'#');
    }
    
    std::cout<<"Presione esc para salir...";
    while (true)
    {
        if(_kbhit())
        {
            input = _getch();
            std::cout<<"Tecla presionada "<<input<<"\n";
            if (input==27) break;
        }
    }
    return 0;
}