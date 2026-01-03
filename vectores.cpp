#include <iostream>
#include <vector>
#include <cstdlib>
#include <array>
#include <sstream>
#include <iomanip>

void impresion(const std::vector <std::vector<double>>& matriz)
{
    int largo = 0;
    std::ostringstream os;

    for(int i = 0; i < matriz.size(); i++)
    {
        for(int j = 0; j < matriz[0].size(); j++)
        {
            os.str("");
            os << std::fixed << std::setprecision(1)<< matriz[i][j];
            if(os.str().length()>largo) largo = os.str().length();
        }
    }

    std::cout<<std::fixed<<std::setprecision(1);
    for(int i = 0; i < matriz.size(); i++)
    {
        for(int j = 0; j < matriz[0].size(); j++) std::cout<<' '<<std::setw(largo)<<matriz[i][j]<<' ';
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

int menu()
{
    int opc;
    while(true)
    {
        try
        {
            std::cout<<
            "Buenas tardes, por favor, seleccione una de las siguientes opciones :\n"
            "1.- Definir una nueva matriz\n"
            "2.- Introducir datos a la matriz\n"
            "3.- Multiplicar una fila\n"
            "4.- Sumar filas\n"
            "5.- Restar filas\n"
            "6.- Intercambiar filas\n"
            "7.- Tratar de solucionar el sistema de ecuaciones\n"
            "8.- Obtener el determinante de la matriz\n"
            "9.- Salir\n"
            "Opcion : ";
            std::cin>>opc;
            
            if((opc < 1)||(opc > 9)) throw 1;
            
            return opc;
        }
        catch(...)
        {
            system("cls");
            std::cout<<"Parece que hubo un problema con la respuesta que diste, por favor, intentalo nuevamente\n\n";
        }
    }
    return opc;
}

std::array<int, 2> dimensiones()
{
    int opc;
    std::array<int,2> dimensiones;

    while(true)
    {
        try
        {
            std::cout<<"Buenas tardes, por favor, introduzca que tan alta quiere que sea su matriz : ";
            std::cin>>dimensiones[0];

            if(dimensiones[0] < 1) throw 1;

            std::cout<<"\nAhora, porfavor selecciones el ancho de su matriz : ";
            std::cin>>dimensiones[1];

            if(dimensiones[1] < 1) throw 1;

            return dimensiones;
        }
        catch(...)
        {
            system("cls");
            std::cout<<"Parece que hubo un problema con la respuesta que diste, por favor, intentalo de nuevo\n\n";
        }
    }
}

std::vector <std::vector<double>> crear(std::vector <std::vector<double>> matriz, const std::array <int, 2>& yx)
{
    matriz.clear();

    std::vector <double> largo;

    for(int i = 0; i < yx[1]; i ++)
    {
        largo.push_back(0);
    }

    for(int i = 0; i < yx[0]; i++)
    {
        matriz.push_back(largo);
    }
    return matriz;
}

std::vector <std::vector<double>> rellenar(std::vector <std::vector<double>> matriz)
{
    double valor;
    char resp;

    while(true)
    {
        try
        {
            std::cout<<"Desea agregar definir un unico valor de la matriz o la matriz entera (U/E)? : ";
            std::cin>>resp;

            if(isalpha(resp))
            {
                resp = toupper(resp);
                if ((resp=='U')||(resp=='E')) break;
            }
            throw 1;
        }
        catch(...)
        {
            system("cls");
            std::cout<<"Parece que hubo un problema con la respuesta que diste, por favor intentalo nuevamente\n";
        }
    }
    
    system("cls");

    if(resp=='U')
    {
        int x, y;
        while(true)
        {
            try
            {
                std::cout<<"Seleccione la coordenada y de su elemento (su matriz tiene hasta "<< matriz.size()<<" elementos) : ";
                std::cin>>y;

                if((y<0)||(y>matriz.size())) throw 1;

                std::cout<<"Seleccione la coordenada x de su elemento (su matriz tiene hasta "<< matriz[0].size()<<" elementos) : ";
                std::cin>>x;

                if((x<0)||(x>matriz[0].size())) throw 1;

                std::cout<<"Ahora ingrese el valor que le quiere asignar al elemento ["<<y<<','<<x<<"] : ";
                std::cin>>valor;

                matriz[y-1][x-1] = valor;
                return matriz;
            }
            catch(...)
            {
                system("cls");
                std::cout<<"Parece que hubo un error con el dato que introdujiste, por favor, intentalo de nuevo\n\n";
            }
        }
    }
    else
    {
        std::string resp;
        for(int i = 0; i < matriz.size(); i++)
        {
            for(int j = 0; j < matriz[0].size(); j++)
            {
                while(true)
                {
                    system("cls");
                    impresion(matriz);
                    try
                    {
                        std::cout<<"Introduzca el valor que le quiere dar al elemento ["<<i+1<<','<<j+1<<"] : ";
                        std::cin>>resp;
                        
                        for(int k = 0; k < resp.length(); k++) if((!isdigit(resp[k]))&&(resp[k]!='.')&&(resp[k]!='-')) throw 1;
                        
                        matriz[i][j] = std::stod(resp);
                        break;
                    }
                    catch(...)
                    {
                        system("cls");
                        std::cout<<"Parece que hubo un error con el dato que introdujiste, por favor, intentalo de nuevo\n\n";
                    }
                }
            }
        }
        return matriz;
    }

}

int main()
{
    int opc;
    std::array <int, 2> yx;
    std::vector <std::vector<double>> matriz;

    while(true)
    {
        system("cls");
        if (matriz.size()>0) impresion(matriz);
        
        opc = menu();
        if (opc == 9) break;
        
        system("cls");
        try
        {

            switch(opc)
            {
                case 1:
                    yx = dimensiones();
                    matriz = crear(matriz, yx);
                    break;
                case 2:
                    if(matriz.size()==0) throw 1;
                    matriz = rellenar(matriz);
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
            }
        }
        catch(...)
        {
            system("cls");
            std::cout<<"Esta opcion necesita que ya tengas una matriz creada\nPresiona ENTER para continuar...";
            std::cin>>opc;
        }

    }
    

    return 0;
}