class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
                sort(nums.begin(), nums.end());
        vector<int> sortedNums = nums;
        vector<vector<int>> ans;
        vector<int> temp;
        for (int i = 0; i < sortedNums.size() - 1; i++) {
            
            if (sortedNums[i] - sortedNums[i + 1] <= k) {
                temp.push_back(sortedNums[i]);
                if(temp.size()==3){
                    ans.push_back(temp);
                    temp.clear() ;
                }

            } else {
                 vector<vector<int>> emp;
                 return emp;
            }
        }
        if(ans[(ans.size()-1)].size()==3){
            vector<int> temp1;
            temp1.push_back(sortedNums[sortedNums.size()-1]);
            ans.push_back(temp1);

        }
        else{
            ans[ans.size()-1].push_back(sortedNums[sortedNums.size()-1]);
        }
        return ans;
    }
};