#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)

{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	ex_atoi(char *str)
{
	int	i;
	int	acc;
	int	sign;

	i = 0;
	acc = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++ ;
	}
	else if (str[i] == '+')
		i++ ;
	while (str[i] >= '0' && str[i] <= '9')
	{
		acc = acc * 10 + (str[i] - 48);
		i++ ;
	}
	return (acc * sign);
}

int	main(int ac, char **av)
{
	int	res;
	int	v1;
	int	v2;

	if (ac != 4)
		return (write(1, "\n", 1), 0);
	v1 = ex_atoi(av[1]);
	v2 = ex_atoi(av[3]);
	if (av[2][0] == '+')
		res = (v1 + v2);
	else if (av[2][0] == '-')
		res = (v1 - v2);
	else if (av[2][0] == '*')
		res = (v1 * v2);
	else if (av[2][0] == '/')
		res = (v1 / v2);
	else if (av[2][0] == '%')
		res = (v1 % v2);
	ft_putnbr(res);
	return (0);
}
