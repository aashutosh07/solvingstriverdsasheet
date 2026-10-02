class Solution {
public:

    void solve(int n,int open, int close,string temp,vector<string>&res){

        if(open == n && close == n){
            res.push_back(temp);
            return;
        }
        
        //first choice
        if(open < n){
            temp.push_back('(');
            solve(n,open+1,close,temp,res);
            temp.pop_back();
        }

        //second choice
        if(close < open){
            temp.push_back(')');
            solve(n,open,close+1,temp,res);
            temp.pop_back();
        }

        return;

    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp;

        solve(n,0,0,temp,res);
        
        return res;
        
    }
};