// https://www.interviewbit.com/problems/prettyprint/

vector<vector<int> > Solution::prettyPrint(int A) {
    int size, temp, limit, i, j;

    size = 2*A-1;
    limit = size;
    temp = 0;

    vector<vector<int> > mat(size, vector<int>(size));

    while(A > 0){
        for(i = temp; i < limit; i++){
            for(j = temp; j < limit; j++){
                mat[i][j] = A;
            }
        }
        A--;
        limit--;
        temp++;
    }

    return mat;
}
