#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int findStartOfPacketMarker(const std::string& datastream) 
{
    int n = datastream.size();

    if(n < 4) 
    {
        return -1; // Not enough characters to find a marker.
    }

    for(int i = 3; i < n; ++i) 
    {
        if(datastream[i] != datastream[i - 1] &&
            datastream[i] != datastream[i - 2] &&
            datastream[i] != datastream[i - 3] &&
            datastream[i - 1] != datastream[i - 2] &&
            datastream[i - 1] != datastream[i - 3] &&
            datastream[i - 2] != datastream[i - 3]) 
        {
            return i + 1; // +1 because the position is 0-based.
        }
    }

    return -1; // No start-of-packet marker found.
}

int findStartOfMessageMarker(const std::string& datastream) 
{
    int n = datastream.size();

    if (n < 14) 
    {
        return -1; // Not enough characters to find a message marker.
    }

    std::unordered_set<char> distinctChars;

    for(int i = 13; i < n; ++i) 
    {
        // Check if the last 14 characters are all different.
        distinctChars.clear();
        bool allDifferent = true;

        for(int j = 0; j < 14; ++j) 
        {
            if(distinctChars.find(datastream[i - j]) != distinctChars.end()) 
            {
                allDifferent = false;
                break;
            }
            distinctChars.insert(datastream[i - j]);
        }

        if(allDifferent)
        {
            return i + 1; // +1 because the position is 0-based.
        }
    }

    return -1; // No start-of-message marker found.
}

int main() 
{
    std::ifstream file("input.txt");
    if (!file.is_open()) 
    {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::string datastream;
    if (getline(file, datastream)) 
    {
        int result = findStartOfMessageMarker(datastream);
        if (result != -1) 
        {
            std::cout << "The first start-of-packet marker is detected after processing " << result << " characters." << std::endl;
        } else 
        {
            std::cout << "No start-of-packet marker was found in the datastream." << std::endl;
        }
    } 
    else 
    {
        std::cerr << "Failed to read datastream from the input file." << std::endl;
        return 1;
    }

    file.close();
    return 0;
}
