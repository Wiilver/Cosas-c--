#include <iostream>
#include <cctype>
#include <string>
#include <list>
void saludo()
{
    std::string a;
    std::cout<<
    "Buenisimas tardes, este programa esta dedicado a derivar funciones simples\n"<<
    "  Las funciones que puedes derivar de momento solo son exponenciales ;-;  \n"<<
    "                  Pero planeamos cambiar esto pronto :D                   \n"<<
    "               (Introduce cualquier caracter para continuar)              \n";
    std::cin>>a;
    std::cout<<"\n\n";
}

void ejemplo()
{
    std::cout<<
    "Un ejemplo de como se veria una funcion escrita correctamente sería :\n\n"<<
    "x^3 + 8x ^ 2-3x - 1";
}

std::string derivar()
{
    std::string resp, ord;
    char car, var;
    bool valido, salir;
    while (true)
    {
        var = ' ';
        valido = true;
        ord = "";
        while(true)
        {
            std::cout<<"\nPor favor introduzca su funcion : ";
            std::getline(std::cin, resp);
            if(!resp.empty()) break;
        }
        
        try
        {
            //x ^2 - 8x +1
            for(int i = 0; i< resp.length(); i++)
            {
                car = resp.at(i);
                
                if (car == ' ') continue;
                
                if((var==' ')&&(isalpha(car))) var=car;
                
                else if((isalpha(car))&&(var!=car)) {valido = false; throw 1;}
                
                if ((isalpha(car))||(isdigit(car))||(car=='+')||(car=='-')||(car=='^')) ord += std::string(1,car);
                else{valido = false; throw 1;}
            }
            //x^2-8x+1
            
            if (valido)
            {
                for(int i = 0; i<ord.length(); i++)
                {
                    car = ord.at(i);
                    if ((car == '+')||(car == '-')||(car == '^'))
                    {
                        if (i==ord.length()-1) valido = false;
                        else if ((ord.at(i+1) == '+')||(ord.at(i+1)=='-')||(ord.at(i+1)=='^')) valido = false;
                    }
                    if((car==var)&&(i<ord.length()-1))
                    {
                        if ((ord.at(i+1)==var)||isdigit(ord.at(i+1))) valido = false;
                    }
                }
                if (valido) return ord;
                else throw 1;
            } 
        }
        catch(...)
        {
            while (true)
            {
                std::cout<<"Parece que hubo un problema en el como escribiste tu maravillosa funcion\n"<<
                "Quieres volver a intentarlo (S/N)? : ";
                std::cin>>car;
                car = toupper(car);
                
                if(car=='S') break;
                else if (car=='N') return ""; 
            }
        }
    }
}
void derivar2(std::string fun)
{
    char car, var;
    std::string ord, num, pot = "";
    double exp, cosa = 0;
    bool ya = false;

    try
    {
        for(int i = 0; i<fun.length(); i++)
        {
            if(isdigit(fun.at(i)))
            {
                if (ya) pot+=std::string(1,fun.at(i));
                else num += std::string(1, fun.at(i));
            }
            else if(isalpha(fun.at(i))) 
            {
                var=fun.at(i);
                if (i<fun.length()-1)
                {
                    if(fun.at(i+1)!='^') 
                    {
                        ya = false;
                        cosa,exp = 0;
                        num, pot="";
                        continue;
                    }
                }
                if(fun.length()>0)
                {
                    if (i==0) cosa = 1;
                    //else if(isdigit())
                }
                cosa = std::stod(num);
                num = "";
            }
            else if(fun.at(i)=='^')
            {
                if (ya) throw 1;
                else ya = true;
            }
            else if((fun.at(i)=='+')||(fun.at(i)=='-'))
            {
                exp = std::stod(pot);
                pot="";
                ya=false;
                
                cosa *=exp;
                exp--;
                std::cout<<exp<<cosa<<"\n";
                ord+=(std::to_string(cosa)+"y^"+std::to_string(exp)+std::string(1,fun.at(i)));
            }
        }
        std::cout<<ord;
    }
    catch(...) {std::cout<<"Parece que hubo un problema con el como se escribio la funcion, se te devolvera al menu principal";}

}

int menu()
{
    int opc;
    while(true)
    {
        try
        {
            std::cout<<
            "Por favor, selecciona una de las siguientes opciones :\n"<<
            "1.- Introducir funcion\n"<<
            "2.- Ver un ejemplo de como se debe de ver la funcion que introduzcas\n"<<
            "3.- Ver una explicacion breve de como se esta derivando\n"<<
            "4.- Salir"<<
            "Opcion : ";
            std::cin>>opc;
            std::cout<<"\n";
            if((opc<1)||(opc>4)) throw;
            else return opc;
        }
        catch(...)
        {
            std::cout<<"Parece que hubo un error con el dato que introdujiste, por favor, intentalo nuevamente\n";
        }
    }

    return opc;
}

int main()
{
    std::string a;
    a = derivar();
    std::cout<<a<<"\n";
    derivar2(a);
    return 0;
}