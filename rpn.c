#include <stdio.h>
#include <stdlib.h>

int main(){

    int d;  // this is to store the integer values
    char c;  // this is to store the operators 
    int size =4;  // initially the a dynamic array of size 4 is created 
    int len = 0;  // length will show that how many elements we add to the list
    int index = 0; // to know the position of the last element

    // we create an array of size 4 first using dynamic memory alloacation
    int *arr = malloc(size*sizeof(int));

    // used feof(stdin) will return 0 when no EOF is entered which is false value so when !feof is added it evaluates to True whereas when it
    // reads EOF it will return  1 or any non zero value which evaluates to True and when its negation is evaluated it turns out to False and the loop stops
    while(!feof(stdin)){
        // Checking that if the scanf is reading one 1 variable (it returns the number of variables read) i.e if it is a integer, it will return 1
        if (1==scanf("%d",&d)){
            // This is to double the size of the array if the array number of elements = size of array i.e the array is full, we double the size to fit the elements
            if (len == size) {
                // alloting a memory allocation with double the size 
                int *newArr = malloc(sizeof(int)*(size*2));
                //copying over the elements
                for (int i = 0; i < len; ++i) {
                    newArr[i] = arr[i];}
                // Changing the value of size to the new value 
                size = size*2;
                // Freeing the previous arr since we created a new array of double the size 
                free(arr);
                // change the pointer of arr to newarr
                arr = newArr;
            }
            arr[index++] = d; // this line will appoint the integer to the required index and will increment the index as well
            len++; // since len represents the no. of elements in the list, it should be incremented as well
            }

        // but if the integer is not entered but a character which is operator in this case 
        else if (1==scanf("%c", &c)){

        // if an operator is encountered 
           if (c == 'p'){
            //the last second item in the array should be replaced by the sum of last item and second last item
                 arr[len-2] = arr[len-1] + arr[len-2];
            // since with this operation the length of the array is reduced by 1 and the index moves 1 place back
                  index --; len --;

           }else if (c =='s'){
                 arr[len-2] = arr[len-2] - arr[len-1]; 
                  index --; len --;

           }
           else if (c == '*'){
                 arr[len-2] = (arr[len-2]) * (arr[len-1]); 
                  index --; len --;

           }else if (c == '/'){
                 arr[len-2] = (arr[len-2]) / (arr[len-1]); 
                  index --; len --;

            }else{
                printf("Invalid input invalid operator\n");
            }

           

            }

        }

if (len == 1){
    printf("%d\n",*arr);
}else {
    printf("0\n");
}
free(arr);
}