#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Generates a number of random lower case letters.
* The letters will be stored in the given array.
*/
void generate_letters(int number, char *destination)
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int i;
    unsigned int rand_seed;
    printf("Number < 1000:\n");
    scanf("%d", &rand_seed); // initialise the PRNG
    getchar();
    srand(rand_seed);
    // Half of the letters should be vowels
    for (i=0; i<number/2; i++, destination++) * destination = vowels[rand()%5];
    for (;i<number;i++,  destination++) * destination = rand()%26+'a';
}

/**
* Tries to read the file into the array.
*
* Each line has one value.
*
* Returns the number of lines read or -1 in case of file open error.
*/
int read_array_from_file(const char* filepath, int *array, int array_length){
    FILE *file;
    int i;
    if ((file = fopen(filepath, "r")) == NULL) return -1;
    for (i=0;i<array_length;i++){
    if (fscanf(file, "%d", &array[i]) == EOF) break;
    }
    return i;
}

/**
*
* This gets all the randomly generated letters and checks how many times they appear
*
*/

void duplicateLetters(char *letters, char *duplicate, int Count){
for (int i = 0; i < 7; i++){
    duplicate[i] = letters[i];
    duplicate[i] = -1;
  }
    for (int i = 0; i < 7; i++){
        Count = 1;
        for(int j = i + 1; j < 7; j++){
            if(letters[i] == letters[j]){
                Count++;
                duplicate[j] = 0;
}
}
            if(duplicate[i] != 0){
                duplicate[i] = Count;
                                }
                }
    printf("Your letters (and their count) are: \n");
    for (int i = 0; i < 7; i++)
        {
        if(duplicate[i] != 0){
        printf("%c --> %d  \n", letters[i], duplicate[i]);
                }
}
}

int wordValues (int *valueOfLetters, char *userWord){
    int wordSize = strlen(userWord);
    int startNum = 0;
   // printf("%d \n", wordSize);
    if(wordSize > 7 ){
        printf("This word is too long,  please try again! \n");
    }
        return 0;
        }

void checkIfLetterUsed(char *userWord, char *randomLetter){
    int x = strlen(userWord);
    int position;
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < x; j++){
            if(randomLetter[i] == userWord[j]){
                randomLetter[i] = randomLetter[i+1];
                }
                }
            }
            }


int userWordValue(int *valueOfLetter, char *userWord, int wordScore){
    wordScore = 0;
    int i = 0;
    int lenghtOfWord = strlen(userWord);
    for (i; i < lenghtOfWord; i++){
        int x = userWord[i] - 97;
        int z = valueOfLetter[x];
        wordScore = wordScore + z;
    }
    printf("The value of the word is %d \n", wordScore);

    return 0;


}
void conventStringtoLower(char *userWord){

    userWord = strlwr(userWord);

}



int main()
{
    int valueOfLetters [26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char randomLetter[7];
    int lengthOfPoints = 26;
    int letterValues [lengthOfPoints];
    int count;
    char duplicate [7];
    char userWord [7];
    int wordScore;
    char x;
    int i;
    char answer = 'y';


       // read_array_from_file("C:/Users/dylan.DESKTOP-LTQ2D4A/Desktop/College/Year2Semester2/CProgramming/Scrabble/letter_values",letterValues,lengthOfPoints);
        generate_letters(7, randomLetter);
        duplicateLetters(randomLetter,duplicate, count);
        while(answer == 'y'){
        printf("Please enter a word:\n");
        scanf("%s", userWord);
        getchar();
        conventStringtoLower(userWord);
        userWordValue(valueOfLetters, userWord, wordScore);
        wordValues(valueOfLetters, userWord);
        checkIfLetterUsed(userWord, randomLetter);
        printf("Would you like to play again? y/n \n");
        scanf("%c", &answer);

        }
}

