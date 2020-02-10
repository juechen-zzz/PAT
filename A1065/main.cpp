//
//  main.cpp
//  A1065
//
//  Created by 倪浩鹏 on 2020/2/10.
//  Copyright © 2020 nihaopeng. All rights reserved.
//


/*
    Given three integers A B and C in [-2^63, 2^63], you are supposed to tell whether A + B > C
    
    Input: The first line of the input gives the positive number of test cases, T. Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.
 
    Output: For each test case, output in one line "Case #X: true"
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num = 0;
    cin >> num;
    int data[num][3];
    for (int i = 0; i < num; i++) {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    for (int i = 0; i < num; i++) {
        if (data[i][0] + data[i][1] > data[i][2]) {
            cout << "Case#" << (i + 1) << ": True" << endl;
        }
        else {
            cout << "Case#" << (i + 1) << ": False" << endl;
        }
    }
    return 0;
}
