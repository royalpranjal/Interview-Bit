// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int paths(vector<vector<int> > A, int currX, int currY, int maxX, int maxY){
    if(currX >= maxX || currY >= maxY){
        return 0;
    }
    else if(A[currX][currY] == 1){
        return 0;
    }
    else if(currX == maxX-1 && currY == maxY-1){
        return 1;
    }
    return paths(A, currX + 1, currY, maxX, maxY) + paths(A, currX, currY + 1, maxX, maxY);
}


int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return paths(A, 0, 0, A.size(), A[0].size());
    
}
