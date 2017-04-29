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
    if (ac != 2)
        return (-1);
    data = getFileContent(data);
    for (int i = 0; i < (int)data.size(); i++)
    {
      if (data[i] >= 0 && data[i] < 127)
	c = 127 - data[i];
      std::cout << c;
    }
    std::cout << std::endl;
    return (0);
}
