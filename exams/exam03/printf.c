
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return ;
	while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
}

int	print_str(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
		i++;
	ft_putstr(s);
	return (i);
}

void	putanbr(int num)
{
	long int	n;

	n = num;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		putanbr(n);
	}
	else if (n > 9)
	{
		putanbr(n / 10);
		putanbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int print_int(int num)
{
	int	n;
	int i;

	n = num;
	i = 1;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"), 11);
	else if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	putanbr(num);
	return (i);
}

int print_hex(int num, int base)
{
	int	i;

	i = 0;
	char *str_base = "0123456789abcdef";
	if (num > base)
		i += print_hex(num / base, base);
	i += write(1, &str_base[(num % base)], 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i += print_str("%");
			else if (*format == 's')
				i += print_str(va_arg(args, char *));
			else if (*format == 'd')
				i += print_int(va_arg(args, int));
			else if (*format == 'x')
				i += print_hex(va_arg(args, int), 16);
			else
				return (va_end(args), -1);
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}

#include <stdio.h>
int main(void)
{
	int x = 17343;
	int q = ft_printf("hex-->%x\n", x);
	int qq = printf("hex-->%x\n", x);
	printf("custom-->%d\n origin-->%d", q, qq);
	return (0);
}