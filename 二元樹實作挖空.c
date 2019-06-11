#include <stdlib.h>
#include <stdio.h>

struct node                       /* 樹的結構宣告       */
{
    int data;                      /* 節點資料           */
    struct node *left;             /* 指向左子樹的指標   */
    struct node *right;            /* 指向右子樹的指標   */
};
typedef struct node treenode;     /* 樹的結構新型態     */


/* ---------------------------------------- */
/*印出二元樹全貌(助教改網路上的code不要問XD)*/
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
/*  插入二元樹的節點                        */
/* ---------------------------------------- */
treenode* insert_node(treenode* root,int value)
{
    treenode* newnode;                 /* 樹根指標           */
    treenode* current;                 /* 目前樹節點指標     */
    treenode* parent;                    /* 父節點指標         */
    
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
/*  二元樹前序走訪                          */
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
/*  二元樹中序走訪                          */
/* ---------------------------------------- */
void inorder_travel(treenode* ptr)
{
	if ( ptr != NULL )             /* 終止條件           */
    {
        inorder_travel(ptr->left);         /* 左子樹             */
        printf("%2d ",ptr->data);  /* 列印節點內容     */
        inorder_travel(ptr->right);        /* 右子樹             */
    }
}


/* ---------------------------------------- */
/*  二元樹後序走訪                          */
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
/*  主程式                                  */
/* ---------------------------------------- */
void main()
{
    /* 二元樹節點資料 */
    int data[9] = { 5, 6, 4, 8, 2, 3, 7, 1, 9 };
    int i; 
    treenode* root = NULL;             /* 樹根指標           */
    
    for ( i = 0; i < 9; i++ )    /* 用迴圈建立樹狀結構 */
        root = insert_node(root,data[i]); 
   
    print_tree(root);			/* 印出樹狀圖全貌	*/ 
   
    printf("樹的前序走訪順序: \n");
    preorder_travel(root);                 /* 前序走訪二元樹     */
    printf("\n樹的中序走訪順序: \n");
    inorder_travel(root);                 /* 中序走訪二元樹     */
	printf("\n樹的後序走訪順序: \n");
    postorder_travel(root);                 /* 後序走訪二元樹     */
}
