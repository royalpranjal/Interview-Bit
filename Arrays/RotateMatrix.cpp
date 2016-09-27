// https://www.interviewbit.com/problems/rotate-matrix/

void rot(vector<vector<int> >& A, int rowStart, int rowEnd, int colStart, int colEnd){

    while(rowStart < rowEnd){
        int i = 0;
        while((i + rowStart) < rowEnd){
            int temp1 = A[rowStart][colStart+i];
            int temp2 = A[rowStart+i][colEnd];
            int temp3 = A[rowEnd][colEnd-i];
            int temp4 = A[rowEnd-i][colStart];
            
            A[rowStart][colStart+i] = temp4;
            A[rowStart+i][colEnd] = temp1;
            A[rowEnd][colEnd-i] = temp2;
            A[rowEnd-i][colStart] = temp3;
            i++;
        }
        colStart++;
        colEnd--;
        rowStart++;
        rowEnd--;
    }
    
}


void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int rows = A.size();
    
    if(rows == 0){
        return;
    }
    
    rot(A, 0, rows-1, 0, rows-1);
    
}
