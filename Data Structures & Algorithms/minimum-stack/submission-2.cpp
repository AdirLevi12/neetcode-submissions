class MinStack {
private:
    vector<pair<int,int>> s;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push_back({val, val});
            return;
        }
        int curr_min = min(val, s[s.size()-1].second);
        s.push_back({val,curr_min});
 
    }
    
    void pop() {
        if(s.size() > 0){
            s.pop_back();
        }
    }
    
    int top() {
        if(!s.empty()){
           return s[s.size()-1].first; 
        }
    }
    
    int getMin() {
        return s[s.size()-1].second;
    }
};
