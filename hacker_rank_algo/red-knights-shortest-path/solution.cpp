#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int,int> pii;

int N;

vector<string> split_string(string);

int getMove(pair<int,int> child, pair<int,int> parent){

    if(parent.first == child.first + 2){
        if(parent.second == child.second-1){
            return 1;
        } else {
            return 0;
        }
    } 
    if(parent.first == child.first){
        if(parent.second < child.second){
            return 2;
        } else {
            return 5;
        }
    }
    if(parent.second < child.second){
        return 3;
    }
    return 4;
}

vector<pii> findNeighbours(pii point){
    vector<pii> neighbours;
    if(point.first > 1){
        if(point.second != 0){
            neighbours.push_back(make_pair(point.first-2,point.second-1));
        }
        if(point.second != N-1){
            neighbours.push_back(make_pair(point.first-2,point.second+1));
        }
    }
    
    if(point.second < N-2){
        neighbours.push_back(make_pair(point.first,point.second+2));
    }
    if(point.first < N-2){
        if(point.second != N-1){
            neighbours.push_back(make_pair(point.first+2,point.second+1));
        }
        if(point.second != 0){
            neighbours.push_back(make_pair(point.first+2,point.second-1));
        }        
    }
    if(point.second > 1){
        neighbours.push_back(make_pair(point.first,point.second-2));
    }
    
    return neighbours;
}


// Complete the printShortestPath function below.
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.
    N = n;
    map<pii, int> cost;
    map<pii, vector<pii>> parents;
    deque<pii> nodes_to_visit;
    set<pii> visited;
    set<pii> inQueue;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pii point = {i,j};
            vector<pii> p;
            parents[point] = p;
            if(i == i_end && j == j_end){
                cost[point] = 0;
                nodes_to_visit.push_back(point);
                inQueue.insert(point);
            } else {
                cost[point] = INF;
                
            }
        }        
    }
    auto cmp = [&cost](pii left, pii righ){return cost[left] > cost[righ];};    
    bool update = false;

    while (!nodes_to_visit.empty())
    {
        auto current = nodes_to_visit.front();
        if(cost[current] == INF){
            break;
        }
        nodes_to_visit.pop_front();
        // cout << nodes_to_visit.size() << endl;
        int newCost = cost[current] + 1;
        for(auto neighbour: findNeighbours(current)){
            if(visited.find(neighbour) == visited.end()){
                if(inQueue.find(neighbour) == inQueue.end()){
                    inQueue.insert(neighbour);
                    nodes_to_visit.push_back(neighbour);
                }
                if(cost[neighbour] > newCost){
                    parents[neighbour].clear();
                    cost[neighbour] = newCost;
                    update = true;
                    parents[neighbour].push_back(current);
                } else if(cost[neighbour] == newCost){
                    parents[neighbour].push_back(current);
                }
            }
        }
        visited.insert(current);
        if(current.first == i_start && current.second == j_start){
            break;            
        }
        if(update){
            make_heap(nodes_to_visit.begin(), nodes_to_visit.end(), cmp);
            update = false;
        }

    }

    auto current = make_pair(i_start, j_start);
    if(parents[current].size() == 0){
        cout << "Impossible" << endl;
        return;
    }
    auto end = make_pair(i_end, j_end);
    const string idToMove[] = {"UL", "UR", "R", "LR", "LL", "L"};
    vector<string> moves;
    while(current != end){
        int bestMove = INF;
        pii n;
        for(auto next: parents[current]){
            int move = getMove(next, current);
            if(move < bestMove){
                bestMove = move;
                n = next;
            }
        }
        moves.push_back(idToMove[bestMove]);
        current = n;
    }
    cout << moves.size() << endl;
    for(auto move: moves){
        cout << move << " ";
    }
    cout <<endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string i_startJ_start_temp;
    getline(cin, i_startJ_start_temp);

    vector<string> i_startJ_start = split_string(i_startJ_start_temp);

    int i_start = stoi(i_startJ_start[0]);

    int j_start = stoi(i_startJ_start[1]);

    int i_end = stoi(i_startJ_start[2]);

    int j_end = stoi(i_startJ_start[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

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
