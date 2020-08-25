#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
typedef pair<int,int> pii;
#define N 10001
long currentDiameter = -1;

pii getKey(int v1, int v2){
    pii key = (v1 > v2) ? make_pair(v1,v2) : make_pair(v2, v1);
    return key;
}
/*
 * Complete the jeanisRoute function below.
 */

void findDiamter(int current, bitset<N>& mst, bitset<N>& visited,map<int,vector<int>>neighbours,map<pii,int>& edges,long cost,int parent){
    visited[current] = 0;
    auto children = neighbours[current];
    for(auto each : children){
        if(each != parent && mst[each]){
            pii key = getKey(current, each);
            findDiamter(each, mst, visited,neighbours, edges, cost+edges[key], current);
        }
    }
    cout << currentDiameter << endl;
    if(cost > currentDiameter){
        currentDiameter = cost; 
    }
    
}
long jeanisRoute(int n,const vector<int> k, vector<vector<int>> roads) {
    /*
     * Write your code here.
     */
    vector<bitset<N>> neighbours(n+1);
    map<pii, int> edgeCost;
    set<int> citiesToVisit(k.begin(), k.end());
    map<int, vector<int>> adj;
    auto start = k[0];
    for(auto each: roads){
        int v1 = each[0];
        int v2 = each[1];
        int cost = each[2];
        auto key = getKey(v1,v2);
        edgeCost[key] = cost;
        if(adj.find(v1) == adj.end()){
            vector<int> tmp;
            tmp.push_back(v2);
            adj[v1] = tmp;
        } else {
            adj[v1].push_back(v2);
        }
        if(adj.find(v2) == adj.end()){
            vector<int> tmp;
            tmp.push_back(v1);
            adj[v2] = tmp;
        } else {
            adj[v2].push_back(v1);
        }

        neighbours[v1][v2] = 1;
        neighbours[v2][v1] = 1;
    }

    queue<int> leafs;
    for(int i = 1; i <= n+1; i++){
        if(citiesToVisit.find(i) == citiesToVisit.end() && neighbours[i].count() == 1){
            leafs.push(i);
        }
    }

    bitset<N> mst;

    for(int i = 1; i <= n; i++){
        mst[i] = 1;

    }
    mst[0] = 0;
    while(!leafs.empty()){
        int node = leafs.front();
        mst[node] = 0;
        leafs.pop();
        int parent = neighbours[node]._Find_first();
        neighbours[parent][node] = 0;
        if(neighbours[parent].count() == 1 && citiesToVisit.find(parent) == citiesToVisit.end()){
            leafs.push(parent);
        }
    }
    queue<int> toVisit;
    toVisit.push(start);
    int current;
    bitset<N> notInQueue(mst);
    notInQueue[start] = 0;

    while(!toVisit.empty()){
        current = toVisit.front();
        toVisit.pop();
        for(auto each : adj[current]){
            if(mst[each] && notInQueue[each]){
                toVisit.push(each);
                notInQueue[each] = 0;
            }
        }
    }
    bitset<N> tmp(mst);
    findDiamter(current, mst,tmp ,adj, edgeCost, 0, -1);
    long total = 0;
    for(auto edge: edgeCost){
        auto key = edge.first;
        if(mst[key.first] && mst[key.second]){
            total += edgeCost[key];
        }
    }
    cout << "*" << endl;
    cout << total << endl;
    cout << currentDiameter << endl;
    cout << (2*total) - currentDiameter;

    return (2*total) - currentDiameter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string city_temp_temp;
    getline(cin, city_temp_temp);

    vector<string> city_temp = split_string(city_temp_temp);

    vector<int> city(k);

    for (int city_itr = 0; city_itr < k; city_itr++) {
        int city_item = stoi(city_temp[city_itr]);

        city[city_itr] = city_item;
    }
    vector<vector<int>> roads(n-1);
    for (int roads_row_itr = 0; roads_row_itr < n-1; roads_row_itr++) {
        roads[roads_row_itr].resize(3);

        for (int roads_column_itr = 0; roads_column_itr < 3; roads_column_itr++) {
            cin >> roads[roads_row_itr][roads_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = jeanisRoute(n,city, roads);

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

