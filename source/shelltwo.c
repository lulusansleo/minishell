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
        execute_command(command_path, args, env);
        free(command_path);
        exit(0);
    }
    waitpid(pid, &status, 0);
    status = WIFEXITED(status) ? WEXITSTATUS(status) : status;
    free(command_path);
    return status;
}

int run_shell_loop(env_t *head, char **paths, char **env)
{
    char *line, **args;
    int status = 0;
    while (1) {
        print_prompt();
        line = get_input();
        if (!line)
            break;
        if (line[0] == '\0')
            continue;
        args = parse_args(line);
        if (my_strcmp(args[0], "/cd") == 0) {
            my_cd(args, head);
            free(line);
            continue;
        }
        env = get_env_from_struct(head);
        status = execute(args, paths, env);
        free_array(args, line);
    }
    return status;
}

char *get_input(void)
{
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        free(line);
        return NULL;
    }
    line[my_strlen(line) - 1] = '\0';
    return line;
}