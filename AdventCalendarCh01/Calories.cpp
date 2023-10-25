#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> elfCalories; // Store Calories for each Elf
    int currentElfCalories = 0;  // Initialize Calories for the first Elf
    std::string line;

    std::ifstream inputFile("input.txt"); // Open the input file

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            // Empty line indicates the end of one Elf's inventory
            elfCalories.push_back(currentElfCalories);
            currentElfCalories = 0; // Reset Calories for the next Elf
        } else {
            int calories = std::stoi(line);
            currentElfCalories += calories;
        }
    }

    // Handle the last Elf (if there was no trailing empty line)
    if (currentElfCalories > 0) {
        elfCalories.push_back(currentElfCalories);
    }

    inputFile.close(); // Close the input file

    // Find the Elf with the most Calories
    int maxCalories = 0;
    std::sort(elfCalories.begin(), elfCalories.end());
    for (int calories : elfCalories) {
        if (calories > maxCalories) {
            maxCalories = calories;
        }
    }

    std::cout << "The Elf carrying the most Calories has: " << maxCalories << " Calories." << std::endl;
    std::cout << "Top three elves carrying the most calories: " << elfCalories[elfCalories.size() - 1] <<
     ", " << elfCalories[elfCalories.size() - 2] << ", " << elfCalories[elfCalories.size() - 3] << "Total of: " << 
     elfCalories[elfCalories.size() - 1] + elfCalories[elfCalories.size() - 2] + elfCalories[elfCalories.size() - 3] << std::endl;
    

    return 0;
}
