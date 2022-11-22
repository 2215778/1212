#include <stdio.h>
#include "bingoboard.h"

#define BINGONUM_HOLE 0//내가 선택한 숫자를 구분짓는 용도 
#define BINGO_RES_UNFINISHED -1
#define BINGO_RES_FINISHED 0

static int bingoboard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

int bingo_checkNum(int selNum)
{
    if (numberStatus[selNum] == BINGONUM_HOLE){
    
        return BINGO_NUMSTATUS_ABSENT;}
    
    return BINGO_NUMSTATUS_PRESENT;
}

void bingo_init(void) //형상만 생각
{
   int i, j;
   int cnt = 1;
   
   for(i=0;i<N_SIZE;i++)
       for(j=0;j<N_SIZE;j++)
       {
          if (cnt==15)
         {
            bingoboard[i][j] = BINGONUM_HOLE;
            numberStatus[cnt-1] = BINGONUM_HOLE;

            
            cnt++;
            
         }
         else
            numberStatus[cnt-1] = i*N_SIZE + j;
            bingoboard[i][j] = cnt++; 
      }
   {
      bingoboard[i][j] = cnt++;
   }
   
}

void bingo_print(void)
{
   int i, j;
   
   printf("====================================\n");
   for (i=0; i<N_SIZE; i++){
      for (j=0; j<N_SIZE; j++){
         if (bingoboard[i][j]== BINGONUM_HOLE)
           printf("X\t");
         else
           printf("%i\t", bingoboard[i][j]);
           
      }
      printf("\n");
      
   }
   printf("===================================\n\n");
   
}

void bingo_inputNum(int sel)
{
   int row, col;
   row = numberStatus[sel - 1]/N_SIZE;
   col = numberStatus[sel - 1]%N_SIZE;
   
   bingoboard[row][col] = BINGONUM_HOLE;
   numberStatus[sel-1] = BINGONUM_HOLE;
}

int bingo_countCompletedLine(void) //완성딘 줄 수 계산  
{
   int i, j;
   int cnt = 0;
   int checkBingo;
   
   //check row
   for (i=0; i<N_SIZE; i++){
      checkBingo = 1;
      for ( j=0; j<N_SIZE; j++){
         if (bingoboard[i][j]>0){
         checkBingo = 0;
         break;
         }
       }
      if (checkBingo == 1){
         cnt++;
      }
      
    }
    
    //check col
    for (j=0; j<N_SIZE; j++){
      checkBingo = 1;
      for ( i=0; i<N_SIZE; i++){
         if (bingoboard[i][j]>0){
         checkBingo = 0;
         break;
         }
       }
      if (checkBingo == 1){
         cnt++;
      }
      
    }
    
    //diagnol
    checkBingo =1;
    for(i=0;i<N_SIZE;i++)
    {
       if (bingoboard[i][j]>0)
       {
          checkBingo = 0;
          break;
          
      }
   }
   if (checkBingo ==1)
      cnt++;
      
      
   checkBingo =1;
   for(i=0; i<N_SIZE;i++)
   {
      if (bingoboard[i][N_SIZE-i-1]>0)
      {
         checkBingo=0;
         break;
      }
   }
   if (checkBingo ==1)
      cnt++;
      
   return cnt;
}
