#include "hedoshell.h"

#include "env.h"
#include "printer.h"

void	print_env(void)
{
	int	i;

	i = 0;
	while (i < g_env.env_size)
	{
		ft_putstr_fd(g_env.env[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}