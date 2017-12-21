#import <iostream>
using namespace std;

class TreeNode
{
public:
  TreeNode();
  TreeNode(int key);

  //virtual, for line below
  ~TreeNode(); //can be overwritten, has to do with polymorphism

  int key;
//  Student myStudent; //hint

  TreeNode *left;
  TreeNode *right;

};
