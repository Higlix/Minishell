#ifndef LEXER_H
# define LEXER_H

#include "hedoshell.h"

t_list	*lexer(char *input);

int     lexer_token_text(char *input, int *i, t_list **tokens);
int     lexer_token_pipe(char *input, int *i, t_list **tokens);
int		lexer_token_quote(char *input, int *i, t_list **tokens);
int     lexer_token_bracket(char *input, int *i, t_list **tokens);
int     lexer_token_redir(char *input, int *i, t_list **tokens);

int		other_len(char *chr);
int		quote_len(char *input);
int     text_len(char *input);

#endif