#include <iostream>

namespace distintas{
    int x = 10;
    double y = 3;
    double z = y-x;
}

int main(){
    const int x = 12;
    double y = 7.5;
    double z = x-y;
    
    std::string saludo = "Buenas tardes, ";
    std::string explicacion = "sabias tu que la resta de ";
    std::string mas = " menos ";
    std::string igual = " es igual a ";
    
    std::cout<<saludo<<explicacion<<distintas::x<<mas<<distintas::y<<igual<<distintas::z;
    return 0;
}