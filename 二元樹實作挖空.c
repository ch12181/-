#include <stdlib.h>
#include <stdio.h>

struct node                       /* �𪺵��c�ŧi       */
{
    int data;                      /* �`�I���           */
    struct node *left;             /* ���V���l�𪺫���   */
    struct node *right;            /* ���V�k�l�𪺫���   */
};
typedef struct node treenode;     /* �𪺵��c�s���A     */


/* ---------------------------------------- */
/*�L�X�G�������(�U�Ч�����W��code���n��XD)*/
/* ---------------------------------------- */
int _print_tree(treenode* tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5, i;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

    int left  = _print_tree(tree->left,  1, offset,                depth + 1, s);
    int right = _print_tree(tree->right, 0, offset + left + width, depth + 1, s);
    
#ifdef COMPACT
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else 
    for (i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif
 
    return left + width + right;
}

void print_tree(treenode* root)
{
	int i;
    char s[20][255];
    for (i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_tree(root, 0, 0, 0, s);

    for (i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

/* ---------------------------------------- */
/*  ���J�G���𪺸`�I                        */
/* ---------------------------------------- */
treenode* insert_node(treenode* root,int value)
{
    treenode* newnode;                 /* ��ګ���           */
    treenode* current;                 /* �ثe��`�I����     */
    treenode* parent;                    /* ���`�I����         */
    
    newnode = (treenode*) malloc (sizeof(treenode));
    newnode -> data = value;
    newnode -> right = NULL;
    newnode -> left = NULL;
    
    current = root;
    
    if(root == NULL){
    	
    	root = newnode;
    	
	}else{
		
		while(1){
		
			if(newnode -> data > current -> data){
				
				if(current -> right == NULL){
					
					current -> right = newnode;
					break; 
					
				}else{
					
					current = current -> right;
					
				}
				
			}else{
				
				if(current -> left == NULL){
					
					current -> left = newnode;
					break; 
					
				}else{
					
					current = current -> left;
					
				}
				
			}
			
		}
		
	}
	
	
	return root;
}

/* ---------------------------------------- */
/*  �G����e�Ǩ��X                          */
/* ---------------------------------------- */
void preorder_travel(treenode* ptr)
{
    
    if ( ptr != NULL ){
    	
    	printf("%2d ",ptr->data);
    	preorder_travel(ptr->left);
    	preorder_travel(ptr->right);
    	
	}
    
}

/* ---------------------------------------- */
/*  �G���𤤧Ǩ��X                          */
/* ---------------------------------------- */
void inorder_travel(treenode* ptr)
{
	if ( ptr != NULL )             /* �פ����           */
    {
        inorder_travel(ptr->left);         /* ���l��             */
        printf("%2d ",ptr->data);  /* �C�L�`�I���e     */
        inorder_travel(ptr->right);        /* �k�l��             */
    }
}


/* ---------------------------------------- */
/*  �G�����Ǩ��X                          */
/* ---------------------------------------- */
void postorder_travel(treenode* ptr)
{
	if ( ptr != NULL ){
		
		postorder_travel(ptr->left);
		postorder_travel(ptr->right);
		printf("%2d ",ptr->data);
		
	}
	
}

/* ---------------------------------------- */
/*  �D�{��                                  */
/* ---------------------------------------- */
void main()
{
    /* �G����`�I��� */
    int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
    int i; 
    treenode* root = NULL;             /* ��ګ���           */
    
    for ( i = 0; i < 9; i++ )    /* �ΰj��إ߾𪬵��c */
        root = insert_node(root,data[i]); 
   
    print_tree(root);			/* �L�X�𪬹ϥ���	*/ 
   
    printf("�𪺫e�Ǩ��X����: \n");
    preorder_travel(root);                 /* �e�Ǩ��X�G����     */
    printf("\n�𪺤��Ǩ��X����: \n");
    inorder_travel(root);                 /* ���Ǩ��X�G����     */
	printf("\n�𪺫�Ǩ��X����: \n");
    postorder_travel(root);                 /* ��Ǩ��X�G����     */
}
