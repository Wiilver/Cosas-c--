#include <iostream>

int main(){
    std::string saludo;
    int ancho;

    std::cout<<"Buenas tardes, por favor, introduce un saludo : ";
    std::getline(std::cin, saludo);
    
    std::cout<<"Tu saludo quedaria como :\nHola "<<saludo<<"\n";

    std::cout<<"Por favor, introduzca que tan grande quiere que sea su piramide: ";
    std::cin>>ancho;
    int largo = (ancho*2)-1;
    int resta = ancho-1;
    for(int i = 1; i<=(ancho); i++)
    {
        for(int j = 1; j<= largo; j++)
        {
            if((j>i*resta)&&(j<largo-i*resta))
            {
                std::cout<<"O";
            }
            else
            {
                std::cout<<" ";
            }
        }
        resta--;
        std::cout<<"\n";
    }

    return 0;   
}