#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>
#include "abb.h"
#include "queue.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
    unsigned int len;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    // return true;
    if (tree == NULL) {
        return false;
    }
    if (tree->left != NULL && tree->left->elem >= tree->elem) {
        return false;
    }
    if (tree->right != NULL && tree->right->elem <= tree->elem) {
        return false;
    }
    return true;
}


abb abb_empty(void) {
    abb tree;
    tree = malloc(sizeof(struct _s_abb));
    assert(tree != NULL);
    tree->len = 0;
    tree->right = NULL;
    tree->left = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

unsigned int element_len(abb_elem e){
    unsigned int count = 1u;
    if (e<0){
        e = -e;
    }
    while (e / 10 >= 1){
        e /= 10;
        count ++;
    }
    return count;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (tree->len == 0){
        tree->elem = e;
    } else{
        if (elem_less(e, tree->elem)){
            if (tree->left == NULL){
                tree->left = abb_empty();
            }
            abb_add(tree->left, e);
        } else {
            if (tree->right == NULL){
                tree->right = abb_empty();
            }
            abb_add(tree->right, e);
        }
    }
    // tree->len += element_len(e);
    tree->len ++;
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return (tree->len == 0);
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree->len!=0){
        if (elem_eq(tree->elem, e)) return true;

        if (elem_less(e, tree->elem)){
            if (tree->left != NULL){
                return abb_exists(tree->left, e);
            } else {
                return false;
            }
        } else {
            if (tree->right != NULL){
                return abb_exists(tree->right, e);
            } else {
                return false;
            }
        }
    }

    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (tree->len!=0){
        length ++;
        if (tree->left != NULL){
            length += abb_length(tree->left);
        }
        if (tree->right != NULL){
            length += abb_length(tree->right);
        }
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

void add_tree(abb tree, abb dump){
    assert(invrep(tree) && invrep(dump));
    if (dump->len>0){
        abb_add(tree, dump->elem);
        if (tree->left != NULL){
            add_tree(tree, dump->left);   
        }
        if (tree->right != NULL){
            add_tree(tree, dump->right);   
        }
    }
}

bool abb_remove(abb tree, abb_elem e) {
    bool exists = false;
    assert(invrep(tree));
    if (tree->len!=0){
        if (elem_eq(tree->elem, e)){
            if (tree->right == NULL && tree->left == NULL){
                abb_destroy(tree);
                tree = NULL;
            } else if (tree->right == NULL && tree->left != NULL){
                tree->elem = tree->left->elem;
                tree->left = tree->left->left;
            } else if (tree->left == NULL && tree->right != NULL){
                tree->elem = tree->right->elem;
                tree->right = tree->right->right;
            } else {
                tree->elem = tree->right->elem;
                add_tree(tree->left, tree->right->left);
                tree->right->left = abb_destroy(tree->right->left);
            }
            exists = true;

        } else if (elem_less(e, tree->elem)){
            if (tree->left != NULL){
                exists = abb_remove(tree->left, e);
            } else{
                exists = false;
            }
        } else {
            if (tree->right != NULL){
                exists = abb_remove(tree->right, e);
            } else{
                exists = false;
            }
        }
    }
    if (exists){
        tree->len --;
        // tree->len -= element_len(e);
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return exists;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->len!=0){
        max_e = tree->elem;
        if (tree->right != NULL){
            max_e = abb_max(tree->right);
        }
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->len!=0){
        min_e = tree->elem;
        if (tree->left != NULL){
            min_e = abb_min(tree->left);
        }
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

typedef struct _print_obj{
    abb tree;
    unsigned int padding;
}* print_obj;

void print_spaces(unsigned int spaces){
    for (unsigned int i = 0; i<spaces; i++){
        printf(" ");
    }
}

void abb_print(Queue s) {
    // sleep(1);
    Queue new = queue_create();
    unsigned int cummulated_padding = 0;

    while (!queue_is_empty(s)) {
        // sleep(1);
        print_obj p = (print_obj) queue_dequeue(s);  // Cast correcto
        
        print_spaces(p->padding - cummulated_padding);
        cummulated_padding = p->padding;
        
        if (p->tree->left != NULL) {
            print_spaces(p->tree->left->len);
            cummulated_padding += p->tree->left->len;

            // Asignamos memoria dinámica
            print_obj left_obj = malloc(sizeof(struct _print_obj));
            left_obj->tree = p->tree->left;
            left_obj->padding = p->padding;

            queue_enqueue(new, left_obj);
        }        

        printf("%d", p->tree->elem);
        cummulated_padding++;

        if (p->tree->right != NULL) {
            print_obj right_obj = malloc(sizeof(struct _print_obj));
            right_obj->tree = p->tree->right;
            right_obj->padding = (p->tree->left != NULL) ? (p->padding + p->tree->left->len + 1) : (p->padding + 1);
            
            queue_enqueue(new, right_obj);
        }        

        free(p); // Liberamos memoria del print_obj actual
    }

    printf("\n");

    if (!queue_is_empty(new)) {
        abb_print(new);
    }

    queue_destroy(new);
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    // abb_print(tree, 0u);
    Queue s = queue_create();
    queue_enqueue(s, &(struct _print_obj){tree, 0});
    abb_print(s);
    queue_destroy(s);
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree->left != NULL){
        abb_destroy(tree->left);
    }
    if (tree->right != NULL){
        abb_destroy(tree->right);
    }    
    free(tree);
    tree = NULL;
    assert(tree == NULL);
    return tree;
}

