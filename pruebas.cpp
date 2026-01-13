#include <iostream>
#include <array>

int main()
{
    std::array <int, 4> figura = {1,2,3,5};
    if(figura == std::array {1,2,3,4}) std::cout<<"Buenas tardfes";
    return 0;
}