//
//  main.cpp
//  B1001
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
B1001:卡拉兹猜想：
 对任意一个自然数n，如果是偶数，那么砍掉一半；如果是奇数，那么把(3n+1)砍掉一半。一直反复砍下去，一定最后得到n=1。
 
 输入：每个测试输入包含1个测试用例，即给出自然数n的值
 输出：输出从n计算到1需要的步数
 */


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "请输入n=";
    int n;
    cin >> n;
    int num = 0;
    while (n != 1) {
        if (n % 2 == 0) {n = n / 2;}
        else {n = (3 * n + 1) / 2;}
        num++;
    }
    cout << "num = " << num << endl;
    return 0;
}
