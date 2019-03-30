#include "pch.h"
#include "TreeNode.h"

TreeNode::~TreeNode()
{
    if (count) {
        ReleaseTree();
    }
}
