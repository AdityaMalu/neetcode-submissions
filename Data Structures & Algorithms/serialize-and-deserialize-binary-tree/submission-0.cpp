class Codec {
public:

    void write(TreeNode* node, string& out) {
        if (!node) {
            out += "#,";
            return;
        }

        out += to_string(node->val) + ",";

        write(node->left, out);
        write(node->right, out);
    }

    TreeNode* read(string& data, int& pos) {

        int end = data.find(',', pos);

        string t = data.substr(pos, end - pos);

        pos = end + 1;

        if (t == "#")
            return nullptr;

        TreeNode* node = new TreeNode(stoi(t));

        node->left = read(data, pos);
        node->right = read(data, pos);

        return node;
    }

    string serialize(TreeNode* root) {
        string out;
        write(root, out);
        return out;
    }

    TreeNode* deserialize(string data) {
        int pos = 0;
        return read(data, pos);
    }
};