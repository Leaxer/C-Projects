#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
Function: printMap
----------------------------------
It does: Prints the game area, uses array of the game area as parameter

gameArea: Array of the game area

*/
void printMap(char gameArea[15][30]);

/*
Function: dice
----------------------------------
It does: Generate a random integer in a range of [1,6]

returns: a random integer

*/
int dice();

/*
Function: startGame
----------------------------------
It does: decides(according to dice numbers) who will start the game

returns: # of the player who will start the game
*/
int startGame();

void flush(char);

int main(){
  srand(time(NULL));
  char gameArea[15][30];

  //Player 1 start pos
  gameArea[1][1] = '1';
  //Player 1 penalty points
  gameArea[1][14] = 'X';
  gameArea[7][28] = 'X';
  gameArea[13][14] = 'X';
  //Player 1 finish line
  gameArea[2][1] = '_';

  //Player 2 start pos
  gameArea[3][3] = '2';
  //Player 2 penalty points
  gameArea[3][10] = 'X';
  gameArea[3][18] = 'X';
  gameArea[5][26] = 'X';
  gameArea[10][26] = 'X';
  gameArea[11][10] = 'X';
  gameArea[11][18] = 'X';
  //Player 2 finish line
  gameArea[4][3] = '_';

  int i,j;
  int a = 30;
  int b = 0;
  for(i = 0;i < 15;i+=2){
    for(j = b;j < a;j++){//Set game area's bounds
      gameArea[i][j] = '-';
    }
    
    if(i > 4){//For game area's top 3 bounds
      b-=2;
      a+=2;
    }else{//For game area's bottom 3 bounds
      b+=2;
      a-=2;
    }
    
    if(i == 4){//That means it set game area's top 3 bounds, now we set new values to set game area's bottom 3 bounds
      i = 8;
      b = 4;
      a = 26;
     }
  }
  
  a = 14;
  b = 1;
  for(i = 0;i < 30;i+=2){
    for(j = b;j < a;j++){
      gameArea[j][i] = '|';
    }
    if(i > 4){
      b-=2;
      a+=2;
    }else{
      b+=2;
      a-=2;
    }
    
    if(i == 4){
      i = 23;
      b = 5;
      a = 10;
     }
  }

  for(i = 1;i < 14;i++){
    for(j = 1;j < 29;j++){
      //If cell is not equal to special characters a '|','1'... Set the cell to space
      if(gameArea[i][j] != '|' && gameArea[i][j] != '-' && gameArea[i][j] != '1' && gameArea[i][j] != '2' && gameArea[i][j] != 'X' && gameArea[i][j] != '_') gameArea[i][j] = ' ';
    }
  }

  char c;
  int player1,player2;
  int player1X = 1,player1Y = 1,player1F = 0;
  int player2X = 3,player2Y = 3,player2F = 0;
  int temp;
  int reverseX = 0,reverseY = 0;
  int who;
  
   printMap(gameArea);
   who = startGame();
   printf("\n");
   if(who == 1) printf("* PLAYER 1 will start the game... *\n");
   else printf("* PLAYER 2 will start the game... *\n");
      
   while(player1F != 2 && player2F != 2){//Player1f or player2f will be '2' if they finish the game and while loop will end
    if(who == 1){//If player1's dice is bigger it will start first
     printf("\033[0;33m");
     printf("PLAYER 1... press ENTER to dice");
     scanf("%c",&c);
     player1 = dice();
     printf("DICE: %d\n",player1);
     printf("\033[0m");
     flush(c);
     
     gameArea[player1X][player1Y] = ' ';//Set first position to ' '
     if(reverseX == 0){//If the player is in the top or right line
      if(player1Y + player1 > 28){// If it reaches top right corner, now it will move in the right line
        player1F = 1;
        temp = player1 - (28 - player1Y);
        player1Y = 28;
        if(player1X + temp >= 13){// If it reaches to bottom right corner, set reverseX = 1 and move at bottom line one time
          reverseX = 1;
          temp = player1 - (13 - player1X);
          player1X = 13;
          player1Y = 28 - temp;
        }else{
          player1X = player1X + temp;
        }
        if(gameArea[player1X][player1Y] == 'X'){
          printf("\033[0;33m");
          printf("Penalty for player 1...\n");
          printf("\033[0m");
          player1X = player1X - 2;//If player's new position is equal to 'X', set new position to (current position - 2)
          }
      }else{
        player1Y = player1Y + player1;
        if(gameArea[player1X][player1Y] == 'X'){
          printf("\033[0;33m");
          printf("Penalty for player 1...\n");
          printf("\033[0m");
          player1Y = player1Y - 2;
        }
       }
     }else{
      if(player1Y - player1 < 1){// If it reaches bottom left corner, now it will move in the left line
        temp = player1 - (player1Y - 1);
        player1Y = 1;
        player1X = player1X - temp;
        if(player1X < 1){// If it reaches to top left corner, set player1f = 2,that means player finish the game, and move at top line one time
          temp = player1 - (player1X + temp - 1);
          player1X = 1;
          player1Y = player1Y + temp;
          player1F = 2;
        }else if(player1X <= 2) player1F = 2;
      }else{
        player1Y = player1Y - player1;
      }
      if(gameArea[player1X][player1Y] == 'X'){
         printf("\033[0;33m");
         printf("Penalty for player 1...\n");
         printf("\033[0m");
         player1Y = player1Y + 2;
        }
     }
     gameArea[player1X][player1Y] = '1';//Set new position to '1'
     if(player1F == 2) break;
     
     printf("\033[0;34m");
     printf("PLAYER 2... press ENTER to dice");
     scanf("%c",&c);
     player2 = dice();
     printf("DICE: %d\n",player2);
     printf("\033[0m");
    
     gameArea[player2X][player2Y] = ' ';
     if(reverseY == 0){
      if(player2Y + player2 > 26){
        player2F = 1;
        temp = player2 - (26 - player2Y);
        player2Y = 26;
        if(player2X + temp >= 11){
          reverseY = 1;
          temp = player2 - (11 - player2X);
          player2X = 11;
          player2Y = 26 - temp;
        }else{
          player2X = player2X + temp;
        }
        if(gameArea[player2X][player2Y] == 'X'){
          printf("\033[0;34m");
          printf("Penalty for player 2...\n");
          printf("\033[0m");
          player2X = player2X - 2;
          }
       }else{
         player2Y = player2Y + player2;
         if(gameArea[player2X][player2Y] == 'X'){
           printf("\033[0;34m");
           printf("Penalty for player 2...\n");
           printf("\033[0m");
           player2Y = player2Y - 2;
           }
       }
     }else{
      if(player2Y - player2 < 3){
        temp = player2 - (player2Y - 3);
        player2Y = 3;
        player2X = player2X - temp;
        if(player2X < 3){
           temp = player2 - (player2X + temp - 3);
           player2X = 3;
           player2Y = player2Y + temp;
           player2F = 2;
         }else if(player2X <= 4) player2F = 2;
      }else{
        player2Y = player2Y - player2;
      }
      if(gameArea[player2X][player2Y] == 'X'){
        printf("\033[0;34m");
        printf("Penalty for player 2...\n");
        printf("\033[0m");
        player2Y = player2Y + 2;
        }
     }
     gameArea[player2X][player2Y] = '2';
    
    }else{//If player2's dice is bigger it will start first
     printf("\033[0;34m");
     printf("PLAYER 2... press ENTER to dice");
     scanf("%c",&c);
     player2 = dice();
     printf("DICE: %d\n",player2);
     printf("\033[0m");
     flush(c);
     
     gameArea[player2X][player2Y] = ' ';
     if(reverseY == 0){
       if(player2Y + player2 > 26){
         player2F = 1;
         temp = player2 - (26 - player2Y);
         player2Y = 26;
         if(player2X + temp >= 11){
           reverseY = 1;
           temp = player2 - (11 - player2X);
           player2X = 11;
           player2Y = 26 - temp;
         }else{
           player2X = player2X + temp;
         }
         if(gameArea[player2X][player2Y] == 'X'){
           printf("\033[0;34m");
           printf("Penalty for player 2...\n");
           printf("\033[0m");
           player2X = player2X - 2;
          }
       }else{
         player2Y = player2Y + player2;
         if(gameArea[player2X][player2Y] == 'X'){
           printf("\033[0;34m");
           printf("Penalty for player 2...\n");
           printf("\033[0m");
           player2Y = player2Y - 2;
          }
        }
     }else{
       if(player2Y - player2 < 3){
         temp = player2 - (player2Y - 3);
         player2Y = 3;
         player2X = player2X - temp;
         if(player2X < 3){
           temp = player2 - (player2X + temp - 3);
           player2X = 3;
           player2Y = player2Y + temp;
           player2F = 2;
         }else if(player2X <= 4) player2F = 2;
       }else{
         player2Y = player2Y - player2;
         }
       if(gameArea[player2X][player2Y] == 'X'){ 
         printf("\033[0;34m");
         printf("Penalty for player 2...\n");
         printf("\033[0m");
         player2Y = player2Y + 2;
         }
     }
     gameArea[player2X][player2Y] = '2';
     if(player2F == 2) break;
     
     printf("\033[0;33m");
     printf("PLAYER 1... press ENTER to dice");
     scanf("%c",&c);
     player1 = dice();
     printf("DICE: %d\n",player1);
     printf("\033[0m");
     
     gameArea[player1X][player1Y] = ' ';
     if(reverseX == 0){
      if(player1Y + player1 > 28){
        player1F = 1;
        temp = player1 - (28 - player1Y);
        player1Y = 28;
        if(player1X + temp >= 13){
          reverseX = 1;
          temp = player1 - (13 - player1X);
          player1X = 13;
          player1Y = 28 - temp;
        }else{
          player1X = player1X + temp;
        }
        if(gameArea[player1X][player1Y] == 'X'){
          printf("\033[0;33m");
          printf("Penalty for player 1...\n");
          printf("\033[0m");
          player1X = player1X - 2;
          }
      }else{
        player1Y = player1Y + player1;
        if(gameArea[player1X][player1Y] == 'X'){
          printf("\033[0;33m");
          printf("Penalty for player 1...\n");
          printf("\033[0m");
          player1Y = player1Y - 2;
          }
       }
     }else{
      if(player1Y - player1 < 1){
        temp = player1 - (player1Y - 1);
        player1Y = 1;
        player1X = player1X - temp;
        if(player1X < 1){
          temp = player1 - (player1X + temp - 1);
          player1X = 1;
          player1Y = player1Y + temp;
          player1F = 2;
        }else if(player1X <= 2) player1F = 2;
      }else{
        player1Y = player1Y - player1;
      }
      if(gameArea[player1X][player1Y] == 'X'){
        printf("\033[0;33m");
        printf("Penalty for player 1...\n");
        printf("\033[0m");
        player1Y = player1Y + 2;
        }
     }
     gameArea[player1X][player1Y] = '1';
    }
    flush(c);
    if(player1F != 2 && player2F != 2) printMap(gameArea);
  }
  
  
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  if(who == 1){//If player1 starts first, then check it's playerf value first
    if(player1F == 2){
      printf("\033[0;33m");
      printf("Player 1 won the game!\n");
      printf("\033[0m");
      }
    else{
      printf("\033[0;34m");
      printf("Player 2 won the game!\n");
      printf("\033[0m");
      }
  }else{
    if(player2F == 2){
      printf("\033[0;34m");
      printf("Player 2 won the game!\n");
      printf("\033[0m");
      }
    else{
      printf("\033[0;33m");
      printf("Player 1 won the game!\n");
      printf("\033[0m");
      }
  }
  printMap(gameArea);
  return 0;
}

void printMap(char gameArea[15][30]){
    int i,j;
    char c;
    /*
     Printf every cell of the game area
     Check for every cell if they are equal to special characters like '1','2'... If they equal color print the cell with color
    */
    for(i = 0;i < 15;i++){
     for(j = 0;j < 30;j++){
      c = gameArea[i][j];
      if(c == '1'){
        printf("\033[0;33m");
        printf("%c",c);
        printf("\033[0m");
      }else if(c == '2'){
        printf("\033[0;34m");
        printf("%c",c);
        printf("\033[0m");
      }else if(c == 'X'){
        printf("\033[0;31m");
        printf("%c",c);
        printf("\033[0m");
      }else if(c == '_'){
        printf("\033[0;32m");
        printf("%c",c);
        printf("\033[0m");
      }else printf("%c",c);
     }
    printf("\n");
  }
  printf("\n");
}

int dice(){
    int random;
    while((random = rand()%7) == 0) ;//Get a random integer in a range of [1,6]
    return random;
}

int startGame(){//Controls dice numbers and return number who has bigger dice number
   printf("To start to game, players should dice and decide who is going to start first according to it ...\n");
   int p1,p2;
   char c;
   printf("\033[0;33m");
   printf("PLAYER 1... press ENTER to dice");
   scanf("%c",&c);
   p1 = dice();
   printf("DICE: %d\n",p1);
   printf("\033[0m");
   flush(c);

   printf("\033[0;34m");
   printf("PLAYER 2... press ENTER to dice");
   scanf("%c",&c);
   p2 = dice();
   printf("DICE: %d\n",p2);
   printf("\033[0m");
   flush(c);

   
   while(p1 == p2){
     printf("Same dice value... Please try again.\n");
     printf("\033[0;33m");
     printf("PLAYER 1... press ENTER to dice");
     scanf("%c",&c);
     p1 = dice();
     printf("DICE: %d\n",p1);
     printf("\033[0m");
     flush(c);

     printf("\033[0;34m");
     printf("PLAYER 2... press ENTER to dice");
     scanf("%c",&c);
     p2 = dice();
     printf("DICE: %d\n",p2);
     printf("\033[0m");
     flush(c);	
   }
   
    if(p1 < p2) return 2;
    else if(p1 > p2) return 1;
    
}

void flush(char c){
   while(c != EOF && c != '\n') c = getchar();
}
