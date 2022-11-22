#include <stdio.h>
#include "bingoboard.h"

#define BINGONUM_HOLE -1 //���� ������ ���ڸ� �������� �뵵 


static int bingoboard[N_SIZE][N_SIZE];
static int numberStatus[N_SIZE*N_SIZE];

int bingo_checkNum(int selNum)
{
    if(numberStatus[selNum-1]==BINGONUM_HOLE)
        return BINGO_NUMSTATUS_ABSENT;
    
    return BINGO_NUMSTATUS_PRESENT;
}

void bingo_init(void) //���� ����
{
    int i, j, k;
    int randNum; //������ȣ(���° ���ڸ� ����)
    int maxNum=N_SIZE*N_SIZE; //���� �����ִ� ���� 
   
    for(i=0;i<N_SIZE*N_SIZE;i++)
        numberStatus[i]=BINGO_NUMSTATUS_ABSENT;
        
    for(i=0;i<N_SIZE;i++)
        for(j=0;j<N_SIZE;j++)
        {
        	randNum=rand()%maxNum; //�������ڼ���
			
			for(k=0;k<N_SIZE*N_SIZE;k++) //�� ���ڿ� ���� �������� 
			{
				if(numberStatus[k]==BINGO_NUMSTATUS_ABSENT) //���� k+1�� ���� �Ҵ��� �ȵǾ� �ִٸ�
				{
					if(randNum==0) //k+1�� randNum��° �����̸� 
					    break;
					else
					    randNum--; //�׷��� ������ �ϳ� ���� 
				}
			}
			//���� k+1�� �Ҵ� 
			
            numberStatus[k]=i*N_SIZE+j;
            bingoboard[i][j]=k+1;
            maxNum--;
        }
}

void bingo_print(void)
{
    int i, j;
   
    printf("====================================\n");
    for(i=0;i<N_SIZE;i++)
	{
        for(j=0;j<N_SIZE;j++)
		{
            if(bingoboard[i][j]==BINGONUM_HOLE)
                printf("X\t");
            else
                printf("%i\t",bingoboard[i][j]);
        }
        printf("\n");
    }
    printf("====================================\n\n");
}

void bingo_inputNum(int sel)
{
    int row, col;
    row=numberStatus[sel-1]/N_SIZE;
    col=numberStatus[sel-1]%N_SIZE;
   
    bingoboard[row][col]=BINGONUM_HOLE;
    numberStatus[sel-1]=BINGONUM_HOLE;
}

int bingo_countCompletedLine(void) //�ϼ��� �� �� ���  
{
    int i, j;
    int cnt=0;
    int checkBingo;
   
    //row
    for(i=0;i<N_SIZE;i++)
    {
        checkBingo=1;
        for(j=0;j<N_SIZE;j++)
            if(bingoboard[i][j]>0)
		    {
                checkBingo=0;
                break;
            }
        if(checkBingo==1)
            cnt++;
    }
    
    //col
    for(j=0;j<N_SIZE;j++)
	{
        checkBingo=1;
        for(i=0;i<N_SIZE;i++)
            if(bingoboard[i][j]>0)
		    {
                checkBingo=0;
                break;
            }
        if(checkBingo==1)
            cnt++;
    }
    
    //diagnol
    checkBingo =1;
    for(i=0;i<N_SIZE;i++)
    {
        if(bingoboard[i][i]>0)
        {
            checkBingo=0;
            break;
        }
    }
    if(checkBingo==1)
        cnt++;
      
      
    checkBingo=1;
    for(i=0;i<N_SIZE;i++)
    {
      if(bingoboard[i][N_SIZE-i-1]>0)
        {
            checkBingo=0;
            break;
        }
    }
    if(checkBingo==1)
        cnt++;
      
      
    return cnt;
}
