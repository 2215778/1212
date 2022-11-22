#define N_SIZE 5//빙고 크기 
#define BINGO_NUMSTATUS_ABSENT -1
#define BINGO_NUMSTATUS_PRESENT 0

#define BINGO_RES_UNFINISHED -1
#define BINGO_RES_FINISHED 0



void bingo_init(void); //형상만 생각

void bingo_print(void);

void bingo_inputNum(int sel);

int bingo_countCompletedLine(void); //완성딘 줄 수 계산  

