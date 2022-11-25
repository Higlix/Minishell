#ifndef TOKEN_H
# define TOKEN_H

# define WHITESPACES " \n\t"
# define QUOTES "\'\""

# define TOKEN_TXT 1
# define TOKEN_D_QUOTE 2
# define TOKEN_S_QUOTE 4
# define TOKEN_PIPE 8
# define TOKEN_CONNECTED 16
# define TOKEN_REDIR 32
# define TOKEN_REDIR_FILE 64
# define TOKEN_C_BRACKET 128
# define TOKEN_O_BRACKET 256

# include "hedoshell.h"

typedef struct s_token	t_token;

struct s_token
{
	char	*tok;
	int		flags;
};

t_list	*tok_create(char *tok, int flags);

t_token	*tok_content(t_list *token);

void    tok_del(void  *content);

#endif