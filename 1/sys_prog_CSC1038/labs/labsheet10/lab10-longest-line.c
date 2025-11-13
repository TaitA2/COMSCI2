/*
Author: Adam Tait
Date: 13/11/25
Description: Print the longest sentence from a text file
*/

// include relevent libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for a text line
typedef struct Line {
  int length;
  char content[200];
} Line;

// function headers
Line *getLongest(char *filename);

// main function
int main(int argc, char *argvp[]) {
  // find the longest line
  Line *line = getLongest("paragraph.txt");
  // print the line length and content
  printf("%d\n%s\n", line->length, line->content);
  // exit with no error
  return 0;
}

// function to return the longest sentence from a text file
Line *getLongest(char *filename) {
  // create a struct to store the longest line
  Line *longestLine = malloc(sizeof(Line));

  // open the file
  FILE *pfile = fopen(filename, "r");

  int status = 0;
  do {
    char line[200];
    status = fscanf(pfile, "%[^\n]%*s", line);
    int len = strlen(line);

    if (len > longestLine->length) {
      longestLine->length = len;
      sprintf(longestLine->content, "%s", line);
    }
  } while (status == 1);

  fclose(pfile);
  return longestLine;
}
