#include "libft.h"

#include "libft_printer.h"

void	ft_print_arr(const int *arr, size_t size)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (i < size)
		ft_putnbr_fd(arr[i++], 1);
	ft_putchar_fd('\n', 1);
}