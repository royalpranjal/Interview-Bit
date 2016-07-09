// https://www.interviewbit.com/problems/pascal-triangle-rows/

int compute(int line, int index){
    if(index == 0){
        return 1;
    }
    else{
        return compute(line, index-1)*(line-index+1)/index;
    }
}

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > tri(A);
    
    for(int i = 0; i < A; i++){
        for(int j = 0; j <= i; j++){
            tri[i].push_back(compute(i, j));
        }
    }
    
    return tri;
}
