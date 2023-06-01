#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main() {

    /* Ask for the problem selection (1,2,3) .....  */
    int problem;
    printf("Please select the problem number: ");
    scanf("%d",&problem);
    
    while(problem != 1 && problem != 2 && problem != 3){
        printf("%d",problem);
        printf("You can only select 1,2 or 3 numbers.\n");
        printf("Please select the problem number: ");
        scanf("%d",&problem);
    }
    
    if(problem == 1){
    /* Get the input from the user for the first problem, i.e., to test dt1a and dt1b */
    /* Compare performances and print results */
        double pl,pw,sl,sw;
        printf("Please enter pl: ");
        scanf("%lf",&pl);
        printf("Please enter pw: ");
        scanf("%lf",&pw);
        printf("Please enter sl: ");
        scanf("%lf",&sl);
        printf("Please enter sw: ");
        scanf("%lf",&sw);
        
        char resultA = dt1a(pl, pw, sl, sw);
        char resultB = dt1b(pl, pw, sl, sw);
        char flower1[7] = "Setosa"; 
        char flower2[10] = "Virginica";
        char flower3[11] = "Versicolor";
        
        if(resultA == resultB){
            if(resultA == 'S'){
                printf("Result of decision trees for P1: %s\n", flower1);
            }else if(resultA == 'I'){
                printf("Result of decision trees for P1: %s\n", flower2);
            }else if(resultA == 'V'){
                printf("Result of decision trees for P1: %s\n", flower3);
            }
        }else{
           //for first result
            if(resultA == 'S'){
                printf("Result of first decision tree for P1: %s\n", flower1);
            }else if(resultA == 'I'){
                printf("Result of first decision tree for P1: %s\n", flower2);
            }else if(resultA == 'V'){
                printf("Result of first decision tree for P1: %s\n", flower3);
            }
            //For second result
            if(resultB == 'S'){
                printf("Result of second decision tree for P1: %s", flower1);
            }else if(resultB == 'I'){
                printf("Result of second decision tree for P1: %s", flower2);
            }else if(resultB == 'V'){
                printf("Result of second decision tree for P1: %s", flower3);
            }
            
            
            
        }
    }else if(problem == 2){
    /* Get the input from the user for the second problem, i.e., to test dt2a and dt2b */
    /* Compare performances and print results */
        double x1,x2,x3;
        int x4,x5;
        printf("Please enter x1: ");
        scanf("%lf",&x1);
        printf("Please enter x2: ");
        scanf("%lf",&x2);
        printf("Please enter x3: ");
        scanf("%lf",&x3);
        
        printf("Please enter x4: ");
        scanf("%d",&x4);
        while(x4 != 1 && x4 != 0){
            printf("You can enter only 1 or 0.\n");
            printf("Please enter x4 again: ");
            scanf("%d",&x4);
        }
        
        printf("Please enter x5: ");
        scanf("%d",&x5);
        while(x5 != 1 && x5 != 0){
            printf("You can enter only 1 or 0.\n");
            printf("Please enter x5 again: ");
            scanf("%d",&x5);
        }
        
        double aResult,bResult;
        aResult = dt2a(x1, x2, x3, x4, x5);
        bResult = dt2b(x1, x2, x3, x4, x5);
        double difference = aResult - bResult;
        if(difference < 0) difference = difference * (-1);
        if(difference <= CLOSE_ENOUGH){
            printf("%lf", (aResult + bResult)/2);
        }else{
            printf("Result of first decision tree for P2: %lf\n", aResult);
            printf("Result of second decision tree for P2: %lf", bResult);
        }
        
    }else{
    /* Get the input from the user for the third problem, i.e., to test dt3a and dt3b */
    /* Compare performances and print results */
        double budget,weather;
        int dayTime,student,with;
        printf("Please enter your budget: ");
        scanf("%lf", &budget);
        
        printf("Choose the day of time\n0 - (08.00-11.00)\n1 - (11.00-14.00)\n2 - (14.00-17.00)\n3 - (17.00-20.00)\n4 - (20.00-00.00)\n");
        scanf("%d", &dayTime);
        while(dayTime != 0 && dayTime != 1 && dayTime != 2 && dayTime != 3 && dayTime != 4){
            printf("You can enter only 0,1,2,3 or 4.\n");
            printf("Please enter the day of time again: ");
            scanf("%d",&dayTime);
        }
        
        printf("Enter the degrees of weather for the time you choose: ");
        scanf("%lf", &weather);
        
        printf("Choose the people you wanna do something together\n0 - family\n1 - loved\n2 - best friends\n3 - ordinary friends\n4- alone\n");
        scanf("%d", &with);
        while(with != 0 && with != 1 && with != 2 && with != 3 && with != 4){
            printf("You can enter only 0,1,2,3 or 4.\n");
            printf("Please enter again: ");
            scanf("%d",&with);
        }
        
        printf("Are you a student(0 for no, 1 for yes): ");
        scanf("%d", &student);
        while(student != 0 && student != 1){
            printf("You can enter only 0 or 1.\n");
            printf("Please enter again: ");
            scanf("%d",&student);
        }
        
        dt3a(budget,weather,student,with,dayTime);
        dt3b(budget,weather,student,with,dayTime);
        
    }
    return 0;
}
