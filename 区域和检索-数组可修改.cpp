class NumArray {
public:
    // 线段树
#define MAXL 70000
    vector<int> segmentTree; // 每个存的是区间和
    vector<int> numsCopy; // 用于update
    int length;
    /* 都是从1开始 方便找子节点 */

    void BuildTree(vector<int> &nums, int l, int r, int index){
        if(l == r)
            segmentTree[index] = nums[l];
        else{ // 先求子节点
            int mid = ( l + r) / 2;
            BuildTree(nums, l, mid, 2*index); // 左节点 
            BuildTree(nums, mid+1, r, 2*index+1); // 右节点
            segmentTree[index] = segmentTree[2*index] + segmentTree[2*index+1];
        }
    }

    void UpdateTree(int numIndex, int change, int l, int r, int index){
        segmentTree[index] += change;
        if(l == r){ // 就更新这个节点
            return;
        }
        else{
            int mid = (l + r) / 2;
            if(numIndex <= mid)
                UpdateTree(numIndex, change, l, mid, 2*index);
            else
                UpdateTree(numIndex, change, mid+1, r, 2*index+1);
        }
    }

    int QueryTree(int l, int r, int cl, int cr, int index){
        if(cl > r || cr < l)
            return 0;
        else if(cl >= l && cr <= r)
            return segmentTree[index];
        else{
            int mid = (cl + cr) / 2;
            return QueryTree(l, r, cl, mid, 2*index) + QueryTree(l, r, mid+1, cr, 2*index+1);
        }

    }


    NumArray(vector<int>& nums) { // Build Tree
        length = nums.size();
        segmentTree = vector<int>(MAXL, 0);
        numsCopy = nums;
        BuildTree(nums, 0, length-1, 1);
    }

    void update(int index, int val) {
        UpdateTree(index, val - numsCopy[index], 0, length-1, 1);
        numsCopy[index] = val;
    }


    int sumRange(int left, int right) {
        return QueryTree(left, right, 0, length-1, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */