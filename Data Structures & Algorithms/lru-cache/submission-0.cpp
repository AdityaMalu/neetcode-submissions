class LRUCache {
    struct ListNode {
        int key;
        int value;

        ListNode* prev;
        ListNode* next;

        ListNode(int k, int v) {
            key = k;
            value = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity = 0;
    unordered_map<int, ListNode*> hash;
    ListNode* head;
    ListNode* tail;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        ListNode* node = hash[key];

        remove(node);
        insertFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (hash.find(key) != hash.end()) {
            ListNode* node = hash[key];

            node->value = value;

            remove(node);
            insertFront(node);

            return;
        } else {
            if (hash.size() == capacity) {
                ListNode* toRemove = tail->prev;
                remove(toRemove);
                hash.erase(toRemove->key);
            }
            ListNode* node = new ListNode(key, value);

            hash[key] = node;
            insertFront(node);
        }
    }
};
