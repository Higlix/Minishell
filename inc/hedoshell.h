#ifndef HEDOSHELL_H
# define HEDOSHELL_H

# define SUCCESS 0
# define ERROR -1
# define PROMPT "$> "

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "libft_printer.h"

typedef struct s_shell	t_shell;

struct s_shell
{
	char			*prompt;
	char			**env;
	unsigned int	env_size;
};

extern t_shell   g_env;

#endif