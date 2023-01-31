long int fibnen[81];

long int fibonacci(int x)
{
    if (x == 1 || x == 2)
        return 1;
    if (fibnen[x] != 0)
        return fibnen[x];
    fibnen[x] = fibonacci(x-1) + fibonacci(x-2);
    return fibnen[x];
}