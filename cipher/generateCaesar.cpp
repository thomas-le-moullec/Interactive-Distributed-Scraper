//
// Created by tchikl_h on 4/20/17.
//

#include        <iostream>

int             main(int ac, char **av)
{
    char    c;
    std::string data(av[1]);
    std::string key(av[2]);
    if (ac != 3)
        return (-1);
    data.append("<HTML></HTML>");
    for (int i = 0; i < (int)data.length(); ++i)
    {
        c = data[i] + key[0];
        std::cout << c;
    }
    std::cout << std::endl;
    return (0);
}