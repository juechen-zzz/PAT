//
//  main.cpp
//  A1042
//
//  Created by 倪浩鹏 on 2020/2/9.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
    Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gambles by proforming inadequate shuffles, mant casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.
    The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order;
    S1, S2, S3, ..., S13, H1, ..., H13, C1, ..., C13, D1, ..., D13, J1, J2
    wheres S stands for Spade, H for Heart, C for Club, D for diamond, and J for Joker. A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be : J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.
    
    Input: Each input file contains one test case. For each case, the first line contains a positive integer K(<=20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are seperated by a space.
    Output: For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.
 */

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    char mp[5] = {'S', 'H', 'C', 'D', 'J'};
    
    int times;
    cout << "请输入重复次数：";
    cin >> times;
    int start[54] = {0};
    int next[54] = {0};
    int ans[54] = {0};
    for (int i = 0; i < 54; i++) {
        start[i] = i + 1;
    }
    for (int i = 0; i < 54; i++) {
        cin >> next[i];
    }
    for (int j = 0; j < times; j++) {
        for (int m = 0; m < 54; m++) {
            ans[next[m] - 1] = start[m];
        }
        for (int m = 0; m < 54; m++) {
            start[m] = ans[m];
        }
    }
    for (int i = 0; i < 53; i++) {
        if (ans[i] % 13 == 0) {
            cout << mp[(ans[i] / 13) - 1] << "13 ";
            continue;
        }
        cout << mp[ans[i] / 13] << (ans[i] % 13) << " ";
    }
    if (ans[53] % 13 == 0) {
        cout << mp[(ans[53] / 13) - 1] << "13" << endl;
    }
    else {
        cout << mp[ans[53] / 13] << (ans[53] % 13) << endl;
    }
    return 0;
}


// 2
// 36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
