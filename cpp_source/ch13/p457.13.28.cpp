#include <iostream>
#include <string>

class TreeNode{
public:
    TreeNode();
    TreeNode(TreeNode&);
    TreeNode& operator=(const TreeNode&);
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(): value(""), count(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(TreeNode& tn): value(tn.value), count(tn.count), left(tn.left), right(tn.right) {}
TreeNode::TreeNode& operator=(const TreeNode& tn) {
    if (&tn != this){
    value = tn.value;
    count = tn.count;
    left = tn.left;
    right = tn.right;
    }
    return *this;
}
TreeNode::~TreeNode() {
    delete left;
    delete right;
}
