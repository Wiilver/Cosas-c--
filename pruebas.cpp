#include <iostream>
#include <vector>
#include <conio.h>

int main()
{
    while(true)
    {
        if(_kbhit())
        {
            int num = _getch();
            std::cout<<num<<'\n';
        }
    }
    return 0;
}