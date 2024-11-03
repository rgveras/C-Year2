//CS2211b 2023
//Assignment 4
//Ricardo Veras
//250692934
//rveras
//March 11, 2023

#include <stdio.h>
#include "headers.h"
#include <stdlib.h>

word word_ini(void) {
  word w;
  w = (word) malloc(sizeof(word_struct));
  w->cp = NULL;
  w->size = 0;
  return w;
}


void word_free(word wd) {
  if (wd->cp != NULL) free(wd->cp);
  free(wd);
}

void word_str_cp(word w, char* l) {
  // calculate the length of the string
  int len = strlen(l);

  // allocate memory for the word's characters
  w->cp = (char*) malloc((len+1) * sizeof(char));

  // copy the characters from l into the word's characters
  strncpy(w->cp, l, len);

  // add a null terminator to the end of the word's characters
  w->cp[len] = '\0';

  // store the size of the word
  w->size = len;
}

void word_cp(word a, word b) {
  // allocate memory for the characters in word a
  a->cp = (char*) malloc((b->size+1) * sizeof(char));

  // copy the characters from word b to word a
  strncpy(a->cp, b->cp, b->size+1);

  // store the size of word b in word a
  a->size = b->size;
}

int word_cmp(word a, word b) {
  // compare the size of the two words
  if (a->size < b->size) {
    return -1;
  } else if (a->size > b->size) {
    return 1;
  }

  // compare the characters of the two words
  int cmp = strncmp(a->cp, b->cp, a->size);

  // return the result of the comparison
  if (cmp < 0) {
    return -1;
  } else if (cmp > 0) {
    return 1;
  } else {
    return 0;
  }
}

void word_print(word w) {
    printf("%s\n", w->cp);
}

