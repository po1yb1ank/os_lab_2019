#include <stdlib.h>
#include <string.h>

static int	wordscnt(char const *s, char c, size_t ac)
{
	size_t	i;
	int		cnt;
	int		wf;

	i = 0;
	cnt = 0;
	wf = 0;
	while (i < ac)
	{
		if (s[i] != c && wf == 0)
		{
			wf = 1;
			cnt++;
		}
		else if (s[i] == c && wf == 1)
			wf = 0;
		i++;
	}
	return (cnt);
}

static char	**dwarray_clean(char **dwarray)
{
	while (*dwarray)
	{
		free(*dwarray);
		*dwarray = NULL;
		dwarray++;
	}
	free(dwarray);
	return (NULL);
}

static char	**dwarray(int n, char const *s, char c, size_t ac)
{
	size_t	cnt;
	size_t	i;
	char	**dwarray;
	char	**dwarraybegin;

	cnt = 0;
	i = 0;
	if (!(dwarray = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	dwarraybegin = dwarray;
	while (i <= ac)
	{
		if (s[i] != c && s[i])
			cnt++;
		else if ((s[i] == c || !(s[i])) && cnt)
		{
			if (!(*dwarray = (char *)malloc(sizeof(char) * (cnt + 1))))
				return (dwarray_clean(dwarray));
			bzero(*dwarray++, cnt + 1);
			cnt = 0;
		}
		i++;
	}
	*dwarray = NULL;
	return (dwarraybegin);
}

char		**strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**warray;
	int		now;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	k = 0;
	now = wordscnt(s, c, strlen(s));
	if (!(warray = dwarray(now, s, c, strlen(s))))
		return (NULL);
	while (s[++i] && warray[0] != NULL)
	{
		if (s[i] == c && warray[j][0] && j < (now - 1))
		{
			j++;
			k = 0;
		}
		else if (s[i] != c)
			warray[j][k++] = s[i];
	}
	return (warray);
}
