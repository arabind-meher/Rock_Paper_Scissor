/**************************************************
---------------------------------------------------
NAME     : SCISSOR PAPER ROCK
DESIGNER : ARABIND
VRRSION  : 1.0.0
---------------------------------------------------
**************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

/**FUNCTIONS TO PLAY GAME**/
void showpoint(int,int);
int check(int);

/**MAIN FUNCTION**/
void main()
{
    int a,n,i,p1=0,p2=0,w;

    printf("_SCISSOR_PAPER_ROCK_\n\n");

    printf("BEST OF : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        showpoint(p1,p2);

        re:
        printf("\nENTER : ");
        scanf("%d",&a);

        if(a<1 && a>3)
        {
            printf("Invalid Input\n");
            goto re;
        }

        w=check(a);

        if(w==1)
        {
            printf("\nWINNER\n");
            p1++;
        }
        else if(w==-1)
        {
            printf("\nLOOSER\n");
            p2++;
        }
        else
            printf("\nDRAW\n");

        getch();
    }

    showpoint(p1,p2);

    if(p1>p2)
        printf("\nWINNER\n");
    else if(p2>p1)
        printf("\nLOOSER\n");
    else
        printf("\nDRAW\n");

    getch();
}

/**TO GET THE OUTCOME**/
int check(int a)
{
    char s1[10],s2[10];

    int b=1+rand()%3;

    switch(a)
        {
        case 1:
            strcpy(s1,"SCISSOR");
            break;
        case 2:
            strcpy(s1,"PAPER");
            break;
        case 3:
            strcpy(s1,"ROCK");
            break;
        }

    switch(b)
        {
        case 1:
            strcpy(s2,"SCISSOR");
            break;
        case 2:
            strcpy(s2,"PAPER");
            break;
        case 3:
            strcpy(s2,"ROCK");
            break;
        }

    if(a==b)
    {
        printf("%s X %s",s1,s2);
        return 0;
    }
    else if((a==1 && b==2) || (a==2 && b==3) || (a==3 && b==1))
    {
        printf("%s X %s",s1,s2);
        return 1;
    }
    else if((b==1 && a==2) || (b==2 && a==3) || (b==3 && a==1))
    {
        printf("%s X %s",s1,s2);
        return -1;
    }
}

/**TO SHOW THE POINT TABLE**/
void showpoint(int p1, int p2)
{
    system("CLS");

    printf("_SCOSSOR_PAPER_ROCK_\n\n");

    printf("\n1. SCISSOR\n2. PAPER\n3. ROCK\n");

    printf(" ______ ______\n");
    printf("|      |      |\n");
    printf("|  P1  |  P2  |\n");
    printf("|______|______|\n");
    printf("|      |      |\n");
    printf("|  %d   |   %d  |\n",p1,p2);
    printf("|______|______|\n");
}
