#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Function: setGameArea
----------------------------------
It does: Places the words on the playing field in the given direction

gameArea: Array of the game area
words: words taken from wordlist.txt
length: length of word
way: direction
whichNum: which word is the function use now
*/
void setGameArea(char gameArea[15][15],char words[7][20],int,int,int,int coordinates[7][3]);
/*
Function: printArea
----------------------------------
It does: Prints the game area, uses array of the game area as parameter

gameArea: Array of the game area

*/
void printArea(char gameArea[15][15]);
/*
Function: GetWord
----------------------------------
It does: Get word from wordlist.txt

random: random num to get random word from wordlist

*/
void GetWord(int,char words[7][20],int);
/*
Function: Game
----------------------------------
It does: Get coordinates and word from the user. Send them to other functions to check if word and coordinates are true

coordinates: coordinates of words

returns: returns the direction of the word,exit code(-2) or false code(-1)
*/
int Game(char gameArea[15][15],char words[7][20],int coordinates[7][3]);
/*
Function: DeleteWord
----------------------------------
It does: Delete the word from game area if the user found the word

x-y:coordinates of the word

*/
void DeleteWord(char gameArea[15][15],int length,int way,int x,int y);

int main(){
    srand(time(NULL));
    char gameArea[15][15];
    int i,j;
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
           gameArea[i][j] = '-';
        }
    }

    int len;
    char word[20];
    int way;
    int randomLine;
    int lineNums[7];
    int control = 0;
    
    char words[7][20];
    int coordinates[7][3];
    int whichNum = 0;
    //Get seven word from wordlist and place to game area
    for(i = 0;i < 7;i++){
        do{
          randomLine = 1 + rand()%11;//??
          control = 1;
          for(j = 0;j < i;j++){
            if(lineNums[j] == randomLine) control = 0;
          }
        }while(control == 0);
        lineNums[i] = randomLine;
        GetWord(randomLine,words,whichNum);
        len = strlen(words[whichNum]);
        way = rand()%8;
        setGameArea(gameArea,words,len,way,whichNum,coordinates);
        whichNum++;
    }
    //Fill the '-' with random letter
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
           if(gameArea[i][j] == '-') gameArea[i][j] = 'a' + rand()%26;
        }
    }

    printArea(gameArea);
    
    int check;
    int attempt = 3;
    int wordFound = 0;
    //Call the game function and start the game,it will finish loop if user find all words or uses all attempts or write ":q" to terminate
    do{
    check = Game(gameArea,words,coordinates);
    if(check == -1){
      attempt--;
      if(attempt > 0) printf("Wrong choice! You have only %d lefts.\n",attempt);
      else if(attempt == 0) printf("Wrong choice! You don't have any attempt\n");
    }else if(check == -2) printf("Your total points: %d\n",wordFound * 2);
    else{
      wordFound++;
      len = strlen(words[check]);
      DeleteWord(gameArea,len,coordinates[check][0],coordinates[check][1],coordinates[check][2]);
      printArea(gameArea);
      printf("Founded! You got 2 points.Your total points: %d\n",wordFound * 2);
    }
    }while(attempt != 0 && wordFound != 7 && check != -2);

    if(attempt == 0) printf("YOU LOSE!");
    else if(wordFound == 7) printf("YOU WON!");

    return 0;
}

void setGameArea(char gameArea[15][15],char words[7][20],int length,int way,int whichNum,int coordinates[7][3]){
    int i;
    char randomX;
    char randomY;
    int wordCheck;
    if(way == 0){
      //It loops until the word is correctly placed in the field and there are no other words in front of it
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(15 - randomY < length) randomY = rand()%13;
        while(i != length){
          if(gameArea[randomX][randomY + i] != '-' && gameArea[randomX][randomY + i] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      //Places the word to game area
      for(i = 0;i < length;i++){
        gameArea[randomX][randomY + i] = words[whichNum][i];
      }
    }else if(way == 1){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(15 - randomY < length) randomY = rand()%13;
        while(15 - randomX < length) randomX = rand()%13;
        while(i != length){
          if(gameArea[randomX + i][randomY + i] != '-' && gameArea[randomX + i][randomY + i] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX + i][randomY + i] = words[whichNum][i];
      }
    }else if(way == 2){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(15 - randomX < length) randomX = rand()%13;
        while(i != length){
          if(gameArea[randomX + i][randomY] != '-' && gameArea[randomX + i][randomY] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX + i][randomY] = words[whichNum][i];
      }
    }else if(way == 3){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(randomY < length) randomY = 3 + rand()%12;
        while(15 - randomX < length) randomX = rand()%13;
        while(i != length){
          if(gameArea[randomX + i][randomY - i] != '-' && gameArea[randomX + i][randomY - i] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX + i][randomY - i] = words[whichNum][i];
      }
    }else if(way == 4){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(randomY < length) randomY = 3 + rand()%12;
        while(i != length){
          if(gameArea[randomX][randomY - i] != '-' && gameArea[randomX][randomY - i] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX][randomY - i] = words[whichNum][i];
      }
    }else if(way == 5){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(randomY < length) randomY = 3 + rand()%12;
        while(randomX < length) randomX = 3 + rand()%12;
        while(i != length){
          if(gameArea[randomX - i][randomY - i] != '-' && gameArea[randomX - i][randomY - i] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX - i][randomY - i] = words[whichNum][i];
      }
    }else if(way == 6){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(randomX < length) randomX = 3 + rand()%12;
        while(i != length){
          if(gameArea[randomX - i][randomY] != '-' && gameArea[randomX - i][randomY] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX - i][randomY] = words[whichNum][i];
      }
    }else if(way == 7){
      do{
        i = 0;
        wordCheck = 1;
        randomX = rand()%15;
        randomY = rand()%13;
        while(15 - randomY < length) randomY = rand()%13;
        while(randomX < length) randomX = 3 + rand()%12;
        while(i != length){
          if(gameArea[randomX - i][randomY + i] != '-' && gameArea[randomX - i][randomY + i] != words[whichNum][i]) wordCheck = 0;
          i++;
        }
      }while(wordCheck != 1);
      
      for(i = 0;i < length;i++){
        gameArea[randomX - i][randomY + i] = words[whichNum][i];
      }
    }
    //Save the coordinates of the word
    coordinates[whichNum][0] = way;
    coordinates[whichNum][1] = randomX;
    coordinates[whichNum][2] = randomY;
    printf("%d-%d %s\n",randomX,randomY,words[whichNum]);

}

void printArea(char gameArea[15][15]){
    int i,j;
    for(i = 0;i < 15;i++){
        for(j = 0;j < 15;j++){
           printf("%c ",gameArea[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void GetWord(int random,char words[7][20],int whichNum){
   int i;
   FILE *txt;
   txt = fopen("wordlist.txt","r");
   for(i = 0;i < random;i++) fscanf(txt,"%s ",words[whichNum]);
   fclose(txt);
}

int Game(char gameArea[15][15],char words[7][20],int coordinates[7][3]){
  int  x = 0,y = 0;
  char userWord[1][20];
  char cx[20];
  int len;
  int i = 0,j;
  printf("Enter coordinates and word:");
  scanf("%s",cx);
  //If user write ":q" terminate the game
  if(cx[i] == ':'){
    i++;
    if(cx[i] == 'q') return -2;
  }
  
  scanf("%d %s",&y,userWord[0]);
  i = 0;
  //string to int
  while(cx[i] != '\0'){
    x = x * 10 + (cx[i] - 48);
    i++;
  }
  len = strlen(userWord[0]);
  int a;
  int flag;
  if(userWord[0][0] == gameArea[x][y]){
    for(i = 0;i < 7;i++){
      flag = 0;
      for(j = 0;j < len;j++){
        if(userWord[0][j] != words[i][j]) flag = 1;
      }
      if(flag == 0) a = i;
    }
  }
  if(a >= 0 && a < 7 && x == coordinates[a][1] && y == coordinates[a][2]) return a;
  return -1;
}

void DeleteWord(char gameArea[15][15],int length,int way,int x,int y){
    int i;
    if(way == 0){
      for(i = 0;i < length;i++) gameArea[x][y + i] = 'X';
    }else if(way == 1){
      for(i = 0;i < length;i++) gameArea[x + i][y + i] = 'X';
    }else if(way == 2){
      for(i = 0;i < length;i++) gameArea[x + i][y] = 'X';
    }else if(way == 3){
      for(i = 0;i < length;i++) gameArea[x + i][y - i] = 'X';
    }else if(way == 4){
      for(i = 0;i < length;i++) gameArea[x][y - i] = 'X';
    }else if(way == 5){
      for(i = 0;i < length;i++) gameArea[x - i][y - i] = 'X';
    }else if(way == 6){
      for(i = 0;i < length;i++) gameArea[x - i][y] = 'X';
    }else if(way == 7){
      for(i = 0;i < length;i++) gameArea[x - i][y + i] = 'X';
    }
}
