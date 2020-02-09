//
//  main.cpp
//  B1018
//
//  Created by 倪浩鹏 on 2020/2/9.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
  锤子剪刀布：
    现给出两人的交锋记录，统计双方的胜、平、负次数，并给出双方分别出什么手势的胜算最大
    输入：第一行给出正整数N，即双方交手的次数。随后N行，每行给出一次交锋的信息，即甲乙给出的手势。
         C代表锤子，J代表剪刀，B代表布，第一个字母代表甲方
    输出：第一、二行分别给出甲乙的胜、平、负次数，第三个给出两个字母，分别代表甲乙获胜次数最多的手势。
         若解不唯一，则输出按字典序最小的解。
 */

#include <iostream>
using namespace std;

int change(char c){                         // BCJ循环相克，且字典序递增
    if (c == 'B') {return 0;}
    if (c == 'C') {return 1;}
    if (c == 'J') {return 2;}
    return 0;
}

int main(int argc, const char * argv[]) {
    int count;
    cin >> count;
    int a[count];
    int b[count];
    int count_a[3] = {0};
    int hand_a[3] = {0};
    int hand_b[3] = {0};
    for (int i = 0; i < count; i++) {
        char a_1, b_1;
        cin >> a_1 >> b_1;
        a[i] = change(a_1);
        b[i] = change(b_1);
        if ((a[i] < b[i]) || ((a[i] == 2 && b[i] == 0))) {      // a胜
            count_a[0]++;
            if (a[i] == 0) {hand_a[0]++;}
            if (a[i] == 1) {hand_a[1]++;}
            if (a[i] == 2) {hand_a[2]++;}
        }
        else if (a[i] == b[i]) {count_a[1]++;}                  // 平
        else {                                                  // b胜
            count_a[2]++;
            if (b[i] == 0) {hand_b[0]++;}
            if (b[i] == 1) {hand_b[1]++;}
            if (b[i] == 2) {hand_b[2]++;}
        }
    }
    cout << count_a[0] << " " << count_a[1] << " " << count_a[2] << endl;
    cout << count_a[2] << " " << count_a[1] << " " << count_a[0] << endl;
    
    int tmp_a = 0;
    int tmp_b = 0;
    for (int j = 0; j < 3; j++) {
        if (hand_a[j] > hand_a[tmp_a]) {
            tmp_a = j;
        }
        if (hand_b[j] > hand_b[tmp_a]) {
            tmp_b = j;
        }
    }
    char dict[3] = {'B', 'C', 'J'};
    cout << dict[tmp_a] << " " << dict[tmp_b] << endl;
    return 0;
}
