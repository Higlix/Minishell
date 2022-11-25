#include "hedoshell.h"

#include "lexer.h"
#include "token.h"

int     lexer_token_text(char *input, int *i, t_list **tokens)
{
	t_list  *token;
	char    *token_str;
	int     len;

	len = text_len(&input[*i]);
	if (len > 0)
	{
		token_str = ft_substr(input, *i, len);
		token = tok_create(token_str, TOKEN_TXT);
		ft_lstadd_back(tokens, token);
		(*i) += len;
        if (!ft_strchr(WHITESPACES, input[*i]) && other_len(&input[*i]) == 0)
			tok_content(token)->flags |= TOKEN_CONNECTED;
	}
	return (0);
}

int     lexer_token_pipe(char *input, int *i, t_list **tokens)
{
	t_list  *token;
	char    *token_str;

	if (input[*i] == '|')
	{
		token_str = ft_substr(input, *i, 1);
		if (token_str == NULL)
			return (ERROR);
		token = tok_create(token_str, TOKEN_PIPE);
		if (token == NULL)
			return (ERROR);
		ft_lstadd_back(tokens, token);
		(*i)++;
	}
	return (0);
}

int		lexer_token_quote(char *input, int *i, t_list **tokens)
{
	t_list	*token;
	char	*token_str;
	int		len;

	len = quote_len(&input[*i]);
    if (len == ERROR)
        return (ERROR);
	if (len > 0)
	{
		token_str = ft_substr(input, *i + 1, len - 2);
		if (input[*i] == '\'')
			token = tok_create(token_str, TOKEN_S_QUOTE | TOKEN_TXT);
		else
			token = tok_create(token_str, TOKEN_D_QUOTE | TOKEN_TXT);
		ft_lstadd_back(tokens, token);
		(*i) += len;
        if (!ft_strchr(WHITESPACES, input[*i]) && other_len(&input[*i]) == 0)
			tok_content(token)->flags |= TOKEN_CONNECTED;        
	}
	return (0);
}

int     lexer_token_bracket(char *input, int *i, t_list **tokens)
{
    char    *token_str;
    t_list  *token;

    if (input[*i] == ')' || input[*i] == '(')
    {
        token_str = ft_substr(input, *i, 1);
        if (input[*i] == ')')
            token = tok_create(token_str, TOKEN_C_BRACKET);
        else
            token = tok_create(token_str, TOKEN_O_BRACKET);
        ft_lstadd_back(tokens, token);
        (*i)++;
    }
    return (0);
}

int     lexer_token_redir(char *input, int *i, t_list **tokens)
{
    char    *token_str;
    int     len;
    t_list  *token;

    len = 0;
    while (ft_isdigit(input[*i + len]))
        len++;
    if (input[*i + len] == '>' || input[*i + len] == '<')
    {
        if (input[*i + len] == input[*i + len + 1])
            len++;
        len++;
        token_str = ft_substr(input, *i, len);
        token = tok_create(token_str, TOKEN_REDIR);
        ft_lstadd_back(tokens, token);
        (*i)+=len;
    }
    return (0);
}