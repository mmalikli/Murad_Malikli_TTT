/************************************************
This program is a simple tic-tac-toe game.
*************************************************/
#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>

/*
char * init_board();
void draw_board(char * board);
int ask_coord();
char check(char * board,int k);
bool play_turn(char* board,char player)
void game()
*/


/************************************************
 ** PROTOTYPES
 ************************************************/
char* init_board();
void draw_board(char* board);
//must return an index of board
int ask_coord();
char check(char * board, int k);
bool play_turn(char* board, char playerw);
//void print(char** Board);
//int isdraw(char** Board);
//char winningmove(char** Board, int i, int j);

int main() {

  char* board;
  int k;
  board = init_board();
  draw_board(board);
  //k = ask_coord();
  char player = 'X';
  while (true){
    if (player == 'X') {
    play_turn(board,'X');
    player = 'Y';
    }
  }
}

char* init_board() {
  char* B = calloc(9, sizeof(char));

  for(int i=0; i < 9; ++i) B[i] = ' ';
  
  return B;
}

void draw_board(char* board) {
  printf(" |1|2|3|\n");
  for(int i = 0; i < 3; ++i) {
    printf("%c|", 'A' + i);
    for(int j = 0; j < 3; ++j) {
      printf("%c|", board[i]);
    }
    printf("\n");
  }
}

int ask_coord() {
  char row;
  char col;
  printf("Player, make your move: ");
  fflush(stdout);
  scanf(" %c %c", &row, &col);
  if(row=='A' && col=='1') return 0;
  else if(row=='A' && col=='2') return 1;
  else if(row=='A' && col=='3') return 2;
  else if(row=='B' && col=='1') return 3;
  else if(row=='B' && col=='2') return 4;
  else if(row=='B' && col=='3') return 5;
  else if(row=='C' && col=='1') return 6;
  else if(row=='C' && col=='2') return 7;     
  else if(row=='C' && col=='3') return 8;          
  else {printf("Wrong Selection\n"); return -1;}
}
char check(char * board, int k){
  //check if game if finished
  for(int i = 0;i<0 ; i++) {
    if((board[i] == ' ') || (board[i] == 'X') || (board[i] == 'O')){
      //return
    } else {
      // board if full
      return -1;
    }
  }
  //???
  int col = k/3;
  int line = k%3;
  //if line has 3 same char
  for (int i = 0; i < 9; i=i+3){
  if((board[i] == board[i+1]) && (board[i+1] == board[i+2]) && board[i] != ' ') return board[i];  
  }
  for (int i = 0; i < 3; i++){
  if((board[i] == board[i+3]) && (board[i+3] == board[i+6]) && board[i] != ' ') return board[i];  
  }
  if((board[0] == board[4]) && (board[4] == board[8]) && board[0] != ' ') return board[0];
  if((board[2] == board[4]) && (board[4] == board[6]) && board[2] != ' ') return board[2];
  else {
    return ' ';
  }
  //if column has 3 same char;
  //if two diagonals  
}
bool play_turn(char* board, char playerw) {
bool nowiner = true;
int k = 0;
char cntr;
char player = 'X';
  if(player == 'X') {
    k = ask_coord();
    board[k] = 'X';
    cntr = check(board,k);
    if(cntr == -1) {
 //    nowiner = false;
      return -1;//drawl
    }
    if(cntr == 'X' || cntr == 'O') {
      printf("Winner is %c", cntr);
      return -1;
    }
    else {
      //player = 'O';
      draw_board(board);

    }
  }
  if(player == 'O') {
    k = ask_coord();
    board[k] = 'O';
    cntr = check(board,k);
    if(cntr == -1) {
      nowiner = false;
      return -1;//drawl
    }
    if(cntr == 'X' || cntr == 'O') {
      printf("Winner is %c", cntr);
      return -1;
    }
    else {
  draw_board(board);
      player = 'X';
    }
}
}