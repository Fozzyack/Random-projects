#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int password(void) {
    char password[40] = "This is the password";
    char Entered[40];
    printf("Enter password: ");
    scanf("%s", Entered);
    getchar();

    if(strcmp(password, Entered) == 0) {return 1;}
    else {return 0;}
    
}



int main(int argc, char * argv[]) {

    int pwCheck = password();

    if (pwCheck == 1) {
        printf("Exit success");
        getchar();
        exit(EXIT_SUCCESS);
    }
    else if(pwCheck == 0) {
        printf("Exit failure");
        getchar();
        exit(EXIT_FAILURE);
    }
    else {exit(EXIT_FAILURE);}



    getchar();
    return 0;
}