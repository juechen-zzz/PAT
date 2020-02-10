//
//  main.cpp
//  B1010
//
//  Created by 倪浩鹏 on 2020/2/10.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    设计函数，求一元多项式的导数
 
    输入：以指数递降方式输入多项式非零项系数和指数  3 4 -5 2 6 1 -2 0
 
    输出：以指数递降方式输出多项式非零项系数和指数  12 3 -10 1 6 0
 */


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "输入：";
    int a[1001] = {0};
    int k, e, count = 0;    // k为系数，e为指数，count计数不为零的导数项个数
    
    while (scanf("%d%d", &k, &e) != EOF) {
        a[e] = k;
    }
    a[0] = 0;
    
    for (int i = 1; i < 1000; i++) {
        a[i - 1] = a[i] * i;
        if (a[i - 1] != 0) {
            count++;
        }
    }
    
    if (count == 0) {
        cout << "0 0" << endl;
    }
    else {
        for (int i = 1000; i >= 0; i--) {
            if (a[i] != 0) {
                cout << a[i] << " " << i << " ";
                count--;
                if (count == 0) {
                    break;
                }
            }
        }
    }
    return 0;
}
