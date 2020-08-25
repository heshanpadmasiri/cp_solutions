
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define INF 1000000000
#define START 1
#define N 50001

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

pii getKey(int v1, int v2){
    pii key = (v1 > v2)? make_pair(v1,v2) : make_pair(v2,v1);
    return key;
}
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
/*
 * Complete the 'getCost' function below.
 *
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    // Print your answer within the function and return nothing
    auto hash_fn = [](const pii& p){return p.first * N + p.second;};
    unordered_map<pii, int,decltype(hash_fn)> edgeWeight(N,hash_fn);
    vector<vector<int>> neighbours(g_nodes+2, vector<int>());
    for(int i = 0; i < g_from.size(); i++){
        int v1 = g_from[i];
        int v2 = g_to[i];
        int cost = g_weight[i];
        auto key = getKey(v1, v2);
        edgeWeight[key] = cost;
        neighbours[v1].push_back(v2);
        neighbours[v2].push_back(v1);
    }
    vector<int> C(g_nodes+2,INF);
    C[START] = 0;
    vector<int> P(g_nodes+2,-1);
    auto cmp = [&C](const int left, const int right) {return C[left] > C[right];};
    priority_queue<int, deque<int>, decltype(cmp)> Q(cmp);
    bitset<N> visited;
    Q.push(START);
    int current = START;
    int current_cost = 0;
    while(!Q.empty()){
        current = Q.top();
        current_cost = C[current];
        if(current_cost == INF){
            break;
        }
        if(visited[current]){
            continue;
        }
        Q.pop();
        for(auto neighbour: neighbours[current]){
           if(visited[neighbour]){
               continue;
           }
           auto key = getKey(current, neighbour);
           int edge_cost = edgeWeight[key] - current_cost;
           int cost = (edge_cost > 0) ? edge_cost + current_cost : current_cost;
           if(cost < C[neighbour]){
               C[neighbour] = cost;
               P[neighbour] = current;
               Q.push(neighbour);
           }
        }
        if(current == g_nodes){
            break;
        }
        visited[current] = 1;
    }
    if(C[g_nodes] != INF){
        cout << C[g_nodes] << endl;
    } else {
        cout << "NO PATH EXISTS" << endl;
    }
}

int main()
{
    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    getCost(g_nodes, g_from, g_to, g_weight);

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
