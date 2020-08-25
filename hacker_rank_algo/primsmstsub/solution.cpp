#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
#define N 3001

typedef pair<int,int> pii;

vector<string> split_string(string);

pii get_key(int v1, int v2){
    pii key = (v1 > v2) ? make_pair(v1, v2) : make_pair(v2, v1);
    return key;
}

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start) {
    int C[N];
    fill_n(C, N, INF);
    int E[N];
    fill_n(E, N, -1);
    map<int, vector<int>> neighbours;
    map<pii, int> edgeCost;
    for(auto each: edges){
        int v1 = each[0];
        int v2 = each[1];
        if(v1 == v2){
            continue;
        }
        int c = each[2];
        if(neighbours.find(v1) == neighbours.end()){
            vector<int> tmp;
            tmp.push_back(v2);
            neighbours[v1] = tmp;
        } else {
            neighbours[v1].push_back(v2);
        }
        if(neighbours.find(v2) == neighbours.end()){
            vector<int> tmp;
            tmp.push_back(v1);
            neighbours[v2] = tmp;
        } else {
            neighbours[v2].push_back(v1);
        }
        auto key = get_key(v1, v2);
        if(edgeCost.find(key) == edgeCost.end()){
            edgeCost[key] = c;
        } else {
            edgeCost[key] = min(edgeCost[key], c);
        }
    }
    for(auto neighbour: neighbours[start]){
        auto key = get_key(start, neighbour);
        C[neighbour] = edgeCost[key];
        E[neighbour] = start;
    }
    for(auto neighbour: neighbours[3]){
        cout << neighbour;
    }
    auto cmp = [&C](const int left, const int right){return C[left] > C[right];};
    deque<int> Q;
    for(int i = 1; i <= n; i++){
        if(i != start){
            Q.push_back(i);
        }
    };
    make_heap(Q.begin(), Q.end(), cmp);
    int total = 0;
    bitset<N> F;
    F[start] = 1;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop_front();
        F[v] = 1;
        if(v == 3 || v == 2 || v == 4){
            cout << v;
            cout << "--" << F[3] << " " << F[2] << " " << F[4] <<  endl;
        }
        if(E[v] != -1){
            total += C[v];
        } else {
            cout << "-sdjfaj" << endl;
            for(auto neighbour: neighbours[v]){
                if(F[neighbour]){
                    cout << "**" << endl;
                }
            }
        }
        for(auto neighbour: neighbours[v]){
            if(neighbour == 3){
                cout << "++" << F[3] << " " << F[2] << " " << F[4] <<  endl;
            }
            if(!F[neighbour]){
                auto key = get_key(v, neighbour);
                auto new_cost = edgeCost[key];
                if(new_cost < C[neighbour]){
                    C[neighbour] = new_cost;
                    E[neighbour] = v;
                }
            }
        }

        make_heap(Q.begin(), Q.end(), cmp);
    }
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

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

