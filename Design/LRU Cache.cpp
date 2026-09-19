//STL implementation
class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mpp;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }

    void makeRecent(int key){
        int val = mpp[key].second;
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key] = {dll.begin(), val};
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        makeRecent(key);
        return mpp[key].second;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            mpp[key].second = value;
            makeRecent(key);
        }
        else {
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            size--;
        }

        if(size < 0){
            int keyToBeDeleted = dll.back();
            dll.pop_back();
            mpp.erase(keyToBeDeleted);
            size++;
        }
    }
};

//non-STL imlementation
class LRUCache {
public:

    // DLL ka ek node
    struct Node {
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    // Key -> us key ka node
    unordered_map<int, Node*> mpp;

    Node* head;
    Node* tail;

    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Dummy head aur tail banaye
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // DLL se node remove karo
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Node ko head ke just baad add karo
    // Matlab ye ab most recently used hai
    void insertFront(Node* node) {

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Node ko front par le aao
    void makeRecent(Node* node) {
        removeNode(node);
        insertFront(node);
    }

    int get(int key) {

        // Key nahi mili
        if (mpp.find(key) == mpp.end()) {
            return -1;
        }

        Node* node = mpp[key];

        // Access hua hai, isliye recent bana do
        makeRecent(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exist karti hai
        if (mpp.find(key) != mpp.end()) {

            Node* node = mpp[key];

            // Value update karo
            node->value = value;

            // Ab ye most recently used hai
            makeRecent(node);

            return;
        }

        // Naya node banao
        Node* newNode = new Node(key, value);

        // Map mein store karo
        mpp[key] = newNode;

        // DLL ke front mein daalo
        insertFront(newNode);

        // Agar capacity exceed ho gayi
        if (mpp.size() > capacity) {

            // Tail ke just pehle wala LRU hai
            Node* lru = tail->prev;

            // DLL se remove karo
            removeNode(lru);

            // Map se bhi remove karo
            mpp.erase(lru->key);

            // Memory free karo
            delete lru;
        }
    }
};
