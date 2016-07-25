// https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i = 0;
    int count = 0;
    int flag = 0;
    int num = B-1;
    
    string ans = "";
    
    if(A.size() == 0 || A.size() == 1 || B == 1){
        return A;
    }
    
    while(count < B){
        i = count;
        flag = 0;
        while(i < A.size()){
            if((count == 0) || (count == B-1)){    
                ans = ans + A[i];
                i = i + 2*num;
            }
            else{
                if(flag == 0){
                    ans = ans + A[i];
                    i = i + 2*(B-count-1);
                    flag = 1;
                }
                else{
                    ans = ans + A[i];
                    i = i + 2*count;
                    flag = 0;
                }
            }
        }
        count++;
    }
    
    return ans;
}
