//
//  double_link.h
//  DataStructure
//
//  Created by leven on 2018/9/25.
//  Copyright © 2018年 leven. All rights reserved.
//

#ifndef double_link_h
#define double_link_h

#include <stdio.h>
// 新建 双向链表 ，成功返回表头，否则返回NULL
extern int create_dlink(void);

// 撤销 双向链表，成功返回0， 否则返回-1
extern int destory_dlink(void);

// 双向链表是否为空 为空返回1， 否则返回0；
extern int dlink_is_empty(void);

extern int dlink_size(void);

extern void* dlink_get(int index);

extern void* dlink_get_first(void);

extern void* dlink_get_last(void);

extern int dlink_insert(int index, void* pval);

extern int dlink_insert_first(void *pval);

extern int dlink_insert_last(void *pval);

extern int dlink_delete(int index);

extern int dlink_delete_first(void);

extern int dlink_delete_last(void);


#endif /* double_link_h */
