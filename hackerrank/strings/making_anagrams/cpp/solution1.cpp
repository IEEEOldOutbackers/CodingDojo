#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<numeric>
#include <math.h>       /* log */

std::vector<int> primeSieve(int n)
{
    std::vector<bool> prime(n+1, true);
    for (unsigned int p = 2; p * p <= n; p++) 
    {       
        if (prime[p] == true) 
        {   
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }
    std::vector<int> primeList; 
    for (unsigned int i = 2; i <= n; i++)
    {
        if (prime[i])
            primeList.push_back(i);
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
    for(unsigned int i = 0; i < siege.size(); i++)
    {
        std::cout << siege[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> siege2(siege.begin(), siege.begin() + alphabet.length());
    // for(unsigned int i = 0; i < siege2.size(); i++)
    // {
    //     std::cout << siege2[i] << " ";
    // }
    // std::cout << std::endl;
     return  siege2;
}


 int integerValue(std::string str, std::vector<int> primeList)
 {
     int total = 1;
     for(int i = 0; i < str.length(); i++)
     {
         int val = *std::find(primeList.begin(), primeList.end(), str[i]);
         total *= val;
     }
     return total;
 }

 int makingAnagrams(std:: string s1, std::string s2, std::vector<int> siege)
{
    int size = 26; // 26 caracteres minusculos do alfabeto
    // Cria array de contadores para as ocorrências dos 26 caracteres do alfabeto
    // arr = [0 0 0 0 0 ....0], arr.size() = 26
    std::vector<unsigned int> counts1(size, 1);
    std::vector<unsigned int> counts2(size, 1);

    // Conta quantas vezes cada letra apareceu e guarda no array de contadores
    for(unsigned int i = 0; i < std::max(s1.length(), s2.length()); i++)
    {

        if( i < s1.length())
            counts1[counts1.size() - 1  - 'z' % s1[i]] *= siege[counts1.size() - 1  - 'z' % s1[i]];

        if( i < s2.length())
            counts2[counts1.size() - 1  - 'z' % s2[i]] *= siege[counts1.size() - 1  - 'z' % s2[i]];
    }
    for(unsigned int i = 0; i < counts1.size(); i++)
    {
        std::cout << counts1[i] << " ";
    }
    std::cout << std:: endl;
    for(unsigned int i = 0; i < counts2.size(); i++)
    {
        std::cout << counts2[i] << " ";
    }


    // Faz a diferença absolute entre os contadores e guarda em um array
    // ex :
    //      "abc"   ->  [1 1 1 0 0 0 ... 0]
    //      "aadcb" ->  [2 1 1 1 0 0 ... 0]
    //      diff    ->  [1 0 0 1 0 0 ... 0]
    std::vector<int> divs ;
    for(unsigned int i = 0; i < size; i++)
    {
        divs.push_back(log(std::max(counts1[i],counts2[i])/std::min(counts1[i],counts2[i]))/log(siege[i]));
    }
    std::cout << std:: endl;
    for(unsigned int i = 0; i < divs.size(); i++)
    {
        std::cout << divs[i] << " ";
    }
    return std::accumulate(divs.begin(), divs.end(), 0);
}

int makingAnagrams(std:: string s1, std::string s2)
{
    return makingAnagrams(s1, s2, charSieve());
}

int main(int argc, char *argv[])
{
    std::string str1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

    std::string str2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    int int_value = makingAnagrams(str1, str2);
    std::cout << int_value;
    return 0;
}



