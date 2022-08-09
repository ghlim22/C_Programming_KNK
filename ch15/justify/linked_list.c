#include "linked_list.h"
#include <string.h>

Node *add_to_list(Node **list, char *str)
{
    Node *new_node;
    new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->value, str);
    new_node->next = *list;
    *list = new_node;
}

Node *search_list(Node *list, int n)
{
    Node *p;

    for (p = list; p != NULL; p = p->next)
    {
        if (p->value == n)
        {
            return p;
        }
    }

    return NULL;
}

Node *delete_from_list(Node *list, int n)
{
    Node *prev, *cur;

    for (prev = NULL, cur = list; cur != NULL && cur->value != n; prev = cur, cur = cur->next)
        ;

    if (cur == NULL) // n was not found.
    {
        return list;
    }

    if (prev == NULL) // n is in the fist node.
    {
        list = list->next;
    }
    else
    {
        prev->next = cur->next;
    }

    free(cur);

    return list;
}

Node *delete_from_list2(Node **list, int n)
{
    Node *item = *list;
    Node *prev = NULL;
    Node *cur = *list;
    while (cur != NULL)
    {
        if (cur->value == n)
        {
            prev->next = cur->next;
            free(cur);
        }
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL)
    {
        return *list;
    }
    if (prev == NULL)
    {
        *list = cur;
        return *list;
    }
    return *list;
}

int count_occurences(Node *list, int n)
{
    int cnt = 0;
    for (; list != NULL; list = list->next)
    {
        if (list->value == n)
        {
            cnt++;
        }
    }

    return cnt;
}

Node *find_last(Node *list, int n)
{
    Node *temp = NULL;
    while (list != NULL)
    {
        if (list->value == n)
        {
            temp = list;
        }
        list = list->next;
    }

    return temp;
}

Node *insert_into_ordered_list(Node *list, Node *new_node)
{
    Node **p = &list;
    Node *prev = NULL;
    Node *cur = list;

    while (cur != NULL && cur->value < new_node->value)
    {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) // insert at front.
    {
        new_node->next = list;
        *p = new_node;
        new_node = list;
    }
    else if (cur == NULL)
    {
        prev->next = new_node;
        new_node->next = NULL;
    }
    else
    {
        prev->next = new_node;
        new_node->next = cur;
    }

    return list;
}

Node *insert_into_ordered_list2(Node *list, Node *new_node)
{
    Node **p = &list;
    while (list != NULL)
    {
        if (new_node->value <= list->value)
        {
            break;
        }
        *p = list->next;
        list = list->next;
    }

    *p = new_node;
    new_node = list;
}
