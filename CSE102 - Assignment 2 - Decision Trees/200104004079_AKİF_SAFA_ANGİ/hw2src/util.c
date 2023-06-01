#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description */
/*int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}*/

//E-Versicolor,I-Virginica,S-Setosa
char dt1a(double pl, double pw, double sl, double sw){
    char r;

    if(pl >= 2.45 && pw >= 1.75) r = 'I';
    else if(pl >= 2.45 && pw < 1.75){
        if(pl >= 4.95) r = 'I';
        else if(pl < 4.95){
            if(pw >= 1.65) r = 'I';
            else r = 'V';
        }
    }
    else if(pl < 2.45) r = 'S';
    return r;
}

char dt1b(double pl, double pw, double sl, double sw){
    char r;
    if(pl >= 2.55 && pw >= 1.69) r = 'I';
    else if(pl >= 2.45 && pw < 1.75){
        if(pl >= 4.95) r = 'I';
        else r = 'V';
    }
    else if(pl < 2.45) r = 'S';
    
    return r;
}

double dt2a(double x1, double x2, double x3, int x4, int x5){
    double r;
    if(x1 < 31.5){
        if(x2 > -2.5) r = 5.0;
        else{
            if(x2 - 0.1 <= x1 && x1 <= x2 + 0.1) r = 2.1;
            else r = -1.1;
        }
    }else{
        if(-1 <= x3 && x3 <= 2) r = 1.4;
        else{
            if(x4 == 1 && x5 == 1) r = -2.23;
            else r = 11.0;
        }
    }
    
    return r;
}

double dt2b(double x1, double x2, double x3, int x4, int x5){
    double r;
    if(12 < x1 && x1 < 22){
        if(x3 > 5/3) r = (-2.0);
        else{
            if(x1 - 0.1 <= x3 && x3 <= x1 + 0.1) r = 1.01;
            else r = (-8.0);
        }
    }else{
        if(x4 == 1 && x5 == 1) r = (-1.0);
        else{
            if(-1 <= x2 && x2 <= 2) r = (-1.0)/7.0;
            else r = sqrt(2.0)/3.0;
        }
    }
    
    return r;
}

void dt3a(double budget, double weather, int student, int with, int time){
    printf("First tree of p3: ");
    if(budget < 250){
        if(student == 0){
            if(with == 0 || with == 1 || with == 2) printf("massage\n");
            else if(with == 3) printf("cafe in bosphorus\n");
            else printf("concert\n");
        }else{
            if(with != 1){
                if(time == 0 || time == 3) printf("museum\n");
                else if(time == 2){
                    if(weather > 25) printf("walk on beach\n");
                    else printf("stay home");
                }
                else if(time == 4) printf("dinner at home\n");
            }else printf("dining outside\n");
        }
    }else{
        if(weather < 25){
            if(time == 0 || time == 1) printf("stay home\n");
            else printf("a short walk\n");
        }else printf("walk in a park\n");
    }
}

void dt3b(double budget, double weather, int student, int with, int time){
    printf("Second tree of p3: ");
    if(budget < 500){
        if(student == 0){
            if(with == 0 || with == 1 || with == 2) printf("museum");
            else if(with == 3) printf("walk on beach");
            else printf("stay home");
        }else{
            if(with == 1){
                if(time == 0 || time == 3) printf("restaurant in a regular place");
                else printf("cinema");
            }else printf("go for a walk");
        }
    }else{
        if(student == 0){
            if(weather < 25){
                if(time == 0) printf("breakfast at home");
                else printf("museum");
            }else printf("a good dinner at bosphorus");    
        }else printf("1 day trip to a nearby city");
    }
}
/* Provide your implementations for all the requested functions here */
