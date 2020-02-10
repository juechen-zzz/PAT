//
//  main.cpp
//  A1002 and A1009
//
//  Created by 倪浩鹏 on 2020/2/10.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
  给出两行，每行表示一个行列式：第一个数表示该多项式中系数非零项的项数，后面每两个数表示一项，这两个数分别表示该项的幂次和系数。
  求两个多项式的和。
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    double p_1[10] = {0};
    double p_2[10] = {0};
    double ans[10] = {0};
    double ans_2[10] = {0};
    int count = 0;
    int count_2 = 0;
    cout << "----------------------------------" << endl;
    int num1 = 0;
    cin >> num1;
    for (int i = 0; i < num1; i++) {
        int a = 0;
        double b = 0;
        cin >> a >> b;
        p_1[a] = b;
    }
    cout << "----------------------------------" << endl;
    int num2 = 0;
    cin >> num2;
    for (int i = 0; i < num2; i++) {
        int a = 0;
        double b = 0;
        cin >> a >> b;
        p_2[a] = b;
    }
    cout << "----------------------------------" << endl;
    // 多项式加法
    for (int i = 0; i < 10; i++) {
        if ((p_1[i] != 0) || (p_2[i] != 0)) {
            ans[i] = p_1[i] + p_2[i];
            count++;
        }
    }
    cout << "----------------------------------" << endl;
    // 多项式乘法
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((p_1[i] != 0) && (p_2[j] != 0)){
                ans_2[i + j] += p_1[i] * p_2[j];
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (ans_2[i] != 0) {
            count_2++;
        }
    }
    cout << "----------------------------------" << endl;
    cout << count << " ";
    for (int i = 10; i >= 0; i--) {
        if (ans[i] != 0) {
            cout << i << " " <<  ans[i] << " ";
        }
    }
    cout << endl;
    cout << count_2 << " ";
    for (int i = 9; i >= 0; i--) {
        if (ans_2[i] != 0) {
            cout << i << " " <<  ans_2[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
