#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}



int main(void)
{
	unsigned char octet = 47;
	
	print_bits(octet);
	return (0);
}