#include <iostream>
#include <cmath>

int main(){
    double a = 3.4;
    double b = 2.9;
    double c = -2.5;
    double z;

    //Devuelve el mayor
    z = std::max(a,b);
    std::cout<<z<<"\n\n";

    //Devuelve el minimo
    z = std::min(a,b);
    std::cout<<z<<"\n\n";
    
    //Devuelve el valor absoluto
    z = std::abs(c);
    std::cout<<z<<"\n\n";

    //Apartir de aqui usa la libreria de cmath

    //Devuelve la potencia
    z = pow(a,b);
    std::cout<<z<<"\n\n";

    //Devuelve la raiz
    z = sqrt(a);
    std::cout<<z<<"\n\n";

    //Redondea
    z = round(c);
    std::cout<<z<<"\n\n";

    //Redondea para arriba
    z = ceil(a);
    std::cout<<z<<"\n\n";

    //Redondea para abajo
    z = floor(b);
    std::cout<<z<<"\n\n";

    //igual la documentacion sale en cmath

    return 0;
}