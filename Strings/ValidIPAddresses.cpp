// https://www.interviewbit.com/problems/valid-ip-addresses/

bool isValid(string AA){
    string A = "", B = "", C = "", D = "";
    int a = 0, b = 0, c = 0, d = 0;
    int count = 0;
    int i = 0;
    
    LOOP:while(i < AA.size()){
        if(AA[i] == '.'){
            i++;
            count++;
            goto LOOP;
        }
        if(count == 0){
            a++;
            A = A + AA[i];
        }
        else if(count == 1){
            b++;
            B = B + AA[i];
        }
        else if(count == 2){
            c++;
            C = C + AA[i];
        }
        else if(count == 3){
            d++;
            D = D + AA[i];
        }
        i++;
    }
    
    if(count != 3){
        return false;
    }
    
    if(a == 0 || b == 0 || c == 0 || d == 0){
        return false;
    }
    if(a > 3 || b > 3 || c > 3 || d > 3){
        return false;
    }
    
    int ta = stoi(A), tb = stoi(B), tc = stoi(C), td = stoi(D);
    
    if(ta < 0 || ta > 255){
        return false;
    }
    if(tb < 0 || tb > 255){
        return false;
    }
    if(tc < 0 || tc > 255){
        return false;
    }
    if(td < 0 || td > 255){
        return false;
    }
    
    int ca = 0, cb = 0, cc = 0, cd = 0;
    
    do{
        ta = ta/10;
        ca++;
    }while(ta);
    do{
        tb = tb/10;
        cb++;
    }while(tb);
    do{
        tc = tc/10;
        cc++;
    }while(tc);
    do{
        td = td/10;
        cd++;
    }while(td);
    
    if(ca != A.size()){
        return false;
    }
    if(cb != B.size()){
        return false;
    }
    if(cc != C.size()){
        return false;
    }
    if(cd != D.size()){
        return false;
    }
    
    
    return true;
    
}

string getStr(string A, int i, int j, int k){
    string x = "";
    
    int in = 0;
    
    while(in < A.size()){
        if(in == i){
            x = x + '.';
        }
        if(in == j){
            x = x + '.';
        }
        if(in == k){
            x = x + '.';
        }
        x = x + A[in];
        in++;
    }
    
    return x;
}

vector<string> Solution::restoreIpAddresses(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> sol;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = i+1; j < A.size(); j++){
            for(int k = j+1; k < A.size(); k++){
                string check = getStr(A, i, j, k);
                if(isValid(check)){
                    sol.push_back(check);
                }
            }
        }
    }
    
    return sol;
}

// Alternate solution using recursion

// Helper function to check validity of a string

bool checkValidNum(string a) {
    return a.size() > 1 && a[0] == '0' ? 0 : stoll(a) >= 0 && stoll(a) <= 255;
}

// Helper function to check validity of a whole IP

bool checkValidIP(string a) {
    int occurences = count(a.begin(), a.end(), '.');
    if (occurences != 3) {
        return 0;
    }
    int start = 0;
    while (a.find('.', start) != string::npos) {
        string temp = a.substr(start, a.find('.', start) - start);
        if (!checkValidNum(temp)) {
            return 0;
        }
        start = a.find('.', start) + 1;
    }
    return checkValidNum(a.substr(start));
}

// Helper function to generate all possibilities

void generate (string A, vector<string> &res, int index, string local) {
    if (index >= A.size()) {
        if (checkValidIP(local)) {
            res.push_back(local);
        }
        return;
    }
    for (int i = 1; i <= A.size() - index; i ++) {
        string temp = A.substr(index, i);
        generate(A, res, index + i, local.size() ? local + "." + temp : temp);
    }
    return;
}
vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> res;
    generate(A, res, 0, string());
    return res;
}

