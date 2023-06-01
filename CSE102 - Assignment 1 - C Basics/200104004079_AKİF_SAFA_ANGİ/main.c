#include <stdio.h>
#include "util.h"

int main(){
    /*                  Part 1                   */
    int x, y, z;
    printf("Enter the first integer: ");
    scanf("%d",&x);
    printf("Enter the second integer: ");
    scanf("%d", &y);
    printf("Enter the divisor: ");
    scanf("%d", &z);

    int returnNumber;
    returnNumber = find_divisible(x, y, z);

    if (returnNumber == -1) {
       printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
    }
    else {
       printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,returnNumber);
       int n;
       printf("Enter the number how many next: ");
       scanf("%d",&n);
       int nthNumber = find_nth_divisible(n, returnNumber, z);
       if(nthNumber > x && nthNumber < y){
          printf("The %dth integer between %d and %d divided by %d is %d\n",n+1,x,y,z,nthNumber);
       }else{
          printf("No possible to find %dth divisible between %d and %d divided by %d\n",n+1,x,y,z);
       }
    }

	
	
	
    /*                  Part 2                   */
    char IDNumber[20];
    printf("Please enter your ID number: ");
    scanf("%s",IDNumber);
    if(validate_identity_number(IDNumber) == 1){
       int password;
       printf("Enter your password: ");
       scanf("%d",&password);
       
       while(password > 9999 || password < 1000){
          printf("Your password must be 4 digits!\nPlease enter your password: ");
          scanf("%d",&password);
       }
       
       create_customer(IDNumber, password);
    }else{
       printf("Wrong ID number\n");
    }
    
    
    /*                  Part 3                   */
    printf("Enter your ID number: ");
    scanf("%s",IDNumber);
    
    int password;
    printf("Enter your password: ");
    scanf("%d",&password);
    
    int checkLoginNum = check_login(IDNumber, password);;
    if(checkLoginNum == 1){
       printf("Login Successful\n");
       
       float amount;
       printf("Enter your withdraw amount: ");
       scanf("%f",&amount);
       
       while(amount <= 0){
          printf("You must enter positive amount: ");
          scanf("%f",&amount);
       }
       
       printf("Withdrawable amount is: %d", withdrawable_amount(amount));
    }else{
       printf("Invalid identity number or password");
    }
    return 0;
}
