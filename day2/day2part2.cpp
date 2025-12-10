#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isInvalidPassword(std::string password) {
    for (size_t splitSize = password.length() / 2; splitSize >= 1; --splitSize) {
        if (password.length() % splitSize != 0) {
            continue; // Skip if password length is not divisible by splitSize
        }
        bool allMatch = true;
        std::string firstPart = password.substr(0, splitSize);
        int numParts = password.length() / splitSize;
        for (int part = 1; part < numParts; ++part) {
            std::string currentPart = password.substr(part * splitSize, splitSize);
            if (currentPart != firstPart) {
                allMatch = false;
                break; // Parts do not match
            }
        }
        if (allMatch) {
            return true; // Found a valid split where all parts match
        }
    }
    return false; // No valid splits found
}

int main() {

    std::vector<std::string> ranges;


    std::ifstream inputFile("day2input.txt");
    if (!inputFile) {
        std::cerr << "Unable to open file input.txt";
        return 1; // Exit with error code
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            ranges.push_back(token); 
        }
        
    }

    // for (const auto& range : ranges) {
    //     std::cout << "Stored range: " << range << std::endl;
    // }
    long sum = 0;

    for (const auto& range : ranges) {
        int dashPos = range.find('-');
        std::string start = range.substr(0, dashPos);
        long startNum = std::stol(start);
        std::string end = range.substr(dashPos + 1);
        long endNum = std::stol(end);
        
        for (long num = startNum; num <= endNum; ++num) {
            std::string password = std::to_string(num);
            if (isInvalidPassword(password)) {
                // std::cout << "Valid password found: " << password << std::endl;
                sum+= num;
            }
        }
    }
    std::cout<<sum<<std::endl;
    inputFile.close();
    return 0; // Exit successfully
}