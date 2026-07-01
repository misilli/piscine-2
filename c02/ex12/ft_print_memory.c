
vft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_print_address(char *addr, unsigned int n)
{
    int i;

    i = 0;
    while(i < n - 1)
    {
    ft_putchar(&addr[i]);
    i++;
    }
}


void *ft_print_memory(void *addr, unsigned int size)
{
    ft_print_address(addr);

























    unsigned int i;
    unsigned int j;
    unsigned char *ptr;

    ptr = (unsigned char *)addr;
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < 16 && i + j < size)
        {
            if (ptr[i + j] < 16)
                write(1, "0", 1);
            ft_putchar("0123456789abcdef"[ptr[i + j] / 16]);
            ft_putchar("0123456789abcdef"[ptr[i + j] % 16]);
            if (j % 2 == 1)
                write(1, " ", 1);
            j++;
        }
        while (j < 16)
        {
            write(1, "  ", 2);
            if (j % 2 == 1)
                write(1, " ", 1);
            j++;
        }
        j = 0;
        while (j < 16 && i + j < size)
        {
            if (ptr[i + j] >= ' ' && ptr[i + j] <= '~')
                ft_putchar(ptr[i + j]);
            else
                ft_putchar('.');
            j++;
        }
        write(1, "\n", 1);
        i += 16;
    }
}