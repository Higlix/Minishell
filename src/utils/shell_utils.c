#include "hedoshell.h"

#include "utils.h"

int		setup_shell()
{
	g_env.prompt = NULL;
	g_env.env = NULL;
	g_env.env_size = 0;
	return (SUCCESS);
}