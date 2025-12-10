#include <iostream>

int main(){
    //Estas son unas cosas rarisimas para resumir codigo, no me gustan mucho visualmente, pero puede servir

    int edad = 10;

    edad <18 ? std::cout<<"Eres menor de edad" : std::cout<<"Eres mayor de edad";

    std::cout<<(edad<18 ? "Eres menor de edad" : "Eres mayor de edad");

    return 0;
}