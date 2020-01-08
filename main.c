int ft_strlen(char *c) {
	int a;

	a = 0;
	while (*c++)
		a++;
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

int beint(char  *y) {
	if (ft_strlen(y) > 10)
		return (0);
	if (ft_strlen(y) == 10) {
		if (!ft_compare(y, "2147483647")) {
			return (0);
		}
	}
	return (1);
} 

int only_digit(char *b) {
	while (*b) {
		if ((*b > '9' || *b++ < '0')) {
			return (0);
		}
	}
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

int main (int argc, char **argv) {
	printf("%d",verif_param(argc, argv));
}
