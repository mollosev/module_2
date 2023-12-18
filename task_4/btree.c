#include "task_4.h"

void insBtree(phoneBook val, btree **q) {
    if(*q == NULL) {
        *q = malloc(sizeof(btree));
        (*q)->left = (*q)->right = NULL;
        (*q)->profile = val;
        return;
    }
    if((*q)->profile.id > val.id)
        insBtree(val, &(*q)->left);
    else
        insBtree(val, &(*q)->right);
}

void printBtree(btree *p) {
    if(p == NULL) {
        return;
    }
    printBtree(p->left);
    printProfile(p->profile);
    printBtree(p->right);
}

int delete(int key, btree **node) {
    btree *t, *up;
    if(*node == NULL) return 0;
    if((*node)->profile.id == key) {
        if(((*node)->left == NULL) && ((*node)->right == NULL)) {
            free(*node);
            *node = NULL;
            printw("Delete list\n");
            return 1;
        }
        if((*node)->left == NULL) {
            t = *node;
            *node = (*node)->right;
            free(t);
            printw("Delete left = 0\n");
            return 1;
        }
        if((*node)->right == NULL) {
            t = *node;
            *node = (*node)->left;
            free(t);
            printw("Delete right = 0\n");
            return 1;
        }
        up = *node;
        t = (*node)->left;
        while(t->right != NULL) {
            up = t;
            t = t->right;
        }
        (*node)->profile = t->profile;
        if(up != (*node)) {
            if(t->left != NULL) up->right = t->left;
            else up->right = NULL;
        }
        else (*node)->left = t->left;
        free(t);
        printw("Delete two\n");
        return 1;
    }
    if((*node)->profile.id < key)
        return delete(key, &(*node)->right);
    return delete(key, &(*node)->left);
}

int editBtree(btree **p, int id) {
    if(*p == NULL) {
        printw("ID=%d not found\n", id);
        return 0;
    }
    if((*p)->profile.id == id) {
        editProfileBtree(p);
        return 1;
    }
    if((*p)->profile.id > id)
        return editBtree(&(*p)->left, id);
    else return editBtree(&(*p)->right, id);
}
