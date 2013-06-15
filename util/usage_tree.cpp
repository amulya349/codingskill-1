/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 *          5
 *       /    \
 *      4      8
 *     /      / \
 *    11     3   4
 *   /  \       / \
 *  7    2     5   1
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include "tree.h"

typedef Tree<int>::TreeNode TreeNode;
typedef const Tree<int>::TreeNode * kpstNode;

int depth_node(kpstNode t, kpstNode & thedepth) { // return the max-depth item
    if (!t) return 0;

    kpstNode ldep;
    int ld = depth_node(t->left, ldep);
    int rd = depth_node(t->right, thedepth);
    
    if (ld > rd) {
        thedepth = ldep;
        return ld+1;
    }
    else {
        if (rd == 0) thedepth = t;
        return rd+1;
    }
}

void tell_depth_node(kpstNode root) {
    kpstNode thedepth;
    int depth = depth_node(root, thedepth);
    printf("line[%d], depth:%d, the value of most depth=%d\n", __LINE__, depth, thedepth->val);
    return;
}

void depth_tree_imp(const TreeNode * t, int lev, int & max_depth) {
    if (!t) {
        if (max_depth < lev)
            max_depth = lev;
        return;
    }
    depth_tree_imp(t->left,  lev+1, max_depth);
    depth_tree_imp(t->right, lev+1, max_depth);
}

int depth_tree(const TreeNode * root) {
    int max_depth = 0;
    depth_tree_imp(root, 0, max_depth);
    return max_depth;
}

int main(int argc, char * argv[]) {
    int A[] = {5, 4, 8, 11, '#', 3, 4, 7, 2, '#', '#', 5, 1};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));
    Tree<int>::InOrder(t.Root());
    printf("\t(in)\n");
    Tree<int>::PreOrder(t.Root());
    printf("\t(pre)\n");
    t.PostOrder(t.Root());
    printf("\t(post)\n");
    printf("node number: %d\n", t.Size());
    printf("tree depth : %d\n", depth_tree(t.Root()));
    tell_depth_node(t.Root());

    return 0;
}
