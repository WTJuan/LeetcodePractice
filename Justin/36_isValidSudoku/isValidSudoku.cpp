#include <stdio.h>
#include <vector>
#include <map>
#include <utility>

using namespace std;

bool isSameRegion(int lr,int lc,int cr,int cc)
{
    if(lr == cr || lc == cc) return true;
    if((lr/3 == cr/3) && (lc/3 == cc/3)) return true;
    return false;
}

bool isValidSudoku(vector<vector<char>>& board) 
{
    map<char,vector<pair<int,int>>> myMap;
    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board[row].size(); col++){
            char c = board[row][col];
            if(c == '.') continue;
            if(myMap.find(c) != myMap.end()){
                vector<pair<int, int>> data = myMap[c];
                for(int i = 0; i < data.size();i++){
                    if(isSameRegion(data[i].first, data[i].second, row, col)) return false;
                }
                myMap[c].push_back(pair<int,int>(row,col));
            }
            else{
                myMap[c] = {pair<int,int>(row,col)};
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    vector<char> row1 = {'8','3','.','.','7','.','.','.','.'};
    vector<char> row2 = {'6','.','.','1','9','5','.','.','.'};
    vector<char> row3 = {'.','9','8','.','.','.','.','6','.'};
    vector<char> row4 = {'8','.','.','.','6','.','.','.','3'};
    vector<char> row5 = {'4','.','.','8','.','3','.','.','1'};
    vector<char> row6 = {'7','.','.','.','2','.','.','.','6'};
    vector<char> row7 = {'.','6','.','.','.','.','2','8','.'};
    vector<char> row8 = {'.','.','.','4','1','9','.','.','5'};
    vector<char> row9 = {'.','.','.','.','8','.','.','7','9'};
    vector<vector<char>> input = {row1,row2,row3,row4,row5,row6,row7,row8,row9};

    bool ans = isValidSudoku(input);

    printf("%s\n",ans ? "true" : "false");
    return 0;
}