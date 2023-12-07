 /******************************************************************
                    Complete solution

******************************************************************/
#define WINNING_NUMBER_START_INDEX 10
#define WINNING_NUMBER_END_INDEX 29
#define MY_NUMBER_START_INDEX 32

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ifstream input;
    std::string line;
    unsigned totalPoints = 0;
    
    if(argc != 2) return -1;
    input.open(argv[1]);
    /*
    plan is to make use of the properties of a set to not really
    have to parse much. we dont need to worry about which numbers
    are winning numbers or numbers we choose, we can take a whole line
    as one set, and all the winning numbers are the numbers that occur
    twice.
    */
    while(getline(input, line)){
        line = line.substr(WINNING_NUMBER_START_INDEX, line.length());
        std::string myNumbers, winningNumbers;
        std::map<int, int> numbers;
        winningNumbers = line.substr(0, WINNING_NUMBER_END_INDEX);
        myNumbers = line.substr(MY_NUMBER_START_INDEX, line.length());
        //std::cout << winningNumbers << " " << myNumbers << std::endl;
        /*
        we dont really even need to seperate them, its just the easiest way to
        get the numbers in a way thats easy to parse because I dont have to worry
        about the line in the middle 
        */
        for(int i = 0; i < winningNumbers.length(); i+= 3) {
            char cstr[2];
            cstr[0] = winningNumbers[i];
            cstr[1] = winningNumbers[i + 1];
            std::string num(cstr);
            //we dont need to check for duplicates yet
            //because there will never be any in the first list
            numbers.insert(std::pair(stoi(num), 1));
        }
        for(int i = 0; i < myNumbers.length() - 1; i+= 3) {
            char cstr[2];
            cstr[0] = myNumbers[i];
            cstr[1] = myNumbers[i + 1];
            std::string num(cstr);
            if(numbers.find(stoi(num)) == numbers.end()) {
                numbers.insert(std::pair(stoi(num), 1));
            } else {
                numbers[stoi(num)] = 2;
            }
        }
        //lamba increments cardValue if the number appears twice
        int cardValue = count_if (numbers.begin(), numbers.end(), 
        [](std::pair<int, int> elem){
            if(elem.second == 2) return 1;
            else return 0;
        });
        //total card value = 2^{n-1}
        totalPoints += pow(2, cardValue - 1);
    }

    std::cout << "*****************************\n" << "total sum is: " << totalPoints;

    
    return 0;
}