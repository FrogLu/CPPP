#pragma once
#ifndef _BINSTRTREE_H_
#define _BINSTRTREE_H_

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

#endif // !_BINSTRTREE_H_

