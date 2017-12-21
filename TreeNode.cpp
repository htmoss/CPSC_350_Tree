#import "TreeNode.h"
#import <iostream>
using namespace std;

TreeNode::TreeNode()
{
  left = NULL;
  right = NULL;
  key = 0;

}

TreeNode::TreeNode(int theKey)
{
  left = NULL;
  right = NULL;
  key = theKey;
}

TreeNode::~TreeNode()
{
  
}
