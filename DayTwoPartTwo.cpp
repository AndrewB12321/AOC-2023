/***********************************************************************
                            Complete solution
************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

#define MAXRED 12
#define MAXGREEN 13
#define MAXBLUE 14
std::vector<std::string> getMatches(std::string line, std::smatch& srx, const std::regex& rx);
int LowestValue(std::vector<std::string> trials) ;
int main(int argc, char* argv[]) {
    unsigned int powerTotal = 0;
    const std::regex regex_green("\\d+ green");
    const std::regex regex_red("\\d+ red");
    const std::regex regex_blue("\\d+ blue");
    std::ifstream input;
    std::string line; 
    if (argc != 2) {
        std::cout << "progam takes one arg for input file";
        exit(1);
    }
    input.open(argv[1]);
    // main loop, 100 total games starting at 1
    for(int i = 1; i <= 100; i++){
        getline(input, line);
        std::vector<std::string> greenDraws;
        std::vector<std::string> redDraws;
        std::vector<std::string> blueDraws;
        std::smatch greenStrings;
        std::smatch redStrings;
        std::smatch blueStrings;
        greenDraws = getMatches(line, greenStrings, regex_green);
        redDraws = getMatches(line, redStrings, regex_red);
        blueDraws = getMatches(line, blueStrings, regex_blue);
        /*
        for(auto s:greenDraws){
            std::cout << s << " " << std::endl;
        }
        */
        int greenSmallest = LowestValue(greenDraws);
        /*
        for(auto s:redDraws){
            std::cout << s << " " << std::endl;
        }
        */
        int redSmallest = LowestValue(redDraws);
        /*
        for(auto s:blueDraws){
            std::cout << s << " " << std::endl;
        }
        */
        int blueSmallest = LowestValue(blueDraws);
        std::cout << "gameID: " << i << std::endl;
        std::cout << "green smallest value: " << greenSmallest << std::endl;  
        std::cout << "red smallest value: " << redSmallest << std::endl;  
        std::cout << "blue smallest value: " << blueSmallest << std::endl;  

        powerTotal += greenSmallest * redSmallest * blueSmallest;
    }

    std::cout << "total Power number Sum = " << powerTotal;
    input.close();
    return 0;
}

// takes in a vector of strings where each string has the form /d+ color
std::vector<std::string> getMatches(std::string line, std::smatch& srx, const std::regex& rx){
    std::vector<std::string> matches;
    while(std::regex_search(line, srx, rx)){
            matches.push_back(srx[0]);
            line = srx.suffix().str();
    }
    return matches;
}
//The lowest value possible, will be the maximum of all the values of a certain color
int LowestValue(std::vector<std::string> trials) {
    const std::regex regex_digit("\\d+");
    std::smatch match;
    int lowestValue = 0;
    for (auto s:trials) {
        std::regex_search(s, match, regex_digit);
        //std::cout << "*** " << stoi(match[0]) << " > " << max << " ***\n";
        if(stoi(match[0]) > lowestValue) lowestValue = stoi(match[0]);
    }
    return lowestValue;
}