#include "hedoshell.h"

#include "signal.h"

void	sig_handle(int signal)
{
	if (SIGINT == signal)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sig_connect(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handle);
}