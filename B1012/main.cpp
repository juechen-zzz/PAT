//
//  main.cpp
//  B1012
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
 给定一系列正整数，按要求分为五类，并输出以下五类数字：
    A1 = 能被5整除的数字中所有偶数的和
    A2 = 能被5除后余1的数字按给出顺序进行交错求和，n1-n2+n3-n4
    A3 = 被5除后余2的数字个数
    A4 = 被5除后余3的数字的平均数，精确到小数点后一位
    A5 = 被5除后余4的数字中最大数字
 输入：每个输入包含一个测试用例，先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数
 输出：A1-A5，以空格分隔，若某种不存在，c输出N
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]) {
    cout << "请输入正整数N：";
    int N;
    cin >> N;
    
    int c[N];
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    
    int A[5] = {0};             // 每类数据求和
    int C[5] = {0};             // 每类数据个数
    double ans[5] = {0};
    
    for (int j = 0; j < N; j++) {
        if (c[j] % 5 == 0 && c[j] % 2 == 0) {
            A[0] += c[j];
            C[0]++;
            ans[0] = A[0];
        }
        else if (c[j] % 5 == 1){
            C[1]++;
            if (C[1] % 2 == 1) {
                A[1] += c[j];
                ans[1] = A[1];
            }
            else{
                A[1] -= c[j];
                ans[1] = A[1];
            }
        }
        else if (c[j] % 5 == 2){
            C[2]++;
            ans[2] = C[2];
        }
        else if (c[j] % 5 == 3){
            C[3]++;
            A[3] += c[j];
            ans[3] = ((double)A[3]) / ((double)C[3]);
        }
        else if (c[j] % 5 == 4){
            C[4]++;
            if (c[j] > ans[4]) {
                ans[4] = c[j];
            }
        }
    }
    for (int m = 0; m < 5; m++) {
        if (C[m] == 0) {
            cout << "N ";
            continue;
        }
        if (m == 3) {
            cout << setiosflags(ios::fixed)<< setprecision(1) << ans[3] << " ";
            continue;
        }
        cout << (int)ans[m] << " ";
    }
    cout << endl;
    return 0;
}

/*
    cout输出固定小数点后精度
    头文件：#include <iomanip>
    cout << setiosflags(ios::fixed)<< setprecision(1) << a4_average
    此为设置小数点后固定一位
    没有setiosflags(ios::fixed)时，setprecision(1)表示输出有效位数，包括小数点左边的数据。
 */
