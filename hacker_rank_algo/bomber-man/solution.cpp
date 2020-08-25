#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vector<string> split_string(string);

void print_grid(int** grid,int tick, int c, int r){
    cout << tick << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // cout << grid[i][j];
            if (grid[i][j] == -1)
            {
                cout << '.';
            } else {
                cout << grid[i][j];
            }
            
        }        
        cout << endl;
    }    
    cout << "===========" << endl;
}

string hash_grid(int** grid, int c, int r, int tick){
    char hash[c*r];
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            
            if (grid[i][j] == -1)
            {
                hash[k] = '*';
            } else {
                hash[k] = (tick - grid[i][j]) + '0';
            }
            k++;
        }        
    }  
    return string(hash);
}

void next_tick(int** grid, int tick, int c, int r){
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] != -1 && grid[i][j] == tick-3)
            {                
                if (i != 0)
                {
                    grid[i-1][j] = -1;
                }
                if (i != r-1 && grid[i+1][j] != grid[i][j])
                {
                    grid[i+1][j] = -1;
                }
                if (j != 0)
                {
                    grid[i][j-1] = -1;
                }
                if (j != c-1 && grid[i][j+1] != grid[i][j])
                {
                    grid[i][j+1] = -1;
                }     
                grid[i][j] = -1;           
            }      
            else if(tick % 2 == 0 && grid[i][j] == -1){
                grid[i][j] = tick;
            }      
        }        
    }  
}

// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {
    int c = grid[0].size();
    int r = grid.size();
    int** solution = new int*[r];
    for(int i=0; i < r; i++){
        int* row = new int[c];
        solution[i] = row;
        for(int j=0; j < c; j++){
            if(grid[i][j] == '.'){
                row[j] = -1;
            } else {
                row[j] = 0;
            }
        }
    }
    map<string,int> hashmap;
    map<int,string> index_to_hash;
    for (int i = 1; i <= n; i++)
    {

        next_tick(solution,i, c, r);
        string hash = hash_grid(solution,c,r, i);

        if(hashmap.find(hash) != hashmap.end()){
            // hash hit
            
            int index = hashmap[hash];
            int remaining = (n+1) % (index+1);
            
            
            while (remaining > 0)
            {
                i++;
                next_tick(solution,i, c, r);
                remaining--;
            }            
            break;
        } else {
            hashmap[hash] = i;
            index_to_hash[i] = hash;
        }
    }
    vector<string> answer;
    for(int i=0; i < r; i++){
        string row = "";
        for(int j=0; j < c; j++){
            if(solution[i][j] == -1){
                row.push_back('.');
            } else {
                row.push_back('O');
            }
        }
        answer.push_back(row);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];
        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    // fout << "\n";

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
