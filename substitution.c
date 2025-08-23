#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    int index;
    char cipher;
    char *key = argv[1];
    
    //Check on one-line argument
    if (argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check that key is 26 letters long
    if (strlen(key) != 26) { 
            printf("Key must be 26 letters.\n"); 
            return 1; 
        }
    
    //Check that key contains only letters 
    for (int i = 0; i < 26; i++){
        if (!isalpha(key[i])){
            printf("Key must only contain letters.\n");
            return 1;
        } 
    }

    //Check that key has no repeated letters
    for (int i = 0; i < 26; i++){
        for (int j = i + 1; j < 26; j++){
            if (tolower(key[i]) == tolower(key[j])){
                printf("Key must not contain duplicates letters.\n");
                return 1;
            }
        }
    }

    //Get user input
    printf("Plaintext: ");
    char plaintext[1000];
    fgets(plaintext, sizeof(plaintext), stdin);

    //Cipher 
    for (int i = 0; plaintext[i] != '\0'; i++){
        if (isupper(plaintext[i])){
            index = plaintext[i] - 'A';
            cipher = toupper(key[index]);
        }
        else if (islower(plaintext[i])){
            index = plaintext[i] - 'a';
            cipher = tolower(key[index]);
        }
        else {
            cipher = plaintext[i];
        }
        printf("%c", cipher);
    }
    printf("\n");
}


