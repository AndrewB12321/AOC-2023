#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main(int argc, char* argv[]) {
    std::ifstream input;
    std::ofstream temp;
    std::string line; 
    if (argc != 2) {
        std::cout << "progam takes one arg for input file";
        exit(1);
    }
    input.open(argv[1]);
    temp.open("temp.txt");

    while(getline(input,line)) {
        for(int i = 0; i < 141; i++){
            if(isdigit(line[i])) temp << i;
            else temp << line[i];
        }
        temp << "\n";
    }

    input.close();
}