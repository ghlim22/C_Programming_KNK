#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include "node.h"
#endif

Node *add_to_list(Node **list, int n);
Node *search_list(Node *list, int n);
Node *delete_from_list(Node *list, int n);