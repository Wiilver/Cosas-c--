#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

int main()
{
    int x;
    while(true)
    {
        if(_kbhit)
        {
            x = _getch();
            std::cout<<x<<'\n';
        }
    }
    return 0;
}