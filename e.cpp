#include <iostream>
#include <vector>
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

void editor()
{
    const int Y_LIENZO = dimensiones('Y');
    const int X_LIENZO = dimensiones('X');
    std::vector<std::vector<std::string>> lienzo = crear_lienzo(Y_LIENZO, X_LIENZO);
    impresion(lienzo);
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
