/*
** EPITECH PROJECT, 2023
** MINISHELL1
** File description:
** sh.h
*/

#ifndef SH_H
    #define SH_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/wait.h>

    typedef struct env {
            char *name;
            char *value;
            struct env *next;
    } env_t;

    //frees env struct
    void free_env(env_t *head);
    //stores env in struct
    env_t *get_env(char **env);
    //gets path from env
    char **get_paths_from_env(env_t *path_env);
    //gets path env
    env_t *get_data_env(char **env, char *path);
    //get command path
    char *get_command_path(char **paths, char *command);
    //run shell loop
    int run_shell_loop(env_t *head, char **paths, char **env);

    void execute_command(char *command_path, char **args, char **env);

    void print_prompt(void);

    char *get_input(void);

    env_t *add_env_node(env_t *head, char *env);

    char **parse_args(char *line);

    void update_oldpwd(env_t *env);

    env_t *get_env_data(env_t *env, char *var);

    int get_list_size(env_t *head);

#endif /* !SH_H */
