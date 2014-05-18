//
//  main.c
//  hw1
//
//  Created by Thomas Hocking on 2/9/14.
//  Copyright (c) 2014 Thomas Hocking. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int factor_power(int,int);
int checkPrime(int);

int main(int argc, const char * argv[])
{
    int userNum = 0;
    int isPrime = 0;
    printf("Please enter in a number: ");
    scanf("%d", &userNum);
    
    int i;
    for (i = 2; i < userNum; i++) {
        if (userNum % i == 0) {
            isPrime = 0;
            break;
        }else{
            isPrime = 1;
        }
    }
    
    
    if (isPrime) {
        printf("%d^1\n", userNum);
    } else {
        int divisor = 2;
        int powerOfDivisor = 0;
        while (userNum != 1) {
            powerOfDivisor = factor_power(userNum, divisor);
            if (powerOfDivisor != 0) {
                int divisorRaisedToPowerOfDivisor = 1;
                int i;
                for (i = 0; i < powerOfDivisor; i++) {
                    divisorRaisedToPowerOfDivisor *= divisor;
                }
                printf("%d^%d", divisor, powerOfDivisor);
                userNum/=divisorRaisedToPowerOfDivisor;
                if (userNum != 1) {
                    printf(" * ");
                }
            }
            divisor++;
        }
    }
    
    printf("\n");
    
    
    return 0;
}



int factor_power(int n, int d)
{
    int powerFactor = d;
    int factorPower = 1;
    while (n % powerFactor == 0) {
        int nextPower = (int)pow(d, factorPower+1);
        
        if (n % nextPower == 0) {
            factorPower++;
        }else {
            return factorPower;
        }
        
        powerFactor = pow(d, factorPower);
    }
    return 0;
}
