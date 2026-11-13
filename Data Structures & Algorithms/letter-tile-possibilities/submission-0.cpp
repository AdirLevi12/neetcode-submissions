class Solution {
public:
    int backtrack(vector<int>& freq){
        int total_count = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                total_count++;
                freq[i]--;
                total_count += backtrack(freq);
                freq[i]++;
            }
        }
        return total_count;
    }
    
    int numTilePossibilities(string tiles) {
        vector<int> freq(26);
        for(char c: tiles){
            freq[c - 'A']++;
        }
        return backtrack(freq);
    }
};
