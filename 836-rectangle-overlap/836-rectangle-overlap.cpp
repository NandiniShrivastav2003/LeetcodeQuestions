class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1=rec1[0],y1=rec1[1],x3=rec1[2],y3=rec1[3];
        int x2=rec2[0],y2=rec2[1],x4=rec2[2],y4=rec2[3];
        int first=min(y3,y4);
        int second=max(y1,y2);
        int third=min(x3,x4);
        int four=max(x1,x2);
        if((first - second) < 0 || (third-four) < 0){
         return false;   
        }
        return ((first-second) > 0 && (third - four) > 0);
    }
};