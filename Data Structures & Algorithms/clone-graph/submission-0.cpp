class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (node == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> clones;
        queue<Node*> q;

        clones[node] = new Node(node->val);

        q.push(node);

        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {

                if (clones.find(neighbor) == clones.end()) {
                    clones[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                clones[curr]->neighbors.push_back(clones[neighbor]);
            }
        }

        return clones[node];
    }
};