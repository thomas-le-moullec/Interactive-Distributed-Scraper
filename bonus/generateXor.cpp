//
// Created by tchikl_h on 4/20/17.
//

#include        <iostream>
#include        <fstream>

std::string     getFileContent(std::string const &fileName)
{
    std::string content;
    std::string line;
    std::ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile,line))
            content.append(line + '\n');
        myfile.close();
    }
    else
        std::cout << "Unable to open file" << std::endl;
    return (content);
}

int             main(int ac, char **av)
{
    char        c;
    std::string data(av[1]);
    std::string key(av[2]);
    if (ac != 3)
        return (-1);
    data = getFileContent(data);
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (key.length() == 1)
            c = data[i] ^ key[0];
        else if (i % 2 == 0)
            c = data[i] ^ key[0];
        else
            c = data[i] ^ key[1];
        std::cout << c;
    }
    std::cout << std::endl;
    return (0);
}