// 解題想法：
// loop 三次對應數獨三種條件，橫/直/九宮格

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowLength = 9;
        // examine horizontal
        for(int i=0; i < rowLength; i++){
            map<char, bool> numMap;
            for(int j=0; j < rowLength; j++){
                char num = board[i][j];
                if(num != '.'){
                    if(numMap.find(num) != numMap.end()){
                        return false;
                    }else{
                        numMap[num] = true;
                    }
                }
            }
        }
        for(int i=0; i < rowLength; i++){
            map<char, bool> numMap;
            for(int j=0; j < rowLength; j++){
                char num = board[j][i];
                if(num != '.'){
                    if(numMap.find(num) != numMap.end()){
                        return false;
                    }else{
                        numMap[num] = true;
                    }
                }
            }
        }
        for(int k=0; k < 3; k++){
            for(int l=0; l < 3; l++){
                map<char, bool> numMap;
                for(int i=(k*3); i < (k*3+3); i++){
                    for(int j=(l*3); j < (l*3+3); j++){
                        char num = board[i][j];
                        if(num != '.'){
                            if(numMap.find(num) != numMap.end()){
                                return false;
                            }else{
                                numMap[num] = true;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};