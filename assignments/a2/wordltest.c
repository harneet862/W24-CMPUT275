#include <stdio.h>
#include <string.h>

const char * const GREEN = "\x1b[32m";
const char * const YELLOW = "\x1b[33m";
const char * const WHITE = "\x1b[0m";
const char * current = WHITE;

void setColour(const char *colour) {
    if (current == colour) return;
    printf("%s", colour);
    current = colour;
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strlen(argv[1]) > 12) {
            // nothing will be done further once the guessed word has more than 12 characters 
            printf("Code longer than 12 characters, invalid input");
        } else {
        //Creating the memory for word which will be given by cmd line argument
        char word[13]; 
        char guess[13];
            strcpy(word, argv[1]); // copying the 1st pointer value to the word 
            // variable to calculate the length of word
            int len = strlen(word);
            int n = 6;
            // if something wrong happens in the code error will be made True (1)
            int error = 0; // 1 means no error and 0 means error 

            int count = 0;

            while (n--) {
                // the number of arguments should be 2 if not the error msg will be printed
                printf("Enter guess: ");
                scanf("%s", guess);
                //These are redeclared everytime because the guesses are changing evrytime 
                char greencolor[12]= {0,0,0,0,0,0,0,0,0,0,0,0};
                char yellowcolor[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
                char color[12] = {0};   // this represents the letters in the actual word

                // Finding the length so to check if the guessed word length matches with the right word
                if (strlen(guess) != len) {
                    printf("Invalid guess, guess length must match word length\n");
                    error = 1;  // This flag will generate error 
                    break;
                } else {
                    // First in the list of green words, we will mark them 
                    for (int i =0; i < len; i++){
                           // if the charcater is same at the same index at word and guess then that will be marked 1 in greencolor array
                            if (guess[i] == word[i]){
                                greencolor[i] = 1;
                                color[i] = 1; }}// marking it one for the actual word so to tell that it is marked and nothing further should be dont with this 

                     for (int i =0; i < len; i++){      
                           // This for loop will compare if we get that character anywhere else and that character in the original word should not used before (which is obtained by marking it 1 in its own array)
                        for (int j =0; j<len; j++){
                            if(guess[i] == word[j] && i==j){
                                break;
                            }
                            else if (guess[i] == word[j] && color[j] == 0){
                                    yellowcolor[i] = 1;
                                    color[j] = 1;
                                    break;
                                }

                            }
                        }
                    }                
            ++ count;

            // Now printing the guesses
            for (int i =0; i <len; i++){
                // if the green array has something marked as 1 which means it should be printed in green color 
                if (greencolor[i] == 1){
                    setColour(GREEN);
                    // if the green array has something marked as 1 which means it should be printed in green color
                } else if (yellowcolor[i] == 1){
                    setColour(YELLOW);
                }else{
                    setColour(WHITE);
                }
                printf("%c", guess[i]);
            }
            printf("\n");
            setColour(WHITE);

            if (0 == strcmp(guess, word)) break;
            }
            if (count == 6 && (strcmp(guess,word) != 0)) {
                    printf("Failed to guess the word: %s\n", word);
                }else if (!error && (0 == strcmp(guess, word))){
                    printf("Finished in %d guesses\n", (count));
                }
        }
    }
    else{
        printf("Invalid number of command line arguments\n");
    }
    return 0;
}
