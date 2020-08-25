#include <bits/stdc++.h>

using namespace std;

int n,m;

typedef vector<int> vi;
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
      cout << i << ',' << j << endl;
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
          int biggestSetSize(){
            int biggest = 0;
            for (int i = 0; i < n*m; i++)
            {
                biggest = max(sizeOfSet(i),biggest);
            }
            
            return biggest;
        }
};


void print_matrix(vector<vector<int>>& matrix, UnionFind& data){
    int id=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(matrix[i][j] != 0){
                cout << setfill('0') << setw(2) <<data.findSet(id) << " ";
            } else {
                cout << ".. ";
            }
            id++;
        }
        cout << endl;
    }
    
}

// Complete the connectedCell function below.
int connectedCell(vector<vector<int>> matrix) {
    UnionFind data(n*m);
    int idMap[n][m];
    int id = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            idMap[i][j] = id;
            id++;
        }
    }
    int other_id;
    int this_id;
    print_matrix(matrix,data);
    cout << "=============" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {            
            if (matrix[i][j] != 0)
            {
                this_id = idMap[i][j];
                if(j != 0){
                    if(matrix[i][j-1] != 0){
                        other_id = idMap[i][j-1];
                        // cout << other_id << ":" << this_id<< endl;
                        data.unionSet(this_id,other_id);
                    }
                    if(i != 0){
                        if(matrix[i-1][j-1] != 0){
                            other_id = idMap[i-1][j-1];
                            data.unionSet(this_id,other_id);
                        }
                    }
                }
                if(i != 0){
                    if(matrix[i-1][j] != 0){
                        other_id = idMap[i-1][j];
                        data.unionSet(this_id, other_id);                        
                    }
                    if(j != m-1){
                            if(matrix[i-1][j+1] != 0){
                                other_id = idMap[i-1][j+1];
                                data.unionSet(this_id, other_id);
                            }
                            
                        }
                }
            }
        }        
    }
    print_matrix(matrix,data);
    
    return data.biggestSetSize();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
