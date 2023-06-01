#include "numbers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static const char* units[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen"
};

static const char* tens[] = {
    "zero",
    "ten",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
};

static const char* biggies[] = {
    "zero",
    "thousand",
    "million",
    "billion",
    "trillion",
    "quadrillion",
    "quintillion",
    "sextillion"
};


char* three_digit_to_str(int num){
    if(num < 0 || num > 999){
        return 0;
    }

    static char buf[100];
    buf[0] = 0;

    if(num > 99){
        strcat(buf, units[num / 100]);
        strcat(buf, " hundred ");
        if(num % 100){
            strcat(buf, "and ");
        }
    }


    int r = num % 100;
    if(r){
        if(r < 20){
            strcat(buf, units[r]);
        }
        else{
            strcat(buf, tens[r / 10]);
            if(r % 10){
                strcat(buf, "-");
                strcat(buf, units[r % 10]);
            }
        }
        strcat(buf, " ");
    }

    int len = strlen(buf);
    char* output = malloc(len + 1);
    strcpy(output, buf);
    return output;
}



char* num_to_str(int num){
    char* output;
    char* tmp;
    static char buf[4000];
    buf[0] = 0;

    if(!num){
        output = malloc(strlen("zero") + 1);
        strcpy(output, "zero");
        return output;
    }

    if(num < 0){
        strcat(buf, "minus ");
        num = -num;
    }

    // a billion
    int helper = 1000000000;
    // power of thousand
    int pot = 3;

    while(pot){
        // three digit number
        int tdn = num / helper;
        if(tdn){
            tmp = three_digit_to_str(tdn);
            strcat(buf, tmp);
            free(tmp);

            strcat(buf, " ");
            strcat(buf, biggies[pot]);
            strcat(buf, " ");
        }

        pot--;
        num %= helper;
        helper /= 1000;
    }

    if(num){
        tmp = three_digit_to_str(num);
        strcat(buf, tmp);
        free(tmp);
    }

    output = malloc(strlen(buf) + 1);
    strcpy(output, buf);
    return output;
}