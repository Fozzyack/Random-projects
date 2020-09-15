#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int password(char pw[]) 
{

    char Entered[40];
    printf("Enter password (40 char max): ");
    scanf("%s", Entered);
    getchar();

    if(strcmp(Entered, pw) == 0) {return 1;}
    else {return 0;}
    
}

void WelcomeScreen(void) 
{
    system("cls");
    printf("THIS IS YOUR DIARY MANAGEMENT SYSTEM\n");
    printf("1. Create new Entry\n2. Edit Entry\n3. Remove Entry\n4. Exit");
}



int main(int argc, char * argv[]) {

    int pwCheck = password(argv[1]);

    if (pwCheck == 1) {
        printf("Exit success");
        getchar();
    }
    else if(pwCheck == 0) {
        printf("Exit failure");
        getchar();
        exit(EXIT_FAILURE);
    }
    else {exit(EXIT_FAILURE);}

    WelcomeScreen();






    getchar();
    return 0;
}