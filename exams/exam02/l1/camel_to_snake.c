#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] >= 'A' && av[1][i] <= 'Z' && i == 0)
		{
			ft_putchar(av[1][i] + 32);
		}
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
		{
			write(1, "_", 1);
			ft_putchar(av[1][i] + 32);
		}
		else
			ft_putchar(av[1][i]);
		i++;
	}
	return (0);
}
