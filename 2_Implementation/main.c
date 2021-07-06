#include<stdio.h>
//#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include "my_header.h"
/*
#include "addition.c"
#include "calculator_operations.c"
#include "division.c"
#include "factorial.c"
#include "modulus.c"
#include "multiplication.c"
#include "power.c"
#include "subtraction.c"
*/
 
#define KEY "Enter the calculator Operation you want to do:"
 
// Function prototype declaration
 
// Start of Main Program
int main()
{
    int X=1;
    char Calc_oprn;
 
    // Function call 
    calculator_operations();
 
    while(X)
    {
        printf("\n");
        printf("%s : ", KEY);
 
        Calc_oprn=getche();
 
        switch(Calc_oprn)
        {
            case '+': addition();
                      break;
 
            case '-': subtraction();
                      break;
 
            case '*': multiplication();
                      break;
 
            case '/': division();
                      break;
 
            case '?': modulus();
                      break;
 
            case '!': factorial();
                      break;
 
            case '^': power();
                      break;
 
            case 'H':
            case 'h': calculator_operations();
                      break;
 
            case 'Q':
            case 'q': exit(0);
                      break;
            case 'c':
            case 'C': system("cls");
                      calculator_operations();
                      break;
 
            default : system("cls");
 
    printf("\n**********You have entered unavailable option");
    printf("***********\n");
    printf("\n*****Please Enter any one of below available ");
    printf("options****\n");
                      calculator_operations();
        }
    }
}




