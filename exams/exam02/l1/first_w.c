#include <unistd.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

int	main(int argc, char **av)
{
	int	i;

	i = 0;
	if (argc != 2 || av[1][i] == '\0')
		return (write(1, "\n", 1), 0);
	while (av[1][i] == 32 || av[1][i] == '\t' || av[1][i] == '\0')
		i++;
	while (av[1][i] != 32 && av[1][i] != '\t' && av[1][i] != '\0')
	{
		write(1, &av[1][i], 1);
		// ft_putchar(av[1][i]);
		i++;
	}
	return (0);
}