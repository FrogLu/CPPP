#include "pch.h"
#include "TreeNode.h"
#include "BinStrTree.h"


BinStrTree::BinStrTree()
{
    root = nullptr;
}


BinStrTree::~BinStrTree()
{
    if (!root->ReleaseTree()) {
        delete root;
    }
}
