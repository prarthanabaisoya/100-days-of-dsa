#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}


struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    struct TreeNode* root = newNode(arr[0]);
    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct TreeNode* curr = queue[front++];

        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[rear++] = curr->left;
            }
            i++;
        }
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[rear++] = curr->right;
            }
            i++;
        }
    }
    return root;
}


void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}


void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);

    inorder(root);   printf("\n");
    preorder(root);  printf("\n");
    postorder(root); printf("\n");

    return 0;
}