#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "definitions.h"
#include "headers.h"

#define MAX_LINE_SIZE 1024

int main() {
  char input[MAX_LINE_SIZE];
  para p = para_ini();
  line current_line = line_ini();
  
  // Process each input line of characters
  while (fgets(input, MAX_LINE_SIZE, stdin)) {
    // Check if the input line is empty
    if (strlen(input) <= 1) {
      break;
    }
    
    // Split the input line into words
    char *word_str = strtok(input, " \t\r\n");
    while (word_str != NULL) {
      // Create a new word structure and copy the word string to it
      word new_word = word_ini();
      word_str_cp(new_word, word_str);
      
      // Add the word to the current line
      line_add(current_line, new_word);
      
      // Get the next word from the input line
      word_str = strtok(NULL, " \t\r\n");
    }
    
    // Add the current line to the paragraph
    para_add(p, current_line);
    
    // Create a new line for the next input line
    current_line = line_ini();
  }
  
  // Print each line and each word in the order they were entered by the user
  para_print(p);
  
  // Prompt the user for a word to search for
  printf("Enter a word to search for: ");
  char search_word_str[MAX_LINE_SIZE];
  fgets(search_word_str, MAX_LINE_SIZE, stdin);
  strtok(search_word_str, " \t\r\n");  // Remove any trailing whitespace
 
  word search_word;
  search_word.cp = search_word_str;
  search_word.size = strlen(search_word.cp);
 
  // Search for the word in the paragraph
  int found = para_search_print(p, search_word);
  if (!found) {
    printf("The word was not found in the text.\n");
  }
  
  // Free the memory used by the structures
  para_free(p);
  
  return 0;
}

