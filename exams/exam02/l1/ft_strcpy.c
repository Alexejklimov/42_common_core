#include <unistd.h>

char	*ft_strcpy(char *s1, char *s2)
{
	while (*s2)
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
	return(s1);
}

#include <stdio.h>

int main(void)
{
	char *q = "qwerry huerry       ";
	char w[30];
	
	printf("-->%s\n", q);
	ft_strcpy(w, q);
	printf("%s", w);
	return (0);
}