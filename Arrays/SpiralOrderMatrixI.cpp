// https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	int rows = A.size();
	int cols = A[0].size();
	int top = 0;
	int bottom = rows-1;
	int left = 0;
	int right = cols-1;
	int dir = 0; // 0 for L->R, 1 for T->B, 2 for R->L, 3 for B->T
	
	LOOP:while(top <= bottom && left <= right){
	    if(dir == 0){
	        //L->R
	        for(int j = left; j <= right; j++){
	            result.push_back(A[top][j]);
	        }
	        dir = 1;
	        top++;
	        goto LOOP;
	    }
	    else if(dir == 1){
	        for(int i = top; i <= bottom; i++){
	            result.push_back(A[i][right]);
	        }
	        right--;
	        dir = 2;
	        goto LOOP;
	    }
	    else if(dir == 2){
	        for(int j = right; j >= left; j--){
	            result.push_back(A[bottom][j]);
	        }
	        bottom--;
	        dir = 3;
	        goto LOOP;
	    }
	    else if(dir == 3){
	        for(int i = bottom; i >= top; i--){
	            result.push_back(A[i][left]);
	        }
	        left++;
	        dir = 0;
	        goto LOOP;
	    }
	}
	
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
