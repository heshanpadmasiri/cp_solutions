#include <bits/stdc++.h>

#define SIZE 100001
#define INF 1000000000

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long valueBelow[SIZE] = {0};
bitset<SIZE> visited;
long treeTotal = 0;
long min = INF;

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

void printMap(unordered_map<int, vector<int>>& m){
    for(auto p: m){
        cout << "parent:" << p.first << endl;
        for(auto child: p.second){
            cout << "  " << child << endl;
        }
    }
}

long dfs(int current, vector<int>& data, unordered_map<int, vector<int>>& edges){
    long total = data[current-1];
    visited[current] = 1;
    bool isLeaf = true;
    if(valueBelow[current] != 0){
        return valueBelow[current];
    }
    for(int child: edges[current]){
        if(visited[child] == 1){
            continue;
        }     
        isLeaf = false;   
        if(valueBelow[child] == 0){            
            valueBelow[child] = dfs(child, data, edges);
        }
        cout << "current:" << current << " child:" << child << " -> " << valueBelow[child] <<endl;
        total += valueBelow[child];
    }
    if(isLeaf){
        cout << "leaf:" << current << ',' <<data[current-1]<< endl;
        return data[current-1];
    }
    valueBelow[current] = total;
    return total;
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    // cout << dfs(0, data, edges) << endl;
    unordered_map<int, vector<int>> edgemap;
    for(auto pair: edges){
        int a = pair[0];
        int b = pair[1];
        if(edgemap.find(a) == edgemap.end()){
            vector<int> tmp;
            tmp.push_back(b);
            edgemap[a] = tmp;
        } else {
            edgemap[a].push_back(b);
        }

        if(edgemap.find(b) == edgemap.end()){
            vector<int> tmp;
            tmp.push_back(a);
            edgemap[b] = tmp;
        } else {
            edgemap[b].push_back(a);
        }
    }
    for(auto each: data){
        treeTotal += each;
    }
    // printMap(edgemap);
    int n = data.size();
    dfs(1, data, edgemap);
    for(int i=0; i < n; i++){
        cout << i+1 << ':' << valueBelow[i+1] << endl;
    }
    long m = INF;
    for(int i=1; i <= n; i++){
        long other = treeTotal - valueBelow[i];
        m = std::min(m, abs(other-valueBelow[i]));
    }
    cout << m;
    return m;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
