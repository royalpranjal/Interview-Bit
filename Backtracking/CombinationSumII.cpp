void back_track(vector<vector<int>> &ans, vector<int> &combination, vector<int>& candidates, int start, int target) {
    if (target == 0) {
        ans.push_back(combination);
        return;
    }
        
    for ( int i = start; i < candidates.size(); i++) {
        if ((target - candidates[i]) < 0)
            return;
        if (candidates[i] <= target) {
            combination.push_back(candidates[i]);
            back_track(ans, combination, candidates, i + 1, target - candidates[i]);
            combination.pop_back();  
            while(i+1<candidates.size() && candidates[i]==candidates[i+1]) {
                i++;
            }
        }
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
	vector<vector<int>> ans;
    vector<int> combination;
    vector<int>::iterator ip;
	
    sort(A.begin(), A.end());
    back_track(ans, combination, A, 0, B);
    
	return ans;
}