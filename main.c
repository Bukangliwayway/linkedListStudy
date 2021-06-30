#include<stdlib.h>
#include<stdio.h>

struct list{
    int x;
    struct list *next;
};

struct list *head, *curr, *tail;
void createList();
void displayList();
void sortList();
void searchList();
int main(){
    char choice;
    head=tail=curr=NULL;
    system("cls");
    do{
        while(1){
            printf("\tMAIN MENU\n\na. Create Linear Linked List\nb. Display a Linear Linked List\n");
            printf("c. Sort a Linear Linked List - Ascending\nd. Search a Number\ne. Exit\n");
            printf("Enter Choice: ");
            scanf(" %c", &choice);
            if(choice < 'a' || choice >= 'e') break; // Invalid if greater than 'e', exit if equals 'e'
            if(head != NULL || choice == 'a') break; // Loop when there's no List and "Create" is not selected
            system("cls");
            printf("Create a List First!\n\n");
        }
        switch(choice){
            default:
                system("cls");
                printf("Invalid Input!\n\n");
                break;
            case 'a':
                createList();
                system("cls");
                break;
            case 'b':
                displayList();
                break;
            case 'c':
                sortList();
                break;
            case 'd':
                searchList();
                break;
            case 'e':
                system("cls");
                printf("\nThank You for using our link system!");
        }
    }while(choice != 'e');
    return 0;
}
void createList(){
    system("cls");
    head=tail=curr=NULL; //Create Another List
    printf("\tCreate List:\n\n");
    while(1){
        curr = (struct list *) malloc(sizeof(struct list));
        printf("Enter any Number other than 0 to continue: ");
        scanf("%d", &curr->x);
        if(curr->x == 0) break;
        if(head == NULL){
            head = curr;
            tail = curr;
            tail->next = NULL;
        }else{
            tail->next = curr;
            tail = curr;
            tail->next = NULL;
        }
    }
}
void displayList(){
    system("cls");
    curr = head;
    printf("\nHere are the datas in the list: \n");
    while(curr!=NULL){
        printf("%5d", curr->x);
        curr = curr->next;
    }
    printf("\n\n");
}
void sortList(){
    tail = curr = head;
    do{
       while(tail->next != NULL){
            tail = tail->next;
            if(curr->x > tail->x){
                curr->x += tail->x;
                tail->x = curr->x - tail->x;
                curr->x -= tail->x;
            }
        }
        tail = curr->next;
        curr = tail;
    }while(curr != NULL);
        displayList();
}
void searchList(){
    int search;
    char choice;
    do{
        system("cls");
        curr = head;
        printf("Enter the Number to Search: ");
        scanf("%d", &search);
        while(curr != NULL){
            if(search == curr->x){
                printf("%d is in the list\n", search);
                break;
            }
            curr = curr->next;
        }
        if(curr == NULL) printf("\n%d is not in the list\n", search);
        while(1){
            printf("\n\nRepeat Process? Y/N: ");
            scanf(" %c", &choice);
            if(choice == 'n' || choice == 'N' || choice == 'y' || choice == 'Y') break;
            system("cls");
            printf("Invalid Input!\n\n");
        }
    }while(choice == 'y' || choice == 'Y');
    system("cls");
}