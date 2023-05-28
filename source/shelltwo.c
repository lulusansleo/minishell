/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** shell
*/

#include "my.h"
#include "sh.h"

char **get_env_from_struct(env_t *head)
{
    env_t *tmp = head;
    char **env = malloc(sizeof (char *) * (get_list_size(head) + 1));
    int i = 0;
    while (tmp != NULL) {
        env[i] = my_strcat(tmp->name, "=");
        env[i] = my_strcat(env[i], tmp->value);
        tmp = tmp->next;
        i++;
    }
    env[i] = NULL;
    return env;
}

char **parse_args(char *line)
{
    char **args = my_str_to_word_array_sep(line, ' ');
    args[0] = my_strcat("/", args[0]);
    return args;
}

int execute(char **args, char **paths, char **env)
{
    char *command_path = get_command_path(paths, args[0]);
    int status = 0;
    __pid_t pid = fork();
    if (pid == 0) {
        status = execute_command(command_path, args, env);
        free(command_path);
        exit(EXIT_FAILURE);
    } else {
        status = 0;
        if (waitpid(pid, &status, 0) == -1) {
            perror("Failed to wait for child process");
            return -1;
        }
        if (WIFEXITED(status))
            return WEXITSTATUS(status);
        if (WIFSIGNALED(status))
            return 128 + WTERMSIG(status);
    }
    return WIFEXITED(status) ? WEXITSTATUS(status) : status;
}

int run_shell_loop(env_t *head, char **paths, char **env)
{
    char *line, **args;
    int status = 0;
    while (1) {
        line = get_input();
        if (!line)
            break;
        if (line[0] == '\0')
            continue;
        status = shell_loop_second_part(line, &head, status, paths);
    }
    return status;
}

int shell_loop_second_part(char *line, env_t **head, char **env, char **paths)
{
    int status = 0;
    char **arg = my_str_to_word_array_sep(line, ';');
    char **args;
    for (int i = 0; arg[i] != NULL; i++) {
        args = parse_args(arg[i]);
        if (is_builtin(args[0]) == 1) {
            status = builtin(args, head);
            continue;
        }
        env = get_env_from_struct(*head);
        status = execute(args, paths, env);
        free_array(args);
    }
    free(line);
    return status;
}
