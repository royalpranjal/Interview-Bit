// https://www.interviewbit.com/problems/implement-strstr/

void preComp(string A, vector<int> &vec){
    int len = A.size();
    vec[0] = -1;
    int k;
    for(int i = 1; i < A.size(); i++){
        k = vec[i-1];
        while(k >= 0){
            if(A[k] == A[i-1]){
                break;
            }    
            else{
                k = vec[k];
            }
        }
        vec[i] = k+1;
    }
}

int Solution::strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int txt_len = haystack.size();
    int pat_len = needle.size();
    int flag = 0;
    
    if(txt_len < pat_len){
        return -1;
    }
    
    if(pat_len == 0){
        return 0;
    }
    
    vector<int> pre(pat_len);
    
    preComp(needle, pre);
    int i = 0; // for hay
    int j = 0; // for needle
    int sol;
    
    while(i < txt_len){
        if(j == -1){
            i++;
            j = 0;
        }
        else if(haystack[i] == needle[j]){
            i++;
            j++;
            if(j == pat_len){
                flag = 1;
                break;
            }
        }
        else{
            j = pre[j];
        }
        if(flag == 1){
            break;
        }
    }
    
    if(flag == 1){
        return i-j;
    }
    
    return -1;
}
