#include "hedoshell.h"

#include "env.h"

char    *env_get_value(const char *name)
{
    int     name_len;
    int     list_idx;
    int     idx;

    list_idx = env_find_var(name);
    if (list_idx == ERROR)
        return (NULL);
    name_len = ft_strlen(g_env.env[list_idx]);
    idx = -1;
    while (++idx < name_len)
        if (g_env.env[list_idx][idx] == '=')
            return (&g_env.env[list_idx][idx + 1]);
    return (NULL);
}

int     env_find_var(const char *name)
{
    int    index;
    int    name_len;
    char   **env;

    index = -1;
    env = g_env.env;
    name_len = ft_strlen(name);
    while (++index < g_env.env_size)
        if (!ft_strncmp(env[index], name, name_len))
            return (index);
    return (ERROR);
}

int     env_size(char **env)
{
    int size;

    size = 0;
    while (env[size])
        size++;
    return (size);
}

void    env_free()
{
    int i;

    i = 0;
    while (i < g_env.env_size)
        free(g_env.env[i++]);
    free(g_env.env);
    free(g_env.prompt);
}