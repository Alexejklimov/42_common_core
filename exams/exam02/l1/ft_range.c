#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i;
	int len;
	int *res;

	i = 0;
	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	while (i < len)
	{
		if (start <= end)
			res[i++] = start++;
		else
			res[i++] = start--;
	}
	return (res);
}

int *ft_rrange(int start, int end)
{
	int i;
	int len;
	int *res;
	int	sign;

	i = 0;
	sign = 1;
	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	res = (int *)malloc(sizeof(int) * len);
	if (!res)
		return (NULL);
	if (start < end)
		sign = -1;
	while (i < len)
	{
		res[i] = end;
		end = end + sign;
		i++;
	}
	return (res);
}

#include <stdio.h>
int	main(void)
{
	int s1 = 4;
	int e1 = 9;
	int s2 = -5;
	int e2 = 3;
	int s3 = 1;
	int e3 = 5;
	int i = 0;
	
	int *re1 = ft_range(s1, e1);
	int *rre1 = ft_rrange(s1, e1);
	int *re2 = ft_range(s2, e2);
	int *rre2 = ft_rrange(s2, e2);
	int *re3 = ft_range(s3, e3);
	int *rre3 = ft_rrange(s3, e3);
	while (i <= abs(e1 - s1))
	{
		printf("%d, ", re1[i]);
		i++;
	}
	printf("%s", "\n");
	i = 0;
	while (i <= abs(e1 - s1))
	{
		printf("%d, ", rre1[i]);
		i++;
	}
	printf("%s", "\n");
///////////////////////////////////////
	i = 0;
	while (i <= abs(e2 - s2))
	{
		printf("%d, ", re2[i]);
		i++;
	}
	printf("%s", "\n");
	i = 0;
	while (i <= abs(e2 - s2))
	{
		printf("%d, ", rre2[i]);
		i++;
	}
	printf("%s", "\n");
	//////////////////////////////////
	i = 0;
	while (i <= abs(e3 - s3))
	{
		printf("%d, ", re3[i]);
		i++;
	}
	printf("%s", "\n");
	i = 0;
	while (i <= abs(e3 - s3))
	{
		printf("%d, ", rre3[i]);
		i++;
	}
	printf("%s", "\n");
	printf("--> %ls", re1);
	return (0);
}