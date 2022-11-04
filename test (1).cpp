#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 9;

void print(vector<vector<int>> grid);
bool validRow(vector<vector<int>> grid,int row,int num);
bool validCol(vector<vector<int>> grid,int col,int num);
bool validBox(vector<vector<int>> grid,int row, int col , int num);
bool validPlace(vector<vector<int>> grid,int row, int col , int num);
bool empty(vector<vector<int>> grid, int &row, int &col);
bool complete(vector<vector<int>> grid);
bool solve(vector<vector<int>> &grid);

int main(){
    vector<vector<int>> grid;/*{
        {0, 4, 0, 0, 0, 0, 1, 7, 9},
        {0, 0, 2, 0, 0, 8, 0, 5, 4},
        {0, 0, 6, 0, 0, 5, 0, 0, 8},
        {0, 8, 0, 0, 7, 0, 9, 1, 0},
        {0, 5, 0, 0, 9, 0, 0, 3, 0},
        {0, 1, 9, 0, 6, 0, 0, 4, 0},
        {3, 0, 0, 4, 0, 0, 7, 0, 0},
        {5, 7, 0, 1, 0, 0, 2, 0, 0},
        {9, 2, 8, 0, 0, 0, 0, 6, 0}

    };*/
    vector<int> row;
    string line = "";
    
    for (int k =0;k<N;k++){
        getline(cin,line);
        row.clear();
        for (int j =0;j<line.length();j++){
            if (line[j]!=' '){
                row.push_back(int(line[j])-48);
            };
        }//for j
        grid.push_back(row);
    };//for k
   


    if (solve(grid)){
        print(grid);
    }
    else{
        cout<<"No Solution";
    }
};

bool solve(vector<vector<int>>& grid){
    int row,col;

    if (complete(grid)){
       // print(grid);
        return true;
    };
    empty(grid,row,col);
    for (int num = 1; num<=N;num++){
        if (validPlace(grid,row,col,num)){
            grid[row][col] = num;
            if (solve(grid)){
                return true;
            };
            grid[row][col]=0;
        };
    };
    return false;

};

void print(vector<vector<int>> grid){
    
    for (int k=0;k<9;k++){
        for (int j =0;j<9;j++){
            if (j==8){
                cout<<grid[k][j];
            }else{
                cout<<grid[k][j]<<' ';
            };
        };//for j
        cout<<endl;
    };//for k

    /*
    for (auto row : grid){
        for (auto element: row){
            cout<<element<<' ';
        };
        cout<<endl;
    }*/
};

bool validRow(vector<vector<int>> grid,int row,int num){
    for (int k = 0;k<N;k++){
        if (grid[row][k]==num){
            return false;
        }
    }
    return true;
};

bool validCol(vector<vector<int>> grid,int col,int num){
    for (int k = 0;k<N;k++){
        if (grid[k][col]==num){
            return false;
        }
    };
    return true;
};

bool validBox(vector<vector<int>> grid,int row, int col , int num){
    for (int k = 0;k<sqrt(N);k++){
        for (int j = 0;j<sqrt(N);j++){
            if (grid[row+k][col+j]==num){
                return false;
            }
        }//for j
    };//for k
    return true;
};

bool validPlace(vector<vector<int>> grid,int row, int col , int num){
   if (validRow(grid,row,num)==false || validCol(grid,col,num)==false || validBox(grid,row - row%3,col - col%3,num)==false){
    return false;
   }
   return true; 
};

bool empty(vector<vector<int>> grid, int &row, int &col){
    for (col = 0; col < N; col++){
        for (row = 0 ; row <N ; row++){
            if (grid[row][col] == 0)
            return true;
        };//for row
    };//for col
    return false;
};

bool complete(vector<vector<int>> grid){
    for (int col = 0; col < N; col++){
        for (int row = 0 ; row <N ; row++){
            if (grid[row][col] == 0)
            return false;
        };//for row
    };//for col
    return true;
}