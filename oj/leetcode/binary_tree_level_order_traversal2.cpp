/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * Given a binary tree, return the bottom-up level order traversal of its \
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *      3
 *     / \
 *    9  20
 *      /  \
 *     15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7]
 *   [9,20],
 *   [3],
 * ]
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <vector>
#include <string.h>
#include "../../util/tree.h"
#include "../../util/io.h"
using namespace std;

class Solution {
    private:
        typedef Tree<int>::TreeNode TreeNode;
    public:
        /* 发信人: ihasleetcode (1337coder)
         * 我贡献一个 Depth-first 递归的解法。
         * 这里注意 ret 是vector, insert() 复杂度是linear to ret.size().
         * 可以改用 double-ended queue 来优化，最后转换回 vector 就好了.
         * */
        /*{{{ 递归方法, elegant!!! */
        vector<vector<int> > levelOrderBottom_rcus(const TreeNode * root) {
            vector<vector<int> > ret;
            levelOrderBottom_rec_imp(root, 0, ret);
            return std::move(ret);
        }
        void levelOrderBottom_rec_imp(const TreeNode * p, size_t level, vector<vector<int> > &ret) {
            if (!p) return;
            if (ret.size() <= level) 
                ret.insert(ret.begin(), vector<int>()); // 这里是应题意倒转输出
            levelOrderBottom_rec_imp(p->left,  level+1, ret);
            levelOrderBottom_rec_imp(p->right, level+1, ret);
            ret[ret.size()-level-1].push_back(p->val);  // 在最后，因为先要确定size()
        }
        /*}}}*/

    public:  
        /*{{{ 迭代方法*/
        vector<vector<int> > levelOrderBottom_iter(const TreeNode *root) {
            vector<vector<int> > res;
            if (!root) 
                return std::move(res);
            vector<const TreeNode *> levs;
            vector<int> lev_begin;
            levs.push_back(root);
            int node_curse(0), levs_upper_num(1);

            while (levs_upper_num) {
                int counter = 0;
                const TreeNode * n(NULL);
                lev_begin.push_back(node_curse);
                for (int i=0; i<levs_upper_num; ++i) {
                    n = levs[node_curse++];
                    if (n->left) {
                        levs.push_back(n->left);
                        ++counter;
                    }
                    if (n->right) {
                        levs.push_back(n->right);
                        ++counter;
                    }
                }
                levs_upper_num = counter;
            }

            make_res(res, levs, lev_begin);
            return std::move(res);
        }

    private:
        void make_res(vector<vector<int> > &res, \
                const vector<const TreeNode *> & levs, \
                const vector<int> & lev_begin) {
            int tree_lev_end = levs.size(); 
            for (int bottom=lev_begin.size()-1; bottom>=0; --bottom) {
                vector<int> tmp;
                for (int i=lev_begin[bottom]; i<tree_lev_end; ++i) 
                    tmp.push_back(levs[i]->val);

                res.push_back(tmp);
                tree_lev_end = lev_begin[bottom];
            }
        }
        /*}}}*/
};

int main(int argc, char * argv[]) {
    int A[] = {3, 9, 20, '#', '#', 15, 7};
    Tree<int> t(A, sizeof(A)/sizeof(A[0]));
    
    static Solution solve;
    vector<vector<int> >res = solve.levelOrderBottom_rcus(t.Root());
    UIO<int>::pr(res);
    return 0;
}
