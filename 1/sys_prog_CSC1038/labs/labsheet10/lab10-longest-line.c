/*
Author: Adam Tait
Date: 13/11/25
Description: Print the length and content of the longest sentence read from a
text file
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
  printf("%d\n%s\n\n", line->length, line->content);
  // exit with no error
  return 0;
}

// function to return the longest sentence from a text file
// returns a pointer to a Line struct
Line *getLongest(char *filename) {

  // create a struct to store the longest line
  Line *longestLine = malloc(sizeof(Line));

  // open the file
  FILE *pfile = fopen(filename, "r");

  // initialise a statuse int
  int status;
  do {
    // initialise a buffer for the next line to parse
    char line[200];
    // scan everything from the start to the newline
    status = fscanf(pfile, "%[^\n]%*[\n]", line);
    // get the length of the sentence
    int len = strlen(line) + 1; // +1 to include '\n'

    // replace the values in the longest line if current line is longer
    if (len > longestLine->length) {
      longestLine->length = len;
      sprintf(longestLine->content, "%s", line);
    }
  } while (status == 1); // repeate while status is 1

  // close the file
  fclose(pfile);

  // return the line
  return longestLine;
}
