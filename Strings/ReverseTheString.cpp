void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void swapBetween(int i, int j, string &A){
    int k = 1;
    for(int z = i; z < (i+j)/2; z++){
        swap(A[z], A[j-k]);
        k++;
    }
}

// string extractWord(string &A, int &i){
//     int temp = i;
//     while(!isspace(A[i])){
//         i++;
//     }
//     return A.substr(temp, i-temp);
// }

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i;
    for(i = 0; i < A.size(); i++){
        if(!isspace(A[i])){
            int j = i+1;
            if(j >= A.size()){
                break;
            }
            while(!isspace(A[j])){
                j++;
                if(j == A.size()){
                    break;
                }
            }
            swapBetween(i, j, A);
            i = j;
        }
    }
    
    string B = "";
    i = A.size()-1;
    int count = 0;
    
    while(i >= 0){
        if(isspace(A[i])){
            if(i == 0){
                break;
            }
            if(isspace(A[i-1])){      
            }
            else{
                if(count != 0){
                    B = B + " ";
                }
            }
        }
        else{
            count ++;
            B = B + A[i];
        }
        i--;
    }
    
    A = B;
}
