//https://www.interviewbit.com/problems/simplify-directory-path/

string Solution::simplifyPath(string A) {
    stack<string> st;
    
    int len = A.length();
    
    for(int i=0;i<len;i++){
        if(A[i]=='/'){
            continue;
        }
        if(A[i]=='.'){
            if(i+1<len && A[i+1]=='.'){
                if(!st.empty())
                    st.pop();
                i++;
            }
        }
        else{
            string tem="";
            while(i<len && A[i]!='/'){
                tem = tem+A[i];
                i++;
            }
            st.push(tem);
        }
    }
    string ans = "";
    while(!st.empty()){
        ans = "/"+st.top()+ans;
        st.pop();
    }

    return (ans=="")?"/":ans;
    
}
