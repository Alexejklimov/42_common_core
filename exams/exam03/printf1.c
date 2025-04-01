#include <unistd.h>
#include <stdarg.h>

// int	ft_char(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// void	ft_str(char *s)
// {
// 	int i = 0;

// 	if (!s)
// 	{
// 		return ;
// 	}
// 	while (s[i] != '\0')
// 	{
// 		ft_char(s[i]);
// 		i++;
// 	}
// }

// void	putan(int num)
// {
// 	int	n;

// 	n = num;
// 	if (n < 0)
// 	{
// 		ft_char('-');
// 		n = -n;
// 		putan(n);
// 	}
// 	else if (n > 9)
// 	{
// 		putan(n / 10);
// 		putan(n % 10);
// 	}
// 	else
// 		ft_char(n + '0');
// }


// int	print_d(int num)
// {
// 	int n;
// 	int i;

// 	i = 1;
// 	n = num;
// 	if (n == -2147483648)
// 		return (ft_str("-2147483648"), 11);
// 	else if (n < 0)
// 	{
// 		n = -n;
// 		i++;
// 	}
// 	while (n > 9)
// 	{
// 		n = n / 10;
// 		i++;
// 	}
// 	putan(num);
// 	return (i);
// }

// int	print_s(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (ft_str("(null)"), 6);
// 	while (s[i] != '\0')
// 		i++;
// 	ft_str(s);
// 	return (i);
// }

// int print_x(int num, int base)
// {
// 	int i;
// 	char *str_b;

// 	str_b = "0123456789abcdef";
// 	i = 0;
// 	if (num > base)
// 		i += print_x((num / base), base);
// 	i += write(1, &str_b[(num % base)], 1);
// 	return (i);
// }

// int	ft_printf(const char *format, ...)
// {
// 	unsigned int 	i;
// 	va_list			args;

// 	i = 0;
// 	va_start(args, format);
// 	while (*format != '\0')
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == '%')
// 				i += ft_char('%');
// 			else if (*format == 's')
// 				i += print_s(va_arg(args, char *));
// 			else if (*format == 'd')
// 				i += print_d(va_arg(args, int));
// 			else if (*format == 'x')
// 				i += print_x(va_arg(args, int), 16);
// 			else
// 				return (va_end(args), -1);
// 		}
// 		else
// 			i += ft_char(*format);
// 		format++;
// 	}
// 	va_end(args);
// 	return (i);
// }
//////////////////////////////////////////////////////////////////////////
// #include <stdio.h>

// int	ft_char(char c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// void	str(char *s)
// {
// 	int i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		ft_char(s[i]);
// 		i++;
// 	}
// }

// void	putan(int num)
// {
// 	int n = num;

// 	if (n < 0)
// 	{
// 		ft_char('-');
// 		n = -n;
// 	}
// 	else if (n > 9)
// 	{
// 		putan(n / 10);
// 		putan(n % 10);
// 	}
// 	else
// 		ft_char(n + '0');
// }

// int	print_s(char *s)
// {
// 	int i = 0;

// 	if (!s)
// 		return(str("(null)"), 6);
// 	while (s[i] != '\0')
// 		i++;
// 	str(s);
// 	return (i);
// }

// int	print_d(int num)
// {
// 	int n = num;
// 	int i = 1;

// 	if (num == -2147483648)
// 		return (str("-2147483648"), 11);
// 	while (n > 9)
// 	{
// 		n = n / 10;
// 		i++;
// 	}
// 	putan(num);
// 	return (i);
// }

// int	print_x(int num, int base)
// {
// 	int i = 0;
// 	char *str_b = "0123456789abcdef";

// 	if (num > base)
// 		i += print_x((num / base), base);
// 	i += write(1, &str_b[(num % base)], 1);
// 	return (i);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int i = 0;
// 	va_list		args;

// 	va_start(args, format);
// 	while (*format != '\0')
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == '%')
// 				i += ft_char('%');
// 			else if (*format == 's')
// 				i += print_s(va_arg(args, char *));
// 			else if (*format == 'd')
// 				i += print_d(va_arg(args, int));
// 			else if (*format == 'x')
// 				i += print_x(va_arg(args, int), 16);
// 			else
// 				return (va_end(args), -1);
// 		#include <stdio.h>


int	ftchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	putstr(char *s)
{
	int i = 0;

	while (s[i])
		write(1, &s[i++], 1);
}
void	putan(int num)
{
	int n = num;
	
	if (n < 0)
	{
		n = -n; 
		putan(n);
	}
	else if (n > 9)
	{
		putan( n / 10);
		putan(n % 10);
	}
	else
		ftchar(n + '0');
}

int print_d(int num)
{
	int n = num;
	int i = 1;

	if (n == -2147483648)
		return (putstr("-2147483648"), 11);
	if (n < 0)
	{
		n = -n;
		i += ftchar('-');
	}
	while (n > 9)
	{
		n =  n / 10;
		i ++;
	}
	putan(num);
	return (i);
}

int print_s(char *s)
{
	int i = 0;

	while(s[i] != '\0')
		i++;
	putstr(s);
	return (i);
}

int print_x(int n, int base)
{
	int i = 0;
	char *str_b = "0123456789abcdef";

	if (n > base)
		i += print_x((n / base), base);
	i += write(1, &str_b[(n % base)], 1);
	return (i);
}

int ft_printf(const char *format, ...)
{
	va_list		args;
	int i = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i += ftchar(*format);
			else if (*format == 's')
				i += print_s(va_arg(args, char *));
			else if (*format == 'd')
				i += print_d(va_arg(args, int));
			else if (*format == 'x')
				i += print_x(va_arg(args, int), 16);
			else
				return (va_end(args), -1);
		}
		else
			i += ftchar(*format);
		format++;
	}
	va_end(args);
	return (i);
}


#include <stdio.h>

int main(void)
{
	int		x = 1000000000;
	char	*w = "zhopa";
	int		q = ft_printf("zhooooo%x   %s  %dzhooo\n\n", x, w, x);
	int		qq = printf("zhooooo%x   %s  %dzhooo\n\n", x, w, x);

	ft_printf("custom-->%d\norigin-->%d", q, qq);
	return (0);
}