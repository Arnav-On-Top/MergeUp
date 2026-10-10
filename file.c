#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[6][6]={0};
    int n, i, j, k, r, c, num, empty, changed, gameover;
    char move;
    srand(time(0));
    printf("MergeUp\n");
    printf("1. 4x4 Board \n");
    printf("2. 5x5 Board \n");
    printf("3. 6x6 Board \n");
    scanf("%d", &n);
    if(n==1)
        n=4;
    else if (n==2)
        n=5;
    else if (n==3)
        n=6;
    else
    {
        printf("Invalid choice!");
        return 0;
    }
    for (k=0; k<2; k++)
    {
        r=rand()%n;
        c=rand()%n;
        if(a[r][c]==0)
            a[r][c]=2;
        else
            k--;
    }
    while (1)
    {
        int old[6][6];
        for (i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                old[i][j]=a[i][j];
            }
        }
        printf("\n");
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
                printf("%5d", a[i][j]);

            printf("\n");
        }
        printf("\n W=up, S=Down");
        printf("\n A=Left, D=Right");
        printf("\n Q=Quit");
        printf("\n Enter move: ");
        scanf(" %c", &move);
        if(move=='q' || move=='Q')
            break;
        if(move=='a' || move=='A')
        {
            for (i=0; i<n; i++)
            {
                for(j=0; j<n-1; j++)
                {
                    for(k=0; k<n-1; k++)
                    {
                        if(a[i][k]==0)
                        {
                            a[i][k]=a[i][k+1];
                            a[i][k+1]=0;
                        }
                    }
                }
                for (j=0; j<n-1; j++)
                {
                    if(a[i][j]==a[i][j+1])
                    {
                        a[i][j]*=2;
                        a[i][j+1]=0;
                    }
                }
                for (j=0; j<n-1; j++)
                {
                    for (k=0; k<n-1; k++)
                    {
                        if(a[i][k]==0)
                        {
                            a[i][k]=a[i][k+1];
                            a[i][k+1]=0;
                        }
                    }
                }
            }
        }
        else if(move=='d' || move=='D')
        {
            for (i=0; i<n; i++)
            {
                for(j=0; j<n-1; j++)
                {
                    for(k=n-1; k>0; k--)
                    {
                        if(a[i][k]==0)
                        {
                            a[i][k]=a[i][k-1];
                            a[i][k-1]=0;
                        }
                    }
                }
                for (j=n-1; j>0; j--)
                {
                    if(a[i][j]==a[i][j-1])
                    {
                        a[i][j]*=2;
                        a[i][j-1]=0;
                    }
                }
                for (j=0; j<n-1; j++)
                {
                    for (k=n-1; k>0; k--)
                    {
                        if(a[i][k]==0)
                        {
                            a[i][k]=a[i][k-1];
                            a[i][k-1]=0;
                        }
                    }
                }
            }
        }
        else if (move=='w' || move=='W')
        {
            for(j=0; j<n; j++)
            {
                for(i=0; i<n-1; i++)
                {
                    for(k=0; k<n-1; k++)
                    {
                        if(a[k][j]==0)
                        {
                            a[k][j]=a[k+1][j];
                            a[k+1][j]=0;
                        }
                    }
                }
                for(i=0; i<n-1; i++)
                {
                    if(a[i][j]==a[i+1][j])
                    {
                        a[i][j]*=2;
                        a[i+1][j]=0;
                    }
                }
                for (i=0; i<n-1; i++)
                {
                    for(k=0; k<n-1; k++)
                    {
                        if(a[k][j]==0)
                        {
                            a[k][j]=a[k+1][j];
                            a[k+1][j]=0;
                        }
                    }
                }
            }
        }
        else if (move=='s' || move=='S')
        {
            for(j=0; j<n; j++)
            {
                for (i=0; i<n-1; i++)
                {
                    for(k=n-1; k>0; k--)
                    {
                        if(a[k][j]==0)
                        {
                            a[k][j]=a[k-1][j];
                            a[k-1][j]=0;
                        }
                    }
                }
                for (i=n-1; i>0; i--)
                {
                    if(a[i][j]==a[i-1][j])
                    {
                        a[i][j]*=2;
                        a[i-1][j]=0;
                    }
                }
                for (i=0; i<n-1; i++)
                {
                    for (k=n-1; k>0; k--)
                    {
                        if(a[k][j]==0)
                        {
                            a[k][j]=a[k-1][j];
                            a[k-1][j]=0;
                        }
                    }
                }
            }
        }
        else
        {
            printf("Invalid move! \n");
            continue;
        }
        changed=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(a[i][j]!=old[i][j])
                {
                    changed=1;
                }
            }
        }
        if(changed==1)
        {
            empty=0;
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    if(a[i][j]==0)
                    {
                        empty=1;
                    }
                }
            }
            if(empty==1)
            {
                while (1)
                {
                    r=rand()%n;
                    c=rand()%n;
                    if(a[r][c]==0)
                    {
                        a[r][c]=2;
                        break;
                    }
                }
            }
        }
        else
        {
            printf("\n Try another move. \n");
        }
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                if(a[i][j]>=2048)
                {
                    printf("\n You Win! \n");
                    return 0;
                }
            }
        }
        empty=0;
        gameover=1;
        for (i=0; i<n; i++)
        {
            for (j=0; j<n; j++)
            {
                if(a[i][j]==0)
                {
                    empty=1;
                }
                if(j<n-1 && a[i][j]==a[i][j+1])
                {
                    gameover=0;
                }
                if(i<n-1 && a[i][j]==a[i+1][j])
                {
                    gameover=0;
                }
            }
        }
        if(empty==0 && gameover==1)
        {
            printf("\n Game Over! No Moves left \n");
            return 0;
        }
    }
    printf("\n Thanks for playing! \n");
    return 0;
}