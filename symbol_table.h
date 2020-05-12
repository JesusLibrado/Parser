#include <stdlib.h>
#include <string.h>

struct node {
    float value;
    int type; // int:1 | float:2
    char *identifier;
    struct node *next;
} typedef Symbol;

void print_table(struct node *head){
    if(head == NULL) {
        printf("null\n");
    } else {
        if(head->type == 1){
            printf("%s: int ", head->identifier);
            if(head->value)
                printf(" = %d ", (int)head->value);
        }else {
            printf("%s: float ", head->identifier);
            if(head->value)
                printf(" = %.2f ", head->value);
        }
        printf("-> ");
        print_table(head->next);
    }
    
}

struct node * find(struct node *head, char id[20]) {
    if(head == NULL) return NULL;
    if(strcmp(head->identifier, id) == 0) return head;
    return find(head->next, id);
}

float get_value(struct node *head, char id[20]) {
    struct node *p = find(head, id);
    if(!p){
        printf("Declaration error!: %s was not declared\n", id);
    }
    return p->value;
}

int get_type(struct node *head, char *id) {
    struct node *p = find(head, id);
    if(!p){
        printf("Declaration error!: %s was not declared\n", id);
        return 0; // doesn't exist
    }
    return p->type;
}

void declare_var(struct node **head_ref, char id[20], int var_type) {
    struct node * new_symbol = (struct node *)malloc(sizeof(struct node));

    new_symbol->identifier = id;
    new_symbol->type = var_type;
    new_symbol->next = (*head_ref);

    (*head_ref) = new_symbol;
}

void assign_value(struct node *head_ref, char id[20], float value) {
    struct node *p = find(head_ref, id);
    if(!p){
        printf("Declaration error!: %s was not declared\n", id);
        return;
    }
    p->value = value;
}  


void read_user_input(struct node *head, char *id){
    float var_float;
    printf("Enter %s: ", id);
    scanf("%f", &var_float);
    assign_value(head, id, var_float);
    printf("\n");
}

// void free_table(){
//     while(head != NULL){
//         free(head);
//         head = head->next;
//     }
// }
