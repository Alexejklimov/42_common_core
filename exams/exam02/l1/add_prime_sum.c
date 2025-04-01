#include <unistd.h>

int	ftatoi(char *num)
{
	int	res;

	res = 0;
	while (*num)
	{
		res = res *10 + *num++ -48;
	}
	return (res);
}

void	putanbr(int num)
{
	char	res;

	if (num >= 10)
		putanbr(num / 10);
	res = num % 10 + 48;
	write(1, &res, 1);
}

int	is_prime(int num)
{
	int	i;

	i = 2;
	if (num < 2)
		return (0);
	while (i < num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int num;
	int	res;

	if (ac != 2)
		return (putanbr(0), 0);
	num = ftatoi(av[1]);
	res = 0;
	while (num > 0)
	{
		if (is_prime(num))
			res += num;
		num --;
	}
	putanbr(res);
	write(1, "\n", 1);
	return (0);
}