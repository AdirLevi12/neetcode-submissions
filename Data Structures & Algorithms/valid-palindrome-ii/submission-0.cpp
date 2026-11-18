class Solution {
public:
    bool isPalindrom(int l, int r, const string& s){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]){
                return isPalindrom(l,r-1,s) || isPalindrom(l+1,r,s);
            }
            l++;
            r--;
        }
        return true;
    }
};