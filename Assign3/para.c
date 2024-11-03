//CS2211b 2023
//Assignment 4
//Ricardo Veras
//250692934
//rveras
//March 11, 2023

#include <stdlib.h>

para para_ini(void) {
  para p;
  p = (para) malloc(sizeof(para_struct));
  p->lp = NULL;
  p->size=0;
  return p;
}

void para_free(para p) {
    int i;
    for (i=0; i<p->size; i++) {
      line_free(p->lp[i]);
}
free(p->lp);
free(p); 
}

void para_add(para p, line l) {
  if (p->size == p->max_size) {
    // Double the max size of the para_struct using realloc()
    p->max_size *= 2;
    p->lp = (line*)realloc(p->lp, p->max_size * sizeof(line));
  }

  // Add the line to the para_struct
  p->lp[p->size] = l;
  p->size++;
}


