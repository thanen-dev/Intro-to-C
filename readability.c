#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    printf("Text: ");
    char text[1000];
    fgets(text, sizeof(text), stdin);

    // Count the number of letters, words, and sentences in the text
    int count_letters(const char *text);
    int count_words(const char *text);
    int count_sentences(const char *text);

    // Compute the Coleman-Liau index
    float L = (float)count_letters(text) / count_words(text) * 100;
    float S = (float)count_sentences(text) / count_words(text) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
    return 0;
}   

// Count the number of alphabetic letters (A–Z, a–z) in the text 
int count_letters(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Count the number of words in the text
int count_words(const char *text)
{
    int count = 0;
    int in_word = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            in_word = 0;
        }
        else if (!in_word)
        {
            in_word = 1;
            count++;
        }
    }
    return count;
}

//Count number of sentences in the text
int count_sentences(const char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

