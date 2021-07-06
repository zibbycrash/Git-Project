#include <stdio.h>
#include <stdio.h>

int main()
{
    int hour, minute, second;
    int d = 1; //Delay of 1000ms for the function sleep

    printf("Set time : \n");
    scanf("%d %d %d", &hour, &minute, &second);
    if(hour>12 || minute>60 || second>60)
    {
        printf("ERROR ! \n");
        exit(0);
    }
    while(1) //infinite loop
    {
        second++;
        if(second>59)
        {
            minute++;
            second=0;
        }
        if(minute>59)
        {
            hour++;
            minute=0;
        }
        if(hour>12)
        {
            hour=1;
        }
        printf("\n Clock :");
        printf("\n %02d:%02d:%02d",hour,minute,second);
        sleep(d);//this fumction slows down the while loop and make it more like a real clock.
        system("cls");//this clears the screen
        

    }


}