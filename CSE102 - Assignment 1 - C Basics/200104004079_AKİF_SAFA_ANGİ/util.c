#include <stdio.h>
#include "util.h"

	/*                  Part 1                   */
int find_divisible(int x,int y,int z){
    int i;
    /*Check first integer can be divided by z and return it*/
    for(i = (x+1);i < y;i++){
        if(i%z == 0){
            return i;
        }
    }
    return -1;
}

int find_nth_divisible(int n, int f_I, int z){
    return f_I+(n*z);
}


	/*                  Part 2                   */
int validate_identity_number(char identity_number[]){
    int i = 0;
    int currentStep = 0;
    int identityLength;
    while(identity_number[i] != '\0'){
        i++;
    }
    identityLength = i;
    if(identityLength == 11){
        currentStep = 1;
    }else{
    return 0;}
    if(currentStep == 1){
        int asciiNumber;
        int stepCheck = 0;
        for(i = 0;i < identityLength;i++){
            asciiNumber = identity_number[i];
            if(asciiNumber > 47 && asciiNumber < 58){
                stepCheck++;
            }
        }
        if(stepCheck == 11) currentStep = 2;
    }else{
    return 0;}
    
    if(currentStep == 2){
      if(identity_number[0] != 48) currentStep = 3;
    }else{
    return 0;}
    
    if(currentStep == 3){
        int sumOfOdd = 0,sumOfEven = 0;
        for(i = 0;i < 9;i++){
           if(i%2==0){
              sumOfOdd = sumOfOdd + (identity_number[i]-48);
           }else{
              sumOfEven = sumOfEven + (identity_number[i]-48);
           }
        }
        if((identity_number[9]-48) == (sumOfOdd*7-sumOfEven)%10) currentStep = 4;
    }else{
    return 0;}
    
    int sumIDNumber = 0;
    if(currentStep == 4){
        for(i = 0;i < identityLength-1;i++){
            sumIDNumber += (identity_number[i]-48);
        }
        if(sumIDNumber % 10 == (identity_number[10]-48)) return 1;
    }
    return 0;
}

int create_customer(char identity_number[],int password){
    FILE *customerTxt;
    customerTxt = fopen("customeraccount.txt","w");
    fprintf(customerTxt,"%s,%d",identity_number,password);
    fclose(customerTxt);

    return 0;
}

	/*                  Part 3                   */
int check_login(char identity_number[], int password){ 
    FILE *customerTxt;
    char TxtIDNumber[11];
    int TxtPassword;
    customerTxt = fopen("customeraccount.txt","r");
    fscanf(customerTxt,"%[^,],%d",TxtIDNumber,&TxtPassword);
    fclose(customerTxt);
    
    /*Controls every character of strings whether they are equal or not. If they are not return 0*/
    int i;
    for(i = 0;i < 11;i++){
       if(TxtIDNumber[i] != identity_number[i]) return 0;
    }
       if(TxtPassword != password) return 0;

    return 1;   
}

int withdrawable_amount(float cash_amount){
    float mod = cash_amount;
    /*Substract ten each time if mod not smaller than 10 and we find remainder */
    while(mod>=10){
       mod = mod-10;
    }
    return cash_amount - mod;
}
