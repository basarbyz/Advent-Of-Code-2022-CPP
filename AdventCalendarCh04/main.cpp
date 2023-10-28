#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// Function to check if one range fully contains the other
bool isFullyContained(const std::pair<int, int>& range1, const std::pair<int, int>& range2) {
    return (range1.first <= range2.first) && (range1.second >= range2.second);
}

bool doRangesOverlap(const std::pair<int, int>& range1, const std::pair<int, int>& range2) {
    return (range1.first <= range2.second) && (range2.first <= range1.second);
}

int main() {
    std::vector<std::string> input;
    std::fstream file("input.txt");
    std::string line;
    
    while(std::getline(file, line)) 
    {
        input.push_back(line);
    }

    int fullyContainedCount = 0;
    int overlappingPairsCount = 0;

    for (const std::string& line : input) {
        std::istringstream ss(line);
        std::string token;
        std::vector<std::pair<int, int>> ranges;

        while (std::getline(ss, token, ',')) {
            std::istringstream rangeStream(token);
            std::pair<int, int> range;
            rangeStream >> range.first;
            rangeStream.ignore(1); // Ignore the dash '-'
            rangeStream >> range.second;
            ranges.push_back(range);
        }
        /*
        // Check for fully contained ranges in each pair
        if (ranges.size() == 2) 
        {
            if (isFullyContained(ranges[0], ranges[1]) || isFullyContained(ranges[1], ranges[0])) 
            {
                fullyContainedCount++;
            }
        }
        */
        for (size_t i = 0; i < ranges.size(); ++i) 
        {
            for (size_t j = i + 1; j < ranges.size(); ++j)
             {
                if (doRangesOverlap(ranges[i], ranges[j]))
                {
                    overlappingPairsCount++;
                }
            }
        }
    }

    //std::cout << "Number of assignment pairs where one range fully contains the other: " << fullyContainedCount << std::endl;
    std::cout << "Number of assignment pairs where one range fully contains the other: " << overlappingPairsCount << std::endl;


    return 0;
}
