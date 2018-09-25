//
//  DoubleLinkTests.m
//  DataStructureTests
//
//  Created by leven on 2018/9/25.
//  Copyright © 2018年 leven. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "double_link.h"
@interface DoubleLinkTests : XCTestCase

@end

@implementation DoubleLinkTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    int iarr[4] = {10, 20, 30 ,40};
    create_dlink();
    dlink_insert(0, &iarr[0]);
    dlink_insert_last(&iarr[1]);
    dlink_insert_last(&iarr[2]);
    dlink_insert(1, &iarr[3]);
    int count = dlink_size();
    int *p;
    for (int  i = 0; i < count; i ++) {
        p = (int *)dlink_get(i);
        printf("dlink_get(%d) = %d \n",i, *p);
    }
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
