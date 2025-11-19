#include <iostream>

typedef std::string str;

//Se usa mas esta segunda manera
using num = int;

int main(){
    str saludo = "Buenas tardes";
    num A = 2;

    std::cout << saludo<<A;

    return 0;
}