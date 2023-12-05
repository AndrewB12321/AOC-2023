
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char ONE[4] = "one";
const char TWO[4] = "two";
const char THREE[6] = "three";
const char FOUR[5] = "four";
const char FIVE[5] = "five";
const char SIX[4] = "six";
const char SEVEN[6] = "seven";
const char EIGHT[6] = "eight";
const char NINE[5] = "nine";

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
                else {
                    switch(letter){
                        case 'o':
                            char one[4];
                            one[0] = 'o';
                            for(int j = 1; j <= 2; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    one[j] = line[i + j];
                                }
                            }
                            one[3] = '\0';
                            if(strcmp(one, ONE) == 0) firstDigit = 1;
                            break;
                        case 't':
                            char two[4];
                            char three[6];
                            two[0] = 't';
                            three[0] = 't';
                            for(int j = 1; j <= 2; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    two[j] = line[i + j];
                                }
                            }
                            two[3] = '\0';
                            if(strcmp(two, TWO) == 0) {
                                firstDigit = 2;
                                break;
                            }
                            for(int j = 1; j <= 4; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    three[j] = line[i + j];
                                }
                            }
                            three[5] = '\0';
                            if(strcmp(three, THREE) == 0) firstDigit = 3;
                            break;
                        case 'f':
                            char fourfive[5];
                            fourfive[0] = 'f';
                            for(int j = 1; j <= 3; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    fourfive[j] = line[i + j];
                                }
                            }
                            fourfive[4] = '\0';
                            //printf("*********\n\n\nfourfive = %s\n\n\n*********\n", fourfive);
                            if(strcmp(fourfive, FOUR) == 0) firstDigit = 4;
                            if(strcmp(fourfive, FIVE) == 0) firstDigit = 5;
                            break;
                        case 's':
                            char six[4];
                            char seven[6];
                            six[0] = 's';
                            seven[0] = 's';
                            for(int j = 1; j <= 2; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    six[j] = line[i + j];
                                }
                            }
                            six[3] = '\0';
                            if(strcmp(six, SIX) == 0) {
                                firstDigit = 6;
                                break;
                            }
                            for(int j = 1; j <= 4; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    seven[j] = line[i + j];
                                }
                            }
                            seven[5] = '\0';
                            if(strcmp(seven, SEVEN) == 0) firstDigit = 7;
                            break;
                        case 'e':
                            char eight[6];
                            eight[0] = 'e';
                            for(int j = 1; j <= 4; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    eight[j] = line[i + j];
                                }
                            }
                            eight[5] = '\0';
                            if(strcmp(eight, EIGHT) == 0) firstDigit = 8;
                            break;
                        case 'n':
                            char nine[5];
                            nine[0] = 'n';
                            for(int j = 1; j <= 3; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    nine[j] = line[i + j];
                                }
                            }
                            nine[4] = '\0';
                            if(strcmp(nine, NINE) == 0) firstDigit = 9;
                            break;
                    }
                }
            }

            if(isdigit(letter) != 0) lastDigit = letter - '0';
                else {
                    switch(letter){
                        case 'o':
                            char one[4];
                            one[0] = 'o';
                            for(int j = 1; j <= 2; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    one[j] = line[i + j];
                                }
                            }
                            one[3] = '\0';
                            if(strcmp(one, ONE) == 0) lastDigit = 1;
                            break;
                        case 't':
                            char two[4];
                            char three[6];
                            two[0] = 't';
                            three[0] = 't';
                            for(int j = 1; j <= 2; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    two[j] = line[i + j];
                                }
                            }
                            two[3] = '\0';
                            if(strcmp(two, TWO) == 0) {
                                lastDigit = 2;
                                break;
                            }
                            for(int j = 1; j <= 4; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    three[j] = line[i + j];
                                }
                            }
                            three[5] = '\0';
                            if(strcmp(three, THREE) == 0) lastDigit = 3;
                            break;
                        case 'f':
                            char fourfive[5];
                            fourfive[0] = 'f';
                            for(int j = 1; j <= 3; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    fourfive[j] = line[i + j];
                                }
                            }
                            fourfive[4] = '\0';
                            if(strcmp(fourfive, FOUR) == 0) lastDigit = 4;
                            if(strcmp(fourfive, FIVE) == 0) lastDigit = 5;
                            break;
                        case 's':
                            char six[4];
                            char seven[6];
                            six[0] = 's';
                            seven[0] = 's';
                            for(int j = 1; j <= 2; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    six[j] = line[i + j];
                                }
                            }
                            six[3] = '\0';
                            if(strcmp(six, SIX) == 0) {
                                lastDigit = 6;
                                break;
                            }
                            for(int j = 1; j <= 4; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    seven[j] = line[i + j];
                                }
                            }
                            seven[5] = '\0';
                            if(strcmp(seven, SEVEN) == 0) lastDigit = 7;
                            break;
                        case 'e':
                            char eight[6];
                            eight[0] = 'e';
                            for(int j = 1; j <= 4; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    eight[j] = line[i + j];
                                }
                            }
                            eight[5] = '\0';
                            if(strcmp(eight, EIGHT) == 0) lastDigit = 8;
                            break;
                        case 'n':
                            char nine[5];
                            nine[0] = 'n';
                            for(int j = 1; j <= 3; j++){
                                if(line[i + j] == '\0') break;
                                else {
                                    nine[j] = line[i + j];
                                }
                            }
                            nine[4] = '\0';
                            if(strcmp(nine, NINE) == 0) lastDigit = 9;
                            break;
                    }
                }
            i++;
        }
        printf("%s \n %d, %d\n\n", line, firstDigit, lastDigit);

        calibrationSum += (firstDigit * 10) + lastDigit;


    }

    printf("%d\n", calibrationSum);
    
    return 0;
}
