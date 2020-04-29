#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int counter = 0;
    map<char, int> mapA, mapB;
    
    // Cria um mapa para armazenar os caracteres em da string a
    for (int i = 0; i < a.length(); i++) mapA[a[i]]++;

    // Cria um mapa para armazenar os caracteres em da string b
    for (int i = 0; i < b.length(); i++) mapB[b[i]]++;

    // A diferenca absoluta entre os mapas (passando de 'a' a 'z')
    // e o resultado de caracteres que precisam ser removidos
    for (int i = 'a'; i <= 'z'; i++) 
        counter += abs(mapA[i] - mapB[i]);
    
    return counter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
