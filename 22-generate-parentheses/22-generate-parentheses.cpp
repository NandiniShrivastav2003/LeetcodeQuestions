class Solution {
public:
     vector<string>ans;
    void generate(int n,int a,int b,string res){
        if(a ==  n && b == n){
            ans.push_back(res);

            return ;
        }
        if(a<n){
        generate(n,a+1,b,res+'(');
          
            
        }
         if (b<a){
              generate(n,a,b+1,res+')');
           
        }
        
    }
    vector<string> generateParenthesis(int n) {
       
                                                                    generate(n,0,0,""); 
        return ans;
    }
};