#include "hedoshell.h"

#include "env.h"

int env_change_value(const char *name, const char *value)
{
    char    *s1;
    char    *s2;
    int     idx;

    idx = env_find_var(name);
    if (idx == ERROR)
        return (ERROR);
    s1 = ft_strjoin(name, "=");
    s2 = ft_strjoin(s1, value);
    free(s1);
    free(g_env.env[idx]);
    g_env.env[idx] = s2;
    return (idx);
}

int env_var_unset(const char *name)
{
    char **new;
    int  name_len;
    int  n_idx;
    int  e_idx;
    
    if (env_find_var(name) == ERROR)
        return (ERROR);
    new = (char **) malloc(sizeof(char *) * g_env.env_size);
    n_idx = -1;
    e_idx = 0;
    name_len = ft_strlen(name);
    while (++n_idx < g_env.env_size - 1)
    {
        if (!ft_strncmp(name, g_env.env[e_idx], name_len))
            e_idx++;
        new[n_idx] = ft_strdup(g_env.env[e_idx]);
        free(g_env.env[n_idx]);
        e_idx++;
    }
    free(g_env.env[n_idx]);
    free(g_env.env);
    g_env.env = new;
    g_env.env_size--;
    return (0);
}

int env_var_set(const char *name, const char *value)
{
    char *s1;
    char *s2;

    if (name == NULL || value == NULL)
        return (ERROR);
    if (env_find_var(name) != ERROR)
    {
        env_change_value(name, value);
        return (env_find_var(name));
    }
    s1 = ft_strjoin(name, "=");
    s2 = ft_strjoin(s1, value);
    free(s1);
    g_env.env = env_realloc(g_env.env, s2);
    g_env.env_size++;
    return (g_env.env_size - 1);
}