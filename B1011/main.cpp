//
//  main.cpp
//  B1011
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
 给定区间[-2^31,2^31]内的三个整数A、B和C，判断A+B是否大于C
 输入：第一行给出正整数T，即测试用例个数，随后给出T组测试用例，每组一行，顺序给出A、B和C，用空格分隔
 输出：对每组测试用例，在一行中输出“Case #X：true“
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cout <<  "请输入测试用例：";
    cin >> T;
    for (int i = 0; i < T; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        if (A + B > C) {
            cout << "Case #" << (i + 1) << ":true" << endl;
        }
        else{
            cout << "Case #" << (i + 1) << ":false" << endl;
        }
    }
    return 0;
}
