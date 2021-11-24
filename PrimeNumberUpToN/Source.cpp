#include <iostream>

using namespace std;

//method 1
void SieveOfEratosthenes(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool* prime = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
        prime[i] = true;

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    for (int p = 2; p < n; p++)
    {
        if (prime[p])
            cout << p << " ";
    }
}

//method 2
bool isPrime(int i) //O(n^0.5)
{
    for (int k = 2; k * k <= i; k++)
    {
        if (i % k == 0)
            return false;
    }
    return true;
}

int countPrimes(int n) //O(n^1.5)
{
    /*
    n = 12         n = 81
    2x6            3x27
    3x4            9x9
    4x3            27x3
    6x2

    n = 36         n = 60
    2x18           2x30
    3x12           3x20
    4x9            4x15
    6x6            5x12
    9x4            6x10
    12x3
    18x2
    */

    int counter = 0;
    for (int i = 2; i < n; i++) //O(n)
    {
        if (isPrime(i))//O(n^0.5)
        {
            cout << i << " ";
            counter++;
        }

    }

    return counter;

}

int main()
{
    int n = 134;
    cout << "Following are the prime numbers smaller "
        << "than " << n << endl;
    cout << "SieveOfEratosthenes method: " << endl;
    SieveOfEratosthenes(n);

    cout << endl;
    cout << "Method2: " << endl;
    countPrimes(n);

    return 0;
}