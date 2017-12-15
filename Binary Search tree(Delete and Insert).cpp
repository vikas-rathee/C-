#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node* insertNode(node *root,int data)
{
    node *ptr=root;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=data;
    if(!root)
    {
        root=newnode;
    }
    else
    {
        while(ptr)
        {
            if(ptr->data>data)
            {
                if(ptr->left==NULL)
                    {ptr->left=newnode;break;}
                ptr=ptr->left;
            }
            else if(ptr->data<data)
            {
                if(ptr->right==NULL)
                {
                    ptr->right=newnode;
                    break;
                }
                ptr=ptr->right;
            }
        }
    }
    return(root);
}

node* findMax(node *root)
{
    if(!root)
        return NULL;
    else
    {
        while(root->right)
            root=root->right;
        return(root);
    }
}

node* deleteNode(node* root,int data)
{
    if(!root)
        return NULL;
    else if(root->data>data)
        root->left=deleteNode(root->left,data);
    else if(root->data<data)
        root->right=deleteNode(root->right,data);
    else
    {
        node *ptr=root;
        if(ptr->left && ptr->right)
        {
            ptr=findMax(ptr->left);
            root->data=ptr->data;
            root->left=deleteNode(root->left,root->data);
        }
        else
        {
            if(root->left==NULL)
                root=root->right;
            else
                root=root->left;
            free(ptr);
        }
    }
    return(root);
}
void Inorder(node *root)
{
    if(!root)
        return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main()
{
    node *root=NULL;
    int choice;
    while(1)
    {
        cout<<"1. Insert Node\n";
        cout<<"2. Delete Node\n";
        cout<<"3. Inorder Traversal\n";
        cout<<"4. Exit\n";
        cout<<"Enter your Choice:\t";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
                int data;
                cout<<"Enter data:\t";
                cin>>data;
                root=insertNode(root,data);
                break;
            }
        case 2:
            {
                int data;
                cout<<"Enter Data:\n";
                cin>>data;
                root=deleteNode(root,data);
                break;
            }
        case 3:
            {
                Inorder(root);
                cout<<endl;
                break;
            }
        case 4:
            {
                exit(0);
            }
        default:
            {
                cout<<"Invalid choice\n";
            }
        }
        cout<<"Press any key to Continue...";
        getch();
        system("cls");
    }

}
