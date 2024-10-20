# include <iostream>

//structline ptr will remain the same and the ptr to the array will change depending on the size
struct inputarray{
    int size; // this will store the size of the array which will store pointers to the struct(max elements that can be stored)
    int len;  // this will store the length of the array i.e how many elements are there in the array for now
    struct line ** pointer; // this is the dynamically stored array pointer which only conatins ptrs

    // Constructor method will be always called when the new object is formed  
    // a object line with a ptr to heap allocated memory of size 4 and length 0 is created 
    inputarray() : size{4}, len{0}, pointer{new struct line *[4]} {} 
    inputarray(int s, int l) : size{s}, len{l}, pointer{new struct line* [s]} {}

    //~inputarray(){
      //     delete [] pointer; // freeing the array later
     //      std::cout << "Destructor inputarray called" <<std::endl;
    //} I cannot use destructor because when I use the poperator it destructs the object and causing memory issues ahead

    void increasesizeinputarray(){
            // the object is implicitly passed to the array so dont need to pass the parameter
            // this functions take the struct as the parameter and increases the size by doubling it and cpoies the elements into the new array change the pointer stored in the struct 
            // This function will only work when the length and the size of the array in the struct is equal
            if (len == size){
                size = 2*(size); // this is the ptr to the struct object
                struct line **ptr1 = new struct line *[size];

                for (int i =0; i <(len); i++){
                     ptr1[i] = (pointer)[i];   // *(ptr1+i) = *(pointer+i)
                }

                delete [] (pointer);
                pointer = ptr1;}
        }

    void lengthincrease(){
    // this method is created since the variables are private and they cannot be modified anywhere else 
        len++;
    }

    int getlength(){
        //getter method
        return len;
    }
};

struct line{
    // this is the structure which will take care of each of the input 
        int size;
        int len; // this store the length of each input 
        char *ptrtolist; // this stores the address of memory location of the array on heap

    /* Now everytime a element is entered:
     1) first the length of the array which pointerd by ptr will be check if it is equal to the size, the sizeincrease function will be called
     2) After this, the entered element will be added to the array
     3) if the entered element is x; the program should stop
     4) if the enetered element is '\n', the previous array if any should be added to the array of pointers and a new struct should be formed which will have a new array
     */
        void increasesizeline(){
        // the object is implicitly passed to the array so dont need to pass the parameter
        // this functions take the struct as the parameter and increases the size by doubling it and cpoies the elements into the new array change the pointer stored in the struct 
        // This function will only work when the length and the size of the array in the struct is equal
        if (this->len == this->size){
            this->size = 2*(this->size); // this is the ptr to the struct object and this->len is equvalent to len
            char *ptr1 = new char[this->size];

            for (int i =0; i <(this->len); i++){
                     ptr1[i] = (this->ptrtolist)[i];
                }

            delete [] (this->ptrtolist);
            this->ptrtolist = ptr1;}
        }

        // Constructor method will be always called when the new object is formed  
        // a object line with a ptr to heap allocated memory of size 4 and length 0 is created 
        line() : size{4}, len{0}, ptrtolist{new char[4]} {} 
        line(int s, int l) : size{s}, len{l}, ptrtolist{new char[s]} {}
       // ~line() {
        //  std::cout << "Destructor line called" <<std::endl;
         //  delete[] ptrtolist; // Release dynamically allocated memory
   // } 
};

void poperator(struct inputarray a1){
    // if the input is p we need to print the matrix but also the no. of elements in a row is variable then the no. of elements printed in each is the no. of elements in 1st row
            int n = a1.len; // length of the input array
            //std::cout << n << std::endl;
            if (*(a1.pointer) != nullptr){
            // checking if it a nullptr
            int n1 = (*(a1.pointer))->len;  // length of first row
            //std::cout << n1 << std::endl;
            for (int i = 0; i<n1; i++){
                std::cout << '|';
            }
                std::cout << std::endl;
            for (int i = 0; i <n; i++){
                for (int j = 0; j< n1; j++){
                    std::cout << (((a1.pointer)[i])->ptrtolist)[j];
                    //std::cout << ((*(a1.pointer)+i)->ptr)[j];  // *(a1.pointer) is the pointer to the struct and *(a1.pointer)->ptr means the pointer to array which holds the input for one row
                }
                std::cout << std::endl;
            }
            for (int i = 0; i< n1; i++){
                std::cout << '|';
            }
                std::cout << std::endl; }
}

void soperator(struct inputarray * a1){
    /* 
    This operator will be executed when s is inputted and should work as follows:
    1) a copy of the inputarray will be formed 
    2) with the help of the for-loop, the element we are loop at its neigbours will be checked (will be checked by checking the array above, at the same level and the one below n-1th, nth, n+1th element )
    3) if less than two neigbours then cell dies, more than three dies 
    4) any dead cell with three alive neighbours gets alive 
    5) Any cell with two or three live will be alive for next generation
    6) After doing this the ptrtolist will be freed and then arr which was given as a parameter will be freed 
    7) The new input array will be given back
    */
    struct inputarray *copy = new struct inputarray(a1->size, a1->len); // envoking the constructor with arguments
    int arraylen = a1->getlength();
    //std::cout << (*(a1->pointer))->len << std::endl;
    int rowlen = (*(a1->pointer))->len; // seg fault 

    int num = 0; // this to count how many alive neigbours are present 
    
    for (int i =0; i < arraylen; i++){
        struct line *ptr = new struct line((a1->pointer)[i]->size, (a1->pointer)[i]->len);
        for (int j = 0; j < rowlen; j++){
            num = 0;
        // Check left neighbor
        if (j - 1 >= 0 && ((a1->pointer)[i]->ptrtolist)[j - 1] == 'O')
            ++num;

        // Check right neighbor
        if (j + 1 < rowlen && ((a1->pointer)[i]->ptrtolist)[j + 1] == 'O')
            ++num;

        // Check upper neighbor
        if (i - 1 >= 0 && ((a1->pointer)[i - 1]->ptrtolist)[j] == 'O')
            ++num;

        // Check lower neighbor
        if (i + 1 < arraylen && ((a1->pointer)[i + 1]->ptrtolist)[j] == 'O')
            ++num;

        // Check upper left neighbor
        if (i - 1 >= 0 && j - 1 >= 0 && ((a1->pointer)[i - 1]->ptrtolist)[j - 1] == 'O')
            ++num;

        // Check upper right neighbor
        if (i - 1 >= 0 && j + 1 < rowlen && ((a1->pointer)[i - 1]->ptrtolist)[j + 1] == 'O')
            ++num;

        // Check lower left neighbor
        if (i + 1 < arraylen && j - 1 >= 0 && ((a1->pointer)[i + 1]->ptrtolist)[j - 1] == 'O')
            ++num;

        // Check lower right neighbor
        if (i + 1 < arraylen && j + 1 < rowlen && ((a1->pointer)[i + 1]->ptrtolist)[j + 1] == 'O')
            ++num;
        //Checking what is the sum for the num??
        if ( (num < 2  || num > 3) && ((a1->pointer)[i]->ptrtolist)[j] == 'O') {//cell dies
            ptr->increasesizeline();
            (ptr->ptrtolist)[j] = '.';
        }
        else if ( (num == 2 || num == 3) && ((a1->pointer)[i]->ptrtolist)[j] == 'O') {// cell alive if the cell there is alive (0)
             ptr->increasesizeline();
            (ptr->ptrtolist)[j] = 'O';
        }
        else if (num == 3 && ((a1->pointer)[i]->ptrtolist)[j] == '.') {//if the cell there is (.) then it will become alive 
            ptr->increasesizeline();
            (ptr->ptrtolist)[j] = 'O';}
        else{
            (ptr->ptrtolist)[j] = '.';
        }
    }
    copy->increasesizeinputarray();
    (copy->pointer)[i] = ptr;
}
    // to free each struct line in the array
    // Free the original inputarray
    for (int i = 0; i < a1->len; ++i) {
        delete[] (a1->pointer[i]->ptrtolist);
        delete (a1->pointer[i]);
    }
    delete[] a1->pointer;

    // Assign the new state
    a1->pointer = copy->pointer;
    a1->size = copy->size;
    a1->len = copy->len;

    delete copy; // We only delete the container, not the contents 
}

int main(){

    struct inputarray *arr1 = new struct inputarray;
    std::cin >> std::noskipws;  // using it so that it can read whitespace characters like '/n'
    char c = ' '; //setting it to whitespace character
    struct line *ptrtoline = new struct line; // default constructor will run and initialise the elements accordingly

    while(c != 'x'){
        std::cin >> c;     // we cannot use std::cin >> c != 'x'  since input/output operator return the stream itself 
        (*ptrtoline).increasesizeline();    // this function will check if it is required to increase size, if so it will increase the size

        if (c != 'x' && c != '\n'){
            if (ptrtoline != nullptr){
            (ptrtoline->ptrtolist)[ptrtoline->len] = c; // ptr1->ptr is the pointer to the array which struct line has and ptr1->len is the length 
            ++(ptrtoline->len);} 
           

        }else if ( c == 'x'){
            delete [] ptrtoline->ptrtolist;
            delete ptrtoline;
            break;        // if x is the input then this should mean that the grid is complete

        }else if (c == '\n'){
                arr1->increasesizeinputarray(); //Using the method of another class and dereferencing the ptr since the method has to be used on the object itself
                (*arr1).pointer[arr1->getlength()] = ptrtoline;
                arr1->lengthincrease(); // this is to add the element to array and now length will go up by one 
                //(arr1.pointer)[arr1.getlength()] = ptr1; // we made the array which contains the ptr to the struct and this is a ptr to the object of struct 
                ptrtoline = new struct line;  // This will probably cause memory leak
            }
    }
   // std::cout << (*(arr1->pointer))->len << std::endl;
    std::cin >> std::skipws;
    while(true){
        std::cin >> c;
        if(std::cin.eof()) break;  // if cltrl+D is entered exit

        if (c == 'p'){
            poperator(*arr1);
        }else if (c == 's'){
            soperator(arr1);
        }

    }
    // I want to free the ptrtolist 
    for (int i =0; i < (arr1->getlength()); ++i){
        //std::cout << "hello" <<std::endl;
        delete [] ((arr1->pointer)[i]->ptrtolist);
        //std::cout << "yello" <<std::endl;
        delete (arr1->pointer)[i];
    }
    delete [] arr1->pointer;
    delete arr1;
    return 0;
}



