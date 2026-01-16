#include <iostream>
#include <array>
#include <chrono>
#include <conio.h>
#include <cstdlib>

typedef std::array<std::array<char,10>,15> matriz;

//Deberia de checar lo de hacer que no parpadee
//De momento solo sirve para windows
//Debo de arreglar lo de que la x detecte si se puede mover o no a la izquierda

void rellenar(matriz& mapa)
{
    for(int i = 0; i < mapa.size(); i ++) for (int j = 0; j < mapa[0].size(); j++) mapa[i][j] = ' ';
}

void imprimir(const matriz& mapa)
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

void cambiar_x(const int y, int& x, const std::array<int,4>& figura,const matriz& mapa, const char& tecla)
{
    int contador;
    if(tecla == 'd')
    {
        contador = 3;
        if(figura[contador] == 9)
        {
            if(x<mapa[0].size()-5)
            {
                if (mapa[y][x+4]==' ') x++;
            }
            return;
        }
        if(x<mapa[0].size()-2)
        {
            if((figura[contador] == 0))
            {
                for(int i = 0; i < 4; i++) if(mapa[y+i][x+1] != ' ') return;
                x++;
                return;
            }
            if(x < mapa[0].size()-3)
            {
                if(figura[contador] == 8)
                {
                    if(mapa[y+2][x+2] == ' ') contador--;
                    else return;
                }
                else if (figura[contador] == 7)
                {
                    if(mapa[y+2][x+1] == ' ') contador--;
                    else return;
                }

                while(true)
                {
                    if(figura[contador] < 7) break;
                    contador--;
                }

                if(figura[contador] == 6)
                {
                    if(x < mapa[0].size()-4)
                    {
                        if(mapa[y+1][x+3] == ' ') contador--;
                        else return;
                    }
                }
                else if(figura[contador] == 5)
                {
                    if(mapa[y+1][x+2] == ' ') contador--;
                    else return;
                }
                else if(figura[contador] == 4)
                {
                    if(mapa[y+1][x+1] == ' ') contador--;
                    else return;
                }

                while(true)
                {
                    if(figura[contador] < 4) break;
                    contador--;
                }

                if(figura[contador] == 3)
                {
                    if(x < mapa[0].size()-4)
                    {
                        if(mapa[y][x+3] == ' ') x++;
                    }
                }
                else if((figura[contador] == 2) && (mapa[y][x+2] == ' ')) x++;
                else if(mapa[y][x+1] == ' ') x++;
                return;
            }
            else return;
        }
        else return;
    }
    
    else if(x > 0)
    {
        contador = 0;
        if(figura[0]==1)
        {
            if(mapa[y][x-1]!=' ') return;
            contador++;
        }
        else if(mapa[y][x]!=' ') return;
        else
        {
            if((figura[0]==3)&&(mapa[y][x+1]!=' ')) return;
            contador++;
        }
        
        while(true)
        {
            if(figura[contador]>3)break;
            contador++;
        }
        
        if(figura[contador]==4)
        {
            if(mapa[y+1][x-1]!=' ') return;
            if(contador==3)
            {
                x--;
                return;    
            }
            contador++;
        }
        else if(figura[contador]==5)
        {
            if(contador==3)
            {
                if(figura[2]==4)
                {
                    if(mapa[y+1][x-1]==' ') x--;
                }
                else if(mapa[y+1][x]==' ') x--;
                return;
            }
            else if((figura[contador-1]==4)&&(mapa[y+1][x-1]!=' ')) return;
            else if(mapa[y+1][x]!=' ') return;
            contador++;
        }
        if(figura[contador]==6)
        {
            if(figura[1]==4)
            {
                if(mapa[y+1][x-1]==' ') x--;
            }
            else if(mapa[y+1][x]==' ')
            {
                if((figura[2]==3)&&(mapa[y+1][x+1]==' '))x--;
            }
            return;
        }
        
        while(true)
        {
            if(figura[contador]>6)break;
            contador++;
        }


        if(figura[contador]==7)
        {
            if(contador==3)
            {
                if(mapa[y+2][x-1]== ' ') x--;
                return;
            }
            else contador++;
        }
        if(figura[contador]==8)
        {
            if(contador==3)
            {
                if(figura[2]==7)
                {
                    if(mapa[y+2][x-1]==' ')x--;
                }
                else if(mapa[y+2][x]==' ') x--;
                return;
            }
        }
        if(mapa[y+3][x-1]==' ') x--;
        return;
    }
}

void cambiar_y(int& y, const int x, bool& piso, const matriz& mapa)
{
    if (y < mapa.size()-1)
    {
        if(mapa[y+1][x] == ' ') y++;
        else piso = true;
    }
    else piso = true;
}

void checar_linea(const int y, bool& linea, const matriz& mapa)
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

void completo_linea(const int y, bool& linea, matriz& mapa)
{
    linea = false;
    for(int i = y; i > 0; i --)
    {
        mapa[i] = mapa[i-1];
    }
    for(int i = 0; i < mapa[0].size(); i ++) mapa [0][i] = ' ';
}

void poner_figura(const int y, const int x, const std::array<int, 4>& figura, matriz& mapa, char relleno)
{
    int contador = 0;
    
    if(figura[contador]==1)
    {
        mapa[y][x] = relleno;
        contador++;
    } 
    if(figura[contador]==2)
    {
        mapa[y][x+1] = relleno;
        contador++;
    }
    if(figura[contador]==3)
    {
        mapa[y][x+2] = relleno;
        contador++;
    }
    if(figura[contador]==4)
    {
        mapa[y+1][x] = relleno;
        contador++;
        if (contador == 4) return;
    }
    if(figura[contador]==5)
    {
        mapa[y+1][x+1] = relleno;
        contador++;
        if (contador == 4) return;
    }
    if(figura[contador]==6)
    {
        mapa[y+1][x+2] = relleno;
        contador++;
        if (contador == 4) return;
    }
    if(figura[contador]==7)
    {
        mapa[y+2][x] = relleno;
        contador++;
        if (contador == 4) return;
    }
    if(figura[contador]==8)
    {
        mapa[y+2][x+1] = relleno;
        contador++;
        if (contador == 4) return;
    }
    if(figura[contador]==9)
    {
        mapa[y][x+3] = relleno;
        contador++;
        if (contador == 4) return;
    }
    if(figura[contador]==0)
    {
        mapa[y+3][x] = relleno;
        contador++;
    }
}

int main()
{
    int x, y, tiempo;
    bool piso, linea;
    char tecla;

    matriz mapa;
    std::array<int, 4> figura;
    std::chrono::steady_clock::time_point inicio, actual;
    std::chrono::duration<double, std::milli> lapso;
    
    linea = piso = false;

    figura = {1,2,5,6};

    y = 0;
    x = 5;
    tiempo = 1000;

    rellenar(mapa);
    imprimir(mapa);
    
    inicio = std::chrono::steady_clock::now();
    
    while(true)
    {
        if(_kbhit())
        {
            conseguir_tecla(tecla);
            
            switch(tecla)
            {
                case 'a':
                case 'd':
                    poner_figura(y,x,figura,mapa,' ');
                    cambiar_x(y, x,figura,mapa,tecla);
                    poner_figura(y,x,figura,mapa,'#');

                    system("cls");
                    imprimir(mapa);
                    break;
                    
                case 's':
                    tiempo = 50;
                    break;
            }
        }

        actual = std::chrono::steady_clock::now();
        lapso = actual-inicio;
        if(lapso.count() > tiempo)
        {
            system("cls");
            poner_figura(y,x,figura,mapa,' ');
            cambiar_y(y, x, piso, mapa);
            if(piso)
            {   
                poner_figura(y,x,figura,mapa,'#');
                checar_linea(y,linea,mapa);
                if(linea)completo_linea(y, linea, mapa);
                y = 0;
                x = 5;
                piso = false;
            }
            poner_figura(y,x,figura,mapa,'#');
            imprimir(mapa);
            
            inicio = std::chrono::steady_clock::now();
        }
        tiempo = 1000;
    }
    
    
    
    return 0;
}