#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
/*
Exemplo de como vai funcionar por iteracao-> 21537864
i = 7 -> 21537648 --- 8 subornou 2 (6, 4)
i = 6 -> 21536478 --- 7 subornou 2 (6, 4) 
i = 5 -> 21534678 --- 6 subornou 1 (4) 
i = 4 -> 21534678 --- 5 subornou 2 (4, 3)
i = 3 -> 21345678 --- posicao correta
i = 2 -> 21345678 --- posicao correta
i = 1 -> 12345678 --- 2 subornou 1 (1)

*/
void minimumBribes(vector<int> q) {
    int numBribes = 0;
    for (int i = q.size() - 1; i >= 0; i--) {
        // verifica se o elemento esta na posicao errada
        if (q[i] != (i + 1)) {
            // caso o anterior tenha ultrapassado 1 pessoa
            if (((i - 1) >= 0) && q[i - 1] == (i + 1)) {
                numBribes += 1;
                swap(q[i], q[i - 1]);
            // caso o anterior tenha ultrapassado 2 pessoas
            } else if (((i - 2) >= 0) && q[i - 2] == (i + 1)) {
                numBribes += 2;
                q[i - 2] = q[i - 1];
                q[i - 1] = q[i];
                q[i] = i + 1;
            // caso nao, teve mais pulos que o normal, caos!
            } else {
                cout << "Too chaotic" << endl;
                return;
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
