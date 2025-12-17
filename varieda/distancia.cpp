#include <iostream>
#include <cmath>

int main(){
    double x1, x2, y1, y2, dy, dx, hip;

    std::cout<<"Introduzca la coordenada x del primer punto : ";
    std::cin>>x1;

    std::cout<<"\nIntroduzca la coordenada y del primer punto: ";
    std::cin>>y1;

    std::cout<<"\nIntroduzca la coordenada x del segundo punto: ";
    std::cin>>x2;

    std::cout<<"\nIntroduzca la coordenada y del segundo punto: ";
    std::cin>>y2;

    if((x1==x2)&(y1==y2)){
        std::cout<<"\nLos dos puntos dados son iguales, no hay distancia entre ellos";
    }
    else{
        if (x1==x2){
            hip = std::abs(y2-y1);
        }
        else if(y1==y2){
            hip = std::abs(x2-x1);
        }
        else{
                dx = x2-x1;
                dy = y2-y1;
                hip = sqrt((pow(dx,2))+(pow(dy,2)));
                std::cout<<"Popis";
        }
        std::cout<<"\nLa distancia entre el P1 y P2 es de "<<hip<<" unidades";
    }

    return 0;
}