//from the C algorithm book
#include <stdio.h>
#include <stdlib.h>
int solution;
int k=0;
void printboard(char * board, int n)
{
    int i, j ;
    if(k==0)
    {
        puts("\nPress 1 to run the program automatically or 2 to control with enter key. \n");
        
        scanf("%d",&k);
    }
    if(k==1)
    {
        system("\n");
        //getchar();
    }
    else
    {
        
        puts("\nPress Enter for next solution.\n");
        getchar();
    }
    printf("\nSolution # %d:\n\n", ++solution);
    for(i = 0; i < n; i++)
    {
        putchar('\t');
        for(j = 0; j < n; j++)
            printf("%c", * (board +i*n + j));
        putchar('\n');
    }
}

int aboveOK(char * board, int i, int j , int n)
{


i=i-1;

    for(i; i >= 0; i--)
        if(*(board + i*n + j) == 'Q')
            return 0;
    return 1;
}

int upleftOK(char * board, int i, int j , int n)
{
    for(i--, j-- ; i >= 0 && j >= 0; i--, j--)
        if(*(board + i*n + j) == 'Q')
            return 0;
    return 1;
}

int uprightOK(char * board, int i, int j , int n)
{
    for(i--, j++; i >= 0 && j < n; i--, j++)
        if(*(board + i*n + j) == 'Q')
            return 0;
    return 1;
}

void putqueen(char * board, int row, int n)
{
    int j ;
    if(row == n)
    {
        printboard(board, n);
        return;
    }
    for(j = 0; j < n; j++)
    {
        if(upleftOK(board,row,j,n) && aboveOK(board,row,j,n) && uprightOK(board,row,j,n))
        {
            *(board + row*n + j) = 'Q';
            putqueen(board, row+1, n);
            *(board + row*n + j) = '=';
        }
    }
}

void initboard(char * board, int n)
{
    int i;
    for(i = 0; i < n*n; i++)
        *(board + i) = '=';
}

int main()
{
    char * board;
    int n, c;
    do
    {
        if(c == 'y' || c == 'Y')
        k=0;
        solution = 0;
        puts("\nEnter size of board:");
        scanf("%d",&n);
        getchar();
        board = (char *)malloc(n*n*sizeof(char));
        initboard(board, n);
        putqueen(board,0,n);
        free(board);
        printf("\n%d solutions total for %d queens problem.",solution, n);
        puts("\n\nContinue? (y/n):");
        while((c = getchar()) == '\n');
    }while(c == 'y' || c == 'Y');
}
