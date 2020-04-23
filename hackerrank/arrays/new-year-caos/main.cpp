#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
/*
sendo i a posição e andando de i=0 até i=7, teriamos:

i=0, a expressão de "for loop"não é válida, portanto a primeira posição só será verificada na próxima iteração.
i=1, neste caso, o j assume o valor de 0, pois a expressão q[i]-2 é negativa.
com i =1, verificamos se o elemento na posição 0 subornou o elemento da posição 1.
O suborno só pode ter acontecido caso o elemento  da posição 1 seja menor que o elemento da posição 0.
i=2, a expressão de "for loop" não é válida, portanto a posição 2 só será validada pelas próximas iterações.
i=3, neste caso, o j assume o valor de 1 até 2.
com i=3, verificamos que o elemento nesta posição sofreu 1 suborno, pois o elemento anterior é maior que ele.
 
## Em resumo, o algoritmo produz os seguintes resultados:

**Fila**: [1, 2, 5, 3, 7, 8, 6, 4]
i=1, j=0, q[i]=2, q[j]=1 Bribe:No
i=3, j=1, q[i]=3, q[j]=2 Bribe:No
i=3, j=2, q[i]=3, q[j]=5 Bribe:1
i=6, j=4, q[i]=6, q[j]=7 Bribe:1
i=6, j=5, q[i]=6, q[j]=8 Bribe:1
i=7, j=2, q[i]=4, q[j]=5 Bribe:1
i=7, j=3, q[i]=4, q[j]=3 Bribe:No
i=7, j=4, q[i]=4, q[j]=7 Bribe:1
i=7, j=5, q[i]=4, q[j]=8 Bribe:1
i=7, j=6, q[i]=4, q[j]=6 Bribe:1
## Resultado
**numBribes**=7
*/

void minimumBribes(vector<int> q) {
    int numBribes = 0;
    for (int i = 0; i < q.size(); i++) {
        if (q[i] - (i + 1) > 2) {
            // verifica se existe um caso caotico (esta a mais de duas)
            // posicoes a frente (mais de dois subornos)
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++) {
            // O loop faz percorrer loop de um item que esteja na posicao
            // incorreta a 2 indices atras, ou zero (caso a operacao tenha um
            // valor negativo). Em outras palavras olhamos de q[i] - 1 ate i.
            if (q[j] > q[i]) {
                /*
                Aqui contamos quantas vezes q[i] um suborno, olhando quem está
                a frente da posicao original de q[i].
                */
                numBribes++;
            }
        }
    }
    cout << numBribes << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
