#include "hedoshell.h"

#include "lexer.h"
#include "token.h"

t_list	*lex_input(char *input)
{
	t_list	*l_tok;
	int		i;

	l_tok = NULL;
	i = 0;
	while (input && input[i])
	{
		if (lexer_token_pipe(input, &i, &l_tok) == ERROR)
			break ;
        if (lexer_token_bracket(input, &i, &l_tok) == ERROR)
            break ;
        if (lexer_token_redir(input, &i, &l_tok) == ERROR)
            break ;
		if (lexer_token_text(input, &i, &l_tok) == ERROR)
			break ;
		if (lexer_token_quote(input, &i, &l_tok) == ERROR)
			break ;
		while (input[i] && ft_strchr(WHITESPACES, input[i]))
			i++;	
	}
	if (input[i] != '\0')
		ft_lstclear(&l_tok, tok_del);
	return (l_tok);
}

t_list	*lexer(char *input)
{
	t_list	*l_tok;

	l_tok = lex_input(input);
	if (l_tok == NULL)
		return (NULL);
	return (l_tok);
}