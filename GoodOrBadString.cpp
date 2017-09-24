#include <iostream>

using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

int main()
 {
	//code
	int test;
	cin >> test;
	
	while(test--){
	    string s;
	    cin >> s;
	    
	    int n = s.size(), i = 0, vCount = 0, cCount = 0, ans = 1;
	    
	    while(i < n){
	        if(s[i] == '?'){
	            vCount++;
	            cCount++;
	        }
	        else if(isVowel(s[i])){
	            vCount++;
	            cCount = 0;
	        }
	        else{
	            cCount++;
	            vCount = 0;
	        }
	        if(vCount == 6 || cCount == 4){
	            ans = 0;
	            break;
	        }
	        i++;
	    }
	    
	    cout << ans << endl;
	}
	
	return 0;
}
