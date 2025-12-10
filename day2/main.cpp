#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isInvalidPassword(std::string password) {
    if (password.length() %2 != 0) {
        return false; // Password length must be even
    }
    std::string firstHalf = password.substr(0, password.length() / 2);
    std::string secondHalf = password.substr(password.length() / 2);
    return firstHalf == secondHalf;
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
        // std::cout << "Range from " << start << " to " << end << std::endl;
        if ((start.length() %2 != 0) && (end.length() %2 != 0)) {
            continue; // Skip ranges with odd-length numbers
        }
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