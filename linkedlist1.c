#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t *next;

}Node;

Node *head = NULL;
Node *tail = NULL;
Node *current = NULL;

void print_list(Node *node){
    while(node != NULL){

        printf("%d", node->data);
        if(node->next == NULL){
            printf(" --I");
        }
        else{
            printf(" -> ");
        }
        node = node->next;
    }
    printf("\n");

}

// push end (lägg till ny nod)      check
//pop end ta bort sista noden       check
//push head                         check
//pop head                          check
//push at (lägg till någon som tex 3e element)
// pop at (ta bort spec element)
// pop value (hitta första förekommande grej med detta value och ta bort det)
//Alla pop ska returnera datat i den poppade nnoden

//Gör om listan till en dubbellänkad lista



void push_head(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
        tail = head;
    }
    else{
        new_node->next = head;
        head = new_node;
    }
}


void push_at(int data, int index){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    int cnt = 0;
    if(head != NULL){
        current = head;
        if(index == 0){
            push_head(data);
        }
        else{
            if(index == 1){
                current = head;
                new_node->next = current->next;
                head->next = new_node;
                current = NULL;
            }
            else{
                while(cnt < index-1 && current->next->next != NULL){    //index > befintlig
                    current = current->next;
                    cnt++;
                    printf("cnt: %d:%d >>> ", cnt, current->data);
                    new_node->next = current->next;
                    current->next = new_node;
                    current = NULL;
                }
                if(index > cnt+1){
                    printf("doh");
                }
            }
        }
    }
}

void pop_at(int index){
    int cnt = 1;
    if(index == 0){
        pop_head();
    }
    else{
        current = head;             //0
        current = current->next;    //1

        
            if(index == cnt){           
                if(tail == current){
                    pop_tail();
                }
                else{
                    
                    //ta bort aktuell plats
                }
                
            }
        
    }
}


void pop_head(){
    int data = 0;
    if(head != NULL){
        if(head->next != NULL){
            current = head;
            head = head->next;
            data = current->data;
            current = NULL;
        }
        else{
            data = head->data;
            head = NULL;
            tail = NULL;
        }
        printf("\n\n >>> Head borttagen. Raderat v%crde: %d \n\n", 132, data);
    }
    else{
        printf("\n\n >>> Listan %cr tom, finns inget att ta bort! \n\n", 132);
    }
}


void push_tail(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
        tail = head;
    }
    else{
        if(head->next == NULL){
            head->next = new_node;
            tail = new_node;
        }
        else{
            current = head->next;
            while(current->next != NULL){
                current = current->next;
            }
            tail = new_node;
            current->next = tail;
            current = NULL;
        }
    }
}


void pop_tail(){
    int count = 0;
    if(head == NULL){
        printf("\n\n >>> Listan %cr tom, finns inget att ta bort! \n\n", 132);
    }
    else{
        if(head == tail){
            printf("Data i head: %d\n", head->data);
            free(head);
            head = NULL;
            tail = NULL;
        }else{
            current = head;
            while(current->next != tail){
                current = current->next;
            }
            free(tail);
            current->next = NULL;
            tail = current;
            current = NULL;
        }
    }
}


int main(){
    int infinity = NULL;
    int input = 0;
    while(!infinity){
        printf("\n\n1. Printa listan\n");
        printf("2. L%cgg till en post sist i listan\n", 132);
        printf("3. Ta bort sista posten ur listan\n");
        printf("4. L%cgg till en post f%crst i listan\n", 132, 148);
        printf("5. Ta bort f%crsta posten ur listan\n", 148);
        printf("6. L%cgg till en post p%c angivet index\n", 132, 134);
        printf("9. Exit\n"); 
        scanf("%d", &input);

        if (input == 1){
            input = 0;
            if(head != NULL){
                print_list(head);
            }
            else{
                printf("\n\n >>> Finns inget i listan\n\n");
            }
        }
        if(input == 2){
            input = 0;
            int new_data;
            printf("Vilket tal vill du l%cgga till i listan?\n", 132);
            scanf("%d", &new_data);
            push_tail(new_data);
        }
        if(input == 3){
            input = 0;
            pop_tail();
        }
        if(input == 4){
            input = 0;
            int new_data;
            printf("Vilket tal vill du l%cgga till i listan?\n", 132);
            scanf("%d", &new_data);
            push_head(new_data);
        }
        if(input == 5){
            input = 0;
            pop_head();
        }
        if(input == 6){
            int data = 0;
            int index = 0;
            input = 0;
            printf("Vilket tal vill du l%cgga till i listan?\n", 132);
            scanf("%d", &data);
            printf("P%c vilken position vill du l%cgga talet i listan? (0-indexerad)\n", 134, 132);
            scanf("%d", &index);
            push_at(data, index);
        }
        if(input == 9){
            exit(0);
        }
    }



    /*head = (Node *)malloc(sizeof(Node));
    head->data = 10; //betyder samma som (*head).data
    head->next = NULL;
    tail = head;

    current = (Node *)malloc(sizeof(Node));
    current->data = 11; 
    current->next = NULL;

    head->next = current;
    tail = current;
    print_list(head);

    current = head;
    while(head != NULL){
        head = head->next;
        free(current);
        current = head;
    }
    tail = NULL; 
    if(head = NULL) {
        printf("this is empty\n");
    }*/
    return 0;
}
