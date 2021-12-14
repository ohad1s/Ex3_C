#include <stdio.h>
#include <string.h>
//--------------------------------
// Created by shira on 13/12/2021.
//--------------------------------

int gimatry_char(char c){
    int value=0;
    if (c<='z' && c>='a'){
        return c-('a'-1);
    }
    if (c<='Z' && c>='A'){
        return c-('A'-1);
    }
    else{
        return value;
    }
}

int calc_word_val(char* word){
    int word_val=0;
    for (int i=0; i<strlen(word); i++){
        word_val+= gimatry_char(word[i]);
    }
    return word_val;
}

void funcA(char* word, char* txt){
    int word_val= calc_word_val(word);
    int snake_flag=0;
    int index=0;
    while (txt[index]!='\0'){
        if ((txt[index]<='z' && txt[index]>='a') || (txt[index]<='Z' && txt[index]>='A') ){
            int temp_sum=0;
            for (int j=index; j< strlen(txt); j++){
                temp_sum+= gimatry_char(txt[j]);
                if (temp_sum==word_val){
                    if (snake_flag!=0){
                        printf("~");
                    }
                    for (int k=index; k<=j; k++){
                        printf("%c",txt[k]);
                    }
                    snake_flag++;
                    break;
                }
                else if (temp_sum<word_val){
                    continue;
                }
                else{
                    break;
                }
            }
        }
        index++;
    }
}


char atbash_char(char c){
    if (c<='z' && c>='a'){
        char pos=c-97;
        pos=25-pos;
        return pos+97;
    }
    if (c<='Z' && c>='A'){
        char pos=c-65;
        pos=25-pos;
        return pos+65;
    }
    else{
        return c;
    }
}

void funcB(char* word, char* txt){
    char rev[strlen(word)];
    int j=strlen(word)-1;
    for (int i = 0; i < strlen(word); i++)
    {
        rev[i] = word[j];
        j--;
    }
    int index=0;
    int snake_flag=0;
    while (txt[index]!='\0'){
        if ((txt[index]== atbash_char(word[0]))){
            int counter=0;
            int word_index=0;
            for (int j=index; j<index+strlen(word); j++){
                if (txt[j]== atbash_char(word[word_index])){
                    counter++;
                    word_index++;
                }
            }
            if (counter== strlen(word)){
                if (snake_flag!=0){
                    printf("~");
                }
                for (int k=index; k<index+strlen(word); k++){
                    printf("%c",txt[k]);
                }
                snake_flag++;
            }
        }
        if ((txt[index]== atbash_char(rev[0]))){
            int counter=0;
            int word_index=0;
            for (int j=index; j<index+strlen(rev); j++){
                if (txt[j]== atbash_char(rev[word_index])){
                    counter++;
                    word_index++;
                }
            }
            if (counter== strlen(rev)){
                if (snake_flag!=0){
                    printf("~");
                }
                for (int k=index; k<index+strlen(rev); k++){
                    printf("%c",txt[k]);
                }
                snake_flag++;
            }
        }
        index++;
    }
}
void swap(char *xp, char *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(char arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void remove_char_from_string(char* str, char ch){
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ch)
        {
            for(int j = i; j < len; j++)
            {
                str[j] = str[j + 1];
            }
            len--;
            i--;
        }
    }
}

void funcC(char* word, char* txt){
    int snake_flag=0;
    char word_sorted[strlen(word)];
    strcpy(word_sorted, word);
    bubbleSort(word_sorted, strlen(word_sorted));
    for (int i=0; i<= strlen(txt); i++){
        for (int j=i; j<= strlen(txt); j++){
            int len=j-i+1;
            char word_to_check[len+1];
            int counter=0;
            for (int t=i; t<j; t++){
                word_to_check[counter]=txt[t];
                counter++;
            }
            word_to_check[counter]='\0';
            char word_to_check_copy[strlen(word_to_check)];
            strcpy(word_to_check_copy,word_to_check);
            bubbleSort(word_to_check_copy, strlen(word_to_check_copy));
            remove_char_from_string(word_to_check_copy, ' ');
            int comp=  strcmp(word_to_check_copy,word_sorted);
            if (comp==0){
                if (snake_flag!=0){
                    printf("~");
                }
                for (int k=0; k< strlen(word_to_check); k++){
                    printf("%c",word_to_check[k]);
                }
                snake_flag++;
            }
        }
    }

}



