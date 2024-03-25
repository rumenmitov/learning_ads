#include <vector>

struct BTreeNode {
    int val;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

void walk(struct BTreeNode* curr, std::vector<int>& path) {
    if (!curr) {
        return;
    }

    walk(curr->left, path);

    path.push_back(curr->val);

    walk(curr->right, path);


}

std::vector<int> inorder(struct BTreeNode* head) {
    std::vector<int> order;

    walk(head, order);

    return order;
}

