//CS2211b 2023
//Assignment 4
//Ricardo Veras
//250692934
//rveras
//March 11, 2023

#include <stdlib.h>

typedef struct word_struct {
	char *cp;
	int size;
  } word;
  
typedef struct line_struct {
	word *wp;
	int size;
  } line;
  
typedef struct para_struct {
	line *lp;
	int size;
  } *para;
