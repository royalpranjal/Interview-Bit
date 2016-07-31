// https://www.interviewbit.com/problems/longest-common-prefix/

string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string temp_overall_max, overall_max, temp_max;
    int max_length, temp_length;

    for(int i = 0; i < A.size(); i++){
        if( i == 0){
            temp_overall_max = A[i];
            overall_max = A[i];
            max_length = A[i].size();
        }

        temp_overall_max = overall_max;

        temp_max = A[i];
        temp_length = A[i].size();

        int check_length = temp_length;

        if(temp_length >= max_length){
            check_length = max_length;
        }

        max_length = 0;
        overall_max = "";

        for(int j = 0; j < check_length; j++){
            char c = temp_overall_max[j];
            char a = temp_max[j];
            if(c == a){
                max_length++;
                overall_max = overall_max + a;
            }
            else{
                break;
            }
        }
    }
    
    return overall_max;
}
