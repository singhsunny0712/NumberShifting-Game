#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void setMatrix(int A[][4]);
void showMatrix(int A[][4]);
int readkey();
int checkWin(int A[][4]);
int shiftRight(int A[][4]);
int shiftLeft(int A[][4]);
int shiftUp(int A[][4]);
int shiftDown(int A[][4]);

void main()
{
    char name[20];
    printf("\t\t\tWELCOME FOR PLAYING GAME:\n\n");
    printf("\t\t\t  WHAT IS YOUR NAME:");
    scanf("%s",&name);
    system("cls");
    int A[4][4],move=500;
    setMatrix(A);
    while(move)
    {
        printf("\t\t\t\t    WELCOME %s\n\n",name);
        printf("\n\t\t\t\t Move Remaining : %d\n\n",move);
        showMatrix(A);
        if(checkWin(A))
        {
            printf("\nCongratulation you win in %d move",500-move);
            printf("\nPress any key to exit....");
            getch();
            exit(0);
        }
        switch(readkey())
        {
        case ESC:
            exit(0);
            break;
        case UP:
            if(!shiftUp(A))
                move++;
            break;
        case DOWN:
            if(!shiftDown(A))
                move++;
            break;
         case LEFT:
            if(!shiftLeft(A))
                move++;
            break;
          case RIGHT:
            if(!shiftRight(A))
                move++;
            break;
          default:
            move++;
        }
        system("cls");
        move--;
    }
    printf("\n\t\t\tTHANK YOU %s FOR PLAYING GAME",name);
    printf("\n\t\t\t  I HOPE YOU ENJOY THE GAME:");
    printf("\n\n\t\t\t   GAME MAKER SUNNY SINGH");

getch();
}
void setMatrix(int A[][4])
{
    int pool[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int maxIndex=14,index,i,j;
    srand(time(NULL));
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(maxIndex>=0)
            {
                index=rand()%(maxIndex+1);//same as random(maxIndex+1)
                A[i][j]=pool[index];
                pool[index]=pool[maxIndex];
                maxIndex--;
            }
            else
            {
                A[i][j]=0;
            }
        }
    }
}
void showMatrix(int A[][4])
{
    int i,j;
    printf("\n\t\t\t\t---------------------\n\t\t\t\t|");
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(A[i][j]!=0)
            {
                printf(" %-2d |",A[i][j]);
            }
            else
            {
                printf("    |");
            }
        }
         printf("\n\t\t\t\t---------------------\n");
         if(i!=3)
            printf("\t\t\t\t|");

    }
}

int readkey()
{
    int ch;
    ch=getch();
    if(ch==224)
    {
        ch=getch();
        switch(ch)
        {
        case 27:
            return(ESC);
            break;
        case 72:
            return(UP);
            break;
        case 80:
            return(DOWN);
            break;
        case 75:
            return(LEFT);
            break;
        case 77:
            return(RIGHT);
            break;
        default:
            return(5);



        }
    }
}
int checkWin(int A[][4])
{
    int i,j,k;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            k<15?k++:(k=0);
            if(A[i][j]!=k)
            {
                return(0);
            }
        }
    }
    return(1);
}
int shiftRight(int A[][4])
{
    int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(A[i][j]==0)
            {
                zerofound=1;
                break;
            }
        }
        if(zerofound)
            break;
    }
    if(j==0)
       {
           return(0);
       }
    else
       {
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
       }
}
int shiftLeft(int A[][4])
{
    int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(A[i][j]==0)
            {
                zerofound=1;
                break;
            }
        }
        if(zerofound)
            break;
    }
    if(j==3)
        return(0);
    else
       {
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
       }
}
int shiftUp(int A[][4])
{
    int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(A[i][j]==0)
            {
                zerofound=1;
                break;
            }
        }
        if(zerofound)
            break;
    }
    if(i==3)
        return(0);
    else
       {
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
       }
}
int shiftDown(int A[][4])
{
    int i,j,temp,zerofound=0;
     for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(A[i][j]==0)
            {
                zerofound=1;
                break;
            }
        }
        if(zerofound)
            break;
    }
    if(i==0)
        return(0);
    else
       {
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
       }
}
