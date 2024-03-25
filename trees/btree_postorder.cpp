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

    walk(curr->right, path);

    path.push_back(curr->val);

}

std::vector<int> postorder(struct BTreeNode* head) {
    std::vector<int> order;

    walk(head, order);

    return order;
}

