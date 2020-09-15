#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

int fileexists(const char *filename) {
    FILE *file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}

int password(char pw[]) 
{

    char Entered[40];
    printf("Enter password (40 char max): ");
    scanf("%s", Entered);
    getchar();

    if(strcmp(Entered, pw) == 0) {return 1;}
    else {return 0;}
    
}

int WelcomeScreen(void) 
{
    system("cls");
    int input = 0;
    printf("THIS IS YOUR DIARY MANAGEMENT SYSTEM\n");
    printf("1. Create new Entry\n2. Edit Entry\n3. Remove Entry\n4. Exit\n");
    sscanf("%d", &input);
    getchar();
    switch(input) {
        case 1:
            printf("Input not recognised")
    }
    

}

void Diary(void)
{
    int closediary = false;
    while (closediary != true)
    {
        WelcomeScreen();
        closediary = true;
    }
}

int main(int argc, char * argv[]) {

    //FILE CHECKING
    char* filename = argv[2];
    int exists = fileexists(argv[2]);
    if (exists == 1) {
        printf("Reading from file %s\n", argv[2]);
    } else {
        printf("File not found \n");
        exit(EXIT_FAILURE);
    }

    //PASSWORD CHECKING
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

    //INITIALISING DIARY FUNCTION
    Diary();


    getchar();
    return 0;
}