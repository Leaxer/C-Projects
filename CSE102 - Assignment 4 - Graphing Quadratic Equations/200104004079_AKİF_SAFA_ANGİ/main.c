#include <stdio.h>

//Part 1
void coefficient_file(int a, int b, int c);
//Part 2
int draw_graph();
//Part 3
int draw_graph_txt();

int main(){
  int operation;

  do{
    printf("Select an operation...\n");
    printf("1 -> Enter the coefficients.\n");
    printf("2 -> Draw the graph.\n");
    printf("3 -> Print the graph into a .txt file.\n");
    printf("4 -> Exit.\n");
    printf("Choice: ");
    scanf("%d",&operation);

    int a,b,c;
    switch(operation){
      case 1:
          printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n");
          printf("a: ");
          scanf("%d",&a);
          printf("b: ");
          scanf("%d",&b);
          printf("c: ");
          scanf("%d",&c);
          coefficient_file(a,b,c);
      break;
      case 2:
          draw_graph();
      break;
      case 3:
          draw_graph_txt();
      break;
      case 4:
      break;
      default:
          printf("You can select only 1,2,3 or 4\n");
          printf("Please select again!\n");
      break;

    }

  }while(operation != 4);

  return 0;
}


void coefficient_file(int a, int b, int c){
  FILE *txt;
  txt = fopen("coefficients.txt","w");
  fprintf(txt,"%d\n",a);
  fprintf(txt,"%d\n",b);
  fprintf(txt,"%d\n",c);
  fclose(txt);
  printf("coefficients.txt file has been created.\n");
}

//if the file is not present, it should warn the user
int draw_graph(){
  int a = 0,b = 0,c = 0;
  FILE *txt;
  txt = fopen("coefficients.txt","r");
  if(txt == NULL)
   {
      printf("Error!");
      return 0;
   }
  fscanf(txt,"%d ",&a);
  fscanf(txt,"%d ",&b);
  fscanf(txt,"%d ",&c);
  fclose(txt);

  printf("Coefficients has been read from the coeffecient.txt file.\n");
  printf("Printing the graph of x=%d(y*y) + %d*y + %d\n",a,b,c);

  int i,j;
  int d = -50,f = 15;
  int x,y;
  for(i = 0;i < 31;i++){
    y = 15 - i;
    x = a*(y*y) + b*y + c;
    if(i != 15){
       for(j = 0;j < 107;j++){
         if(i == 16 && j%10==0){
            printf("\033[0;33m");
            printf("%3d",d);
            printf("\033[0m");
            j+=3;
            d+=10;
         }
         if(j == x + 54){
            if(i != 16){
              printf("\033[0;34m");
              printf("\b#");
              printf("\033[0m");
            }
            else if(i == 16){
              if(j%10 == 1){
               printf("\033[0;34m");
               printf("\b#\b\b  ");
               printf("\033[0m");
              }else if(j%10 == 2){
               printf("\033[0;34m");
               printf("\b\b #\b ");
               printf("\033[0m");
              }else if(j%10 == 3){
               printf("\033[0;34m");
               printf("\b\b\b  #");
               printf("\033[0m");
              }else{
               printf("\033[0;34m");
               printf("\b#");
               printf("\033[0m");
              }
            }
            
         }
         printf(" ");
       if(i%5 == 0 && j == 52){
        if(f == 0) f = -5;
        printf("\033[0;33m");
        printf("\b\b\b%3d",f);
        printf("\033[0m");
        
       }

       if(j == 53) printf("\b|");
       }
    }else{
       printf("<");
       for(j = 0;j < 105;j++){
          if(j != 52)printf("-");
          else printf("|");
          if(j == c + 52){
            printf("\033[0;34m");
            printf("\b#");
            printf("\033[0m");
          }
       }
       printf(">");
    }

    printf("\n");
  }
}

int draw_graph_txt(){
  int a = 0,b = 0,c = 0;
  FILE *txt;
  txt = fopen("coefficients.txt","r");
  if(txt == NULL)
   {
      printf("Error!");
      return 0;
   }
  fscanf(txt,"%d ",&a);
  fscanf(txt,"%d ",&b);
  fscanf(txt,"%d ",&c);
  fclose(txt);

  printf("Coefficients has been read from the coeffecient file.\n");
  
  FILE *graphFd;
  graphFd = fopen("graph.txt","w");
  
  int i,j;
  int d = -50,f = 15;
  int x,y;
  for(i = 0;i < 31;i++){
    y = 15 - i;
    x = a*(y*y) + b*y + c;
    if(i != 15){
       for(j = 0;j < 107;j++){
         if(i == 16 && j%10==0){
            fprintf(txt,"%3d",d);
            j+=3;
            d+=10;
         }
         if(j == x + 54){
            if(i != 16){
              fprintf(txt,"\b#");
            }
            else if(i == 16){
              if(j%10 == 1){
               fprintf(txt,"\b#\b\b  ");
              }else if(j%10 == 2){
               fprintf(txt,"\b\b #\b ");
              }else if(j%10 == 3){
               fprintf(txt,"\b\b\b  #");
              }else{
               fprintf(txt,"\b#");
              }
            }
            
         }
         fprintf(txt," ");
       if(i%5 == 0 && j == 52){
        if(f == 0) f = -5;
          fprintf(txt,"\b\b\b%3d",f);
        f-=5;
       }

       if(j == 53) fprintf(txt,"\b|");
       }
    }else{
       fprintf(txt,"<");
       for(j = 0;j < 105;j++){
          if(j != 52){
            fprintf(txt,"-");
          }else fprintf(txt,"|");
          if(j == c + 52){
            fprintf(txt,"\b#");
          }
       }
       fprintf(txt,">");
    }

    fprintf(txt,"\n");
  }
  fclose(graphFd);
  printf("The graph of x=%d(y*y) + %d*y + %d has been written to graph.txt file.\n",a,b,c);
  printf("\n");
}
