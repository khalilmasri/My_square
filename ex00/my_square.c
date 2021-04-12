#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char *array;
    size_t used;
    size_t size;
} StringArray;
void initArray(StringArray *a, size_t initialSize) {
    a->array = malloc(initialSize * sizeof(char));
    a->used = 0;
    a->size = initialSize;
}
void insertArray(StringArray *a, char element) {
    if (a->used == a->size) {
        a->size *= 2; // if reach limit duplicate size and alloc in the heap
        a->array = realloc(a->array, a->size * sizeof(char));
    }
    a->array[a->used++] = element;
}
void clearArray(StringArray *a, size_t newSize) {
    a->array = NULL;
    a->used = 0;
    a->array = realloc(a->array, newSize * sizeof(char));
    a->size = newSize;
}
void freeArray(StringArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
void printLineX( int x,  StringArray line){
    for (int i = 0; i < x; i++) {
        if(i == 0  ||  i == x-1)insertArray(&line, 'o');
        else insertArray(&line, '-');
    }
    printf("%s\n", line.array);
   //
}
void printLineY(int x,  StringArray line){
    for (int i = 0; i < x; i++) {
        if(( i == 0) || ( i == x-1))insertArray(&line, '|');
        else insertArray(&line, ' ');
    }
   printf("%s\n", line.array);
   // freeArray(&line);
}
int main(int argc, char **argv) {
    // remove 1 from each dimension to offset for first char
    int x;
    int y;
     if (argc < 2){
        x = 1;
        y = 1;
    }
    else if(argc < 3) {
        x = atoi(argv[1]);
        y = 1;
    }	
  	else{
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }
    if (x < 1) x = 0;
    if (y < 1) y = 0;
    StringArray line;
    initArray(&line, x);
  if(argc > 2)
   for (int i = 0; i < y; i++) {
      if(i == 0 || i == y -1) printLineX( x, line);
     else printLineY( x, line);
     clearArray(&line, x);
    }
    freeArray(&line);
    return 0;
}