/***********************************************************************
Complete solution, although if there were any symbols in the first and 
line this program would not account for that, but there werent any 
in my puzzle input so I didnt worry about it

************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <numeric>
#define ROW_LENGTH 140
/* takes in a line from the file and returns
a vector with all the indexes of the symbols on that line
*/
std::vector<int> findSymbolIndexes(std::string s);

int getSum(std::string s1, std::string s2, std::string s3, int index);

int getWholeNumber(std::string s, int index);


int main(int argc, char* argv[]) {
    std::ifstream input;
    std::ofstream temp;
    std::string s1, s2, s3; 
    int totalSum = 0;
    if (argc != 2) {
        std::cout << "progam takes one arg for input file";
        exit(1);
    }
    input.open(argv[1]);
    temp.open("temp.txt");

    getline(input, s1);
    getline(input, s2);
    while(getline(input, s3)){
        std::vector<int> indices = findSymbolIndexes(s2);
        for(auto i:indices) {
            totalSum += getSum(s1, s2, s3, i);
        }
        s1 = s2;
        s2 = s3;
    
    }

    std::cout << "total sum is: " << totalSum;
        


    input.close();
}

std::vector<int> findSymbolIndexes(std::string s) {
    std::vector<int> indices;
    //std::cout << s << std::endl;
     for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == '*') {
            indices.push_back(i);
        }
     }
     return indices;
}

int getSum(std::string s1, std::string s2, std::string s3, int index) {
    std::set<int> validNumbers;
    int numberProduct = 0;
    for(int i = index - 1; i <= index + 1; i++){
        if(isdigit(s1[i])) validNumbers.insert(getWholeNumber(s1, i));
    }
    for(int i = index - 1; i <= index + 1; i++){
        if(isdigit(s2[i])) validNumbers.insert(getWholeNumber(s2, i));
    }
    for(int i = index - 1; i <= index + 1; i++){
        if(isdigit(s3[i])) validNumbers.insert(getWholeNumber(s3, i));
    }
    if(validNumbers.size() == 2){
        numberProduct = std::accumulate(validNumbers.begin(), validNumbers.end(), 1, std::multiplies<int>());
    }
    return numberProduct;
}
/*
    takes the index of a digit,
    and gets the whole number surrounding that digit
*/
int getWholeNumber(std::string s, int index){
    //std::cout << s << " index: " << index << std::endl;
    int i = index;
    int j = 0;
    int wholeNumber = 0;
    //finds the index of the last digit in the number
    while(isdigit(s[i])) i++;
    i--;
    //std::cout << "index of last digit is " << i << std::endl;
    while(isdigit(s[i])) {
        wholeNumber += (s[i] - '0') * pow(10, j);
        j++;
        i--;
    }
    return wholeNumber;
}