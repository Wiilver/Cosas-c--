#include <iostream>
#include <vector>
#include <array>
#include <conio.h>
#include <windows.h>
#include <cctype>
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
    std::string car = "   ";
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
            tecla = 's';
            break;

        case 100:
        case 68:
            tecla = 'd';
            break;

        case 112:
        case 80:
            tecla = 'p';
            break;

        case 109:
        case 77:
            tecla = 'm';
            break;

        case 8:
            tecla = '0';
            break;

        case 13:
            tecla = '1';
            break;

        case 27:
            tecla = '2';
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

void menu_materiales(const std::vector<std::string>& usuario, std::string& material){
    std::string resp;
    system("cls");
    while(true)
    {
        std::cout<<
        "Seleccione una de las siguientes opciones:\n"<<
        "1.- Lineas simples\n"<<
        "2.- Lineas dobles\n"<<
        "3.- Texturas\n"<<
        "4.- Bloques\n"<<
        "5.- Del usuario\n"<<
        "6.- Otros\n"<<
        "7.- Cancelar\n"<<
        "Opcion : ";
        std::cin>>resp;
        if(checar_num(resp))break;
        estupido();
    }
    int num = std::stoi(resp);
    system("cls");
    std::vector<std::string> materiales;
    switch(num)
    {
        case 1:
            materiales = {" ┌─","─┘ ","─┐ ", " └─", "─┴─", "─┬─", " ├─", "───", "─┼─", "─┤ ", " │ "};
            break;
        case 2:
            materiales = {"═╣ ", " ║ ", "═╗ ", "═╝ ", " ╚═", " ╔═", "═╩═", "═╦═", " ╠═", "═══", "═╬═"};
            break;
        case 3:
            materiales = {"░░░", "▒▒▒", "▓▓▓", " ░ ", " ▒ ", " ▓ "};
            break;
        case 4:
            materiales = {"███", " █ "," ▄ ", " ▀ ", " ■ "};
            break;
        case 5:
            if(usuario.size()==0)
            {
                std::cout<<"Parece que aun no tienes materiales creados, saldras de este menu";
                return;
            }
            materiales = usuario;
            break;
        case 6:
            materiales = {" ≡ ", " ¦ ", " ¤ ", " O "};
            break;
        case 7:
            return;
    }
    while(true)
    {
        try
        {
            std::cout<<"Por favor, seleccione uno de estos materiales\n\n";
            for(int i = 0; i < materiales.size(); i++) std::cout<<i+1<<".- "<<materiales[i]<<'\n';
            std::cout<<materiales.size()+1<<".- Cancelar\n";
            std::cout<<"\nOpcion : ";
            std::cin>>num;
            if(num==materiales.size()+1) return;
            else if((num > 0) && (num <= materiales.size()))
            {
                material = materiales[num-1];
                return;
            }
        }
        catch(...)
        {
            estupido();
        }
    }
}

bool menu_salir(){
    while(true){
        char resp;
        std::cout<<"Estas seguro de querer salir (S/N)? : ";
        std::cin>>resp;
        resp = std::toupper(resp);
        if((resp=='S')||(resp=='N')) return (resp == 'S') ? true : false;
        estupido();
    }
}

void editor()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    bool salir = false;

    
    std::vector<std::string> usuario = {};

    std::string anterior = "   ";
    std::string material = " - ";
    std::string personaje = escojer_personaje();
    std::cout<<'\n';

    const int Y_LIENZO = dimensiones('Y');
    const int X_LIENZO = dimensiones('X');
    int y = Y_LIENZO/2;
    int x = X_LIENZO/2;
    
    std::vector<std::vector<std::string>> lienzo = crear_lienzo(Y_LIENZO, X_LIENZO);

    lienzo[y][x] = material;
    
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
                case 'a':
                case 'd':
                case 's':
                case 'w':
                    lienzo[y][x] = anterior;
                    cambiar_coord(x, y, X_LIENZO, Y_LIENZO, tecla);
                    anterior = lienzo[y][x];
                    lienzo[y][x] = material;
                    system("cls");
                    break;
                case 'm':
                    menu_materiales(usuario, material);
                    break;
                case 'p':
                    personaje = escojer_personaje();
                    break;
                case '0':
                    anterior = "   ";
                    break;
                case '1':
                    anterior = material;
                    lienzo[y][x] = material;
                    system("cls");
                    break;
                case '2':
                    salir = menu_salir();
                    break;
            }
            impresion(lienzo);
        }
        if(salir) break;
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