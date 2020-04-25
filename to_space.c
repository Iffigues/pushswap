int put_space(char *b) {
    while (*b) {
        if ((*b > '9' || *b < '0') && *b != ' ' ) {
            return (0);
        }
        b++;
    }
    return (1);
}