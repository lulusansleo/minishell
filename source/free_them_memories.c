/*
** EPITECH PROJECT, 2023
** sh
** File description:
** free
*/

#include "sh.h"

void free_env(env_t *head)
{
    env_t *tmp = head;
    while (tmp != NULL) {
        tmp = tmp->next;
        free(head->name);
        free(head->value);
        free(head);
        head = tmp;
    }
}
