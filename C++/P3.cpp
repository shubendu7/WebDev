#include <iostream>
class PrimeFiboRange
{
    int isPrime(int);

public:
    void getRange();
    void fibonacci(int, int);
    void fibonacciprime(int, int);
};
void PrimeFiboRange::getRange()
{
    int m, n, i;
    std::cout << "Enter the lower limit of the range: ";
    std::cin >> m;
    std::cout << "Enter the upper limit of the range: ";
    std::cin >> n;
    for (i = m; i <= n; i++)
    {
        if (isPrime(i))
            std::cout << i << "   ";
    }
    std::cout << "\nFibonacci numbers in this range: ";
    fibonacci(m, n);
    std::cout << "\nFibonacci numbers which are prime in this range: ";
    fibonacciprime(m, n);
}
void PrimeFiboRange::fibonacciprime(int m, int n)
{
    int a = 0, b = 1, c;
    while (a <= n)
    {
        if (a >= m && isPrime(a))
            std::cout << a << "  ";
        c = a + b;
        a = b;
        b = c;
    }
}
void PrimeFiboRange::fibonacci(int m, int n)
{
    int a = 0, b = 1, c;
    while (a <= n)
    {
        if (a >= m)
            std::cout << a << "  ";
        c = a + b;
        a = b;
        b = c;
    }
}
int PrimeFiboRange::isPrime(int i)
{
    int j;
    for (j = 2; j <= i / j; j++)
    {
        if (i % j == 0)
            break;
    }
    if (j > i / j)
        return 1;
    return 0;
}
int main()
{
    PrimeFiboRange p1;
    p1.getRange();
    return 0;
}