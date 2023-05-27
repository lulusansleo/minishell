/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** shell
*/

#include "my.h"
#include "sh.h"

int main(int ac, char **av, char **env);

void print_env(env_t *head)
{
    env_t *tmp = head;
    while (tmp != NULL) {
        my_putstr(tmp->name);
        my_putchar('=');
        my_putstr(tmp->value);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

int get_list_size(env_t *head)
{
    env_t *tmp = head;
    int i = 0;
    while (tmp != NULL) {
        tmp = tmp->next;
        i++;
    }
    return i;
}

static env_t *assign_values(env_t *node, char *env)
{
    int name_len = 0, len = my_strlen(env);
    for (; env[name_len] != '='; name_len++);
    node->name = malloc(sizeof (char) * (name_len) + 1);
    node->value = malloc(sizeof (char) * (len - name_len + 1));
    for (int i = 0; i < name_len; i++)
        node->name[i] = env[i];
    node->name[name_len] = '\0';
    for (int i = 0; i < len -  name_len - 1; i++)
        node->value[i] = env[i + name_len + 1];
    node->value[len - name_len - 1] = '\0';
    return node;
}

env_t *add_env_node(env_t *head, char *env)
{
    env_t *tmp = head, *new_node = NULL;

    if (head == NULL) {
        head = malloc(sizeof (env_t));
        head = assign_values(head, env);
        head->next = NULL;
        return head;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    new_node = malloc(sizeof (env_t));
    new_node = assign_values(new_node, env);
    tmp->next = new_node;
    new_node->next = NULL;
    return head;
}

env_t *get_env(char **env)
{
    env_t *head = NULL;
    for (int i = 0; env[i] != NULL; i++) {
        head = add_env_node(head, env[i]);
    }
    return head;
}
