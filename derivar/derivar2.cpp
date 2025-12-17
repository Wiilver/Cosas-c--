#include <iostream>
#include <cctype>

void ejemplo()
{
    char a;
    std::cout<<
    "\nEl sistema es simple, por tanto, admite solo numeros enteros, espacios, una variable y los signos '+', '-' y '^'"<<
    "\nEjemplo de una funcion valida seria:\n"<<
    "\n3x^3 + 2 x ^ 2 + 34x -1\n"<<
    "\nEjemplo de una funcion que no seria aceptada por el sistema seria:\n"<<
    "\n4.5x^-3 + -5y*3^2 -z + %\n\n"<<
    "Ingrese cualquier caracter para continuar: ";
    std::cin>>a;
    std::cout<<'\n';
}

void explicacion()
{
    char a;
    std::cout<<
    "\nEl programa hace la forma mas sencilla de derivacion, que es la ley del exponente"<<
    "\nEste teorema nos ayuda a derivar cualquier funcion de la forma...\n"<<
    "\nf(x) = x^n\n"<<
    "\nHaciendo que pase a ser...\n"<<
    "\nf'(x) = nx^(n-1)\n"<<
    "\nDe manera simple, se basa en bajar el exponente como coeficiente de la x y lo volvemos a dejar como potencia pero ahora restandole 1"<<
    "\nPor poner un ejemplo, la derivada de la funcion f(x)=3x^2 es igual a f'(x) = 6x\n"<<
    "\nPara continuar, ingrese cualquier caracter : ";
    std::cin>>a;
    std::cout<<'\n';
}

char menu()
{
    char valido[] = {'a','b','c','d'};
    char opcion;
    while(true)
    {
        std::cout<<
        "Escoja una de las siguientes opciones:\n"<<
        "a) Derivar\n"<<
        "b) Mostrar un ejemplo de como se puede ver una funcion posible\n"<<
        "c) Obtener una explicacion de lo que hace el programa\n"
        "d) Salir\n"
        "Opcion : ";
        
        std::cin>>opcion;
        opcion = tolower(opcion);

        std::cout<<'\n';

        for(int i = 0; i<sizeof(valido); i++)
        {
            if(opcion==valido[i]) return opcion;
        }
        std::cout<<"Parece introdujiste algo que no estaba en las opciones, por favor, intentalo nuevamente\n";
    }
    
    
    
    return opcion;
}

void derivar()
{
    int coe, exp;
    std::string resp, ord, num;
    bool yava, yaex, ya;
    char car, var;
    
    coe = 1;
    exp = 1;

    ord = "";
    var = ' ';

    ya = false;
    yava = false;
    yaex = false;


    while(true)
    {
        try{

            while(true)
            {
                std::cout<<"Por favor, introduzca la funcion que quiera derivar : ";
                std::getline(std::cin, resp);
                std::cout<<'\n';
                if(!resp.empty()) 
                {
                    break;
                }
            }
            
            for(int i = 0; i < resp.length(); i++)
            {
                //Obtenemos el caracter
                car = resp.at(i);
                
                if (car == ' ') continue;

                else if(isalpha(car))
                {
                    if (yava) throw 1;
                    else
                    {
                        if (var == ' ') var = car;
                        else if (var!=car) throw 1;
                        
                        ya = true;
                        yava = true;
                    }
                }

                else if (isdigit(car))
                {
                    if(i>0)
                    {
                        if (isalpha(resp.at(i-1))) throw 1;
                    }
                    ya = true;
                }

                else if(car == '^')
                {
                    if((yaex)||(!yava)) throw 1;
                    yaex = true;
                }
                
                else if((car =='+')||(car=='-'))
                {
                    if(!ya) throw 1;
                    yaex = false;
                    yava = false;
                    ya = false;
                }
                
                else throw 1;

                ord += std::string(1,car);
            }

            if((ord.back()=='+')||(ord.back()=='-')||(ord.back()=='^')) throw 1;

            ya = false;
            yava = false;
            yaex = false;
            resp = "";            

            for(int i = 0; i < ord.length(); i++)
            {
                car = ord.at(i);
                if(i<ord.length()-1)
                {
                    if ((ord.at(i) == '^')&&(!isdigit(ord.at(i+1)))) throw 1;
                }
                if(isdigit(car))
                {
                    num+=std::string(1,car);
                }
                else if(car==var)
                {
                    if(!num.empty()) coe = std::stoi(num);
                    yava = true;
                    num = "";
                }
                else if(car=='^')
                {
                    yaex = true;
                }
                
                if((i==ord.length()-1)||(car=='+')||(car=='-'))
                {
                    if (yaex)
                    {
                        exp = std::stoi(num);
                        num = "";
                        
                        coe *= exp;
                        exp--;

                        resp += std::to_string(coe);
                        resp += var;
                        if (exp!=1)
                        {
                            resp += "^";
                            resp += std::to_string(exp);
                        }
                        if(i!=ord.length()-1) resp += std::string(1,car);
                    }
                    else if(yava)
                    {
                        resp += std::to_string(coe);
                        if (i!=ord.length()-1) resp += std::string(1,car);
                    }
                    yaex = false;
                    yava = false;
                    num = "";
                    exp = 1;
                    coe = 1;
                }
            }
            
            if((resp.back() == '+')||(resp.back()=='-')) resp.back() = ' ';
            
            std::cout<<"Tu funcion derivada es : "<<resp<<"\n\n";
            
            break;
        }

        catch(...)
        {
            while(true)
            {
                std::cout<<"Desea volver a intentarlo (S/N)? :  ";
                std::cin>>car;
                
                car = tolower(car);
                
                if((car == 'n')||(car == 's')) break;
                else std::cout<<"\nPero tu eres tonto perdido\n";
            }
            if (car == 'n') break;
            
            else
            {
                ya = false;
                yava = false;
                yaex = false;
                ord = "";
                var = ' ';
            }
        }
    }
}

int main()
{
    bool seguir = true;
    while(seguir)
    {
        char opcion = menu();

        if (opcion =='d') break;

        switch(opcion)
        {
            case 'a':
                derivar();
                break;
            case'b':
                ejemplo();
                break;
            case'c':
                explicacion();
                break;
        }
    }
}