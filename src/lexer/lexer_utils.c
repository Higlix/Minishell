#include "hedoshell.h"

#include "lexer.h"
#include "token.h"

int     text_len(char *input)
{
	int idx;
    
    idx = 0;
    while (input[idx])
	{
		if (ft_strchr(QUOTES, input[idx]))
			break ;
        else if (other_len(&input[idx]) > 0)
            break ;
		else if (ft_strchr(WHITESPACES, input[idx]))
			break ;
		idx++;
	}
	return (idx);
}

int		quote_len(char *input)
{
	int 	i;
	char	quote;

	if (input == NULL || *input == '\0')
		return (0);
	if (ft_strchr(QUOTES, input[0]) == NULL)
		return (0);
	quote = input[0];
	i = 1;
	while (input[i])
	{
		if (input[i] == quote)
			break ;
		i++;
	}
	if (input[i] != quote)
	{
		printf("You didn't close your quotesions\n");
		return (ERROR);
	}
	return (i + 1);
}

int	other_len(char *chr)
{
	if (*chr == '(' || *chr == ')')
		return (1);
	else if (*chr == '<' && *(chr + 1) != '<')
		return (1);
	else if (*chr == '<' && *(chr + 1) == '<')
		return (2);
	else if (*chr == '>' && *(chr + 1) != '>')
		return (1);
	else if (*chr == '>' && *(chr + 1) == '>')
		return (2);
	else if (*chr == '|' && *(chr + 1) != '|')
		return (1);
	return (0);
}
