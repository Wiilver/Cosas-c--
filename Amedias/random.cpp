#include <iostream>
#include <ctime>

int main()
{
    int rnd;
    srand(time(NULL));

    rnd = rand();

    std::cout<<rnd;

    return 0;
}