// https://www.interviewbit.com/problems/hotel-reviews/

struct TrieNode{
    unordered_map<char,TrieNode*> children;
    bool is_word;
    TrieNode(bool x) : is_word(x) {}
};
 
struct ResNode{
    int index;
    int val;
};
 
bool myfunction (ResNode i,ResNode j) {
    bool ret = 0;
    if(i.val>j.val){
        ret=1;
    }
    else if(i.val==j.val){
        if(i.index<j.index){
            ret=1;
        }
    }
    return ret;
}
 
void construct_trie(string good_words, TrieNode* A){
    TrieNode* current = A;
    for(int i=0; i<good_words.length(); i++){

        if(good_words[i]=='_'){
            current=A;
            continue;
        }
        else{
            unordered_map<char,TrieNode*>::iterator it = (current->children).find(good_words[i]);
            if(it != (current->children).end()){
                current = it->second;
            }
            else{
                TrieNode* B = new TrieNode(0);
                (current->children)[good_words[i]] = B;
                current=B;
            }
            if(i==good_words.length()-1 || good_words[i+1]=='_'){
                current->is_word = 1;
            }
        }
    }
}
 
int solveReview(TrieNode* A, string review){
    int result = 0;
    review = review+"_";
    vector<string> arr;
    int start = 0;
    for(int i=0; i<review.length(); i++){
        if(review[i]=='_'){
            if(start!=i){
                arr.push_back(review.substr(start,i-start));
            }
            start = i+1;
        }
    }
    for(int i=0; i<arr.size(); i++){
        TrieNode* current = A;
        for(int j=0; j<arr[i].length(); j++){
            unordered_map<char,TrieNode*>::iterator it = (current->children).find(arr[i][j]);
            if(it != (current->children).end()){
                current = it->second;
            }
            else{
                break;
            }
            if(j==arr[i].length()-1){
                if(current->is_word == 1){
                    result++;
                }
            }
        }
    }
    return result;
}
 
vector<int> Solution::solve(string good_words, vector<string> &reviews) {
	// Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
    vector<int> result;
    vector<ResNode> temp_res;
    TrieNode* A = new TrieNode(0);
    construct_trie(good_words, A);
 
    for(int i=0; i<reviews.size(); i++){
        ResNode res;
        res.val = solveReview(A,reviews[i]);
        res.index = i;
        temp_res.push_back(res);
    }
    sort(temp_res.begin(),temp_res.end(),myfunction);
    for(int i=0; i<temp_res.size(); i++){
        result.push_back(temp_res[i].index);
    }
    return result;
}