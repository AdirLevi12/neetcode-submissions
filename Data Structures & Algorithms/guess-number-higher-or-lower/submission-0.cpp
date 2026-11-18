/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while(low <= high){
            int mid = (low+high)/2;
            int guess_res = guess(mid);
            if(!guess_res){
                return mid;
            }
            else if(guess_res == 1){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return 0; // just for the compiler because we alayws find the guess
    }
};