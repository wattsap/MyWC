#include <stdio.h>
#include <string.h>
/*///////////////////////////////////////////////////////////////////////////
 * -------------------------------------------------------------------------
 * @author: Andrew Watts
 * @date: 1/28/15
 * @version: 1
 * @description: creating my own word count(wc) fxn.
 * ------------------------------------------------------------------------
 *//////////////////////////////////////////////////////////////////////////


/* @method: main
 * @int argc: command line args
 * @char *argv[]: command line args
 * purpose: this method will calculate the total lines, words, and 
 * bytes of one or more files and return the file name(s) along 
 * with those numbers.
 */
int readFile(char *filename, int *lines, int *words, int *bytes);

int main(int argc, char *argv[]){
    int lines;
    int words;
    int bytes;
    char filename;
    while (argv[i] != NULL) {
        int x = readFile(&argv[i], &lines, &words, &bytes);
        if (x == 0){
            perror("Error in opening file");
            return 0;
        }
    }
    printf("%d, %d, %d\n", lines, words, bytes);
}

/*
 * @method: readFile
 * @char *fileName: pointer to name of file being inputted
 * @int *lines: pointer to number of lines in file
 * @int *words: pointer to number of words in file
 * @int *bytes: pointer to number of bytes in file
 * @purpose: to tally the total number of lines, words, bytes, of 
 * one file.
 */
int readFile(char *filename, int *lines, int *words, int *bytes) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error in opening file\n");
        return 0;
    }
    while (fgetc(fp) != EOF) {
        char cur = fgetc(fp);
        if(cur == '\n') {
            lines++;
        }
        else if (cur == (' ')) {
            words++;
        }
        else if (cur != '\n' && cur != ' ' && cur != EOF) {
            bytes++;
        }
    }
}
/*
 * this was another idea for how the project could be done. using one 
 * struct for an individual file, and another struct for the totals of 
 * the files. I will revisit this idea and do it this way, but I would 
 * like to get the lab done at the present and do not know that much 
 * about structs anyway.
 */
/*
typedef struct {
    int lines;
    int words;
    int chars;
    char *fileName;
} FILEINFO;

typedef struct {
    int totalLines;
    int totalWords;
    int totalChars;
    char *fileNames;
} ALLFILEINFO;
*/
/*
int main(int argc, char *argv[]){
    FILE *fp;
    char str[60];
    fp = fopen("hash.dat", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return (-1);
    }
    if ( fgets (str, 60, fp)!= NULL ) {
        puts(str);
    }
    fclose(fp);
    return 0;
}
*/
