#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (write(1, "\n", 1), 0);
	while (av[1][i] != '\0')
	{
		if ((av[1][i] == ' ' || av[1][i] == '\t') && (av[1][i - 1] == ' '
			|| av[1][i - 1] == '\t'))
			i++;
		else if ((av[1][i] == ' ' || av[1][i] == 't') && (av[1][i - 1] != ' '
			|| av[1][i - 1] != '\t'))
		{
			write(1, " 1 ", 3);
			i++;
		}
		else
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}
	return (write(1, "\n", 1), 0);
}