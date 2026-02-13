#include <iostream>
#include <vector>


int main()
{
    std::vector<std::vector<std::string>> matriz;

    for(int i = 0; i < 5; i++)
    {
        std::vector<std::string> arreglo;
        for(int j = 0; j < 5; j++) arreglo.push_back(" - ");
        matriz.push_back(arreglo);
    }

    for(int i = 0; i < matriz.size(); i++)
    {
        for(int j = 0; j < matriz[0].size(); j++) std::cout<<matriz[i][j];
        std::cout<<'\n';
    }

    std::cout<<"Hello world";
    return 0;
}