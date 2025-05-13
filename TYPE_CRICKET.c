#include <stdio.h>  //PRESENTING TO YOU
#include <stdlib.h> //A GAME MADE POSSIBLE BY TALEEM HOSSIAN
#include <time.h>   //TYPE CRICKET

int main()
{
    int toss, call, utcl, ulct, bowlcount, user, user_score, user_wicket, comp, comp_score, comp_wicket, pa, warningcount;
play_again:
    utcl = 0;
    ulct = 0;
    user_score = 0;
    user_wicket = 0;
    comp_score = 0;
    comp_wicket = 0;
    warningcount = 3;
    srand(time(0));
    toss = rand() % 2 + 1;
    printf("A GAME OF CRICKET WILL START BETWEEN YOU AND COMPUTER ...\nEACH PLAYER WILL HAVE 5 WICKETS...\nMAY THE BEST ONE WIN\n");
    printf("UMPIRE HAVE COME TO THE FIELD FOR TOSS\nTYPE 1 FOR HEAD AND 2 FOR TAIL\n");
    scanf("%d", &call);
    if (call != 1 && call != 2)
    {
        printf("\n Wrong Input");
        warningcount--;
        if (warningcount == 0)
        {
            printf("\n\n\t ***YOU ARE ELIMINATED!***");
            goto end_screen;
        }
        else
        {
            printf("\n YOU HAVE ENTERED WRONG INPUT ... DO THIS %d MORE TIMES AND YOU WILL BE ELIMINATED\nNOW BY DEFAULT RULES YOU WILL LOSE THE TOSS", warningcount);
        }
    }
    printf("\nUMPIRE HAS TOSSED THE COIN IN THE AIR AND IT's A ...\n");
    if (toss == 1)
        printf("HEAD!\n");
    else
        printf("TAIL!\n");
    if (toss == call)
    {
        printf("YOU HAVE WON THE TOSS!\n");
        printf("UMPIRE IS ASKING YOU WHAT WILL YOU CHOOSE?\nTYPE 1 FOR BAT AND 2 FOR BOWL\n");
        scanf("%d", &call);
        if (call == 1)
        {
            printf("YOU HAVE SELECTED TO BAT FIRST\n");
            utcl++;
        }
        else if (call == 2)
        {
            printf("YOU HAVE SELECTED TO BOWL FIRST\n");
            ulct++;
        }
        else
        {
            printf("\n Wrong Input");
            warningcount--;
            if (warningcount == 0)
            {
                printf("\n\n\t ***YOU ARE ELIMINATED!***");
                goto end_screen;
            }
            else
            {
                printf("\n YOU HAVE ENTERED WRONG INPUT ... DO THIS %d MORE TIMES AND YOU WILL BE ELIMINATED", warningcount);
            }
        }
    }
    else
    {
        printf("YOU HAVE LOST THE TOSS\n");
        call = rand() % 2 + 1;
        if (call == 1)
        {
            printf("COMP HAS SELECTED TO BAT FIRST\n");
            ulct++;
        }
        else
        {
            printf("COMP HAS SELECTED TO BOWL FIRST\n");
            utcl++;
        }
    }
    if (ulct == 1)
    {
        printf("\nYOUR PLAYERS HAVE COME TO FIELD\nCOMP HAS SENT ITS TWO FINEST BATSMAN\nLET's SEE WHAT HAPPENS");
        while (comp_wicket != 5)
        {
            comp = rand() % 6 + 1;
            printf("\nENTER YOUR CHOICE = ");
            scanf("%d", &user);
            if (user == 1 || user == 2 || user == 3 || user == 4 || user == 5 || user == 6)
            {
                if (user == comp)
                {
                    printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\n\t***WHAT A DELIVARY! IT IS A WICKET !***", user, comp);
                    comp_wicket++;
                }
                else
                {
                    printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\t*COMP GETS %d RUN(s) HERE*", user, comp, comp);
                    comp_score = comp_score + comp;
                }
            }
            else
            {
                printf("\n Wrong Input");
                warningcount--;
                if (warningcount == 0)
                {
                    printf("\n\n\t ***YOU ARE ELIMINATED!***");
                    goto end_screen;
                }
                else
                {
                    printf("\n YOU HAVE ENTERED WRONG INPUT ... DO THIS %d MORE TIMES AND YOU WILL BE ELIMINATED", warningcount);
                }
            }
            printf("\n\n\t*COMPUTER SCORE IS %d/%d*", comp_score, comp_wicket);
        }
        printf("\n\n\t\t***COMPUTER TEAM IS ALL OUT FOR %d RUNS***", comp_score);
        printf("\nYOU MUST SCORE %d RUNS TO WIN BEFORE YOU LOSE 5 WICKETS", comp_score + 1);
        printf("\nCOMPUTER PLAYERS HAVE COME TO FIELD\nYOU HAVE SENT TWO OF YOUR FINEST BATSMANS\nLET's SEE WHO WINS THIS MATCH");
        while (user_wicket != 5)
        {
            if (user_score > comp_score)
                break;
            else
            {
                printf("\nYOU NEED %d RUNS FROM %d WICKETS", comp_score + 1 - user_score, 5 - user_wicket);
                comp = rand() % 6 + 1;
                printf("\nENTER YOUR CHOICE = ");
                scanf("%d", &user);
                if (user == 1 || user == 2 || user == 3 || user == 4 || user == 5 || user == 6)
                {
                    if (user == comp)
                    {
                        printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\n\t***WHAT A DELIVARY! IT IS A WICKET !***", user, comp);
                        user_wicket++;
                    }
                    else
                    {
                        printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\t*YOU GET %d RUN(s) HERE*", user, comp, user);
                        user_score = user_score + user;
                    }
                }
                else
                {
                    printf("\n Wrong Input");
                    warningcount--;
                    if (warningcount == 0)
                    {
                        printf("\n\n\t ***YOU ARE ELIMINATED!***");
                        goto end_screen;
                    }
                    else
                    {
                        printf("\n YOU HAVE ENTERED WRONG INPUT ... DO THIS %d MORE TIMES AND YOU WILL BE ELIMINATED", warningcount);
                    }
                }
                printf("\n\n\t*YOUR SCORE IS %d/%d*", user_score, user_wicket);
            }
        }
        if (user_score < comp_score)
            printf("\n\n\t\t***DESPITE YOUR BEST EFFORTS, YOUR TEAM HAS BEEN DEFEATED BY %d RUNS", comp_score - user_score);
        else if (user_score > comp_score)
            printf("\n\n\t\t***CONGRATULATIONS!!! YOU HAVE WON THE MATCH WITH %d WICKETS REMAINING!", 5 - user_wicket);
        else
            printf("\n\n\t\t***WHAT A MATCH! LOOKS LIKE BOTH TEAMS ARE EQUALLY GOOD AND THEREFORE THE RESULT IS A DRAW");
    }
    else
    {
        printf("\nCOMPUTER PLAYERS HAVE COME TO FIELD\nYOU HAVE SENT TWO OF YOUR FINEST BATSMANS\nLET's SEE WHAT HAPPENS");
        while (user_wicket != 5)
        {
            comp = rand() % 6 + 1;
            printf("\nENTER YOUR CHOICE = ");
            scanf("%d", &user);
            if (user == 1 || user == 2 || user == 3 || user == 4 || user == 5 || user == 6)
            {
                if (user == comp)
                {
                    printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\n\t***WHAT A DELIVARY! IT IS A WICKET !***", user, comp);
                    user_wicket++;
                }
                else
                {
                    printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\t*YOU GET %d RUN(s) HERE*", user, comp, user);
                    user_score = user_score + user;
                }
            }
            else
            {
                printf("\n Wrong Input");
                warningcount--;
                if (warningcount == 0)
                {
                    printf("\n\n\t ***YOU ARE ELIMINATED!***");
                    goto end_screen;
                }
                else
                {
                    printf("\n YOU HAVE ENTERED WRONG INPUT ... DO THIS %d MORE TIMES AND YOU WILL BE ELIMINATED", warningcount);
                }
            }
            printf("\n\n\t*YOUR SCORE IS %d/%d*", user_score, user_wicket);
        }
        printf("\n\n\t\t***YOUR TEAM IS ALL OUT FOR %d RUNS***", user_score);
        printf("\nCOMPUTER MUST SCORE %d RUNS TO WIN BEFORE IT LOSES 5 WICKETS", user_score + 1);
        printf("\nYOUR PLAYERS HAVE COME TO FIELD\nYOU HAVE SENT TWO OF YOUR FINEST BATSMANS\nLET's SEE WHO WINS THIS MATCH");
        while (comp_wicket != 5)
        {
            if (comp_score > user_score)
                break;
            else
            {
                printf("\nCOMP NEEDS %d RUNS FROM %d WICKETS", user_score + 1 - comp_score, 5 - comp_wicket);
                comp = rand() % 6 + 1;
                printf("\nENTER YOUR CHOICE = ");
                scanf("%d", &user);
                if (user == 1 || user == 2 || user == 3 || user == 4 || user == 5 || user == 6)
                {
                    if (user == comp)
                    {
                        printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\n\t***WHAT A DELIVARY! IT IS A WICKET !***", user, comp);
                        comp_wicket++;
                    }
                    else
                    {
                        printf("\nYOUR CHOICE WAS %d\nCOMP's CHOICE WAS %d\n\t*COMP GETS %d RUN(s) HERE*", user, comp, comp);
                        comp_score = comp_score + comp;
                    }
                }
                else
                {
                    printf("\n Wrong Input");
                    warningcount--;
                    if (warningcount == 0)
                    {
                        printf("\n\n\t ***YOU ARE ELIMINATED!***");
                        goto end_screen;
                    }
                    else
                    {
                        printf("\n YOU HAVE ENTERED WRONG INPUT ... DO THIS %d MORE TIMES AND YOU WILL BE ELIMINATED", warningcount);
                    }
                }
                printf("\n\n\t*COMPUTER SCORE IS %d/%d*", comp_score, comp_wicket);
            }
        }
        if (user_score < comp_score)
            printf("\n\n\t\t***DESPITE YOUR BEST EFFORTS, COMP HAS WON THE MATCH WITH %d WICKETS REMAINING***", 5 - comp_wicket);
        else if (user_score > comp_score)
            printf("\n\n\t\t***CONGRATULATIONS!!! YOU HAVE WON THE MATCH BY %d RUN(s)!***", user_score - comp_score);
        else
            printf("\n\n\t\t***WHAT A MATCH! LOOKS LIKE BOTH TEAMS ARE EQUALLY GOOD AND THEREFORE THE RESULT IS A DRAW***");
    }
end_screen:
    printf("\nDO YOU WANT TO PLAY AGAIN?");
    printf("\nTYPE 1 TO PLAY AGAIN AND ANYTHING TO QUIT\n");
    scanf("%d", &pa);
    if (pa == 1)
        goto play_again;
    else
        goto end;
end:
    return 0;
}