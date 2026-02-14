#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
//#include <fstream> Esta es la libreria para manejo de archivos
//"═╣ ", " ║ ", "═╗ ", "═╝ ", " ╚═", " ╔═", "═╩═", "═╦═", " ╠═", "═══", "═╬═"


bool checar_num(std::string cadena)
{
    for(int i = 0; i < cadena.length(); i++) if(!isdigit(cadena[i])) return false;
    return true;
}

void estupido()
{
    system("cls");
    std::cout<<"Parece que hubo un error con el dato que introdujiste, porfavor, intentalo nuevamente\n\n";
}

int dimensiones(char dim)
{
    std::string cad;
    while(true)
    {
        std::cout<<"Por favor, ingrese el largo del eje ("<<dim<<") para el lienzo: ";
        std::cin>>cad;
        if(checar_num(cad))
        {
            int num = std::stoi(cad);
            if(num > 0) return num;
        }
        estupido();
    }
}

void impresion(const std::vector<std::vector<std::string>>& matriz)
{
    for(int i = 0; i < matriz.size()+2; i++)
    {
        for(int j = 0; j < matriz[0].size()+2; j++)
        {
            if((j==0)&&(i==0))
            {
                std::cout<<" ╔═";
                continue;
            }
            else if((j==0)&&(i==matriz.size()+1))
            {
                std::cout<<" ╚═";
                continue;
            }
            else if((j==matriz[0].size()+1)&&(i==0))
            {
                std::cout<<"═╗ ";
                continue;
            }
            else if((j==matriz[0].size()+1)&&(i==matriz.size()+1))
            {
                std::cout<<"═╝ ";
                continue;
            }
            else if((i == 0)||(i == matriz.size()+1))
            {
                std::cout<<"═══";
                continue;
            }
            else if((j==0)||(j==matriz[0].size()+1))
            {
                std::cout<<" ║ ";
                continue;
            }
            else std::cout<<matriz[i-1][j-1];
        }
        std::cout<<'\n';
    }
}

std::vector<std::vector<std::string>> crear_lienzo(const int Y, const int X)
{
    std::string car = " - ";
    std::vector<std::string> vector;
    std::vector<std::vector<std::string>> matriz;
    
    for(int i = 0; i < X; i++) vector.push_back(car);
    for(int i = 0; i < Y; i++) matriz.push_back(vector);
    return matriz;
}

std::string escojer_personaje()
{
    std::string str;
    
    while(true)
    {
        std::cout<<"Vamos a crear un personaje, ingresa de 1 a 3 caracteres\n";
        std::cout<<"Esto puede ser cambiado posteriormente : ";
        std::cin>>str;
        
        if(str.size() == 3) return str;
        if(str.size() == 1) return " " + str + " ";
        estupido();
    }

    return str;
}

char conseguir_tecla(){
    char tecla;
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
    
    return tecla;
}

void cambiar_coord(int& x, int& y, const int x_lim, const int y_lim, const char tecla)
{
    switch(tecla)
    {
        case 'w':
            if(y > 0) y--;
            break;
        case 'a':
            if(x > 0) x--;
            break;
        case 's':
            if(y < y_lim-1) y++;
            break;
        case 'd':
            if(x < x_lim-1) x++;
            break;
    }
}

void editor()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::string personaje = escojer_personaje();
    std::cout<<'\n';

    const int Y_LIENZO = dimensiones('Y');
    const int X_LIENZO = dimensiones('X');
    std::vector<std::vector<std::string>> lienzo = crear_lienzo(Y_LIENZO, X_LIENZO);
    
    int y = Y_LIENZO/2;
    int x = X_LIENZO/2;

    lienzo[y][x] = personaje;
    
    system("cls");
    impresion(lienzo);

    while(true)
    {
        char tecla = ' ';
        if(_kbhit())
        {
            tecla = conseguir_tecla();
            switch(tecla)
            {
                case 'w':
                case 'a':
                case 's':
                case 'd':
                    lienzo[y][x] = " - ";
                    cambiar_coord(x, y, X_LIENZO, Y_LIENZO, tecla);
                    lienzo[y][x] = personaje;
                    system("cls");
                    impresion(lienzo);
                    break;
            }
        }
    }
}

int main()
{
    //Necesitamos el coso para que pueda decidir entre checar si hay archivos, abrirlos o crearlos
    //Deberia de usar un typedef
    //Debo de checar de nuevo lo de detectar inputs del usuario
    //Debo de hacer lo de los visuales
    //Necesito ver si es que hay cosa para colores
    
    editor();
    return 0;
}