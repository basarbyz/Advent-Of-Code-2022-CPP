#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

int getItemPriority(char item)
{
    if( item >= 'a' && item <= 'z')
    {
        return item - 'a' + 1;
    }
    if( item >= 'A' && item <= 'Z')
    {
        return item - 'A' + 27;
    }
    return 0;
}

int main()
{
    std::fstream file("input.txt");
    std::vector<std::string> rucksacks;
    int totalPriority = 0;

    while(!file.eof())
    {
        std::string line;
        std::getline(file, line);
        rucksacks.push_back(line);
    }
    /*                      FIRST PART
    for(const std::string& rucksack : rucksacks)
    {
        int firstCompartment[53] = {0};
        int secondCompartment[53] = {0};

        for(int i = 0; i < rucksack.size() / 2; i++)
        {
            int item = getItemPriority(rucksack[i]);
            firstCompartment[item]++;
        }
        for(int i = rucksack.size() / 2; i < rucksack.size(); i++)
        {
            int item = getItemPriority(rucksack[i]);
            secondCompartment[item]++;
        }

        for(int i = 1; i < 53; i++)
        {
            if(firstCompartment[i] > 0 && secondCompartment[i] > 0)
            {
                totalPriority += i;
            }
        }
    }
    */
    std::string line;
    while(std::getline(file, line))
    {
        std::string group1 = line;

        std::getline(file, line);
        std::string group2 = line;

        std::getline(file, line);
        std::string group3 = line;

        char commonLetter;

        for(int i = 0; i < group1.size(); i++)
        {
            for(int j = 0; j < group2.size(); j++)
            {
                for(int k = 0; k < group3.size(); k++)
                {
                    if(group1[i] == group2[j] && group1[i] == group3[k])
                    {
                        commonLetter = group1[i];
                    }
                }
            }
        }
        totalPriority += getItemPriority(commonLetter);


    }
    std::cout << totalPriority << std::endl;


    return 0;
}