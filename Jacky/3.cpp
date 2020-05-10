// 解題想法:
// 依序 trace 過 string element，用 map 暫存出現過的 element 與對應的字串位置
// 如果發現 element 重複了，則目前累計的長度為最長的子字串長度，清除 map 重複的元素並調整子字串長度

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int currLongestLength = 0;
        map<char, int> foundElementPosList;
        for(int i = 0; i < s.size(); i++){
            auto foundElementPos = foundElementPosList.find(s[i]);
            
            if(foundElementPos != foundElementPosList.end()){
                ans = max(ans, currLongestLength);
                int repeatElePos = foundElementPos -> second;               
                for(auto iter=foundElementPosList.begin(); iter != foundElementPosList.end();){
                    if(iter -> second < repeatElePos){
                        iter = foundElementPosList.erase(iter);
                    }else {
                        iter -> second =  iter -> second - repeatElePos;
                        ++iter;
                    }
                }
                currLongestLength = currLongestLength - repeatElePos + 1;
                foundElementPosList[s[i]] = currLongestLength;
            }else {
                currLongestLength++;
                foundElementPosList[s[i]] = currLongestLength;
            }
        }
        ans = max(ans, currLongestLength);
        
        return ans;
    }
};