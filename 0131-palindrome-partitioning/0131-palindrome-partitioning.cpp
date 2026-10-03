class Solution {
public:
     
    bool ispalin(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());

        if(s2 == s){
            return true;
        }else{
            return false;
        }
    }
    void fun(string s, vector<string>&res,vector<vector<string>>&ans)
    {
        if(s.size() == 0){
            ans.push_back(res);
            return;
        }

        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0 , i+1);

            if(ispalin(part)){
                res.push_back(part);
                fun(s.substr(i+1),res,ans);
                res.pop_back();
            }
        }


    }

    vector<vector<string>> partition(string s) {
        vector<string>res;
        vector<vector<string>>ans;

        fun(s,res,ans);

        return ans;
    }
};