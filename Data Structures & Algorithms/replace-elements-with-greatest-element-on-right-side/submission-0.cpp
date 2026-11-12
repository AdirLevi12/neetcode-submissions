class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int size = arr.size();
        int gr = -1;
        for(int i = size-1; i >= 0; i--){
            int tmp = arr[i];
            arr[i] = gr;
            gr = max(gr,tmp);
        }
        return arr;
    }
};