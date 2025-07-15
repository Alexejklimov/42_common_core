#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 3)
		return (write(1, '\n', 1), 0);
	i = 0;
	j = 0;
	while (av[2][i] != '\0')
	{
		if (av[1][j] == av[2][i])
			j++;
		i++;
	}
	if (av[1][j] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
	return (0);
}