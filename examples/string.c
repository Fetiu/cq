#include <stdio.h>
#include <string.h>

struct string_mut
{
    char pointer[16];
};

struct string_immut
{
    char *pointer;
};


void run_string_mut(const char* reason)
{
    struct string_mut src;
    strcpy(src.pointer,reason);

    struct string_mut result = src;

    printf("copied to result: %s\n", result.pointer);

    result.pointer[strlen(reason)] = '!';
    printf("modified result: %s\n", result.pointer);

    printf("source stayed: %s\n", src.pointer);
}


void run_string_immut(const char* reason)
{
    struct string_immut src = { .pointer = strdup(reason) };

    struct string_immut result = src;

    printf("copied to result: %s\n", result.pointer);

    result.pointer[strlen(reason)] = '!';
    printf("modified result: %s\n", result.pointer);

    printf("source stayed: %s\n", src.pointer);
}

int main(void)
{
    run_string_mut("hello");
    run_string_immut("hello");
    
    return 0;
}
