// 用双指针完成将时间复杂度减为O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int l=1,r=height.size()-2;//左边的0位置和右边的n-1位置都不可能接水
        int ans=0;
        int lmax=height[0],rmax=height[height.size()-1];
while(l<=r)
{
if(lmax<=rmax)
{
ans+=max(0,lmax-height[l]);//用0做左值是为了避免接的雨水为负数，用0来更新
lmax=max(lmax,height[l++]);

}
else
{
ans+=max(0,rmax-height[r]);
rmax=max(rmax,height[r--]);

}

}
return ans;

    }
};
