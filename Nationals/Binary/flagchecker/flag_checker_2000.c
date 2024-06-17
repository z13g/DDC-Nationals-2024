#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {

    /*
        A warning to all who thinks that bruteforce is a good idea:

        Flag form: (DDC){[a-zA-Z0-9-_]{6,50}}

        Flag inner part allowed characters = 2*26+10+2 = 64
        Flag inner part max size = 29 - 5 = 24

        64^24 = You're gonna have a bad time
    */

    setvbuf(stdout, NULL, _IONBF, 0);

    char command[50] = "./check_f ";
    char input[30];
    printf("Input the flag. I'll check to see if it is correct> ");
    scanf("%[^\n]", input);

    strcat(command, input);

    printf("\nRunning: %s\n\n", command);

    for(int i = 0; command[i] != '\0'; i++){
        char ch = command[i];
        if(!(isalnum(ch) || strchr("{}-_./ ", ch))){
            printf("Syntax error, character: '%c' is not allowed.", ch);
            exit(1);
        }
    }

    system(command);


    return 0;
}