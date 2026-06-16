class Solution {
public:
    string processStr(string s) {
        string res;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='*'&& !res.empty()) res.pop_back();
            if(s[i]=='*') continue;
            else if(s[i]=='#') res += res;
            else if(s[i]=='%') reverse(res.begin(), res.end());
            else res += s[i];
        }
        return res;
    }
};
