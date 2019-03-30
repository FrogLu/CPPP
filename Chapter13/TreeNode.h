#pragma once
class TreeNode
{
public:
    TreeNode(const std::string& str = std::string()) :
        value(str), count(0), left(nullptr), right(nullptr) {};
    TreeNode(const TreeNode& tn) :
        value(tn.value), count(tn.count), left(tn.left), right(tn.right) {
        tn.~TreeNode();
    }
    TreeNode& operator=(const TreeNode& rhs);
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

inline
TreeNode& TreeNode::operator=(const TreeNode& rhs) {
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    rhs.~TreeNode();
}
