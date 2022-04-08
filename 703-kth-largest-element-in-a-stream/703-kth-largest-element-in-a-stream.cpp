class KthLargest {
private:
    struct comp{
        bool operator()(const int& a, const int& b){
            return a > b;
        }
    };
    
    priority_queue<int, vector<int>, comp > stream;
    int size;
    
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int num : nums){
            stream.push(num);
            if(stream.size() > k) stream.pop();
        }
    }
    
    int add(int val) {
        stream.push(val);
        if(stream.size() > size) stream.pop();
        
        return stream.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */