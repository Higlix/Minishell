#include "hedoshell.h"

#include "utils.h"
#include "env.h"
#include "printer.h"
#include "signal.h"

t_shell  g_env;

static	char *get_input(void);

int main(int argc, char **argv, char **env)
{
	setup_shell();
	if (env_init(env) == ERROR)
		return (ERROR);
	sig_connect();
	env_shlvl();

	char *input;
	while (1)
	{
		input = get_input();
		if (input == NULL)
			break ;
		if (ft_strncmp(input, "test123", 7) == 0)
		{
			print_env();
		}
		add_history(input);
		system(input);
		free(input);
	}
	if (input == NULL)
	{
		ft_putstr_fd("exit", STDOUT_FILENO);
		return (0);
	}
	return (0);
}

static	char	*get_input(void)
{
	char	*prompt;
	char	*input;

	if (env_find_var("PS1") != ERROR)
		prompt = env_get_value("PS1");
	else
		prompt = PROMPT;
	if (isatty(STDIN_FILENO))
		input = readline(prompt);
	else
		return (NULL);
	if (input == NULL)
		return (NULL);
	else if (isatty(STDIN_FILENO) && input && input[0])
		add_history(input);
	return (input);
}