#include<stdio.h>
#include<stdlib.h>

typedef struct link {
    int coeff;
    int pow;
    struct link * next;
} poly;

void create_poly(poly **);
void show_poly(poly *);
void add_poly(poly **, poly *, poly *);

int main() {
    
    poly * poly1, * poly2, * poly3;
    printf("\nCreate 1st polynomial\n");
    create_poly(&poly1);
    
    show_poly(poly1);
    printf("\n\nCreate 2nd polynomial\n");
    create_poly(&poly2);
    
    show_poly(poly2);
    add_poly(&poly3, poly1, poly2);
    printf("\n\nAdding results:\n");
    show_poly(poly3);
    
    return 0;
}

/*
	輸入多項式 
*/
void create_poly(poly ** node) {
	
    int coeff, pow;
    poly * tmp_node; 
    tmp_node = (poly *) malloc(sizeof(poly)); 
    *node = tmp_node; 
    do {
        
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        tmp_node->pow = pow;
        
        tmp_node->next = NULL;
        
        if(coeff != 0 && pow != 0) {
            tmp_node->next = (poly *) malloc(sizeof(poly)); 
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (coeff != 0 && pow != 0);
}


/*
	印出多項式 
*/ 
void show_poly(poly * node) {
    printf("\nThe polynomial is:\n");
    while(node != NULL) {
    	if(node->pow == 0){
    		printf("%d", node->coeff);
		}else{
			printf("%dx^%d", node->coeff, node->pow);
		}
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}

/*
	多項式相加 
*/ 

void add_poly(poly ** result, poly * poly1, poly * poly2) {
    poly * tmp_node; 
    tmp_node = (poly *) malloc(sizeof(poly));
    tmp_node->next = NULL;
    *result = tmp_node;
    
    while(poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
 
        
        if(poly1 && poly2) {
            tmp_node->next = (poly *) malloc(sizeof(poly));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
    
    while(poly1 || poly2) {
        
        tmp_node->next = (poly *) malloc(sizeof(poly));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
 
        if(poly1) {
            tmp_node->pow = poly1->pow;
            tmp_node->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            tmp_node->pow = poly2->pow;
            tmp_node->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }
}
