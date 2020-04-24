#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<numeric>


int makingAnagrams(std:: string s1, std::string s2)
{
    int size = 26; // 26 caracteres minusculos do alfabeto
    // Cria array de contadores para as ocorrências dos 26 caracteres do alfabeto
    // arr = [0 0 0 0 0 ....0], arr.size() = 26
    std::vector<int> counts1(size, 0);
    std::vector<int> counts2(size, 0);

    // Conta quantas vezes cada letra apareceu e guarda no array de contadores
    for(unsigned int i = 0; i < std::max(s1.length(), s2.length()); i++)
    {
        if( i < s1.length())
            counts1[counts1.size() - 1  - 'z' % s1[i]]++;
        if( i < s2.length())
            counts2[counts1.size() - 1  - 'z' % s2[i]]++;
    }

    // Faz a diferença absolute entre os contadores e guarda em um array
    // ex :
    //      "abc"   ->  [1 1 1 0 0 0 ... 0]
    //      "aadcb" ->  [2 1 1 1 0 0 ... 0]
    //      diff    ->  [1 0 0 1 0 0 ... 0]
    std::vector<int> diffs ;
    for(unsigned int i = 0; i < size; i++)
    {
        diffs.push_back(abs(counts1[i] - counts2[i]));
    }
    return std::accumulate(diffs.begin(), diffs.end(), 0);
}

int main()
{
    std::cout  << makingAnagrams("aabc", "cabz");
    return 0;
}
