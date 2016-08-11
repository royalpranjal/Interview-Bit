// https://www.interviewbit.com/problems/least-recently-used-cache/

map<int, int> myMap;
int maxi = 0;
int current = 0;

struct Node{
  int val;
  Node *next;
  Node *prev;
  Node(int x){
      val = x;
      next = NULL;
      prev = NULL;
  }
};

Node* first;
Node* lru;

LRUCache::LRUCache(int capacity) {
    myMap.erase(myMap.begin(), myMap.end());
    maxi = capacity;
    current = 0;
    first = NULL;
    lru = NULL;
}

int LRUCache::get(int key) {
    if(current > 0){
        auto it = myMap.find(key);
        if(it != myMap.end()){
            int temp = it->second;
            int value = it->first;
            Node* curr = first;
            while(curr->val != value){
                curr = curr->next;
            }
            Node* prv = curr->prev;
            Node* nxt = curr->next;
            if(prv != NULL){
                prv->next = nxt;
                if(nxt == NULL){
                    lru = prv;
                }
                else{
                    nxt->prev = prv;
                }
                curr->next = first;
                curr->prev = NULL;
                first->prev = curr;
                first = curr;
            }
            return temp;
        }
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(myMap.find(key) == myMap.end()){
        Node* temp = new Node(key);
        myMap.insert({key, value});
        if(current != maxi){
            current++;
            if(current == 1){
                lru = temp;
                first = lru;
            }
            else{
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
        }
        else{
            int t = lru->val;
            auto it = myMap.find(t);
            myMap.erase(it);
            if(lru->prev != NULL){
                lru = lru->prev;
                lru->next = NULL;    
                temp->next = first;
                first->prev = temp;
                first = temp;
            }
            else{
                lru = temp;
                first = lru;
            }
        }
    }
    else{
        myMap[key] = value;
        Node* curr = first;
        while(curr->val != key){
            curr = curr->next;
        }
        Node* prv = curr->prev;
        Node* nxt = curr->next;
        if(prv != NULL){
            prv->next = nxt;
            if(nxt == NULL){
                lru = prv;
            }
            else{
                nxt->prev = prv;
            }
            curr->next = first;
            curr->prev = NULL;
            first->prev = curr;
            first = curr;
        }
    }
}


