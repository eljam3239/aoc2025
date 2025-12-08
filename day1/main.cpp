#include <iostream>
#include <fstream>
#include <string>

int moveRight(int startPosition, int changeInPosition, int cardinality) {
    return (startPosition+changeInPosition)%cardinality;
}

int moveLeft(int startPosition, int changeInPosition, int cardinality) {
    return (startPosition-changeInPosition)%cardinality;
}

int main() {
    int counter = 0;
    int position = 50;
    std::ifstream inf{ "inputday1part1.txt" };
    if (!inf) {
        std::cerr << "Error opening file\n";
        return 1;
    }
    std::string strInput;
    while (std::getline(inf, strInput)) {
        // std::cout << stoi(strInput.substr(1)) << std::endl;
        if (strInput[0] == 'R') {
            position = moveRight(position, stoi(strInput.substr(1)), 100);
            if (position == 0) {
                counter++;
            }
        } else if (strInput[0] == 'L') {
            position = moveLeft(position, stoi(strInput.substr(1)), 100);
            if (position == 0) {
                counter++;
            }
        }
    }
    std::cout << counter << std::endl;

    return 0;
    
}