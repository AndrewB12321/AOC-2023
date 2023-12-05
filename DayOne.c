
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    FILE* calibration; 
    char line[1000];
    int calibrationSum = 0;
    calibration = fopen("calibration.txt", "r");
    if (calibration == NULL) return 1;

    while(fgets(line, sizeof(line), calibration) != NULL){
        int firstDigit = 0, lastDigit = 0;
        int i = 0;
        while(line[i] != '\0'){
            char letter = line[i];
            if(firstDigit ==  0) {
                if(isdigit(letter) != 0) firstDigit = letter - '0';
            }
            if(isdigit(letter) != 0) lastDigit = letter - '0';
            i++;
        }

        calibrationSum += (firstDigit * 10) + lastDigit;


    }

    printf("%d\n", calibrationSum);
    
    return 0;
}

