#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int **Create_game_board(int size, int mines)
{
    int i, x, y, **board;

    // Creating the board

    board = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
        board[i] = (int *)malloc(size * sizeof(int));
    // Filling the board

    for (x = 0; x < size; x++)
        for (y = 0; y < size; y++)
            board[x][y] = 0;

    // Generating the mines
    int rand_x, rand_y;
    srand(time(NULL));
    for (i = 0; i < mines; i++)
    { 
        do
        {   
        rand_x = rand() % (size);
        rand_y = rand() % (size);
        }while(board[rand_x][rand_y]==-1);
        board[rand_x][rand_y] = -1;

        if (rand_y == 0)
        {
            if (rand_x == 0)
            {
                if (board[1][0] != -1)
                    board[1][0]++;
                if (board[1][1] != -1)
                    board[1][1]++;
                if (board[0][1] != -1)
                    board[0][1]++;
            }
            else if (rand_x == size - 1)
            {
                if (board[size - 2][0] != -1)
                    board[size - 2][0]++;
                if (board[size - 2][0] != -1)
                    board[size - 2][1]++;
                if (board[size - 1][0] != -1)
                    board[size - 1][1]++;
            }
            else
            {

                if (board[rand_x + 1][0] != -1)
                    board[rand_x + 1][0]++;
                if (board[rand_x + 1][1] != -1)
                    board[rand_x + 1][1]++;
                if (board[rand_x][1] != -1)
                    board[rand_x][1]++;
                if (board[rand_x - 1][0] != -1)
                    board[rand_x - 1][0]++;
                if (board[rand_x - 1][1] != -1)
                    board[rand_x - 1][1]++;
            }
        }
        else if (rand_y == size - 1)
        {

            if (rand_x == 0)
            {
                if (board[1][size - 1] != -1)
                    board[1][size - 1]++;
                if (board[1][size - 2] != -1)
                    board[1][size - 2]++;
                if (board[0][size - 2] != -1)
                    board[0][size - 2]++;
            }
            else if (rand_x == size - 1)
            {
                if (board[size - 2][size - 1] != -1)
                    board[size - 2][size - 1]++;
                if (board[size - 2][size - 1 - 2] != -1)
                    board[size - 2][size - 2]++;
                if (board[size - 1][size - 2] != -1)
                    board[size - 1][size - 2]++;
            }
            else
            {

                if (board[rand_x + 1][size - 1] != -1)
                    board[rand_x + 1][size - 1]++;
                if (board[rand_x + 1][size - 2] != -1)
                    board[rand_x + 1][size - 2]++;
                if (board[rand_x][size - 2] != -1)
                    board[rand_x][size - 2]++;
                if (board[rand_x - 1][size - 1] != -1)
                    board[rand_x - 1][size - 1]++;
                if (board[rand_x - 1][size - 2] != -1)
                    board[rand_x - 1][size - 2]++;
            }
        }
        else
        {
            if (rand_x == 0)
            {
                for (y = rand_y - 1; y <= rand_y + 1; y++)
                    if (board[1][y] != -1)
                        board[1][y]++;
                if (board[0][rand_y - 1] != -1)
                    board[0][rand_y - 1]++;
                if (board[0][rand_y + 1] != -1)
                    board[0][rand_y + 1]++;
            }
            else if (rand_x == size - 1)
            {
                for (y = rand_y - 1; y <= rand_y + 1; y++)
                    if (board[size - 2][y] != -1)
                        board[size - 2][y]++;
                if (board[size - 1][rand_y - 1] != -1)
                    board[size - 1][rand_y - 1]++;
                if (board[size - 1][rand_y + 1] != -1)
                    board[size - 1][rand_y + 1]++;
            }
            else
            {

                for (y = rand_y - 1; y <= rand_y + 1; y++)
                {
                    if (board[rand_x - 1][y] != -1)
                        board[rand_x - 1][y]++;
                    if (board[rand_x + 1][y] != -1)
                        board[rand_x + 1][y]++;
                }
                if (board[rand_x][rand_y - 1] != -1)
                    board[rand_x][rand_y - 1]++;
                if (board[rand_x][rand_y + 1] != -1)
                    board[rand_x][rand_y + 1]++;
            }
        }
    }
    return board;
}
char **Create_display_game(int size)
{
    int i, j;
    char **board;

    board = (char **)malloc(size * sizeof(char *));
    for (i = 0; i < size; i++)
        board[i] = (char *)malloc(size * sizeof(char));
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            board[i][j] = '.';

    return board;
}
void Delete_board(void **x, int size)
{
    int i;
    for (i = 0; i < size; i++)
        free(x[i]);
    free(x);
}
void Display_game(void **x, int size, bool isint,int score,bool mine_encountered)
{
    const cols = 50, rows = 8;
    int i, j;
    if (isint)
    {
        for (i = 0; i <= rows; i++)
            printf("\n");
        int **intmatrix = x;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j <= cols; j++)
                printf(" ");
            for (j = 0; j < size; j++)
                printf(" %d ", intmatrix[i][j]);
            printf("\n");
        }
    }
    else
    {
        char **charmatrix = x;
        if(mine_encountered==false)
        {
        printf("\n\n");
        for (j = 0; j <= cols-40; j++)
                printf(" ");
        printf("Your score is : %d",score);
        }
        for (i = 0; i <= rows; i++)
            printf("\n");
        for (i = 0; i < size; i++)
        {
            for (j = 0; j <= cols; j++)
                printf(" ");
            for (j = 0; j < size; j++)
                printf(" %c ", charmatrix[i][j]);
            printf("\n");
        }
    }
}

Read_player_input(char **board, int **r_board, int size, bool *mine_encountered,int *score)
{
    int i, j, x, y;
    bool outofrange;
    do
    {
        outofrange=false;
        printf("\nPlease give me the x axis of the location that you want to sweep :\n");
        scanf("%d", &x);
        printf("\n\nPlease give me the y axis of the location that you want to sweep :\n");
        scanf("%d", &y);
        if((x<1)||(x>size)||(y<1)||(y>size))
        {
        printf("The numbers are out of range please try another numbers");
        outofrange=true;
        }
    } while (outofrange);
    for (i = y - 2; i <= y; i++)
        for (j = x - 2; j <= x; j++)
            if ((i >= 0) && (i < size) && (j >= 0) && (j < size))
            {
                if (r_board[i][j] == -1)
                {
                    board[i][j] = 'X';
                    *mine_encountered = true;
                }
                else
                {
                    if(board[i][j]=='.')
                    {
                    board[i][j] = '0' + r_board[i][j];
                    if(*mine_encountered==false)(*score)++;
                    }
                }
            }
}
void Gameover(int score,bool gamewon)
{
    const cols=50;
    printf("%c",7);
    printf("\n\n");
    for(int i=0;i<=cols;i++)
    printf(" ");
    printf("Game over\n\n");
    for(int i=0;i<=cols;i++)
    printf(" ");
    if(gamewon){
    printf("You've won\n\n");
    }
    else
    printf("You've lost\n\n");
    for(int i=0;i<=cols;i++)
    printf(" ");
    printf("Your score is : %d",score);










}
bool Replay()
{
    int x;
    printf("\n\nDo you want to play again? :\n1-Yes     2-No\n");
    scanf("%d",&x);
    if(x==1)return true;
    else return false;










}
int main()
{
    int size, mine_number, **r_board,score=0;
    char **d_board;
    bool mine_encountered = false,won=false,replay=true;
    do
    {
    printf("Please enter the size of the board (the maximume size is 24 and the minimume is 3): \n");
    scanf("%d", &size);
    }while(size>24 || size<=2);
    system("cls");
    do
    {
    printf("Please enter the number of mines in the board (the maximume number of mines is %d): \n",size/2);
    scanf("%d", &mine_number);
    }while(mine_number>size/2 || mine_number<=0);
    while (replay)
    {
        mine_encountered = false;
        won=false;
        replay=true;
        score=0;
    system("cls");
    r_board = Create_game_board(size, mine_number);
    d_board = Create_display_game(size);
    Display_game(d_board, size, 0,score,mine_encountered);
    while (mine_encountered == false && score<size*size-mine_number)
    {
        Read_player_input(d_board, r_board, size, &mine_encountered,&score);
        system("cls");
        Display_game(d_board, size, 0,score,mine_encountered);
    }
    if(mine_encountered==false)won=true;
    Gameover(score,won);
    Delete_board(r_board, size);
    Delete_board(d_board, size);
    replay=Replay();
    }
}