/*
** EPITECH PROJECT, 2023
** SHELL
** File description:
** third
*/

#include "my.h"
#include "sh.h"

env_t *get_data_env(char **env, char *data)
{
    env_t *tmp = get_env(env);

    while (my_strcmp(data, tmp->name) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

char **get_paths_from_env(env_t *path_env)
{
    return my_str_to_word_array_sep(path_env->value, ':');
}

char *get_command_path(char **paths, char *command)
{
    char *command_path;

    for (int i = 0; paths[i] != NULL; i++) {
        command_path = my_strcat(paths[i], command);
        if (access(command_path, X_OK) == 0) {
            return command_path;
        }
        free(command_path);
    }
    return NULL;
}

int execute_command(char *command_path, char **args, char **env)
{
    int status;
    if ((status = execve(command_path, args, env)) == -1) {
        my_printf("%s: Command not found.\n", args[0]);
        exit(EXIT_FAILURE);
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
