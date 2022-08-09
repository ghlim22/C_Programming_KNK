#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point upper_left;
    struct point lower_right;
};

struct
{
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] =
    {{"new", new_cmd},
     {"open", open_cmd},
     {"close", close_cmd},
     {"close all", close_all_cmd},
     {"save as", save_as_cmd},
     {"save all", save_all_cmd},
     {"print", print_cmd},
     {"exit", exit_cmd}};

void run_func(char *str)
{
    for (int i = 0; i < sizeof(file_cmd) / sizeof(file_cmd[0]); ++i)
    {
        if (strcmp(str, file_cmd[i]) == 0)
        {
            return (*file_cmd[i].cmd_pointer)();
        }
    }

    return;
}

void *my_malloc(size_t size)
{
    void *res = malloc(size);
    if (res == NULL)
    {
        fprintf(stderr, "malloc failed at my_malloc\n");
        exit(0);
    }
    return res;
}

char *duplicate(char *str)
{
    char *res = malloc(strlen(str) + 1);
    if (res == NULL)
    {
        return NULL;
    }

    strcpy(res, str);
    return res;
}

int *create_array(int n, int initial_value)
{
    int *res = (int *)malloc(n);
    if (res == NULL)
    {
        fprintf(stderr, "malloc failed.\n");
        return NULL;
    }

    for (int i = 0; i < n; ++i)
    {
        *(res + i) = initial_value;
    }

    return res;
}

int sum(int (*f)(int), int start, int end)
{
    int sum = 0;
    for (int i = start; i <= end; ++i)
    {
        sum += f(i);
    }
    return sum;
}

int main(void)
{
}