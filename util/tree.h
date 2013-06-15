#ifndef __TREE_H_20121029
#define __TREE_H_20121029 
#include <iostream>
#include <stack>
#include <queue>
// http://pastebin.com/5QjBnjiS is another tree class, more professional at bst

template <typename T>
class Tree { // deserialize a tree. in fact there is another way by (preOrder || postOrder) && inOrder)
    public:
        struct TreeNode {
            T val;
            TreeNode * left;
            TreeNode * right;
            TreeNode(const T & x) : val(x), left(0), right(0) {}
        };

    public:
        Tree(const T * content, int num, T empty_sign='#'); // escape !!!!!
        ~Tree();

        static void PreOrder (const TreeNode * r);
        static void InOrder  (const TreeNode * r);
        static void PostOrder(const TreeNode * r);

        int Size() const { return num_; }
        TreeNode * Root() const { return root_; }

    private:
        Tree() {}
        Tree(const Tree &) {}
        Tree operator=(const Tree &) {}
    private:
        int num_;
        TreeNode * root_;
};

template <typename T>
Tree<T>::Tree(const T * content, int num, T empty_sign) {
    num_ = 0, root_ = 0;
    if (!content || num == 0)
        return;
    ++num_;
    root_ = new TreeNode(content[0]);
    std::deque<TreeNode *> dq;
    dq.push_front(root_);
    for (int i=1; i<num && dq.size(); ) {
        TreeNode * dqn = dq.back();
        dq.pop_back();

        if (content[i] != empty_sign) {
            dqn->left = new TreeNode(content[i]);
            dq.push_front(dqn->left);
            ++num_;
        }
        ++i;
        if (i<num && content[i] != empty_sign) {
            dqn->right = new TreeNode(content[i]);
            dq.push_front(dqn->right);
            ++num_;
        }
        ++i;
    }
}

template <typename T>
Tree<T>::~Tree() { // morris travs
    for (TreeNode *c=root_; c; ) {
        TreeNode *pre = c->left;
        if (!pre) {
            pre = c;
            c = c->right;
            delete pre;
            continue;
        }

        while (pre->right && pre->right != c)  
            pre = pre->right; 
        if (!pre->right) { // Make current as right child of its inorder pre
            pre->right = c;
            c = c->left;
        } else { 
            pre->right = 0; // consider the reason for NULL kindly
            pre = c;
            c = c->right;
            delete pre;
        }
    }
    root_ = 0, num_ = 0;
}

template <typename T>
void Tree<T>::PreOrder(const TreeNode * r) {
    bool ed=true;
    std::stack<const TreeNode *> s;
    if (r) s.push(r);
    while (!s.empty()) {
        const TreeNode * t = s.top();
        s.pop();
        ed?(std::cout << t->val, ed=false):(std::cout << ", " << t->val);
        if (t->right) s.push(t->right);
        if (t->left)  s.push(t->left);
    }
}

template <typename T>
void Tree<T>::InOrder(const TreeNode * r) {
    bool ed=true;
    std::stack<const TreeNode *> s;
    while (r || !s.empty()) {
        if (r) {
            s.push(r);
            r = r->left;
        } else {
            r = s.top();
            s.pop();
            ed?(std::cout << r->val, ed=false):(std::cout << ", " << r->val);
            r = r->right;
        }
    }
}

template <typename T>
void Tree<T>::PostOrder(const TreeNode * r) {
    bool ed=true;
    std::stack<const TreeNode *> s, o;
    if (r) s.push(r);
    while (!s.empty()) {
        const TreeNode * t = s.top();
        s.pop(), o.push(t);
        if (t->left)  s.push(t->left);
        if (t->right) s.push(t->right);
    }

    while (!o.empty()) {
        ed?(std::cout << o.top()->val, ed=false):(std::cout << ", " << o.top()->val);
        o.pop();
    }
}
#endif

