class Solution {
public:
    string processStr(string s) {
     string res;
     int n = s.size();
     for(int i =0; i<n; i++ ) {
        char ch = s[i];
        if(ch>='a' &&  ch<='z'){
            res.push_back(ch);
        }else if(ch == '*'){
        if(res.length()!=0){
            res.pop_back();}
        }else if(ch == '#'){
            res = res + res;
        }else {
          reverse(res.begin(),res.end());
        }
        }
     
     return res;
    }
};