#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

#define inf 100000

typedef pair<int,int> pii;

int shortest = inf;
vector<vector<pii>> shortestPaths;
int N;

vector<pair<int,int>> findNeighbours(pii point){
    vector<pair<int,int>> neighbours;
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

void backtrack(pii current, pii& end,vector<pii>& path, int length){
    if(length > shortest){
        return;
    }
    if(current == end){
        vector<pii> newPath(path);
        if(shortest > length){            
            shortest = length;
            shortestPaths.clear();
        }
        shortestPaths.push_back(newPath);
    }
    path.push_back(current);
    length++;
    for(auto neighbour: findNeighbours(current)){
        if(find(path.begin(), path.end(), neighbour) == path.end()){
            backtrack(neighbour, end,path, length);
        }
    }
    length--;
    path.pop_back();
}

string getMove(pair<int,int> child, pair<int,int> parent){
    if(parent == make_pair(-1,-1)){
        return "";
    }

    if(parent.first == child.first + 2){
        if(parent.second == child.second-1){
            return "UR";
        } else {
            return "UL";
        }
    } 
    if(parent.first == child.first){
        if(parent.second < child.second){
            return "R";
        } else {
            return "L";
        }
    }
    if(parent.second < child.second){
        return "LR";
    }
    return "LL";
}

// Complete the printShortestPath function below.
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.
    N = n;
    pii end = {i_end, j_end};
    vector<pii> path;
    backtrack(make_pair(i_start,j_start), end, path, 0);
    cout << shortest;
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
