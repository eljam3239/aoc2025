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
	int distance = stoi(strInput.substr(1));
        if (strInput[0] == 'R') {
	    for (int i = 1; i<=distance; i++) {
	        position = (position+1)%100;
		if (position == 0) {
    		    counter++;
		}
	    }
            //position = moveRight(position, stoi(strInput.substr(1)), 100);
	}    
        if (strInput[0] == 'L') {
	    for (int i = 1;i<=distance;i++) {
	        position = (position-1+100)%100;
	        if (position == 0) {
		    counter++;
		}
	    }
	}
	/**	
        } else if (strInput[0] == 'L') {
	    counter += std::truncf(((position+stoi(strInput.substr(1)))/100));		
	    position = moveLeft(position, stoi(strInput.substr(1)), 100);
            

            if (position == 0) {
                counter++;
            }
        }
	*/
    }
    std::cout << counter << std::endl;

    return 0;
    
}
