
int	ft_strlen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str[ctd] != '\0')
		ctd++;
	return (ctd);
}


char *ft_strcat(char *dest, char *src)
{
	int	ctd;
	char *originalDest;
	ctd = 0;
	dest += ft_strlen(dest);
	while (ctd < ft_strlen(src))
	{
		*dest = src[ctd];
		dest++;
		ctd++;
	}
}
