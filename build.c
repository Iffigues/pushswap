int ft_atoi(char *str) {
	int a;
	int s;

	a = 0;
	s = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str && (*str == '+' || *str == '-'))
		s = ',' - *str++;
	while (*str)
		a = a * 10 + *str++ - '0';
	return (a * s);
}
