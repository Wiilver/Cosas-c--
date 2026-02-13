#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
//#include <fstream> Esta es la libreria para manejo de archivos

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
    for(int i = 0; i < matriz.size(); i++)
    {
        for(int j = 0; j < matriz[0].size(); j++) std::cout<<matriz[i][j];
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
    char chr;
    
    std::cout<<"Por favor, ingrese cual quiere que sea su personaje, esto puede ser cambiado posteriormente : ";
    std::cin>>chr;
    
    std::string str = " ";
    str+=chr;
    str+=" ";
    return str;
}

void editor()
{
    std::string personaje = escojer_personaje();

    const int Y_LIENZO = dimensiones('Y');
    const int X_LIENZO = dimensiones('X');
    std::vector<std::vector<std::string>> lienzo = crear_lienzo(Y_LIENZO, X_LIENZO);
    
    int y = Y_LIENZO/2;
    int x = X_LIENZO/2;

    
    lienzo[y][x] = personaje;
    
    while(true)
    {
        char tecla = ' ';
        if(_kbhit())
        {
            lienzo[y][x] = " - ";

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
            
            switch(tecla)
            {
                case 'w':
                    y--;
                    break;
                case 'a':
                    x--;
                    break;
                case 's':
                    y++;
                    break;
                case 'd':
                    x++;
                    break;
            }
            lienzo[y][x] = personaje;
            system("cls");
            impresion(lienzo);
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