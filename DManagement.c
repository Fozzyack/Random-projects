#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

#define MAXCHAR         10000
#define MAXENTRIES      10000

int entries [MAXENTRIES][2];

int fileexists(const char *filename) {
    FILE *file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;
    }
    return 0;
}

int readingfile(const char *filename) {
    FILE *file;
    char str[MAXCHAR];
    file = fopen(filename, "r");
    while(fgets(str, MAXCHAR, file) != NULL) {
        printf("%s", str);
    }
    fclose(file);
    return 0;

}

int password(char pw[]) 
{
    
    char Entered[40]; //PASSWORD USER ENTERES
    printf("Enter password (40 char max): ");
    scanf("%s", Entered);
    getchar();

    if(strcmp(Entered, pw) == 0) {return 1;}
    else {return 0;}
    
}

int WelcomeScreen(void) 
{
    //CLEARS SCREEN AND INPUT
    system("cls");
    fflush(stdin);

    char input[5];
    int output = 0;
    //INTERFACE
    printf("THIS IS YOUR DIARY MANAGEMENT SYSTEM\n");
    printf("1. Create new Entry\n2. Edit Entry\n3. Remove Entry\n4.Read Diary\n5. Exit\n");
    scanf("%s", input);
    getchar();

    //OUTPUT OCCURS
    if(strcmp(input, "1") == 0)  {
        printf("Creating entry\n");
        output = 1;

    }
    else if(strcmp(input, "2") == 0) {
        printf("Editing Entry\n");
        output = 2;
    }
    else if(strcmp(input, "3") == 0) {
        printf("Removing Entry\n");
        output = 3;
    }
    else if(strcmp(input, "4") == 0) {
        printf("Reading\n");
        output = 4;
    }
    else if(strcmp(input, "5") == 0) {
        printf("Exiting\n");
        output = 5;
    } else {
        printf("Input not recognised\n");
    }
    return output;

}

//-------------------------------------------------------
void Diary(const char *filename)
{
    int closediary = false;
    int toRun = 0;
    while (closediary != true)
    {
        toRun = WelcomeScreen();

        switch (toRun) {
            case 0:
                printf("Error\n");
                exit(EXIT_FAILURE);
                break;
            case 4:
                printf("Reading\n");
                readingfile(filename);
                getchar();
                break;
            case 5:
                printf("Exiting program\n");
                closediary = true;
                break;
        }
        printf("===\n");
    }
}
//-------------------------------------------------------

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
    Diary(argv[2]);

    printf("Testomg");
    getchar();
    return 0;
}