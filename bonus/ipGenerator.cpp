//
// Created by tchikl_h on 4/26/17.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void    createIp()
{
    std::cout << rand() % 255;
    std::cout << ".";
    std::cout << rand() % 255;
    std::cout << ".";
    std::cout << rand() % 255;
    std::cout << ".";
    std::cout << rand() % 255;
}

int     main(int ac, char **av)
{
    (void)av;
    char c;
    std::srand(std::time(0));
    if (ac != 2)
        return (-1);
    for (int i = 0; i != atoi(av[1]); ++i)
    {
        std::cout << " ";
        createIp();
        std::cout << " ";
        int max = rand() % 100;
        for (int nb = 0; nb != max; ++nb)
        {
            c = 32 + rand() % 94;
            std::cout << c;
        }
    }
    return (0);
}