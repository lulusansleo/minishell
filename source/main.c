/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "my.h"
#include "sh.h"

int main(int ac, char **av, char **env)
{
    env_t *head = get_env(env);
    int status = 0;
    char **paths = get_paths_from_env(get_data_env(env, "PATH"));
    status = run_shell_loop(head, paths, env);
    free_env(head);
    return status;
}
