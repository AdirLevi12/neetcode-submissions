class Solution {
public:
    int countSeniors(vector<string>& details) {
        int AGE_TENS_DIGIT_PLACE = 11;
        int AGE_UNITS_DIGIT_PLACE = 12;
        int res = 0;
        for(const string& s : details){
            if(s[AGE_TENS_DIGIT_PLACE] > '6' || (s[AGE_TENS_DIGIT_PLACE] == '6' && s[AGE_UNITS_DIGIT_PLACE] > '0')){
                res++;
            }
        }
        return res;
    }
};