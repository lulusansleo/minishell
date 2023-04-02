/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** bultin
*/

#include "my.h"
#include "sh.h"

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
    } else {
        env_t *new_env = malloc(sizeof(env_t));
        new_env->name = "PWD";
        new_env->value = cwd;
        new_env->next = NULL;
        env_t *tmp = env;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_env;
    }
    return env;
}

int my_cd(char **args, env_t *env)
{
    char *dir;
    update_oldpwd(env);
    if (args[1] == NULL) {
        dir = get_env_data(env, "HOME")->value;
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
    env = update_pwd(env);
    return 0;
}
