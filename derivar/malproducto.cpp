#include <iostream>
#include <cctype>
bool validar(std::string fun)
{
    std::string nueva = "";
    char car, var;
    bool yava, yaex, ya;
    var= ' ';
    try
    {

        for(int i = 0; i<fun.length(); i++)
        {
            car = fun[i];
            
            if(isalpha(car))
            {
                if (var == ' ') var = car;
                else if (var != car) return false;
                ya = true;
            }
            else if(isdigit(car))
            {
                if(i>0)
                {
                    if(fun[i-1] == '^') return false;
                }
                ya = true;
            }
            else if(car = '^')
            {
                if((yaex)||(!ya)) return false;
                else yaex = true;
            }
            else if((car=='-')||(car=='+'))
            {
                if((yaex)&&(car=='-'))
                {
                    if((fun[i-1]=='^')&&(isdigit(fun[i+1]))) continue;
                }
            }
        }
    }
    catch(...){return false;}

    return true;
}

void producto(std::string fun1, std::string fun2)
{
    std::string producto;
}

int main()
{
    char resp;
    std::string fun1, fun2;
    while(true)
    {
        try
        {
            std::cout<<"Ingrese su primer factor : ";
            std::getline(std::cin,fun1);
            if(!validar(fun1)) throw 1;

            std::cout<<"\nAhora ingrese su segundo factor : ";
            std::getline(std::cin,fun2);
            if(!validar(fun2)) throw 1;
            
            producto(fun1, fun2);
            break;
        }
        catch(...)
        {
            while(true)
            {
                std::cout<<"\nParece que hubo un error, quieres intentarlo de nuevo (S/N)? : ";
                std::cin>>resp;
                resp = toupper(resp);

                if ((resp=='S')||(resp=='N')) break;
            }
            if (resp=='N') break;
            else
            {
                fun1.clear();
                fun2.clear();
            }
        }
    }
        

    return 0;
}