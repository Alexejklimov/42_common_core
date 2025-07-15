#include <stdlib.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int	i;
	int	start;
	int	end;
	int point;

	if (argc != 2)
		return (write(1, "\n", 1), 0);
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	while (i >= 0)
	{
		while (argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
			i--;
		end = i;
		while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
			i--;
		start = i + 1;
		point = start;
		while (start <= end)
		{
			write(1, &argv[1][start], 1);
			start++;
		}
		if (point != 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
