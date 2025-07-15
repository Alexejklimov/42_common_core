#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
		{
			ft_putchar(122 - (av[1][i] - 97));
		}
		if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			ft_putchar(90 - (av[1][i] - 65));
		}
		i++;
	}
	return (0);
}