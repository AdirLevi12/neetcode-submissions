class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> freq(26);
       int l = 0;
       int res = 0;
       for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'A']++;
            while((i-l+1) - *max_element(freq.begin(),freq.end()) > k){
                freq[s[l] - 'A']--;
                l++;
            }
            res = max(res, (i-l+1));
       }
       return res; 
    }
};
