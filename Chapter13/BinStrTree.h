#pragma once
class BinStrTree
{
public:
    BinStrTree();
    BinStrTree(const BinStrTree& bst) :
        root(bst.root) {
        root->CopyTree();
    }
    
    ~BinStrTree();
private:
    TreeNode* root;
};

