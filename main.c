#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoBoard.h"

#define BINGO_RES_UNFINISHED -1
#define BINGO_RES_FINISHED 0

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int check_gameEnd(void)
{
    int res=BINGO_RES_UNFINISHED;
    if(bingo_countCompletedLine()>=N_LINE)
        res=BINGO_RES_FINISHED;
      
    return res;
}

int get_number(void)
{
    int selNum=0;
   
    do{
        printf("select a number: ");
        scanf("%d",&selNum);
        fflush(stdin);
      
        if (selNum<1 || selNum>N_SIZE*N_SIZE || bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT)
        {
            printf("%i is not on the board! select other one.\n",selNum);
        }
    } while(selNum<1 || selNum>N_SIZE*N_SIZE || bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT);
   
    return selNum;
}


int main(int argc, char *argv[]) {
   
    srand((unsigned)(time(NULL))); //랜덤함수  
    int selNum;
   
    //opening
    printf("======================================\n");
    printf("**************************************\n");
    printf("*         bingo game START!!         *\n");
    printf("**************************************\n");   
    printf("======================================\n\n");
   
    //game
    bingo_init();
    //initialize bingo board

   
    while(check_gameEnd()==BINGO_RES_UNFINISHED)  // 줄수가 N_BINGO 보다 작음  
    {
        //bingo board print
        bingo_print();
        
        //print no. of completed line
        printf("No. of completed line: %i\n",bingo_countCompletedLine());
      
        //select a number
        selNum=get_number();
      
        //update the board status
        bingo_inputNum(selNum);
    }
   

    //ending
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("======================================\n");
    printf("**************************************\n");
    printf("*          congratulation!!          *\n");
    printf("*            BINGO!!!!!!!            *\n");
    printf("*             U win!!!!!             *\n");
    printf("**************************************\n");
    printf("======================================\n\n");
   
    bingo_print();

    return 0;
}
