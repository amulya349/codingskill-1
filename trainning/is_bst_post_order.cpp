/*{{{+++++++++++++++++++++++ <Description> ++++++++++++++++++++++++++
 * 给一个数组，判定是否可能是一个BST后序遍历得到的
 *
 * naive做法是O(NlogN)，下边收藏的是O(N)做法(对原注释有修改，适合自己理解)
 *
 * 发信人: longway2008 (longway2008)
 * 从末尾向前扫描，试图建立一棵BST（不一定要真正建立树结构）
 * 
 * 节点A[idx]是当前子树的根，同时也维护当前子树的合法数值范围[min_val, max_val].
 * 右子树的数值范围就是[A[idx], max_val]; 左子树范围[min_val, A[idx]]  
 *
 * 1 数组从尾向头，根据>A[idx]决定将结点入右子树。直到不满足返回失败下标
 * 2 上一步的返回，从它开始向数组头判定入左子树。返回最后失败的结点
 * 这样, 最多一遍扫描数组, 判定最后返回的(失败)下标是否合法
 * -------------------------------------------------------------}}}*/
#include <stdio.h>
#include <limits.h>

int scanPostOrder(int *A, int idx, int min, int max) {
    if (idx<0 || A[idx]<min || A[idx]>max) return idx; 

    int val = A[idx];
    idx  = scanPostOrder(A, idx-1, val, max); // 右子树
    return scanPostOrder(A, idx,   min, val); // 左子树
}

bool checkPostOrder(int *A, int n) {
    return scanPostOrder(A, n-1, INT_MIN, INT_MAX) < 0;
}

void honglei(int A[], int n) {
    for (int i=0; i<n; ++i)
        printf("%d, ", A[i]);
    printf("\n");
    if (checkPostOrder(A, n))
        printf("yes!\n");
    else
        printf("nop!\n");
}

int main(int argc, char * argv[]) {
    int A1[] = {1,2,4,5,3};
    honglei(A1, sizeof(A1)/sizeof(A1[0]));
    int A2[] = {2,4,1,3};
    honglei(A2, sizeof(A2)/sizeof(A2[0]));
    return 0;
}
