class Solution {
public:
 
   void  Fill(vector<vector<int>>& image, int sr, int sc, int newColor,int comp,int m,int n) {
       if(sr<0  || sc<0 ||sr>=m || sc>=n ||image[sr][sc] != comp){
           return ;
       }
image[sr][sc]=newColor;
  
       Fill(image,sr-1,sc,newColor,comp,m,n);
        Fill(image,sr+1,sc,newColor,comp,m,n);
        Fill(image,sr,sc-1,newColor,comp,m,n);
        Fill(image,sr,sc+1,newColor,comp,m,n);
    
       
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         
        int m=image.size();int n=image[0].size();
       
          if(image.size() && image[sr][sc]!=newColor){
        Fill(image,sr,sc,newColor,image[sr][sc],m,n);
          }
        return image;
    }
};