//
//  main.cpp
//  A1046
//
//  Created by 倪浩鹏 on 2020/2/9.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
 
    Input: Each input file contains one test case. For each case, the first line contains an integer N(in [3, 10^5]), followed by N integer distances D1 D2 ... DN, where D_i is the distance between the i-th and the (i+1)-st exits, and D_N is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M(<=10^4), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbers from 1 to N. It it guaranteed that the total round trip distance is no more than 10^7.
 
    Output: For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
 */

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int total_count = 0;
    int sum = 0;
    // cout << "输入出口个数及相邻距离：";
    cin >> total_count;
    int D[total_count];
    for (int i = 0 ; i < total_count; i++) {
        cin >> D[i];
        sum += D[i];
    }
    
    // cout << "输入测试案例数目：";
    int num = 0;
    cin >> num;
    int test_case[2 * num];
    
    // cout << "输入测试案例出口号码：" << endl;
    for (int i = 0; i < (2 * num); i = i + 2) {
        cin >> test_case[i] >> test_case[i + 1];
    }
    
    // cout << "结果为：" << endl;
    for (int i = 0; i < (2 * num); i = i + 2) {
        int a, b;
        int min_d = 0;
        int tmp = 0;
        // 交换次序
        if (test_case[i] > test_case[i + 1]) {
            a = test_case[i + 1];
            b = test_case[i];
        }
        else {
            a = test_case[i];
            b = test_case[i + 1];
        }
        // 计算顺时针距离
        for (int j = (a - 1); j < (b - 1); j++) {
            tmp += D[j];
        }
        // 比较
        if (tmp > (sum - tmp)) {
            min_d = sum - tmp;
        }
        else {
            min_d = tmp;
        }
        cout << min_d << endl;
    }
    return 0;
}
