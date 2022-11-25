#include "hedoshell.h"

#include "env.h"

int env_init(char **env)
{
    if (env == NULL)
        return (ERROR);
    g_env.env = env_copy(env);
    return (0);
}

char    **env_realloc(char **env, char *str)
{
    char **new;
    int idx;

    idx = -1;
    new = (char **) malloc(sizeof(char *) * (g_env.env_size + 2));
    while (++idx < g_env.env_size)
    {
        new[idx] = ft_strdup(env[idx]);
        free(env[idx]);
    }
    new[idx] = str;
    new[idx + 1] = NULL;
    free(env);
    return (new);
}

char    **env_copy(char **env)
{
    char **new;
    int idx;

    g_env.env_size = env_size(env);
    idx = -1;
    new = (char **) malloc(sizeof(char *) * (g_env.env_size + 1));
    while (++idx < g_env.env_size)
        new[idx] = ft_strdup(env[idx]);
    new[idx] = NULL;
    return (new);
}

void	env_shlvl()
{
	int shell;
	char *tmp;

	shell = ft_atoi(env_get_value("SHLVL"));
	shell++;
	tmp = ft_itoa(shell);
	env_var_set("SHLVL", tmp);
	free(tmp);
}