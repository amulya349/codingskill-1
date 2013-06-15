/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 给一个N个节点的二叉搜索树（BST/Binary Search Tree）
 * 给一个Key，返回与key最接近的m个节点（m<N）
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include "../util/tree.h"
#include "../util/io.h"
using namespace std;

typedef Tree<int>::TreeNode TreeNode;
class NearestOfBST {
    public :
        vector<int> getNearests(const TreeNode * tree, int key, int m) {
            vector<int> res;
            if (!tree || m <= 0) return res;

            stack<const TreeNode *> parentsPre;
            int nearest = getTheNearestVal(tree, key, parentsPre);
            stack<const TreeNode *> parentsSuc  = parentsPre;

            vector<int> successors   = getSuccessors(parentsSuc, m);
            vector<int> predecessors = getPredecessors(parentsPre, m);

            fillNearest(res, m, nearest, key, predecessors, successors);
            return res;
        }

    private:
        /*{{{ fillNearest() picking the smallest(the distance to key) $m numbers 
         * from two sorted arrays (one of them is reversed)*/
        void fillNearest(vector<int> & rres, size_t m, int nearest, int key, \
                const vector<int> & predecessors, const vector<int> & successors) {
            rres.push_back(nearest);
            size_t s, p, c;
            for (s=p=c=0; c<m-1 && (s<successors.size() || p<predecessors.size()); ++c) {
                if (s >= successors.size()) {
                    rres.push_back(predecessors[p++]);
                }
                else if (p >= predecessors.size()) {
                    rres.push_back(successors[s++]);
                }
                else
                {
                    if (key-predecessors[p] < successors[s]-key)
                        rres.push_back(predecessors[p++]);
                    else
                        rres.push_back(successors[s++]);
                }
            }
        }
        /*}}}*/

        /*{{{ getTheNearestVal() finds the nearest value and parents on the path*/
        int getTheNearestVal(const TreeNode * t, int k, \
                stack<const TreeNode *> & rparents) {
            while (t) { // root -> leaf, colletcing path 
                rparents.push(t);
                if      (t->val == k) return k;
                else if (t->val >  k) t = t->left;
                else                  t = t->right;
            } // nearest check over

            t = rparents.top();
            rparents.pop();
            int min_d = distance(t->val, k);
            while (rparents.size()){  // get the nearest's distance
                t = rparents.top();
                rparents.pop();
                int d = distance(t->val, k);
                if (min_d > d) min_d = d;
            }

            while (t) { // top -> min_d, colletcing parents
                rparents.push(t);
                if (distance(t->val,  k) == min_d) break;
                else if     (t->val > k)           t = t->left;
                else                               t = t->right;
            } // nearest check over
            return t->val;
        }
        /*}}}*/

        /*{{{ getPredecessors() get $m predecessors */
        vector<int> getPredecessors(stack<const TreeNode *> & parents, int m) {
            vector<int> predecessors;
            const TreeNode * pivot;
            while (m-- > 0) {
                if (!parents.size()) break;
                pivot = parents.top();
                if (pivot->left) { // turn to left 
                    pivot = pivot->left;
                    parents.push(pivot);
                    int mostright = pivot->val;
                    while ((pivot=pivot->right)) {
                        mostright = pivot->val;
                        parents.push(pivot);
                    }
                    predecessors.push_back(mostright);
                }
                else {
                    const TreeNode * directparent;
                    while (parents.size()) {
                        parents.pop();

                        if (!parents.size()) break;
                        directparent = parents.top();
                        if (directparent->right == pivot) {
                            predecessors.push_back(directparent->val);
                            break;
                        }
                        pivot = directparent;
                    }
                }
            }
            return predecessors;
        }
        /*}}}*/

        /*{{{ getSuccessors() get $m successors */
        vector<int> getSuccessors(stack<const TreeNode *> & parents, int m) {
            vector<int> successors;
            const TreeNode * pivot;
            while (m-- > 0) {
                if (!parents.size()) break;
                pivot = parents.top();
                if (pivot->right) { // turn to right
                    pivot = parents.top();
                    pivot = pivot->right;
                    parents.push(pivot);
                    int mostleft = pivot->val;
                    while ((pivot=pivot->left)) {
                        mostleft = pivot->val;
                        parents.push(pivot);
                    }
                    successors.push_back(mostleft);
                }
                else {
                    const TreeNode * directparent;
                    while (parents.size()) {
                        parents.pop();

                        if (!parents.size()) break;
                        directparent = parents.top();
                        if (directparent->left == pivot) {
                            successors.push_back(directparent->val);
                            break;
                        }
                        pivot = directparent;
                    }
                }
            }
            return successors;
        }
        /*}}}*/

        int distance(int a, int b) { return a > b ? a-b : b-a; }
};

void test_imp(const TreeNode * root, int key, int m) {
    static NearestOfBST near;
    vector<int> res = near.getNearests(root, key, m);
    printf("%d +- %d: ", key, m);
    UIO<int>::pr(res);
}

int main(int argc, char * argv[]) {
    int A[] = {10, 3, 12, 2, 6, 11, 13, '#', '#', \
        5, 9, '#', '#', '#', '#', '#', '#', 8, '#'};
    Tree<int> tree(A, sizeof(A)/sizeof(A[0]));
    Tree<int>::InOrder(tree.Root());
    printf("<InOrder>\n");

    test_imp(tree.Root(), 6, 5);
    test_imp(tree.Root(), 2, 5);
    test_imp(tree.Root(), 13, 5);
    test_imp(tree.Root(), 7, 200);
    test_imp(tree.Root(), 2, 0);
    test_imp(tree.Root(), 2, 1);
    test_imp(tree.Root(), 2000, 2);

    return 0;
}
