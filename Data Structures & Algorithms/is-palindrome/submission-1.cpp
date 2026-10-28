class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int i = 0, j = size-1;
        while(i < j){
            while(!isalnum(s[i])){
                i++;
            }
            while(!isalnum(s[j])){
                j--;
            }
            if(i < j && tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // time complexity: O(N)
    // space complexity: O(1)
};
