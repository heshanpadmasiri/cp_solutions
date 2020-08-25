#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
int I, J;

int decisions(pair<int,int> current, pair<int,int> last, int count,vector<string>& matrix){
    if(matrix[current.first][current.second] == '*'){
        return count;
    }

    cout << "start:" << current.first << ',' << current.second << ':' << last.first << ',' << last.second << endl;

    vector<pair<int,int>> possibleNext;
    if(current.first != 0 && matrix[current.first-1][current.second] != 'X'){
        pair<int,int> next(current.first-1, current.second);
        if(next != last){
            possibleNext.push_back(next);
        }
    }
    if(current.first != (I-1) && matrix[current.first+1][current.second] != 'X'){
        pair<int,int> next(current.first+1, current.second);
        if(next != last){
            possibleNext.push_back(next);
        }
    }
    if(current.second != 0 && matrix[current.first][current.second-1] != 'X'){
        pair<int,int> next(current.first, current.second-1);
        if(next != last){
            possibleNext.push_back(next);
        }
    }
    if(current.second != (J-1) && matrix[current.first][current.second+1] != 'X'){
        pair<int,int> next(current.first, current.second+1);
        if(next != last){
            possibleNext.push_back(next);
        }
    }

    cout << "possible next:" << endl;
    for(auto next: possibleNext){
        cout << next.first << ',' << next.second << endl;
    }

    if(possibleNext.size() > 1){
        count++;
    }
    for(auto next:possibleNext){
        // cout << next.first << ',' << next.second << ':' << last.first << ',' << last.second << ':'<< (next != last)<<endl;
        int tmp = decisions(next, current, count, matrix);
        if(tmp != -1){
            return tmp;
        }
    }
    return -1;
}

// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k) {
    pair<int,int> starting_point;
    for(int i=0; i< matrix.size(); i++){
        auto index = matrix[i].find('M');
        if(index != string::npos){
            starting_point.first = i;
            starting_point.second = index;
            break;
        }
    }
    int d = decisions(starting_point, make_pair(-1,-1),0,matrix);
    if(d == k){
        return "Impressed";
    } else {
        return "Oops!";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);
        I = n;
        J = m;

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

    fout.close();

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
