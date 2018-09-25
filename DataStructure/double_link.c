//
//  double_link.c
//  DataStructure
//
//  Created by leven on 2018/9/25.
//  Copyright © 2018年 leven. All rights reserved.
//

#include "double_link.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct tag_node {
    struct tag_node *prev;
    struct tag_node *next;
    void * p;
} node;

static node *pheade = NULL;
static int count = 0;

static node* creat_node(void *pval) {
    node *pnode = NULL;
    pnode = (node *)malloc(sizeof(node));
    if (!pnode) {
        printf("creat node error!\n");
        return NULL;
    }
    pnode->prev = pnode->next = pnode;
    pnode->p = pval;
    return pnode;
}

int create_dlink()
{
    pheade = creat_node(NULL);
    if (!pheade) {
        return -1;
    }
    count = 0;
    return 0;
}

int dlink_is_empty() {
    return count == 0;
}

int dlink_size() {
    return count;
}

static node* get_node(int index)
{
    if (index < 0 || index >= count ) {
        printf("%s failed! index out of bound!\n",__func__);
        return NULL;
    }
    
    if (index <= count/2) {
        int i = 0;
        node* pnode = pheade->next;
        while (++i <= index) {
            pnode = pnode->next;
        }
        return pnode;
    }
    
    int j = 0;
    int rinde = count - index - 1;
    node* rnode = pheade->prev;
    while (++j <= rinde) {
        rnode = rnode->prev;
    }
    return rnode;
}

static node* get_first_node()
{
    return get_node(0);
}

static node* get_last_node()
{
    return get_node(count-1);
}

void* dlink_get(int index)
{
    node* pindex = get_node(index);
    if (!pindex) {
        printf("%s failed!\n",__func__);
        return NULL;
    }
    return pindex->p;
}

void* dlink_get_first()
{
    return dlink_get(0);
}

void* dlilnk_get_last()
{
    return dlink_get(count-1);
}

int dlink_insert(int index, void* pval)
{
    node* pnode = creat_node(pval);
    if (!pnode) {
        return  -1;
    }
 
    node* pindex = NULL;
    if (index == 0) {
        pindex = pheade;
        pnode->prev = pindex;
        pnode->next = pindex->next;
        pindex->next->prev = pnode;
        pindex->next = pnode;
        count++;
        return 0;
        
    }else if(index == count) {
        pindex = pheade->prev;
        pnode->prev = pindex;
        pnode->next = pheade;
        pheade->prev->next = pnode;
        pheade->prev = pnode;
        count ++;
        return 0;
    }else {
        pindex = get_node(index);
    }
    
    if (!pindex) {
        return -1;
    }
    
    pnode->prev = pindex->prev;
    pnode->next = pindex;
    pindex->prev->next = pnode;
    pindex->prev = pnode;
    count++;
    return 0;
}

int dlink_insert_first(void * pval)
{
    return dlink_insert(0, pval);
}

int dlink_insert_last(void* pval)
{
    return dlink_insert(count, pval);
}

int dlink_delete(int index)
{
    node *pindex = get_node(index);
    if (!pindex) {
        printf("%s failed ! the index is out of bound!\n" ,__func__);
        return -1;
    }
    pindex->prev->next = pindex->next;
    pindex->next->prev = pindex->prev;
    free(pindex);
    count --;
    return 0;
}

int dlink_delete_first()
{
   return dlink_delete(0);
}

int dlink_delete_last()
{
    return dlink_delete(count - 1);
}

int destory_dlink()
{
    if (!pheade) {
        printf("%s failed! dlink is Null！ \n", __func__);
        return -1;
    }
    
    node* pnode = pheade->next;
    node *ptmp = NULL;
    while (pnode != pheade) {
        ptmp = pnode;
        pnode = pnode->next;
        free(ptmp);
    }
    free(pheade);
    pheade = NULL;
    count = 0;
    return 0;
}
