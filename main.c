#include <stdio.h>
#include <string.h>
#include "my_str.h"

int main() {
    char TXT[1024];
    char word[30];
    printf("pleae enter your word\n");
    scanf("%s", word);
    printf("pleae enter your text\n");
    int counter_letter_text=0;
    char ch;
    ch = getchar();
    while(ch!= '~'){
        TXT[counter_letter_text]=ch;
        ch = getchar();
        counter_letter_text++;
    }
    printf("Gematria Sequences: ");
    funcA(word,TXT);
    printf("\n");
    printf("Atbash Sequences: ");
    funcB(word,TXT);
    printf("\n");
    printf("Anagram Sequences: ");
    funcC(word,TXT);
    printf("\n");
    return 0;
}
