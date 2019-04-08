#pragma once
#ifndef _TREENODE_H_
#define _TREENODE_H_

class TreeNode
{
public:
    TreeNode(const std::string& str = std::string()) :
        value(str), count(0), left(nullptr), right(nullptr) {};
    TreeNode(const TreeNode& tn);
    TreeNode& operator=(const TreeNode& rhs);
    void CopyTree(void);
    int ReleaseTree(void);
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode* left;
    TreeNode* right;
};

inline
TreeNode::TreeNode(const TreeNode& tn) :
    value(tn.value), count(tn.count), left(tn.left), right(tn.right) {
    if (left) {
        left->CopyTree();
    }
    if (right) {
        right->CopyTree();
    }
}

inline
TreeNode& TreeNode::operator=(const TreeNode& rhs) {
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
    if (left) {
        left->CopyTree();
    }
    if (right) {
        right->CopyTree();
    }
    rhs.~TreeNode();
}

inline
void TreeNode::CopyTree(void)
{
    if (left) {
        left->CopyTree();
    }
    if (right) {
        right->CopyTree();
    }
    count++;
}

inline int TreeNode::ReleaseTree(void)
{
    if (left) {
        if (!(left->count)) {
            delete left;
        }
    }
    if (right) {
        if (!(right->count)) {
            delete right;
        }
    }
    count--;
    return count;
}

#endif // !_TREENODE_H_