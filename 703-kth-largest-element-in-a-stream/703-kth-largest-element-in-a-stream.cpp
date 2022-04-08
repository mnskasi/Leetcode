class KthLargest {
    priority_queue <int, vector<int>, greater<int> > minHeap;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k;
        for(int i = 0; i < nums.size(); i++){
            minHeap.push( nums[i] );
        }
        int t = nums.size()-k;
        while( t-- > 0 ){
            minHeap.pop();
        }
    }
    int add(int val) {
        if( minHeap.size() == kth-1 ){ 
            minHeap.push(val);
        } 
        else if(val >= minHeap.top() )
        {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */