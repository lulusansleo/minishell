/*
** EPITECH PROJECT, 2023
** builtin env functions
** File description:
** builtin_env
*/

#include "my.h"
#include "sh.h"

int is_builtin(char *command)
{
    if (my_strcmp(command, "/cd") == 0)
        return 1;
    if (my_strcmp(command, "/setenv") == 0)
        return 1;
    if (my_strcmp(command, "/unsetenv") == 0)
        return 1;
    if (my_strcmp(command, "/exit") == 0)
        return 1;
    return 0;
}

void remove_node(env_t *env, int i)
{
    env_t *tmp = env;
    env_t *tmp2 = env;

    if (i == 0) {
        env = env->next;
        free(tmp);
        return;
    }
    for (int j = 0; j < i - 1; j++)
        tmp = tmp->next;
    tmp2 = tmp->next;
    tmp->next = tmp2->next;
    free(tmp2);
}

int my_setenv(char **args, env_t **env)
{
    env_t *tmp = *env;
    char *new_env = NULL;
    if (args[1] == NULL) {
        print_env(*env);
        return 0;
    }
    if (args[2] == NULL)
        new_env = my_strcat(args[1], "=");
    else
        new_env = my_strcat(my_strcat(args[1], "="), args[2]);
    while (tmp != NULL) {
        if (my_strcmp(args[1], tmp->name) == 0) {
            free(tmp->value);
            tmp->value = new_env;
            return 0;
        }
        tmp = tmp->next;
    }
    *env = add_env_node(*env, new_env);
    return 0;
}

int my_unsetenv(char **args, env_t **env)
{
    env_t *tmp = *env;
    int i = 0;

    if (args[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    while (tmp != NULL) {
        if (my_strcmp(args[1], tmp->name) == 0) {
            remove_node(*env, i);
            return 0;
        }
        tmp = tmp->next;
        i++;
    }
    return 0;
}

int my_exit(char **args, env_t **env)
{
    (void)args;
    (void)env;
    exit(0);
    return 0;
}
