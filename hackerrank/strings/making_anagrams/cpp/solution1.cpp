#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> primeSieve(int n)
{
    std::vector<bool> prime(n+1, true);
    for (int p = 2; p * p <= n; p++) 
    {       
        if (prime[p] == true) 
        {   
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }
    std::vector<int> primeList; 
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            primeList.push_back(p);
    }
    return primeList; 
 }

std::vector<int> charSieve()
{
     std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
     std::vector<int> siege = primeSieve(alphabet.size());
     int k = 2;
     while(siege.size() < alphabet.length())
     {
         siege = primeSieve(k * alphabet.size());
         k *= 2;
     }
     return siege;
}


 int integerValue(std::string str, std::vector<int> primeList)
 {
     int total = 1;
     for(int i = 0; i < str.length(); i++)
     {
         total *= *std::find(primeList.begin(), primeList.end(), str[i]);
     }
     return total;
 }

int main(int argc, char *argv[])
{
    std::vector<int> sieve = charSieve();

    std::string str = "abc";
    int int_value = integerValue(str, sieve);
    std::cout << int_value;
    return 0;
}



