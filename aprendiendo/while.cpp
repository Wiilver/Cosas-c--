#include <iostream>

int main(){
    std::string respuesta;
    while(true){
        std::cout<<"\nHola muy buenas tardes, de casualidad quieres seguir con el codigo ? (Si/No) : ";
        std::cin>>respuesta;

        if(respuesta.empty()){
            std::cout<<"\nSabias que para que yo pueda entenderte debes de, tipo, contestar?\n";
        }
        else if(respuesta.length()>2){
            std::cout<<"\nTe prometo que no me pagan por andar leyendo tantas estupideces que me escribes\n";
        }
        else if(islower(respuesta.at(0))){
            std::cout<<"\nAy corazon, recordemos que las mayusculas sirven para algo\n";
        }
        else if(isupper(respuesta.at(1))){
            std::cout<<"\nSabias tu que si tienes una mayuscula despues de la primera eres mas o menos una desgracia?\n";
        }
        else if((respuesta.at(0) != 'S')&(respuesta.at(0) != 'N')){
            std::cout<<"\nQuisiera que sepas que en realidad pude haberme saltado unas cuantas lineas de texto, pero que esta puesto asi especificamente para molestar\nNo te admitire algo que no sea una S o una N al principio\n";
        }
        else if((respuesta.at(1) != 'i')&(respuesta.at(0) != 'o')){
            std::cout<<"\nTe prometo, mi hermano, en nombre de cristo, que escribir correctamente no es tan complicado, aqui solo deberian de haber o una i o una o\n";
        }
        else if(respuesta == "No"){
            std::cout<<"Rarillo que quieras seguir hablando conmigo";
        }
        else{
            break;
        }
    }

    return 0;
}