// 解題想法：
// 用 map 計算 string 中的 element 出現次數，接著把 map 中的 element 轉成特定格式的 string
// 用此 string 去比對是否有重複出現過的字並放在同一組

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        map<string, int> anagrams;
        int emptyPos = -1;
        for(int i=0; i < strs.size(); i++){
            string str = strs[i];
            
            string charNumString = "";
            vector<int> charList (26, 0);
            for(int j=0; j < str.size(); j++){
                charList[str[j] - 'a'] ++;
            }
            for(int k=0; k<26; k++){
                if(charList[k] > 0){
                    charNumString += ( to_string(k) + ":" +  to_string(charList[k]) + "/");
                }
            }
            
            auto repeatAnagram = anagrams.find(charNumString);
            
            if(repeatAnagram == anagrams.end()){
                anagrams[charNumString] = ans.size();
                // cout << charNumString << ans.size() << endl;
                vector<string> s;
                s.push_back(str);
                ans.push_back(s);
            }else{
                cout << repeatAnagram -> first << ":" << repeatAnagram -> second << endl;
                ans[repeatAnagram -> second].push_back(str);
            }
        }
        
        return ans;
    }
};