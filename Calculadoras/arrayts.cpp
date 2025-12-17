#include <iostream>
#include <string>
#include <array>

std::array<double,2> numeros()
{
    double resultado, prim, seg;
    while(true)
    {
        std::string resp;
        try
        {
            std::cout<<"\nBuenisimas tardes, introduzca el primer numero que quiera usar: ";
            std::cin>>resp;
            
            if(resp.empty()) throw;
            else prim = std::stod(resp);
            
            std::cout<<"\nAhora por favor introduzca el segundo de sus numeros : ";
            std::cin>>resp;
            
            if(resp.empty())throw;
            else seg = std::stod(resp);
            break;
        }
        catch(...)
        {
            std::cout<<"Parece que no sabes como escribir, por favor, intentalo de nuevo\n";
        }
    }
    return {prim,seg};
}

int menu()
{
    std::string opcion;
    int coso;
    bool supo;

    while(true)
    {
        supo = true;
        std::cout<<
        "Por favor, ingrese una de las siguientes opciones\n"<<
        "1.- Suma\n"<<
        "2.- Resta\n"<<
        "3.- Multiplicacion\n"<<
        "4.- Division\n"<<
        "5.- Salir\n"
        "Opcion : ";
        std::cin>>opcion;

        for(int i = 0; i<opcion.length(); i++)
        {
            if (isalpha(opcion.at(i))) {supo = false; break;}
        }
        if(supo)
        {
            coso = std::stoi(opcion);
            if ((coso>0)&&(coso<6)) return coso;
            else std::cout<<"\nEsta fuera del rango tu numerazo hermano\n";
        }
        else std::cout<<"\nParece que no le supiste hermano, intentale de nuevo\n";
    }
}

int main()
{
    while(true)
    {
        int x = menu();
        if (x==5) break;
        else
        {
            std::array<double,2> num = numeros();
            std::cout<<"\n";
            switch(x)
            {
                case 1:
                    std::cout<<"El resultado de la suma es : "<<num[0]+num[1];
                    break;
                case 2:
                    std::cout<<"El resultado de la resta es :"<<num[0]-num[1];
                    break;
                case 3:
                    std::cout<<"El producto de tu mulptiplicacion es : "<<num[0]*num[1];
                    break;        
                case 4:
                    if(num[1]==0)std::cout<<"Parece que trataste de dividir entre cero, lo cual no se puede";
                    else std::cout<<"El resultado de tu division es : "<<num[0]/num[1];
                    break;
            }
            std::cout<<"\n\n";
        }
    }
    return 0;
}