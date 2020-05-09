#include <string>
#include <stdio.h>
#include <map>

using namespace std;
int lengthOfLongestSubstring(string s)
{
    map<char,int> myMap;
    int l = 0;
    int length = s.length();
    int ans = 0;
    for(int i = 0; i < length; i++){
        char c = s[i];
        if(myMap.find(c) != myMap.end() && l <= myMap[c]){
            l = myMap[c] + 1;
            myMap[c] = i;
        }else{
            myMap[c] = i;
            ans = max(ans,(i - l + 1));
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    string input = "tmmuxst";
    int ans = lengthOfLongestSubstring(input);
    printf("ans = %d\n",ans);
    return 0;
}
