#include <stdio.h>
#include <stdlib.h>

int* createarray(int size){
    // This function is to create an array of specified size and will return a pointer to that array created 
    int *s = malloc(sizeof(int)*size);
    return s;
}

int readcharacter(char *y) {
    // This function is to get rid of  white spaces and scan the letter between a and z 
    int x;
    do {
       x = scanf(" %c", y); 
    } while (*y < 'a' || *y > 'z'); 
    return x;
}

void append(int num, int *len, int *size, int **ptr) {
    int flag = 1;

    if (*len == *size) {
        *size = (*size) * 2;
        int *newarr = createarray(*size);
        for (int i = 0; i < *len; i++) {
            newarr[i] = (*ptr)[i];
        }
        free(*ptr);
        *ptr = newarr;
    }
    
    for (int i = 0; i < *len; i++) {  // this loop is to check if the number is already in the array
        if (num == (*ptr)[i]) {
            flag = 0;  // if the num is already in the array, the flag will be set 0 and further it would not be added to the array
            break;
        }
    }
    // Now if the flag is 1, the only it will be appended to the end of the array
    if (flag) {
        (*ptr)[(*len)] = num;
        (*len)++;
        //printf("Done!");
    }
}

void print(int x[], int xlen){

    int *newarr = createarray(xlen); // Allocate memory for newarr
    int len = xlen; // Assign xlen to len
    for (int i = 0; i < xlen; ++i) {
        newarr[i] = x[i];
    } // initialising the array

    // Remove duplicates
    int dupli = len;
    for (int i = 0; i < dupli; ++i) {
        for (int j = i + 1; j < dupli; ++j) {
            if (newarr[i] == newarr[j]) {
                newarr[j] = newarr[dupli - 1];
                dupli--;
            }
        }
    }

    if (dupli == 0) {
        free(newarr);
        return;

    } else {
        int dup = dupli;
        // Selection sort to sort newarr
        while (dup != 0) {
            int index = 0;
            int max = newarr[0];
            for (int i = 0; i < dup; i++) {
                if (max < newarr[i]) {
                    max = newarr[i];
                    index = i;
                }
            }
            int tmp = newarr[index];
            newarr[index] = newarr[dup - 1];
            newarr[dup - 1] = tmp;
            dup--;
        }

        for (int i = 0; i < len; i++) {
            printf("%d", newarr[i]);
            if (i == len-1){
                printf("\n");
            }else{
                printf(" ");
            }
        }
        free(newarr);
    }
}

void removed(int num, int *x, int* xlen){
    int index =0; // this is to store the index of the elemnt of array which is need to be removed 
    int flag = 0; // 1 means the action will be done and 0 means the required action wont be done 
   
    for (int i =0; i < *xlen; i++){
        if (num == x[i] ){
            flag = 1; //we found the element to remove thus the removal action wull occur
            index = i;  // storing the index and breaking the for loop
            break;
            }}
        
    if (flag) {  // now if the element which was needed to be removed was found 
        x[index] = x[*(xlen) - 1]; 
         // the element which was on index was moved to last element and the length was reduced by 1 thus now it is not in the array and no longer matter
        *(xlen) = (*(xlen) - 1);
        //printf("removed");
        //printf("%i", *xlen);
            }}

void intersection(int *x, int *y, int xlen, int ylen) {
    int *intersection = createarray(xlen);
    int len = 0;

    for (int i = 0; i< xlen; i ++){
        for (int j = 0; j <ylen; j++){
            if (x[i] == y[j]){
                intersection[len++] = x[i];
                break;
            }
        }
    }
    if (len == 0) {
        free(intersection);
        return;
    } else {
        print(intersection, len);
        free(intersection);
    }
}


void uniono (int *x, int *y, int xlen, int ylen){
        int *uniono = createarray(xlen + ylen);
        int len = 0;

        for (int i =0; i < xlen; i++){
            uniono[i] = x[i];
            len ++;   // we are adding all elements of array1 (x) and in the next loop we will check if the elements are repeated we wont add it 
        }
        for (int i = 0; i < ylen; i++){
            int flag = 1;
            for (int j =0; j <xlen; j++){
                 if (y[i] ==x[j]){
                    flag = 0;
                    break;
                 }
            }
            if (flag){
                uniono[len++] = y[i];
            }
        }
        print(uniono, len);
        free(uniono);
}

int main(){
    int *x = createarray(4);
    int *y = createarray(4);
    int **ptr_to_x = &x;
    int **ptr_to_y = &y;
    int xlen = 0;
    int ylen = 0;
    int xsize = 4;
    int ysize = 4;

    char targ = ' '; // this will be used to store which set is used 
    int num = 0; // this will be used to store the value to be added or removed 
    char c = ' '; // this is used for taking input and then matching it with relevant function

     while (c != 'q'){

        if (readcharacter(&c)){
        // Now the cases will be matches with adequate functions
            if (c == 'a'){
                if (readcharacter(&targ)){
                    if (1 == scanf("%i", &num)){
                        if (targ =='x'){
                             append(num, &xlen, &xsize, ptr_to_x);}
                        else if (targ =='y'){
                             append(num, &ylen, &ysize, ptr_to_y);}
                    }}
           } else if (c == 'p'){
                    if (readcharacter(&targ)){
                        if (targ =='x'){
                             print(x, xlen);}
                        else if (targ =='y'){
                             print(y, ylen);}
            }
            }  else if (c == 'r'){
                    if (readcharacter(&targ)){
                    if (1 == scanf("%i", &num)){
                        if (targ =='x'){
                             removed(num, x, &xlen);}
                        else if (targ =='y'){
                             removed(num, y, &ylen);}
            }}
            } else if (c == 'i'){
                intersection(x, y, xlen, ylen);
            } else if (c == 'u'){
                uniono( x, y, xlen, ylen);
            }
                
            
}}
ptr_to_x = NULL;
ptr_to_y = NULL;
free(x);
free(y);

return 0;
}