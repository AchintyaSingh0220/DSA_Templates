#include <iostream>
#include <vector>
using namespace std;

vector<bool> seiveOfEratoSthenes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    // O(n log(log(n))) -> almost linear
    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }

    return isPrime;
}

int main()
{

    vector<bool> isPrime = seiveOfEratoSthenes(20);
    for (int i = 0; i <= 20; i++)
    {
        cout << isPrime[i] << " ";
    }

    return 0;
}