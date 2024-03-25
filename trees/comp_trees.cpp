struct BTreeNode {
    int val;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

bool compare(struct BTreeNode* a, struct BTreeNode* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }

    if (a == nullptr || b == nullptr) {
        return false;
    }

    if (a->val != b->val) {
        return false;
    }

    return compare(a->left, b->left) && compare(a->right, b->right);
}
