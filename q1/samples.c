#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>
#include <time.h>


int main(int argc, char* argv[]){

    if(argc != 4){
        printf("usage: samples filename numberfrags fragsize.\n");
        exit(EXIT_FAILURE);
    }

    FILE *filepointer;
    int numPrints = atoi(argv[2]); // convert string input to int
    int numChar = atoi(argv[3]); // convert string input to int

    if (numPrints < 0 || numChar < 0 ){
        printf("Please insert positive numbers.\n");
        exit(EXIT_FAILURE);
    }

    filepointer = fopen(argv[1], "r");

    if(filepointer == NULL){
        printf("This file can't be opened.\n");
        exit(EXIT_FAILURE);
    }

    int fileSize = 0;

    fseek(filepointer, 0L, SEEK_END);
    long int file_size = ftell(filepointer);
    rewind(filepointer);

    int randoNum = 0;
    char c;
    srand(time(0)); // different sequence of random numbers on every program run

    for(int i = 0; i < numPrints; i++){
        randoNum = rand() % (file_size - numChar); // random numbers from 0 to file_size - numChar

        //printf ("num : %d", randoNum);

        fseek (filepointer, randoNum, SEEK_SET); // seek file from starting point

        printf(">");
        for(int i = 0; i < numChar; i++){ // print chars from starting point to input numChar

            char c = fgetc(filepointer);

            if (c == '\n' || c == '\t' || c == '\r'){ // if \n count as a break and replace it as a space
                printf(" ");
            } else {
                printf("%c", c );
            }     
        }
        printf("<\n");
    }

  
    fclose(filepointer);
    return 0;
}
  