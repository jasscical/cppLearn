#include <cstdlib>
#include <cstdio>
#include <cstring>

/*
#include <cstdio>

scanf ：当遇到回车，空格和tab键会自动在字符串后面添加’\0’，但是回车，空格和tab键仍会留在输入的缓冲区中。
gets：可接受 回车键之前 输入的所有字符，并用’\0’替代 ‘\n’.回车键不会留在输入缓冲区中
eg.
从键盘输入字符串 asd df时，遇到空格，scanf（）就认为输入结束了，所以a中存放的字符串是 ‘asd\0’。
而同样输入，用gets的话，最后敲回车b中存放的字符串是 ‘asd df\0’。

printf:
puts:在输出字符串时会将’\0’自动转换成’\n’进行输出，也就是说，puts方法输出完字符串后会自动换行。

    char a[10];
    char b[20];
    scanf("%s",a);

    printf("%s\n",a);

    gets(b);


*/

int main(){
    char strArr[] = "Hello World!";
    const char* cstr = "Hello    world Welcome to   China";
    
    int len = strlen(cstr);
    char *a = new char[len]; // new/delete 为c++中动态分配内存
    char *b = (char*)malloc(len); // malloc/free 为c++中动态分配内存
    strcpy(a, strArr);
    strcpy(b, cstr);
    printf("%s\n", a);
    puts(a);
    printf("%s\n", b);
    puts(b);

}