#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}* Node;

int leftof(Node root, int data){
    return data < root->data;
}

int rightof(Node root, int data){
    return data > root->data;
}

Node createNode(int data){  
    Node temp = (Node)malloc(sizeof(struct node));
    temp->data = data;
    temp->left =  temp->right = NULL;
    return temp;
}


Node insertNode(Node root, int data){
    if(root == NULL){
        return createNode(data);
    }else{
        if(leftof(root,data)){
            root->left = insertNode(root->left,data);
        }else{
            root->right = insertNode(root->right,data);
        }
        return root;
    }
}

Node inOrder(Node t){ //  như cái tên
    if(t != NULL){
        inOrder(t->left);
        printf("%d ", t->data);
        inOrder(t->right);
    }
}

Node LeftMostTree(Node root){
    if(root->left == NULL) return root;
    while(root->left != NULL){
        return LeftMostTree(root->left);
    }
}

int max (int a, int b){
    return a > b ? a : b;
}

int treeLevel(Node root){
    if(root == NULL) return -1;
    return 1 + max(treeLevel(root->left), treeLevel(root->right));
}

Node maxLeft(Node root){ // lớn nhất ở nhánh bên trái
    Node temp = root;
    while(temp && temp->right){
        temp = temp->right;
    }
    return temp;
}

Node deleteNode(Node root, int data){
    if(root == NULL) return root;
    if(leftof(root, data)){ // 
        root->left = deleteNode(root->left, data);// tìm vị trí bên trái
    }else if(rightof(root,data)){
        root->right = deleteNode(root->right, data); // tìm vị trí bên phải
    }else{ // Đã tìm thấy node
        if(root->left == NULL && root->right == NULL){ // ko có node nào hay bên
            return NULL;
        }else if(root->left == NULL){ // còn một node bên phải
            Node temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){ // còn một node bên trái
            Node temp = root->left;
            free(root);
            return temp;
        }

        Node temp = maxLeft(root->left);
        root->data = temp->data;
        root->left = deleteNode(root->left, temp->data);
    }
    return root;

}





int main(){
    Node root = NULL;
    int n, x, i;
    Node p = root;
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++){
        scanf("%d", &x);
        p = insertNode(p, x);
    }
    inOrder(p);
    printf("nhap gia tri node can xoa "); 
    scanf("%d",&x);
    p = deleteNode(p,x);

    inOrder(p);


}