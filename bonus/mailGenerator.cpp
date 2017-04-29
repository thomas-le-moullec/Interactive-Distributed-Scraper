//
// Created by tchikl_h on 4/26/17.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

void    createEmail()
{
    char c;
    int     nb1 = rand() % 10;
    int     nb2 = rand() % 10;
    int     nb3 = rand() % 5;

    for (int i = 0; i != nb1; ++i)
    {
        c = 97 + rand() % 26;
        std::cout << c;
    }
    std::cout << ".";
    for (int i = 0; i != nb2; ++i)
    {
        c = 97 + rand() % 26;
        std::cout << c;
    }
    std::cout << "@";
    for (int i = 0; i != nb3; ++i)
    {
        c = 97 + rand() % 26;
        std::cout << c;
    }
    std::cout << ".";
    for (int i = 0; i != 2; ++i)
    {
        c = 97 + rand() % 26;
        std::cout << c;
    }
}

int     main(int ac, char **av)
{
    char c;
    (void)av;
    std::srand(std::time(0));
    if (ac != 2)
        return (-1);
    for (int i = 0; i != atoi(av[1]); ++i)
    {
        std::cout << " ";
        createEmail();
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