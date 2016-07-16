// https://www.interviewbit.com/problems/array_bug/

vector<int> Solution::rotateArray(vector<int> &A, int B) {
	vector<int> ret;
	int j = 0;
	B = B%(A.size());
	for (int i = 0; i < A.size(); i++) {
		if((i+B) < A.size()){
		    ret.push_back(A[i + B]);    
		}
		else{
		    ret.push_back(A[j]);
		    j++;
		}
		
	}
	return ret; 
}
