#include <stdio.h>
#include <tgmath.h>
#include <cmath>

float probabilty(float mean, float stdv,float x, char sign); 

int main(int argc, char* argv[]) {
    printf("problem 1a: %f\n", probabilty(0, 1, 2, '<'));
    printf("problem 1b: %f\n", probabilty(0, 1, 3, '>'));
    printf("problem 2a: %f\n", probabilty(-1, 3, 2, '<'));
    printf("problem 2b: %f\n", probabilty(-1, 3, 3, '>'));
    printf("problem 3a: %f\n", probabilty(3, .5, 2, '<'));
    printf("problem 3b: %f\n", probabilty(3, .5, 4, '>'));
    printf("problem 4b: %f\n", probabilty(1, 5, -1, '>') - probabilty(1, 5, 2, '>'));
    return 0;
}


float probabilty(float mean, float stdv,float x, char sign) {
    if (sign == '<') {
        float arg = (x-mean) / (stdv * sqrt(2));
        return (1+erf(arg)) / 2;
    }
    if (sign == '>') {
        float arg = (x-mean) / (stdv * sqrt(2));
        return (1-erf(arg)) / 2;
    }
    else return -1;


}