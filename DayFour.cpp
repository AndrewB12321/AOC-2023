/******************************************************************
                    Work in Progress

******************************************************************/
#define WINNING_NUMBER_START_INDEX 10
#define WINNING_NUMBER_END_INDEX 28
#define MY_NUMBER_START_INDEX 32

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ifstream input;
    std::string line;
    
    if(argc != 2) return -1;
    input.open(argv[1]);

    while(getline(input, line)){
        line = line.substr(WINNING_NUMBER_START_INDEX, line.length());
        std::string myNumbers, winningNumbers;
        winningNumbers = line.substr(0, WINNING_NUMBER_END_INDEX);
        myNumbers = line.substr(MY_NUMBER_START_INDEX, line.length());
        std::cout << winningNumbers << " " << myNumbers << std::endl;
        /*
        we dont really even need to seperate them, its just the easiest way to
        get the numbers in a way thats easy to parse. 
        */
        for(int i = 0; i < winningNumbers.length() - 1; i++)

    }

    
    return 0;
}