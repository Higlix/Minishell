#include "libft.h"
#include "libft_printer.h"

void	ft_print(const char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}