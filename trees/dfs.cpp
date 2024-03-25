struct BTreeNode {
    int val;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

bool dfs(struct BTreeNode* head, int needle) {
    if (!head) return false;

    if (head->val == needle) return true;

    if (head->val < needle) return dfs(head->right, needle);

    return dfs(head->left, needle);
}
