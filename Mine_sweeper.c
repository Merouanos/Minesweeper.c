#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int **Create_game_board(int size,int* rand_mine)
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
    do
    {
   
    
    (*rand_mine) = rand() % ((size*size)/5);
    }while(*rand_mine<2);
    
    for (i = 1; i <=*rand_mine ; i++)
    {
        do
        {
            rand_x = rand() % (size);
            rand_y = rand() % (size);
        } while (board[rand_x][rand_y] == -1);
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
void Display_game(void **x, int size, bool isint, int score, bool mine_encountered)
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
        if (mine_encountered == false)
        {
            printf("\n\n");
            for (j = 0; j <= cols - 40; j++)
                printf(" ");
            printf("Your score is : %d", score);
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

void Read_player_input(int *x, int *y, int size)
{
    bool outofrange;
    do
    {
        outofrange = false;
        printf("\nPlease give me the x axis of the location that you want to sweep (x starts from 1) :\n");
        scanf("%d", x);
        printf("\n\nPlease give me the y axis of the location that you want to sweep(y starts from 1) :\n");
        scanf("%d", y);
        if ((*x < 1) || (*x > size) || (*y < 1) || (*y > size))
        {
            printf("The numbers are out of range please try another numbers");
            outofrange = true;
        }
    } while (outofrange);
}
int highscore(int score)
{
    int current_high_score;
    FILE *f;
    f=fopen("score.txt","r+");
    if(fscanf(f,"%d",&current_high_score)==-1)
    {
    fprintf(f,"%d",0);
    rewind(f);
    current_high_score=0;
    }
    if(current_high_score<score)
    {
        fprintf(f,"%d",score);
        return score;
    }
    else return current_high_score;







}
void Checkpoint(int x, int y, int **r_board, char **d_board, int *score, bool *mine_encountered, int size, bool zero)
{
    if (!zero && r_board[x][y] == -1)
    {
        d_board[x][y] = 'X';
        *mine_encountered = true;
    }
    else
    {
        if (d_board[x][y] == '.'&&  r_board[x][y]==0)
        {
            d_board[x][y] = '0' + r_board[x][y];
            (*score)++;
            if (x + 1 < size)
                Checkpoint(x + 1, y, r_board, d_board, score, mine_encountered, size, true);
            if (x - 1 > -1)
                Checkpoint(x - 1, y, r_board, d_board, score, mine_encountered, size, true);
            if (y + 1 < size)
                Checkpoint(x, y + 1, r_board, d_board, score, mine_encountered, size, true);
            if (y - 1 > -1)
                Checkpoint(x, y - 1, r_board, d_board, score, mine_encountered, size, true);
            
        }
        else if (!zero && d_board[x][y]=='.')
        {
            d_board[x][y] = '0' + r_board[x][y];
            (*score)++;
        }
    }
}
void Gameover(int score, bool gamewon)
{
    const cols = 50;
    printf("%c", 7);
    printf("\n\n");
    for (int i = 0; i <= cols; i++)
        printf(" ");
    printf("Game over\n\n");
    for (int i = 0; i <= cols; i++)
        printf(" ");
    if (gamewon)
    {
        printf("You've won\n\n");
    }
    else
        printf("You've lost\n\n");
    for (int i = 0; i <= cols; i++)
        printf(" ");
    printf("Your score is : %d", score);
    printf("\n");
    for (int i = 0; i <= cols; i++)
        printf(" ");
    printf("The current highscore is : %d",highscore(score));
}

bool Replay()
{
    int x;
    printf("\n\nDo you want to play again? :\n1-Yes     2-No\n");
    scanf("%d", &x);
    if (x == 1)
        return true;
    else
        return false;
}
int main()
{
    int x, y, size, mine_number, **r_board, score = 0;
    char **d_board;
    bool mine_encountered = false, won = false, replay = true;
    do
    {
        printf("Please enter the size of the board either 8 or 16 or 24 : \n");
        scanf("%d", &size);
    } while (size!=8 &&size!=16 && size!=24);
    system("cls");
    while (replay)
    {
        mine_encountered = false;
        won = false;
        replay = true;
        score = 0;
        system("cls");
        r_board = Create_game_board(size,&mine_number);
        d_board = Create_display_game(size);
        Display_game(d_board, size, 0, score, mine_encountered);
        while (mine_encountered == false && score < (size * size)-mine_number)
        {
            Read_player_input(&x, &y, size);
            Checkpoint(x-1, y-1, r_board, d_board, &score, &mine_encountered, size, false);
            system("cls");
            Display_game(d_board, size, 0, score, mine_encountered);
        }
        if (mine_encountered == false)
            won = true;
        Gameover(score, won);
        Delete_board(r_board, size);
        Delete_board(d_board, size);
        replay = Replay();
    }
}
