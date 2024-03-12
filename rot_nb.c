
static int get_pos(char c, char *str)
{
    int i;

    i = 0;
    while (str[i] != c || str[i])
        i++;
    return (i);
}

int rot_nb(char *str)
{
    char alph = "abcdefghijklmnopqrstuvwxyz";
    int i, j, k, l;
    int rot = 15;

    i = 0;
    while (str[i])
    {
        k = 0;
        j = get_pos(str[i], alph);
        while (k < rot)
        {
            if (j + 1 > ft_strlen(alph))
                j = 0;
            else
                j++;
            k++;
        }
        l = (int)alph[j];
        write(1, &l, 1);
    }
}