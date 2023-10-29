#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

void part1(vector<stack<char>>& stacks , int amountToMove, int sourceStack, int destStack);
void part2(vector<stack<char>>& stacks, int amountToMove, int sourceStack, int destStack);

int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> lines;
    std::string line;

    if(!file.is_open()){
        std::cout << "File not found" << std::endl;
        return 0;
    }

    while (getline(file, line))
    {
        lines.push_back(line);
    }

    int middleLine;
    for (int i = 0; i < lines.size(); i++)
    {
        if (lines[i].length() == 0)
        {
            middleLine = i;
            break;
        }
    }

    std::vector<std::stack<char>> stacks;
    std::string stackNumbersLine = lines[middleLine - 1];
    
    for(int i = 0; i < stackNumbersLine.size(); i++)
    {
        if(stackNumbersLine[i] == ' ')
        {
            continue;
        }

        std::stack<char> stackForOneColumn;

        for(int j = middleLine - 2; j >= 0; j--)
        {
            if(lines[j][i] == ' ')
            {
                break;
            }
            stackForOneColumn.push(lines[j][i]);
        }

        stacks.push_back(stackForOneColumn);
    }
    
    for(int i = middleLine + 1; i < lines.size(); i++)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::stringstream ss(lines[i]);

        while (getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        int amountToMove = stoi(tokens[1]);
        int sourceStack = stoi(tokens[3]) - 1;
        int destStack = stoi(tokens[5]) - 1;

        //part1(stacks, amountToMove, sourceStack, destStack);
        part2(stacks, amountToMove, sourceStack, destStack);
    }

    for(int i = 0; i < stacks.size(); i++)
    {
        cout << stacks[i].top();
    }

    return 0;
}

void part1(vector<stack<char>>& stacks, int amountToMove, int sourceStack, int destStack)
{
    for (int s = 0; s < amountToMove; s++)
    {
        char ch = stacks[sourceStack].top();
        //cout << "moving " << ch << " from stack " << sourceStack << " to stack " << destStack << endl;
        stacks[sourceStack].pop();
        stacks[destStack].push(ch);
    }
}

void part2(vector<stack<char>>& stacks, int amountToMove, int sourceStack, int destStack)
{
    stack<char> newStack = stack<char>();
    for (int s = 0; s < amountToMove; s++)
    {
        char ch = stacks[sourceStack].top();
        stacks[sourceStack].pop();
        newStack.push(ch);
    }

    while (!newStack.empty())
    {
        char ch = newStack.top();
        newStack.pop();
        stacks[destStack].push(ch);
    }
}
