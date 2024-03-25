#include <vector>

struct BTreeNode {
    int val;
    struct BTreeNode* left;
    struct BTreeNode* right;

};

void walk(struct BTreeNode* curr, std::vector<int>& path) {
    if (curr) {
        return;
    }

    path.push_back(curr->val);

    walk(curr->left, path);

    walk(curr->right, path);
}

std::vector<int> pre_order(struct BTreeNode* head) {
    std::vector<int> order;

    walk(head, order);

    return order;


}
