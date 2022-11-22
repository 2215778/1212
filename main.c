#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bingoboard.h"

#define BINGO_RES_UNFINISHED
#define BINGO_RES_FINISHED

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int check_gameEnd(void)
{
	int res=BINGO_RES_UNFINISHED;
	if(bingo_countCompleted()>=N_LINE)
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
		
		if(selNum<1||selNum>N_SIZE*N_SIZE||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT)
		{
			printf("%i is not on the board! select other one.\n",selNum);
		}
	} while(selNum<1||selNum>N_SIZE*N_SIZE||bingo_checkNum(selNum)==BINGO_NUMSTATUS_ABSENT);
	
	return selNum;
}

int main(int argc, char *argv[]) {
	
	int selNum;
	srand((unsigned) time(NULL));
	
	
	//opening
	printf("=====================================\n");
	printf("*************************************\n");
	printf("            bingo game               \n");
	printf("*************************************\n");	
	printf("=====================================\n\n\n");
	
	
	//game
	bingo_init();
	bingo_printBoard();
	bingo_inputNum(5);
	bingo_printBoard();
	bingo_inputNum(12);
	
	//initialize bingo board
	/*
	while(game is not end)  // ?? ???? N_BINGO ???? ????  
	{
	   //bingo board print
	   .
	   //print np. of completed line  
	   .
	   //selct a number
	   .
	   //update the board status
    }
	*/

	
	while(check_gameEnd()==BINGO_RES_UNFINISHED){
		bingo_print();
		printf("No, of completed line: %i\n",bingo_countCompletedLine());
		selNum=get_number();
		
		bingo_inputNum(selNum);
	}
	
	//ending
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("=====================================\n");
	printf("*************************************\n");
    printf("           congratulation!!!         \n");
	printf("             BINGO!!!!!!!           \n");
	printf("             U WINNN!!!!!          \n");
	printf("*************************************\n");
	printf("=====================================\n\n");
	
	
	return 0;
}
