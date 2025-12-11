#include <iostream>

int main(){
    std::string nombre;

    std::cout<<"Por favor, introduzca su nombre : ";
    std::getline(std::cin, nombre);

    if(nombre.empty()){
        std::cout<<"\nHermano, no introdujiste nada";
    }
    else if (nombre.length() == 6){
        std::cout<<"\nQue casualidad, el mio tambien";
    }
    nombre.append(" es un tonto");
    std::cout<<"\nJejejeje, te llamaste tonto "<<nombre;

    std::cout<<"\nLa primera letra de tu nombre es " <<nombre.at(0);

    nombre.insert(0,"xX69");
    std::cout<<"\nBuen nombre "<<nombre;

    if (nombre.find(" ")){
        std::cout<<"\nParece que tienes un espacio en tu nombre, raroncio ";
    }

    nombre.erase(0,1);
    std::cout<<"\nTe quite la primera x porque no me gustaba "<<nombre;

    nombre.clear();
    std::cout<<"\nJejejeje, te robe tu nombre "<<nombre;

    return 0;
}