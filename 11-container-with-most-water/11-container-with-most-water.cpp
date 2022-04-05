class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0;int j=height.size()-1;
        while(i<j){
                int l=min(height[i],height[j]);
                int b=j-i;
                res=max(res,(l*b));
            if(height[i]<height[j]){i++;}
            else{j--;}
            }
        
        return res;
    }
};