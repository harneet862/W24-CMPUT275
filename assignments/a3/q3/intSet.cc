# include "intSet.h"
// help taken from https://codzify.medium.com/what-is-copy-constructor-in-c-what-is-shallow-copy-constructor-and-deep-copy-constructor-in-7196e6fe063

intSet::intSet(): data{new int [4]}, size{0}, capacity{4} {} //Default constructor 

intSet(const intSet& is){
    int *p =  new int[is.capacity];
    for (int i =0; i<is.size ; i++){
        p[i] = (is.data)[i];
    }    
    size = is.size;
    capacity = is.capacity;
}
intSet &operator=(const intSet& is){
    return intSet(const intSet& is);
}

void add(int e){  // add the element only if it is not present in the array 
//and if need increase the capacity
    int flag = 1;
    for (int i =0; i <size; i++){
        if (data[i] == e) flag = 0;
    }
    if (flag){
        if (size == capacity){
            capacity = 2*capacity;
            int *p = new int[capacity];
            for (int i = 0; i < size; i++){
                p[i] = data[i];
            }
            delete [] data;
            data = p;
        }
        data[capacity] = e;
        size ++;
    }
}