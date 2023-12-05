#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define ROW_LENGTH 10
/* takes in a line from the file and returns
a vector with all the indexes of the symbols on that line
*/
std::vector<int> findSymbolIndexes(std::string s);
int main(int argc, char* argv[]) {
    std::ifstream input;
    std::ofstream temp;
    std::string s1, s2, s3; 
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
        
        s1 = s2;
        s2 = s3;
    }

    input.close();
}

std::vector<int> findSymbolIndexes(std::string s) {
    std::vector<int> indices;
    //std::cout << s << std::endl;
     for(int i = 0; i < s.size() - 1; i++){
        if(s[i] != '.' && !isdigit(s[i])) {
            indices.push_back(i);
        }
     }
     return indices;
}