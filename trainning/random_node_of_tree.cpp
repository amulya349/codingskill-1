/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 输入：一棵二叉树的根节点。每个节点只有左右孩子指针，无指向父亲指针。拥有一个随机函数rand(n) 可以产生[0..n - 1]的随机数。
 * 输出：随机选取二叉树的一个节点，保证每个节点选取的概率相同
 * -------------------------------------------------------------}}}*/
#include "../util/tree.h"
typedef Tree<int>::TreeNode TreeNode;

int rand(int n);

void randNodeImp(const TreeNode * node, int & idx, const TreeNode * & r) {
    if (!node) return;
    if (rand(++idx) == 0)
        r = node;
    randNodeImp(node->left,  idx, r);
    randNodeImp(node->right, idx, r);
}

const TreeNode * randNode(const TreeNode * root) {
    int idx = 0;
    const TreeNode * r = 0;
    randNodeImp(root, idx, r);
    return r;
}

int main(int argc, char * argv[]) {
    return 0;
}
