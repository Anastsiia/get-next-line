#include "get_next_line.h"

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin (char *s1, char const *s2)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc((sizeof(*str)) * (ft_strlen(s1) + 1 + ft_strlen(s2)));
	if (str == NULL)
		return (NULL);
	while (s1 && *s1 != '\0')
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		i++;
		s2++;
	}	
	str[i] = '\0';
	return (str);
}

char	*ft_strchr (const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return ((char *)str + i);
	else
		return (NULL);
}

char	*ft_strdup_new (const char *str, int flag)
{
	char	*str1;
	int		len;
	int		a;

	len = ft_strlen(str);
	a = 0;
	str1 = (char *)malloc(sizeof(char) * (len + flag));
	if (!str1)
		return (NULL);
	while (a < len)
	{
		str1[a] = str[a];
		a++;
	}
	if (flag == 2)
		str1[a++] = '\n';
	str1[a] = '\0';
	return (str1);
}
