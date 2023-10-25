#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#define WON 6
#define LOST 0
#define DRAW 3

int main()
{
    std::fstream file("input.txt");
    unsigned int totalScore = 0;
    std::string line;

    if(!file.is_open())
    {
        std::cout << "Error: File not found" << std::endl;
        return 1;
    }
    
    while(std::getline(file, line))
    {
        char me = line[2];
        switch (me)
        {
        case 88:
            if(line[0] == 'A')
            {
                totalScore += LOST + 3;
            }
            else if(line[0] == 'B')
            {
                totalScore += LOST + 1;
            }
            else
            {
                totalScore += LOST + 2;
            }
            break;
        case 89:
            if(line[0] == 'A')
            {
                totalScore += DRAW + 1;
            }
            else if(line[0] == 'B')
            {
                totalScore += DRAW + 2;
            }
            else
            {
                totalScore += DRAW + 3;
            }
            break;
        case 90:
            if(line[0] == 'A')
            {
                totalScore += WON + 2;
            }
            else if(line[0] == 'B')
            {
                totalScore += WON + 3;
            }
            else
            {
                totalScore += WON + 1;
            }
            break;
        default:
            std::cout << "Error: Invalid input" << std::endl;
            break;
        }
    }
    file.close();
    std::cout << totalScore << std::endl;

    return 0;
}