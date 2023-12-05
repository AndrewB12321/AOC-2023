#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <regex>

#define MAXRED 12
#define MAXGREEN 13
#define MAXBLUE 14
std::vector<std::string> getMatches(std::string line, std::smatch& srx, const std::regex& rx);
bool areTrialsValid(std::vector<std::string> trials, const unsigned int max);
int main(int argc, char* argv[]) {
    unsigned int IDTotal = 0;
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
        bool isValid = true;
        getline(input, line);
        //each vector holds a bunch of strings taken from the line formatted as "n color"
        //where n is the number drawn, and color is the color. 
        std::vector<std::string> greenDraws;
        std::vector<std::string> redDraws;
        std::vector<std::string> blueDraws;
        //honestly dont really know what these do, but are needed for the 
        //regex to work properly 
        std::smatch greenStrings;
        std::smatch redStrings;
        std::smatch blueStrings;
        //This actually uses the regex to fill the vectors
        greenDraws = getMatches(line, greenStrings, regex_green);
        redDraws = getMatches(line, redStrings, regex_red);
        blueDraws = getMatches(line, blueStrings, regex_blue);
        /*
        for(auto s:greenDraws){
            std::cout << s << " " << std::endl;
        }
        */
        // isValid starts at 1, anding it with the results means 
        //if one fails, all the other ones fail aswell.
        isValid = isValid && areTrialsValid(greenDraws, MAXGREEN);
        /*
        for(auto s:redDraws){
            std::cout << s << " " << std::endl;
        }
        */
        isValid = isValid && areTrialsValid(redDraws, MAXRED);
        /*
        for(auto s:blueDraws){
            std::cout << s << " " << std::endl;
        }
        */
        isValid = isValid && areTrialsValid(blueDraws, MAXBLUE);
        std::cout << "gameID: " << i << " " << std::boolalpha << line << "\n**this game is valid: " << isValid << "\ncurrent total: " << IDTotal << std::endl << std::endl;
        //if all of the trials of each colors passed, isValid will still be true, if any of them failed it will be 0
        if(isValid) IDTotal += i;
    }

    std::cout << "total ID number Sum = " << IDTotal;
    input.close();
    return 0;
}

// takes in a vector of strings where each string has the form "n color"
// *inportant* line is passed in as a value and not a reference, because I modify the input in this function,
// but need the whole line to stay intact as this proccess gets repeated 3 times per line.
std::vector<std::string> getMatches(std::string line, std::smatch& srx, const std::regex& rx){
    std::vector<std::string> matches;
    while(std::regex_search(line, srx, rx)){
            matches.push_back(srx[0]);
            line = srx.suffix().str();
    }
    return matches;
}

bool areTrialsValid(std::vector<std::string> trials, const unsigned int max) {
    const std::regex regex_digit("\\d+");
    std::smatch match;
    for (auto s:trials) {
        std::regex_search(s, match, regex_digit);
        //std::cout << "*** " << stoi(match[0]) << " > " << max << " ***\n";
        if(stoi(match[0]) > max) return false;
    }
    return true;
}