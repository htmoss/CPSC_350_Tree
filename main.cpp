#import <iostream>
#import <string>
#import "BST.h"
using namespace std;

int main(int argc, char** argv)
{
  BST<int>b;
  b.insert(5);
  b.insert(3);
  b.insert(11);
  b.insert(8);

  TreeNode* max = b.getMax();
  cout<< "max num: "<< max->key <<endl;

  TreeNode* min = b.getMin();
  cout<< "min num: "<< min->key <<endl;

  cout<<b.contains(11)<<endl;

  b.deleteNode(11);

  cout<<b.contains(11)<<endl;




  return 0;
}
