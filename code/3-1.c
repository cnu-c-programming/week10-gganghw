#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct A{
    char name[20];
    int score;
    struct A* next;
};

struct A* head = NULL;

void add(char* n , int s){
    struct A* p = (struct A*)malloc(sizeof(struct A));
    strcpy(p->name, n);
    p->score = s;
    p->next = NULL;

    if (head == NULL){
        head = p;
    }else{
        struct A* now = head;
        while (now->next != NULL) {
            now = now->next;
        }
        now->next = p;
    }
}

void delete(char* n){
    struct A* now = head;
    struct A* prev = NULL;
    while (now != NULL) {
    if (strcmp(now->name, n) == 0) {
        if(prev == NULL){
            head = now->next;
        }else{
            prev->next = now->next;
        }
        free(now);
        break;
    }
    prev = now;
    now = now ->next;
    }
}

void print(){
    for (struct A* current = head; current != NULL; current = current->next) {
        printf("%s %d\n", current->name, current->score);
    }
}

int main(){
    char c[20];
    char n[20];
    int s;

    while(1) {
        scanf("%s", c);

        if (strcmp(c, "add") == 0) {
            scanf("%s %d", n, &s);
            add(n, s); 
        } 
        else if (strcmp(c, "delete") == 0) {
            scanf("%s", n);
            delete(n);
        }
        else if (strcmp(c, "print") == 0) {
            print(); 
        } 
        else if (strcmp(c, "quit") == 0) {
            break; 
        }
    }
}
