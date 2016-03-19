// 146. LRU Cache
// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

class LRUCache{
private:
    struct Node{
        int val;
        Node * prev;
        Node * next;
        int key;
        Node(Node* p, Node* n, int num, int k) : prev(p), next(n), val(num), key(k){};
        Node(int num,int k): prev(NULL), next(NULL),val(num), key(k){};
    };

    unordered_map<int, Node*> map;
    Node * head;
    Node * tail;
    int cp;

public:

    LRUCache(int capacity) {
        cp = capacity;
        head = NULL;
        tail = NULL;
        map.clear();
    }

    void Insert(Node * root){
        if(!head){
            head = root;
            tail = root;
        }else{
            tail->next = root;
            root->prev = tail;
            tail = root;
        }
    }

    void remove(){
        map.erase(head->key);
        if(head->next == NULL){
            head = NULL;
            tail = NULL;
        }else{
            head = head->next;
            head->prev = NULL;
        }
    }

    void move(Node * root){
        if(head == tail || root == tail)
            return;

        if(root == head){
            tail->next = root;
            root->prev = tail;
            head = head->next;
            head->prev = NULL;
            tail = tail->next;
            //tail->next = NULL;
        }else{
            root->next->prev = root->prev;
            root->prev->next = root->next;
            tail->next = root;
            root->prev = tail;
            tail = tail->next;
            //tail->next = NULL;
        }
    }

    int get(int key) {
        if(map.count(key)){
            Node* temp = map[key];
            move(temp);
            return map[key]->val;
        }else{
            return -1;
        }
    }

    void set(int key, int value) {
        if(map.count(key)){
            Node * temp = map[key];
            move(temp);
            map[key]->val = value;
        }else{
            if(map.size() == cp){
                remove();
            }

            Node * temp = new Node(value,key);
            map[key] = temp;
            Insert(temp);
        }
    }

};
