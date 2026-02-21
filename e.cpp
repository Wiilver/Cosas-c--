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

void impresion(const std::vector<std::vector<std::string>>& matriz, const std::vector<std::vector<int>>& color, const std::vector<std::vector<int>>& fondo)
{
    std::string cactual;
    std::string factual;
    std::string lista_colores [] = 
    {
        "\033[30;", "\033[90;", "\033[31;", "\033[91;", 
        "\033[32;", "\033[92;", "\033[33;", "\033[93;", 
        "\033[34;", "\033[94;", "\033[35;", "\033[95;",
        "\033[36;", "\033[96;", "\033[37;", "\033[97;"
    }; 
                
    std::string lista_fondos [] =
    {
        "40m", "100m", "41m", "101m",
        "42m", "102m", "43m", "103m",
        "44m", "104m", "45m", "105m",
        "46m", "106m", "47m", "107m"
    };
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
            else
            {
                

                cactual = lista_colores[color[i-1][j-1]];
                factual = lista_fondos[fondo[i-1][j-1]];
                std::cout<<cactual<<factual<<matriz[i-1][j-1]<<"\033[0m";
            }
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

std::vector<std::vector<int>> crear_matriz(const int Y, const int X)
{
    int car = 0;
    std::vector<int> arr;
    std::vector<std::vector<int>> matriz;
    
    for(int i = 0; i < X; i++) arr.push_back(car);
    for(int i = 0; i < Y; i++) matriz.push_back(arr);
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
        case 72:
        case 87:
        case 119:
            tecla = 'w';
            break;

        case 65:
        case 75:
        case 97:
            tecla = 'a';
            break;
        
        case 83:
        case 115:
            tecla = 's';
            break;

        case 68:
        case 100:
            tecla = 'd';
            break;

        case 67:
        case 99:
            tecla = 'c';
            break;
        
        case 70:
        case 102:
            tecla = 'f';
            break;

        case 80:
        case 112:
            tecla = 'p';
            break;

        case 77:
        case 109:
            tecla = 'm';
            break;

        case 78:
        case 110:
            tecla = 'n';
            break;

        case 39:
        case 63:
        case 168:
            tecla = '?';
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
                std::cout<<"Parece que aun no tienes materiales creados, saldras de este menu\n";
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
        std::cout<<"Por favor, seleccione uno de estos materiales\n\n";
        for(int i = 0; i < materiales.size(); i++) std::cout<<i+1<<".- "<<materiales[i]<<'\n';
        std::cout<<materiales.size()+1<<".- Cancelar\n";
        std::cout<<"\nOpcion : ";
        std::cin>>resp;
        if (checar_num(resp))
        {
            num = std::stoi(resp);
            if(num==materiales.size()+1) return;
            else if((num > 0) && (num <= materiales.size()))
            {
                material = materiales[num-1];
                return;
            }
        }
        estupido();
    }
}

void menu_colores(int& color)
{
    int i;
    std::string resp;
    system("cls");
    while(true)
    {
        std::cout<<
        "Por favor, selecciona una de las siguientes opciones :\n"<<
        " 1 .- Negro\n"<<
        " 2 .- Gris Oscuro\n"<<
        " 3 .- Rojo\n"<<
        " 4 .- Rojo Claro\n"<<
        " 5 .- Verde\n"<<
        " 6 .- Verde Claro\n"<<
        " 7 .- Amarillo\n"<<
        " 8 .- Amarillo Claro\n"<<
        " 9 .- Azul\n"<<
        "10 .- Azul Claro\n"<<
        "11 .- Purpura\n"<<
        "12 .- Purpura Claro\n"<<
        "13 .- Cyan\n"<<
        "14 .- Cyan Claro\n"<<
        "15 .- Gris Claro\n"<<
        "16 .- Blanco\n"<<
        "17 .- Cancelar\n"<<
        "Opcion : ";
        std::cin>>resp;
        if(checar_num(resp))
        {
            i = std::stoi(resp);
            if((i > 0)||(i < 18)) break;
        }
        estupido();
    }
    if(i == 17) return;
    color = i-1;
}

void nuevo_material(std::vector<std::string>& usuario)
{
    std::string resp;
    while(true)
    {
        std::cout<<"Por favor introduzca el material que quiera crear, solo se admiten 1 o 3 caracteres : ";
        std::cin>>resp;
        if(resp.size() == 3)
        {
            usuario.push_back(resp);
            return;
        }
        else if(resp.size() == 1)
        {
            resp = " " + resp + " ";
            usuario.push_back(resp);
            return;
        }
        estupido();
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

void ayuda()
{
    char c;
    std::cout<<
    "Esta es una lista de los comandos que tienes disponibles:\n"<<
    "1.- WASD : Son las teclas de movimiento\n"<<
    "2.- M : Sirve para seleccionar un material\n"<<
    "3.- N : Te permite crear un nuevo material\n"<<
    "4.- P : Con esta tecla puedes escojer el personaje con el que juega el usuario\n"<<
    "5.- BACKSPACE : Te permite borrar los contenidos de la celda\n"<<
    "6.- ENTER : Asigna el contenido a la celda en la que te encuentras\n"<<
    "7.- ESC : Salir\n\n"<<
    "Presiona ENTER para salir de este menu...";
    std::cin>>c;
}

void editor()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    bool salir = false;
    int color = 0;
    int ant_color = 0;
    int fondo = 0;
    int ant_fondo = 0;
    
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
    std::vector<std::vector<int>> colores = crear_matriz(Y_LIENZO,X_LIENZO);
    std::vector<std::vector<int>> fondos = crear_matriz(Y_LIENZO,X_LIENZO);
    lienzo[y][x] = material;
    
    system("cls");
    impresion(lienzo, colores, fondos);

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
                    fondos[y][x] = ant_fondo;
                    colores[y][x] = ant_color;
                    lienzo[y][x] = anterior;
                    cambiar_coord(x, y, X_LIENZO, Y_LIENZO, tecla);
                    anterior = lienzo[y][x];
                    ant_color = colores[y][x];
                    ant_fondo = fondos[y][x];
                    lienzo[y][x] = material;
                    colores[y][x] = color;
                    fondos[y][x] = fondo;
                    break;
                case 'c':
                    menu_colores(color);
                    break;
                case 'f':
                    menu_colores(fondo);
                    break;
                case 'm':
                    menu_materiales(usuario, material);
                    break;
                case 'n':
                    nuevo_material(usuario);
                    break;
                case 'p':
                    personaje = escojer_personaje();
                    break;
                case '0':
                    anterior = "   ";
                    ant_color = 0;
                    ant_fondo = 0;
                    break;
                case '1':
                    anterior = material;
                    lienzo[y][x] = material;
                    ant_color = color;
                    colores[y][x] = color;
                    ant_fondo = fondo;
                    fondos[y][x] = fondo;
                    break;
                case '2':
                    salir = menu_salir();
                    break;
                case '?':
                    ayuda();
                    break;
                case ' ':
                    break;
            }
            system("cls");
            impresion(lienzo, colores, fondos);
        }
        if(salir) 
        {
            system("cls");
            break;
        }
    }
}

int main()
{
    //Necesitamos el coso para que pueda decidir entre checar si hay archivos, abrirlos o crearlos
    
    editor();
    return 0;
}