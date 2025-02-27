#include <stdio.h>
#include <stdlib.h>

void pop(int *arr, int len){
  int *p = malloc((len-1)*sizeof(int))
  for (int i=0; i<(len-1); i++){
    p[i] = arr[i];
  }
  *arr = p;
}

void push(int **p, size_t *len, size_t *cap, int val) {
  if (*len == *cap) {
    int *newArr = malloc(*cap*sizeof(int)*2);
    for (size_t i = 0; i < *len; ++i) newArr[i] = (*p)[i];
    free(*p);
    *p = newArr;
    *cap = *cap*2;
  }
  int *arr = *p;
  arr[(*len)++] = val;
}

int main() {
  size_t cap = 4;
  size_t len = 0;
  int *arr = malloc(sizeof(int)*4);
  while (!feof(stdin)) {
    int x;
    if (1 == scanf("%d", &x)) {
      push(&arr, &len, &cap, x);
    }
  }
  for (size_t i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  void()
  free(arr);
}
