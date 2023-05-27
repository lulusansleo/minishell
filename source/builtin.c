/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** bultin
*/

#include "my.h"
#include "sh.h"

int builtin(char **args, env_t **head)
{
    if (my_strcmp(args[0], "/cd") == 0)
        return my_cd(args, head);
    if (my_strcmp(args[0], "/setenv") == 0)
        return my_setenv(args, head);
    if (my_strcmp(args[0], "/unsetenv") == 0)
        return my_unsetenv(args, head);
    if (my_strcmp(args[0], "/exit") == 0)
        return my_exit(args, head);
    return 1;
}

env_t *get_env_data(env_t *env, char *var)
{
    for (env_t *tmp = env; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(var, tmp->name) == 0) {
            return tmp;
        }
    }
    return NULL;
}

void update_oldpwd(env_t *env)
{
    char *cwd = getcwd(NULL, 0);
    env_t *oldpwd = get_env_data(env, "OLDPWD");
    if (oldpwd) {
        free(oldpwd->value);
        oldpwd->value = cwd;
    } else {
        env_t *new_env = malloc(sizeof(env_t));
        new_env->name = "OLDPWD";
        new_env->value = cwd;
        new_env->next = NULL;
        env_t *tmp = env;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_env;
    }
}

env_t *update_pwd(env_t *env)
{
    char *cwd = getcwd(NULL, 0);
    env_t *pwd = get_env_data(env, "PWD");
    if (pwd) {
        free(pwd->value);
        pwd->value = cwd;
        return env;
    }
    env_t *new_env = malloc(sizeof(env_t));
    new_env->name = "PWD";
    new_env->value = cwd;
    new_env->next = NULL;
    if (env == NULL) {
        env = new_env;
    } else {
        env_t *tmp = env;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_env;
    }
    return env;
}

int my_cd(char **args, env_t **head)
{
    char *dir;
    if (args[1] == NULL) {
        dir = get_env_data(*head, "HOME")->value;
    } else if (my_strcmp(args[1], "-") == 0) {
        dir = get_env_data(*head, "OLDPWD")->value;
        my_printf("%s\n", dir);
    } else {
        dir = args[1];
    }
    if (dir == NULL) {
        my_putstr("cd: HOME not set\n");
        return 1;
    }
    if (chdir(dir) == -1) {
        perror("cd");
        return 1;
    }
    update_oldpwd(*head);
    *head = update_pwd(*head);
    return 0;
}
