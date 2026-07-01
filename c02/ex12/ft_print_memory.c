
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putaddr(unsigned long long addr)
{
    if (addr >= 16)
        ft_putaddr(addr / 16);
    ft_putchar("0123456789abcdef"[addr % 16]);
}

void ft_print_address(char *addr, unsigned int n)
{
    unsigned int i;

    i = 0;
    while(i < n - 1)
    {
    ft_putaddr(&addr[i]);
    i++;
    }
}

void *ft_print_memory(void *addr, unsigned int size)
{
    ft_print_address(addr, size);
    return (addr);
}

int main(void)
{
    char *str = "Hello, World!";
    ft_print_memory(str, 13);
    return (0);
}