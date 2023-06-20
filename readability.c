#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//declaring functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

//main function
int main(void)
{
    string text = get_string("Text: ");
    int Letters_count = count_letters(text);
    int Words_count = count_words(text);
    int Sentences_Count = count_sentences(text);


    //calculating the value of L
    float L = ((float) Letters_count / (float) Words_count) * (float) 100;

    //calculating the value of s
    float S = ((float)Sentences_Count / (float) Words_count) * (float) 100;

    //calcualting index
    float Index = (0.0588 * L) - (0.296 * S) - 15.8;

    //rounding the answer
    int rounded_Index = round(Index);

    //if the index is 16+ it prints 16+ and if the index is lesser that 1 it prints before grade 1 otherwise gives exact values 2-15
    if (rounded_Index > 1 && rounded_Index < 16)
    {
        printf(" Grade %i\n", rounded_Index);
    }

    else if (rounded_Index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (rounded_Index > 16)
    {
        printf("Grade 16+\n");
    }


    return 0;
}

// function to calculate no of letters

int count_letters(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }


    return count;
}

//function to calculate no of words

int count_words(string text)
{
    int space = 1;
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == ' ')
        {

            space++;

        }

    }

    return space;

}

//function to calculate no of sentences

int count_sentences(string text)
{
    int sign = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        if (text[k] == '?' || text[k] == '.' || text[k] == '!')
        {

            sign++;

        }
    }

    return sign;

}
