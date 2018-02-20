#include<stdio.h>
#include<string>
#include<cmath>
using namespace std;

int k, n;
const int maxk = 31;
int pre[maxk], in[maxk];
struct node {
    int lnum, rnum;
    int v;
    node *left, *right;
};

void create(node* &root, int v) {
    if(root==NULL) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->v = v;
        return;
    }
    if(abs(root->v) > abs(v)) {
        create(root->left, v);
    } else {
        create(root->right, v);
    }
}

bool isSearch = true;
int preNum = -1;

void judgeSearch(node* root) {
    if(root==NULL || !isSearch) {
        return;
    }
    judgeSearch(root->left);
    if(abs(root->v) < preNum) {
        isSearch = false;
        return;
    } else {
        preNum = abs(root->v);
    }
    judgeSearch(root->right);
}

bool isBalance = true;

int getNum(node *root) {
    if (root == NULL) return 0;
    root->lnum = getNum(root->left);
    root->rnum = getNum(root->right);
    return root->v > 0 ? max(root->lnum, root->rnum) + 1 : max(root->lnum, root->rnum);
}

bool judgeBalance(node *root) {
    if (root == NULL) return true;
    if(root->lnum != root->rnum) return false;
    return judgeBalance(root->left) && judgeBalance(root->right);
}

bool redAndBlack(node* root) {
    if (root == NULL) return true;
    if (root->v < 0) {
        if (root->left != NULL && root->left->v < 0) return false;
        if (root->right != NULL && root->right->v < 0) return false;
    }
    return redAndBlack(root->left) && redAndBlack(root->right);
}

int main() {
    scanf("%d", &k);
    int i, j;
    for(i=0;i<k;i++) {
        isSearch = true;
        preNum = -1;
        node *root = NULL;
        scanf("%d", &n);
        for(j=0;j<n;j++) {
            scanf("%d", &pre[j]);
            create(root, pre[j]);
        }
        if(root->v<0) {
            printf("No\n");
            continue;
        }
        judgeSearch(root);
        if(!isSearch) {
            printf("No\n");
            continue;
        }
        getNum(root);
        if(!judgeBalance(root)) {
            printf("No\n");
            continue;
        }
        if(!redAndBlack(root)) {
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}
