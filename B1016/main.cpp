//
//  main.cpp
//  B1016
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
 正整数A的D_A部分定义为由A中所有D_A组成的新整数P_A。
 例如： 给定A=3862767，D_A=6，则”A的6部分“P_A为66。
 输入：在一行中依次输入A、D_A、B、D_B，以空格分隔，其中0<A,B<10^10
 输出：在一行中输出P_A+P_B
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long a, b, D_a, D_b;
    cout << "请依次输入A、D_A、B、D_B的值：";
    cin >> a >> D_a >> b >> D_b;
    long long P_a = 0;
    long long P_b = 0;
    while (a != 0) {
        if (a % 10 == D_a) {
            P_a = P_a * 10 + D_a;
        }
        a = a / 10;
    }
    while (b != 0) {
        if (b % 10 == D_b) {
            P_b = P_b * 10 + D_b;
        }
        b = b / 10;
    }
    cout << P_a + P_b << endl;
    return 0;
}

// C++对于整型数据的整除运算就是正常的除号/运算符
