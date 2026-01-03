#include <iostream>
#include <cctype>
#include <list>
#include <array>
//f(x) = 32x^-3-8x^2+x+1

std::string validar(std::string fun)
{
    std::string ord = "";
    char var, car;
    bool yava, yaex;
    
    var = ' ';
    yava = yaex = false;

    try
    {
        for(int i = 0; i < fun.length(); i++)
        {
            car = fun[i];
            
            if (car == ' ') continue;

            else if (isalpha(car))
            {
                //Notese que esta validacion es para que no puedan suceder exponenciales del tipo 8^y, puede ser cambiado
                if (yaex) throw 1;

                if (var == ' ') var = car;
                else if (var != car) throw 1;
                yava = true;
            }
            else if (isdigit(car))
            {
                if (!ord.empty())
                {
                    if (isalpha(ord.back())) throw 1;
                }
            }
            
            else if (car == '^')
            {
                if (i == fun.length()-1)throw 1;
                if ((!yava) || (yaex)) throw 1;
                yaex = true;
            }
            
            else if ((car == '+') || (car == '-'))
            {
                if (i == fun.length()-1) throw 1;
                if ((ord.back()=='+') || (ord.back() == '-')) throw 1;
                if (ord.back()== '^')
                {
                    if (car == '+') throw 1;
                    ord += '-';
                    continue;
                }
                yava = false;
                yaex = false;
            }
            
            else throw 1;
            
            ord += std::string(1,car);
        }
    }
    catch(...)
    {
        return "Nosepudp";
    }

    return ord;
}

std::list<std::array<std::string,3>> hacerarreglo(std::string fun)
{
    std::list<std::array<std::string,3>> lista;
    std::array<std::string,3> arr;
    std::string num, coe, exp;
    bool yava, yaex;
    char car;


    yava = yaex = false;
    num = "";
    
    for(int i = 0; i < fun.length(); i++)
    {
        car = fun[i];
        
        if(isdigit(car)) num+=std::string(1,car);
        else if(isalpha(car))
        {
            yava = true;
            if(!num.empty()) coe = num;
            else 
            {
                coe = "1";
                num = "";   
            } 
        }
        else if(car == '^') yaex=true;
        else if((car=='-')||(car=='+'))
        {
            if (car=='-')
            {
                if(i>0)
                {
                    if(fun[i-1]=='^') 
                    {
                        num+="-";
                        continue;
                    }
                }
            }
            if(yaex)
            {
                if(!num.empty()) 
                {
                    exp = num;
                    num = "";
                }
                else exp = "1"; 
            }
            else exp = "1";
            if(coe.empty())
            {
                coe = "1";
            }
        }
    }

    
}

int main()
{
    std::string fun, fun2;

    std::getline(std::cin, fun);
    fun2 = validar(fun);

    std::cout<<fun2;

    return 0;
}