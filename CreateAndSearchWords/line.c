//CS2211b 2023
//Assignment 4
//Ricardo Veras
//250692934
//rveras
//March 11, 2023

#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include "definitions.h"

line line_ini(void) {
  line l;
  l = (line) malloc(sizeof(line_struct));
  l->wp = NULL;
  l->size = 0;
  return l;
}
void line_free(line l) {
  int i;
  for (i=0; i<l->size; i++) {
    word_free(l->wp[i]);
}
free(l); }

void line_add(line l, word w) {
    // Increase the size of the wp array by one using realloc()
    l.wp = (word *) realloc(l.wp, (l.size + 1) * sizeof(word_struct *));
    
    // Allocate memory for a new word and copy the contents of the given word into it
    word new_word = word_ini();
    word_str_cp(new_word, w->cp);
    
    // Set the size of the new word
    new_word->size = w->size;
    
    // Add the new word to the end of the wp array
    l->wp[l->size] = new_word;
    l->size++;
}

void line_cp(line a, line b) {
  // Reset line a to remove all existing words
  line_reset(a);

  // Copy each word from line b to line a
  for (int i = 0; i < b->size; i++) {
    word current_word = b->wp[i];
    word new_word = word_ini();
    word_str_cp(new_word, current_word->cp);
    line_add(a, new_word);
  }
}

void line_print(line l) {
  for (int i = 0; i < l->size; i++) {
    word_print(l->wp[i]);
    printf(" ");
  }
  printf("\n");
}

int line_search(line l, word w) {
  for (int i = 0; i < l->size; i++) {
    if (word_cmp(l->wp[i], w) == 0) {
      return i; // return the index of the matching word
    }
  }
  return -1; // return -1 if the word is not found in the line
}

int line_word_position(line l, word w) {
  int i;
  for (i = 0; i < l->size; i++) {
    if (word_cmp(l->wp[i], w) == 0) {
      return i;
    }
  }
  return -1; // return -1 if word not found
}

void line_reset(line l) {
    int i;
    for (i = 0; i < l->size; i++) {
        word_free(l->wp[i]);
    }
    free(l->wp);
    l->wp = NULL;
    l->size = 0;
}

