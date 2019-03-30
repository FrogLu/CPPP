#pragma once
class BinStrTree
{
public:
    BinStrTree();
    BinStrTree(const BinStrTree& bst) :
        root(bst.root) {
        bst.~BinStrTree();
    }
    ~BinStrTree();
private:
    TreeNode* root;
};

