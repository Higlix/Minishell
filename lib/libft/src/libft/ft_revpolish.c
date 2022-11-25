#include "../inc/libft.h"
#include <stdio.h>
#include <stdarg.h>

static void starting_do_op(char op, int n1, int n2, int *to_store)
{
	if (op == '+')
		(*to_store) += (n1 + n2);
	else if (op == '-')
		(*to_store) += (n1 - n2);
	else if (op == '/')
		(*to_store) += (n1 / n2);
	else if (op == '*')
		(*to_store) += (n1 * n2);
}

static void do_op(char op, int n1, int *to_store)
{
	if (op == '+')
		(*to_store) += (n1);
	else if (op == '-')
		(*to_store) -= (n1);
	else if (op == '/')
		(*to_store) /= (n1);
	else if (op == '*')
		(*to_store) *= (n1);
}

int	ft_revpolish(char *ops, ...)
{
	va_list nums;
	unsigned int count_ops;
	int final;
	int i;
	
	count_ops = ft_strlen(ops);
	i = 0;
	final = 0;
	if (count_ops == 0)
		return (-1);
	starting_do_op(ops[i], va_arg(nums, int), va_arg(nums, int), &final);
	i++;
	while (ops[i])
		do_op(ops[i++], va_arg(ops, int), &final);
	return (final);
}

int main(void)
{
	printf("%d = 5 + 5\n", ft_revpolish("+", 5, 5));
	printf("%d = 5 * 5\n", ft_revpolish("*", 5, 5));
	printf("%d = 5 - 5\n", ft_revpolish("-", 5, 5));
	printf("%d = 5 / 5\n", ft_revpolish("/", 5, 5));
	printf("%d = 5 - 5 + 6 * (4 * 4) / 2\n", ft_revpolish("**/-", 4, 4, 6, 2, 5, 5));
	printf("%d = 5 - 5 + 6 * (4 * 4) / 2\n", 5 - 5 + 6 * (4 * 4) / 2);
	 

}
