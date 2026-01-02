/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcassi-d <gcassi-d@42urduliz.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:16:45 by gcassi-d          #+#    #+#             */
/*   Updated: 2025/12/24 14:02:12 by gcassi-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

size_t ft_strlen(const char* str)
{
	size_t n = 0;

	while (str[n])
		n++;
	return n;
}

bool getContent(std::istream& is, std::string& str)
{
    str.clear();
    char c;
    while (is.get(c)) 
    {
		if (is.fail())
			return 1;
		str += c;
	}
    return 0;
}  

int main(int ac, char **av)
{
	if (ac != 4 || av[1][0] == '\0' || av[2][0] == '\0' || av[3][0] == '\0')
		return (1);
	
	std::ifstream file(av[1]);
	std::string replaceFileName;
	std::string fileContents;
	int i = 0;
	size_t n = ft_strlen(av[2]);

	if (file.fail())
	{
		std::cout << "failed to open given file";
		return 1;
	}
	if (getContent(file, fileContents))
	{
		std::cout << "failed to read given file";
		return 1;
	}	
	file.close();
	replaceFileName += av[1];
	replaceFileName += ".replace";
	std::ofstream replace(replaceFileName);

	if (replace.fail())
	{
		std::cout << "failed to create d.replace file";
		return 1;
	}

	while (i < (int)fileContents.size() - (int)n + 1)
	{
		if (!fileContents.compare(i, n, av[2]))
		{
			replace << av[3];
			i += n;
		}
		else
		{
			replace << fileContents[i];
			i++;
		}
	}
	while (i < (int)fileContents.size())
	{
		replace << fileContents[i];
		i++;
	}
	replace.close();
}