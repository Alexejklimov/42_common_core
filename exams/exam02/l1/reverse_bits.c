#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	res = 0;
	int				i = 8;

	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

unsigned char	rev_bits(unsigned char	octet)
{
	int i;
	unsigned char	res;

	i = 8;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

int main(void)
{
	unsigned char bit = 0;
	unsigned char res = reverse_bits((unsigned char)5);
	int i = 8;

	while (i--)
	{
		bit = ((res >> i & 1) + 48);
		printf("%c", bit);
	return (0);
	}
}
