#include <stdlib.h>
#include <vector>

using namespace std;
int maxArea(vector<int> &height)
{
    int max_area = 0;
        int left = 0;
        int right = height.size()-1;
        while(left <  right){
            max_area = max(max_area,(right-left)*min(height[left],height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
}

int main(int argc, char *argv[])
{
    vector<int> intput = {1,8,6,2,5,4,8,3,7};

    int ans = maxArea(intput);

    printf("ans = %d",ans);
    return 0;

}

