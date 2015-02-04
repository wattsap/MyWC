#include<stdio.h>
#include<ctype.h>
/*//////////////////////////////////////////////////////////////////////////////////////////
 * @Author: Andrew Watts
 * @username: wattsap
 * @version: 2.0
 * @purpose: to simulate unix wc command
 */////////////////////////////////////////////////////////////////////////////////////////
int readFile(char *filename, int *lines, int *words, int *bytes);
/*
 * @function: main
 * @purpose: loop argv, which will be the test files, and count words, lines, and bytes
 * @param argc: number of items in argv
 * @param argv: file to be read
 */
int main(int argc, char *argv[]){ 
    int i;
    int lines;
    int words;
    int bytes;
    int tLine = 0;
    int tWord = 0;
    int tByte = 0;
    for (i = 1; i < argc; i++){
        lines = 0;
        words = 0;
        bytes = 1; 
        readFile(argv[i], &lines, &words, &bytes); 
        tLine += lines;
        tWord += words;
        tByte += bytes;
        printf("%4d %4d %4d %s\n", lines, words, bytes, argv[i]); 
    }
    if (argc > 2) {
            printf("%4d %4d %4d total\n", tLine, tWord, tByte);
    }

}
/*
 * @function: readFile
 * @purpose: will take in file, read it, and count number of lines, words, and bytes in file
 * @param filename: name of file
 * @param lines: number of lines in file
 * @param words: number of words in file
 * @param bytes: number of bytes in file
 */
int readFile(char *filename, int *lines, int *words, int *bytes){
    FILE *fp = fopen(filename, "r");
    int itr2 = fgetc(fp);
    int itr = 0;
    if (fp == NULL){
        printf("Error in opening file\n");
        return 0;
    }
    while((itr = fgetc(fp))!= EOF){
        if (itr != ' ' || itr != '\n' || itr != '\t'){
            (*bytes)++;
        }
        if (itr == '\n'){
            (*lines)++;
        }
        if (isspace(itr) || itr == '\t' || itr == '\n'){
            (*words)++;
            if (itr2 == ' ' || itr2 == '\t' || itr2 == '\n') {
                (*words)--;
            }
        }
        itr2 = itr;
    }
    fclose(fp);
}       
