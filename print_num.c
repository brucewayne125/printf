void print_num(int n)
{
        char digit;

        if(n < 0)
        {
                write(1, "-", 1);
                n = -n;
        }
        if(n / 10)
                print_num(n / 10);

        digit = (n % 10) + '0';
        write(1, &digit, 1);
}
