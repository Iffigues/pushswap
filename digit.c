int ft_strlen(char *c) {
	int a;

	a = 0;
	while (*c++) {
		a++;
	}
	return(a);
}

int ft_compare(char *b, char *c) {
	while (*b) {
		if (*b < *c)
			return (1);
		if (*b++ > *c++)
			return (0);
	}
	return (1);
}

int beint(char  *b) {
	int a;

	a = 1;
	 while (*b && ((*b >= 9 && *b <= 13) || *b == 32))
                b++;
	if ((*b && *b == '+') || (*b && *b == '-'))
		if (*b++ == '-')
			a = 0;
	if (!*b)
                return (0);
	while (*b && *b == '0')
		b++;
	if (ft_strlen(b) > 10)
                return (0);
	if (ft_strlen(b) == 10)
		if ((a && !ft_compare(b, "2147483647")) || (!a && ft_compare(b, "2147483648")))
			return (0);
	return (1);
}

int only_digit(char *b) {
	while ((*b >= 9 && *b <= 13) || *b == 32)
		b++;
	if ((*b && *b == '+') || (*b && *b == '-'))
		b++;
	if (!*b)
		return (0);
	while (*b)
		if ((*b > '9' || *b++ < '0'))
			return (0);
	return (1);
}

int verif_param(int a, char **b) {
	if (a-- == 1)
		return (0);
	while (b[a]) {
		if (!only_digit(b[a]) || !beint(b[a])) {
			return (0);
		}
		a++;
	}
	return (1);
}
