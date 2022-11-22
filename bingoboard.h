#define N_LINE 2
#define N_SIZE 5
#define BINGO_NUMSTATUS_ABSENT -1
#define BINGO_NUMSTATUS_PRESENT 0



void bingo_init(void); //형상만 생각

void bingo_print(void);

void bingo_inputNum(int sel);

int bingo_countCompletedLine(void); //완성딘 줄 수 계산

int bingo_checkNum(int selNum);
