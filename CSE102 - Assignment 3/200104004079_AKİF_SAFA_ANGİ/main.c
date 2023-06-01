#include <stdio.h>
#include <math.h>

//Part 1
int sum(int n1, int n2, int flag);
int multi(int n1, int n2, int flag);

//Part 2
int isprime(int a);

//Part 3
void write_file(int number);
void print_file();
void sort_file();
void write_temp_file(int n1, int n2, int n3, int length);

int main(){
    int operation;
    printf("Select operation\n");
    printf("1. Calculate sum/multiplication between two numbers\n");
    printf("2. Calculate prime numbers\n");
    printf("3. Show number sequence in file\n");
    printf("4. Sort number sequence in file\n");
    printf("-------------------------\n");
    scanf("%d", &operation);
    
    while(operation != 1 && operation != 2 && operation != 3 && operation != 4){
    	printf("You can select only 1,2,3 or 4\n");
    	printf("Please select operation again: ");
    	scanf("%d", &operation);
    }
    
    int prime,flag;
    int temp;
    switch(operation){
           case 1:
             printf("Select operation\n");
             printf("Please enter '0' for sum, '1' for multiplication.\n");
    	     scanf("%d", &flag);

            int num1,num2,result;
    	    switch(flag){
    	      case 0:
    	        printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
    	        scanf("%d", &flag);
    	        switch(flag){
    	              case 0:
    	                  printf("Please enter two different number:\n");
                          printf("Number 1: ");
                          scanf("%d", &num1);
                          printf("Number 2: ");
                          scanf("%d", &num2);

                          while(num1 == num2){
                            printf("Numbers must be different\n");
                            printf("Please enter second number again: ");
                            scanf("%d", &num2);
                          }
                          if(num1 > num2){
                             temp = num1;
                             num1 = num2;
                             num2 = temp;
    	                   }
    	                   printf("Result\n");
           		    result = sum(num1,num2,flag);
    	                   printf("= %d\n", result);
    	                   write_file(result);
    	                   printf("The result is written to the results.txt file.");
    	              break;
    	              case 1:
    	                  printf("Please enter two different number:\n");
                          printf("Number 1: ");
                          scanf("%d", &num1);
                          printf("Number 2: ");
                          scanf("%d", &num2);

                          while(num1 == num2){
                            printf("Numbers must be different\n");
                            printf("Please enter second number again: ");
                            scanf("%d", &num2);
                          }
                          if(num1 > num2){
                             temp = num1;
                             num1 = num2;
                             num2 = temp;
    	                   }
    	                   printf("Result\n");
           		    result = sum(num1,num2,flag);
    	                   printf("= %d\n", result);
    	                   write_file(result);
    	                   printf("The result is written to the results.txt file.");
    	              break;
    	              default: printf("Wrong entry!");
    	              break;
    	        }
    	        break;
    	        case 1:
    	          printf("Please enter '0' to work on even numbers, '1' to work on odd numbers.\n");
    	          scanf("%d", &flag);
    	          switch(flag){
    	            case 0:
    	                  printf("Please enter two different number:\n");
                          printf("Number 1: ");
                          scanf("%d", &num1);
                          printf("Number 2: ");
                          scanf("%d", &num2);

                          while(num1 == num2){
                            printf("Numbers must be different\n");
                            printf("Please enter second number again: ");
                            scanf("%d", &num2);
                          }
                          if(num1 > num2){
                             temp = num1;
                             num1 = num2;
                             num2 = temp;
    	                   }
    	                   printf("Result\n");
           		    result = multi(num1,num2,flag);
    	                   printf("= %d\n", result);
    	                   write_file(result);
    	                   printf("The result is written to the results.txt file.");
    	              break;
    	              case 1:
    	                  printf("Please enter two different number:\n");
                          printf("Number 1: ");
                          scanf("%d", &num1);
                          printf("Number 2: ");
                          scanf("%d", &num2);

                          while(num1 == num2){
                            printf("Numbers must be different\n");
                            printf("Please enter second number again: ");
                            scanf("%d", &num2);
                          }
                          if(num1 > num2){
                             temp = num1;
                             num1 = num2;
                             num2 = temp;
    	                   }
    	                   printf("Result\n");
           		    result = multi(num1,num2,flag);
    	                   printf("= %d\n", result);
    	                   write_file(result);
    	                   printf("The result is written to the results.txt file.");
    	              break;
    	              default: printf("Wrong entry!");
    	              break;
    	             }
    	        break;
    	        default: printf("Wrong entry!");
    	        break;
    	   }
    	   break;
           case 2:
                printf("Please enter an integer: ");
                scanf("%d", &prime);

                int i;
                for(i = 2;i < prime;i++){
                   if(isprime(i) == 1) printf("%d is a prime number.\n", i);
                   else printf("%d is not a prime number, it is dividible by %d.\n", i, isprime(i));
                }
           break;
           case 3:
               print_file();
           break;
           case 4:
               sort_file();
               printf("Sorting is complete.\n");
               printf("Result :\n");
               print_file();
           break;
    }
    return 0;
}

int sum(int n1, int n2, int flag){
    int sum = 0;
    int even = 1;
    if(flag == 0){
      if(n2 % 2 == 0) even = 2; 
       for(n1 = n1 + 1;n1 < n2;n1++){
          if(n1%2 == 0){
             printf("%d ", n1);
             sum = sum + n1;
             
             if(n1+even != n2) printf("+ ");
          }
       }
    }else{
      if(n2 % 2 == 1) even = 2; 
       for(n1 = n1 + 1;n1 < n2;n1++){
          if(n1%2 != 0){
             printf("%d ", n1);
             sum = sum + n1;
             if(n1+even != n2) printf("+ ");
          }
       }
    }
    return sum;
}

int multi(int n1, int n2, int flag){
    int mult = 1;
    int even = 1;
    if(flag == 0){
       if(n2 % 2 == 0) even = 2; 
       for(n1 = n1 + 1;n1 < n2;n1++){
          if(n1%2 == 0){
             printf("%d ", n1);
             mult = mult * n1;
             if(n1+even != n2) printf("* ");
          }
       }
    }else{
             if(n2 % 2 == 1) even = 2; 
       for(n1 = n1 + 1;n1 < n2;n1++){
          if(n1%2 != 0){
             printf("%d ", n1);
             mult = mult * n1;
             if(n1+even != n2) printf("* ");
          }
       }
    }
    return mult;
}

int isprime(int a){
    int i,flag = 1;
    for(i = 2;i <= sqrt(a);i++){
       if(a%i == 0) return i;
    }
    return flag;
}

void write_file(int number){
    FILE *txt;
    txt = fopen("results.txt","a");
    fprintf(txt,"%d ", number);
    fclose(txt);
}

void print_file(){
    int num = 0;
    FILE *txt;
    txt = fopen("results.txt","r");

    while (!feof(txt))
    {
       fscanf(txt,"%d ", &num);
       printf("%d ", num);
    }
    fclose(txt);
}

//Check the length and write the numbers,if i have less than 3 numbers it will only write this numbers to txt file
void write_temp_file(int n1, int n2, int n3, int length){
    FILE *txt;
    txt = fopen("temporary.txt","a");
    if(length == 3) fprintf(txt,"%d %d %d ", n1,n2,n3);
    else if(length == 2) fprintf(txt,"%d %d ", n1,n2);
    else if(length == 1) fprintf(txt,"%d ", n1);
    fclose(txt);
}

void sort_file(){
    int temp,min1 = 0,min2 = 0,min3 = 0,max = 0;
    int length = 0;
    int num;
    
    FILE *txt;
    txt = fopen("results.txt","r");
    
    while(!feof(txt)){
       fscanf(txt,"%d ", &num);
       if(num > max) max = num;
       length++;
    }
    fclose(txt);
    min1 = max;
    min2 = max;
    min3 = max;
    txt = fopen("results.txt","r");
    
    while(!feof(txt)){
       fscanf(txt,"%d ", &num);
       if(num < min1){
          min3 = min2;
          min2 = min1;
          min1 = num;
       }else if(num < min2){
          min3 = min2;
          min2 = num;
       }else if(num < min3){
          min3 = num;
       }
    }
    fclose(txt);
    
    if(length>=3){
       write_temp_file(min1,min2,min3,3);
       length-=3;
    }
    else if(length == 2){
       write_temp_file(min1,min2,min3,2);
       length-=2;
    }
    else if(length == 1){
       write_temp_file(min1,min2,min3,1);
       length-=1;
    }
    
    int count = 3,countTo = 0;
    txt = fopen("results.txt","r");
    FILE *tempTxt;
    tempTxt = fopen("temporary.txt","a");
    int a = 0,b = 0,c = 0;
    while(!feof(txt)){
       fscanf(txt,"%d ",&num);
       if(num == min1 && a == 0) a++;
       else if(num == min2 && b == 0) b++;
       else if(num == min3 && c == 0) c++;
       else{
          fprintf(tempTxt,"%d ",num);
       }
    }
    fclose(tempTxt);
    fclose(txt);
    
    tempTxt = fopen("temporary.txt","r");
    txt = fopen("results.txt","w");
    while(!feof(tempTxt)){
       fscanf(tempTxt,"%d ",&num);
       fprintf(txt,"%d ",num);
    }
    fclose(tempTxt);
    fclose(txt);

    while(length > 0 ){
    countTo = 0;
    min1 = max;
    min2 = max;
    min3 = max;
    
    txt = fopen("results.txt","r");
    while(countTo < count) {
    fscanf(txt,"%d ",&num);
    countTo++;
    }

    while(!feof(txt)){
       fscanf(txt,"%d ", &num);
       if(num < min1){
          min3 = min2;
          min2 = min1;
          min1 = num;
       }else if(num < min2){
          min3 = min2;
          min2 = num;
       }else if(num < min3){
          min3 = num;
       }
    }

    fclose(txt);

    tempTxt = fopen("temporary.txt","w");
    txt = fopen("results.txt","r");
    countTo = 0;
    while(countTo < count){
       fscanf(txt,"%d ", &num);
       fprintf(tempTxt,"%d ", num);
       countTo++;
    }
    fclose(txt);
    fclose(tempTxt);
    if(length>=3){
       write_temp_file(min1,min2,min3,3);
       length-=3;
    }
    else if(length == 2){
       write_temp_file(min1,min2,min3,2);
       length-=2;
    }
    else if(length == 1){
       write_temp_file(min1,min2,min3,1);
       length-=1;
    }
    
    
    txt = fopen("results.txt","r");
    FILE *tempTxt;
    tempTxt = fopen("temporary.txt","a");
    countTo = 0;
    while(countTo < count){
       fscanf(txt,"%d ",&num);
       countTo++;
    }
    a = 0;
    b = 0;
    c = 0;
    while(!feof(txt)){
       fscanf(txt,"%d ",&num);
       if(num == min1 && a == 0) a++;
       else if(num == min2 && b == 0) b++;
       else if(num == min3 && c == 0) c++;
       else{
          fprintf(tempTxt,"%d ",num);
       }
    }
    fclose(tempTxt);
    fclose(txt);
    
    tempTxt = fopen("temporary.txt","r");
    txt = fopen("results.txt","w");
    while(!feof(tempTxt)){
       fscanf(tempTxt,"%d ",&num);
       fprintf(txt,"%d ",num);
    }
    fclose(tempTxt);
    fclose(txt);
    count+=3;
    }
}
