#include <iostream>

//Esto resulto ser mas que nada util para agrupar las variables
namespace variablres{
    int x = 1;
    int y = 2;
    int z = 3;
}

int main(){
    using namespace variablres;

    std::cout<<"Buenas tardes"<<x<<y<<z;
    
    std::string nombre;
    int a;    
    int b;
    
    std::cout<<"\nPor favor ingresa el primero de tus numeros enteros: ";
    std::cin>> a;
    
    std::cout<<"\nAhora por favor ingrese el segundo: ";
    std::cin>>b;
    
    std::cout<<"\nEl producto de multiplicar ambos numeros es "<<a*b;
    std::cout<<"\nEl cociente de dividirlos entre si es de "<<a/b<<" con un residuo de "<<a%b;
    std::cout<<"\nSi los quisieras dividir al reves entonces seria "<<b/a<<" como resultado y "<<b%a<<" como residuo";
    std::cout<<"\nLa suma entre ambos es de "<<a+b;
    std::cout<<"\nLa resta del primero al segundo es de "<<a-b;
    std::cout<<"\nLa resta del segundo al primero es de "<<b-a;
    
    //La funcion getline es porque al hacer cin solo lee hasta el primer espacio
    //Hay un problema curioso y es que si tenemos en el buffer un salto de linea del cin, getline lo detecta y entonces no te deja introducir nada
    //Para evitar esto hay que usar la estraccion de los espacios blancos (ws) y la variable
    std::cout<<"\n\nPor favor, ingrese su nombre completo: ";
    std::getline(std::cin >> std::ws, nombre);
    std::cout<<"\nTu nombre es :"<<nombre;
    
    return 0;
}