#include <iostream>
#include <cmath>

int main(){
    double n1,n2,res;
    bool Nosabeescribir = false;
    int opc;
    std::cout<<
    "Esta es una calculadora mal hecha, por favor, seleccione una de las siguientes opciones :\n"<<
    "1.- Suma\n"
    "2.- Resta\n"
    "3.- Producto\n"
    "4.- Division\n"
    "5.- Potencia\n"
    "6.- Raiz cuadrada\n"
    "Opcion : ";
    std::cin>>opc;

    if ((opc>=1)&(opc<=4)){
        std::cout<<"\nIntroduzca el valor del primer numero : ";
        std::cin>>n1;

        std::cout<<"\nIntroduzca el valor del segundo numero : ";
        std::cin>>n2;
        
        switch(opc){
            case 1:
                res = n1+n2;
                break;
            case 2:
                res = n1-n2;
                break;
            case 3:
                res = n1*n2;
            case 4:
                if(n2==0){
                    std::cout<<"\nHermano, no se puede dividir entre 0";
                    Nosabeescribir = true;
                }
                else{
                    res = n1/n2;
                }
                break;
        }
    }
    else{
        switch(opc){
            case 5:
                std::cout<<"\nIntroduzca el numero que quiere elevar : ";
                std::cin>>n1;

                std::cout<<"\nIntroduzca a que potencia desea elevarlo : ";
                std::cin>>n2;

                res = pow(n1,n2);
                break;
            case 6:
                std::cout<<"\nIntroduzca a que numero quiere sacarle raiz : ";
                std::cin>>n1;
                if (n1<0){
                    Nosabeescribir = true;
                    std::cout<<"\nA ser imaginario a tu perra casa hermano, aqui solo los reales";
                }
                res = sqrt(n1);
                break;
            default:
                Nosabeescribir = true;
                std::cout<<"\nHermano, no lo lograste";
                break;
        }
    }
    if (not Nosabeescribir){
        std::cout<<"\nEl resultado de su operacion fue de "<<res;
    }

   return 0; 
}