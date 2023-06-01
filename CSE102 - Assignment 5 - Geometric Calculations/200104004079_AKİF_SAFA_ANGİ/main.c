#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

enum shapes{Triangle = 1,Quadrilateral,Circle,Pyramid,Cylinder};
enum calculators{Area = 1,Perimeter,Volume};

//Selection operations
int select_calc();
int select_shape();
int calculate(int (*fs)(),int (*fc)());

//Calculation functions
int calc_triangle(int calc);
int calc_quadrilateral(int calc);
int calc_circle(int calc);
int calc_pyramid(int calc);
int calc_cylinder(int calc);

//Function that check received input are only digits
float check_number();
//Reset the input
void flush();

int main(){
    printf("Welcome to the geometric calculator!\n");
    printf("\n");
    calculate(select_shape,select_calc);
  return 0;
}

int select_shape(){
    printf("Select a shape to calculate:\n");
    printf("----------------------------\n");
    printf("1. Triangle\n");
    printf("2. Quadrilateral\n");
    printf("3. Circle\n");
    printf("4. Pyramid\n");
    printf("5. Cylinder\n");
    printf("0. Exit\n");
    printf("----------------------------\n");
    printf("Input : ");

    return check_number();
}

int select_calc(){
    int cal;
    printf("Select calculator:\n");
    printf("----------------------------\n");
    printf("1. Area\n");
    printf("2. Perimeter\n");
    printf("3. Volume\n");
    printf("0. Exit\n");
    printf("----------------------------\n");
    printf("Input : ");

    cal = check_number();

    while(cal != 1 && cal != 2 && cal != 3 && cal != 0){//Control the input at this range or not
        printf("You can't select this number.\n");
        cal = check_number();
    }
    return cal;
}

int calculate(int (*fs)(),int (*fc)()){
    int shape,calculator;
    calculator = 4;
    do{
      shape = fs();
      switch(shape){
          case Triangle:
              calculator = fc();
              if(calculator == Volume){
                printf("ERROR ! You can't calculate volume of a triangle. Please try again.\n");
              }else if(calculator == 0){
              }else{
                calc_triangle(calculator);
              }
              break;
          case Quadrilateral:
              calculator = fc();
              if(calculator == Volume){
                printf("ERROR ! You can't calculate volume of a quadrilateral. Please try again.\n");
              }else if(calculator == 0){
              }else{
                calc_quadrilateral(calculator);
              }
              break;
          case Circle:
              calculator = fc();
              if(calculator == Volume){
                printf("ERROR ! You can't calculate volume of a circle. Please try again.\n");
              }else if(calculator == 0){
              }else{
                calc_circle(calculator);
              }
              break;
          case Pyramid:
              calculator = fc();
              if(calculator == 0){
              }else calc_pyramid(calculator);
              break;
          case Cylinder:
              calculator = fc();
              if(calculator == 0){
              }
              else calc_cylinder(calculator);
              break;
          case 0:
              break;
          default:
              printf("You can't select this number!\n");
              break;
      }
    }while(shape != 0 && calculator != 0);
}

int calc_triangle(int calc){
    float a,b,c;
    float result;
    float s;
    printf("Please enter three sides of Triangle :\n");

    a = check_number();
    b = check_number();
    c = check_number();
    s = (a + b + c)/2.0;

    while(s <= a || s <= b || s <= c){
        printf("ERROR ! Please enter valid sides.\n");
        a = check_number();
        b = check_number();
        c = check_number();
        s = (a + b + c)/2.0;
    }
    switch(calc){
    case Area: ;
        result = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("Area of TRIANGLE : %.2f\n",result);
        break;
    case Perimeter:
        result = a + b + c;
        printf("Perimeter of TRIANGLE : %.2f\n",result);
        break;
    }
}

int calc_quadrilateral(int calc){
    float a,b,c,d;
    float result;
    printf("Please enter four sides of Quadrilateral :\n");
    a = check_number();
    b = check_number();
    c = check_number();
    d = check_number();
    switch(calc){
    case Area: ;
        float s = (a + b + c + d)/2.0;
        result = sqrt((s - a)*(s - b)*(s - c)*(s - d));
        printf("Area of QUADRILATERAL : %.2f\n",result);
        break;
    case Perimeter:
        result = a + b + c + d;
        printf("Perimeter of QUADRILATERAL : %.2f\n",result);
        break;
    }
}

int calc_circle(int calc){
    float r;
    float result;
    printf("Please enter the radius of Circle :\n");
    r = check_number();
    switch(calc){
    case Area:
        result = PI * r * r;
        printf("Area of CIRCLE : %.2f\n",result);
        break;
    case Perimeter:
        result = 2 * PI * r;
        printf("Perimeter of CIRCLE : %.2f\n",result);
        break;
    }
}

int calc_pyramid(int calc){
    float a,h;
    float b,l;
    float result;
    switch(calc){
    case Area:
        printf("Please enter the base side and slant height of a Pyramid :\n");
        a = check_number();
        h = check_number();
        b = a * a;
        printf("Base Surface Area of a PYRAMID : %.2f\n",b);
        printf("\n");
        l = 2 * a * h;
        printf("Lateral Surface Area of a PYRAMID : %.2f\n",l);
        printf("\n");
        printf("Surface Area of a PYRAMID : %.2f\n", b + l);
        break;
    case Perimeter:
        printf("Please enter the base side of a Pyramid :\n");
        a = check_number();
        printf("Base Surface Perimeter of a PYRAMID : %.2f\n",4*a);
        break;
    case Volume:
        printf("Please enter the base side and height of a Pyramid :\n");
        a = check_number();
        h = check_number();
        result = (1.0/3.0) * a * a * h;
        printf("Volume of a PYRAMID : %.2f\n",result);
        break;
    }
}

int calc_cylinder(int calc){
    float r,h;
    float b,l;
    float result;
    printf("Please enter the radius and height of a Cylinder :\n");
    r = check_number();
    h = check_number();
    switch(calc){
    case Area:
        b = PI * r * r;
        printf("Base Surface Area of a PYRAMID : %.2f\n",b);
        printf("\n");
        l = 2 * PI * r * h;
        printf("Lateral Surface Area of a PYRAMID : %.2f\n",l);
        printf("\n");
        result = 2 * PI * r * (r + h);
        printf("Surface Area of a PYRAMID : %.2f\n", result);
        break;
    case Perimeter:
        result = 2 * PI * r;
        printf("Base Surface Perimeter of a CYLINDER : %.2f\n",result);
        break;
     case Volume:
        result = PI * r * r * h;
        printf("Volume of a CYLINDER : %.2f\n",result);
        break;
    }
}

/* This function will check the input it's number or not */
float check_number(){
  float x,num,num2;
  int checkInvalid = 0,c = 0;
  int dot = 0;
  int length = 0;
  while(checkInvalid == 0){
    if(c != 0){// c = 0 to not print error message at first.
     printf("ERROR ! Please enter a valid entry.\n");
     flush();
    }
    // Set the numbers to default every time when function get input from user
    num = 0;
    num2 = 0;
    c = 1;
    dot = 0;
    x = getchar();
    //Check the first char
    if(x >= 48 && x <= 57){
     checkInvalid = 1;
     num = num * 10 + (x - 48);
    }
    while(x >= 48 && x <= 57){
     x = getchar();
     if(x != 10 && x < 48 || x > 57){ // Check char is not equal to '\n'(ascii number is 10) and not in the ascii value range
      if(x == 46 && dot == 0){ // If char is '.' for the first time
        dot = 1;// Means there is at least one dot in our number
        x = getchar();
        if(x == 46) checkInvalid = 0; // If there is a dot for second time, we set invalid 0
      }
      else{
       checkInvalid = 0;
      }
     }
     if(x >= 48 && x <= 57 && dot != 1) num = num * 10 + (x - 48); //Equation to find the received number
     else if(x >= 48 && x <= 57 && dot == 1){//Equation to find the received number after dot if there is one dot
        num2 = num2 * 10 + (x - 48);
        length++;
     }
    }
  }
  for(int i = 0;i < length;i++) num2 = num2/10;//Find the number after dot
  return num + num2;
}

/* This function reset the input*/
void flush(){
    int c;
    do{
      c = getchar();
    }while(c != EOF && c != '\n');
}
