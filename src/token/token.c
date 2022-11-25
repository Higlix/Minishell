#include "hedoshell.h"

#include "token.h"

static	t_token *tok_new_tok(char *tok, int flags);

t_list	*tok_create(char *tok, int flags)
{
	t_list *new;

	new = (t_list *) malloc(sizeof(t_list));
	new->content = (void *) tok_new_tok(tok, flags);
	new->next = NULL;
	return (new);
}

t_token	*tok_content(t_list *token)
{
	if (token == NULL)
		return (NULL);
	return (token->content);
}

void    tok_del(void  *content)
{
    t_token *token;

    token = (t_token *) content;
    free(token->tok);
    free(token);
}

static	t_token *tok_new_tok(char *tok, int flags)
{
	t_token *new;

	new = (t_token *) malloc(sizeof(t_token));
	new->tok = tok;
	new->flags = flags;
	return (new);
}