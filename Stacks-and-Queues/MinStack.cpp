// https://www.interviewbit.com/problems/min-stack/

stack<int> st;
stack<int> minSt;

MinStack::MinStack() {
    while(!st.empty()){
        st.pop();
    }
    while(!minSt.empty()){
        minSt.pop();
    }
}

void MinStack::push(int x) {
    st.push(x);
    if(minSt.size() == 0){
        minSt.push(x);
    }
    else{
        if(x <= minSt.top()){
            minSt.push(x);
        }
        else{
            minSt.push(minSt.top());
        }
    }
}

void MinStack::pop() {
    if(st.size() != 0){
        st.pop();
        minSt.pop();
    }
}

int MinStack::top() {
    if(st.size() == 0){
        return -1;
    }
    return st.top();
}

int MinStack::getMin() {
    if(minSt.size() == 0){
        return -1;
    }
    return minSt.top();
}

