#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

string reArrange(string s)
{
    sort(s.begin(),s.end());
    return s;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> ans;
    map<string, int> myMap;
    for(int i=0; i < strs.size(); i++){
        string sortedS = strs[i];
        sort(sortedS.begin(),sortedS.end());
        if(myMap.find(sortedS)!=myMap.end()){
             vector<string> &v = ans[myMap[sortedS]];
             v.push_back(strs[i]);
        }else
        {
            myMap[sortedS] = ans.size();
            vector<string> tempAns = {strs[i]};
            ans.push_back(tempAns);
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> ans = groupAnagrams(input);

    for(int i=0; i<ans.size();i++){
        printf("[");
        for(int j = 0; j< ans[i].size(); j++){
            printf("%s,",ans[i][j].c_str());
        }
        printf("]\n");
    }

    return 0;
}