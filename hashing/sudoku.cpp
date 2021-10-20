//32.7 problem
#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define mii map<int, int>
#define pii pair<int, int>
#define vii vector<pii> 

void helper(int r, int c, vector<vector<char>> &s, map<pii, map<int, int>> &mp, 
vector<map<int, int>> &row, vector<map<int, int>> &col){
    if(r==9){
        for(auto it : s){
            for(auto i : it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    if(c==9){
        helper(r+1,0,s,mp,row,col);
        return;
    }
    if(s[r][c]!='.'){
        helper(r, c+1,s,mp,row,col);
        return;
    }

    for(int i=1;i<=9;i++){
        int rl=r/3, cl=c/3;
        if(!mp[{rl,cl}][i] && !row[r][i] && !col[c][i]){
            mp[{rl,cl}][i]=1;
            row[r][i]=1;
            col[c][i]=1;
            s[r][c]=i+'0';
            helper(r, c+1, s, mp, row, col);
            mp[{rl,cl}][i]=0;
            row[r][i]=0;
            col[c][i]=0;
            s[r][c]='.';
        }
    }


}

void solveSudoku(vector<vector<char>> &s){

    //map for 3X3 boxes, pii- becoz identifier for boxes would be a pair eg-(0,0) i.e 1st block,
    //& its mapped to a map<int, int> which will hold pair- (number, 0 or 1) 0 if doesnt exists, else 1
    map<pii, map<int, int>> mp;
    // row[i][0-9 anynumber] will tell if that no exists in the row
    vector<map<int, int>> row(9);
    //similarly for col
    vector<map<int, int>> col(9);
    rep(i,0,9){
        rep(j,0,9){
            if(s[i][j]!='.'){
                //in the box- (i/3,j/3), a[i][j] which is a no b/w 0-9 exists . So set it to 1
                mp[{i/3,j/3}][s[i][j]-'0']=1;
                row[i][s[i][j]-'0']=1;
                col[j][s[i][j]-'0']=1;
            }
        }
    }
    helper(0,0,s,mp,row,col);

}

int main(){
    vector<vector<char>> sudoku={
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(sudoku);

    
    return 0;
}