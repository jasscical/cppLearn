#include <cctype>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


// Print string str partially, from start to end-1. 
void print_word(const char* str, int start, int end)
{
    for(int i = start; i < end; i++){
        printf("%c", str[i]);
    }
}
/// Reversely print string str. 
void reversely_print_string(const char* str)
{
    int len = strlen(str);
    int end = len;
    for(int i = len - 1; i >= 0; i--){
        if(' ' == str[i]){
            print_word(str, i + 1, end);
            printf("%c", str[i]);
            end = i;
        }
    }
    print_word(str, 0, end); // 打印[0, end)头部单词
}
int main(int argc, char* argv[])
{
    reversely_print_string("Hello    world Welcome to   China");
}



/*
int main(){
    // "abc  bc  ab"变为"ab bc abc"
    char str[] = "abc  bc  ab";
    char* cstr = str;
    *(cstr + 1) = 'a';
    cout << cstr << endl;
}*/

