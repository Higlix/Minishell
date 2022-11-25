#ifndef ENV_H
# define ENV_H

int     env_var_set(const char *name, const char *value);
int     env_var_unset(const char *name);
int     env_init(char **env);
int     env_size(char **env);
int     env_find_var(const char *name);
int     env_change_value(const char *name, const char *value);

char    *env_get_value(const char *name);
char    **env_realloc(char **env, char *str);
char    **env_copy(char **env);

void	env_shlvl();
void    env_free();

#endif