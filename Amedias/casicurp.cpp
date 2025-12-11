#include <iostream>
#include <cctype>

int main()
{
    bool valido;
    char c;
    std::string input, respuesta;
    
    
    while(true)
    {
        valido = true;
        std::cout<<"Por favor, introduzca su CURP : ";
        std::cin>>input;
        std::cout<<"\n";

        if(input.length()!=18)
        {
            while(true)
            {
                std::cout<<"Hermano en cristo, escribir la una buena CURP no es tan complicado, por favor, intentalo de nuevo : ";
                std::cin>>input;
                std::cout<<"\n";
                if(input.length() == 18) break;
            }
        }

        for(int i = 0; i < input.length(); i++)
        {
            if((i < 4) || ((i >= 10) && (i < 17)))
            {
                if(isdigit(input.at(i))) valido = false;
            }
            else if((i < 10) || (i == 17))
            {
                if(isalpha(input.at(i))) valido = false;
            }
            if (!valido) break;
        }
        if(valido)
        { 
            std::cout<<"Felicitaciones, tu CURP es medianamente valido, ahora toca lo feo";
            break;
        }
        else
        {
            while(true)
            {
                std::cout<<"Parece que tu desmadre esta mal hecho, quieres intentarlo con uno nuevo? (S/N) : ";
                std::cin>>respuesta;
                std::cout<<"\n";
                
                if(respuesta.length()!=1)
                {
                    std::cout<<"Para responder solo se admite un caracter, por favor, intentalo de nuevo\n";
                    continue;        
                }
                else c = respuesta.at(0);

                if(isdigit(c))
                {
                    std::cout<<"Hermano, no se admiten numeros, por favor, intentalo de nuevo\n";
                    continue;
                }
                else c = toupper(c);
                
                if((c=='S')||(c=='N')) break;
                else std::cout<<"Hermano, solo se admiten 'S' o 'N' como respuesta, por favor, intentalo de nuevo\n";
            }
            if (c=='N') break;
        }
    }
    return 0;
}