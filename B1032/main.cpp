//
//  main.cpp
//  B1032
//
//  Created by 倪浩鹏 on 2020/2/6.
//  Copyright © 2020 nihaopeng. All rights reserved.
//

/*
 输入：在第一行给出不超过10^5的正整数N，即参赛人数。
      随后N行，每行给出以为参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）及其比赛成绩，以空格分隔。
 输出：在一行中给出总得分最高的学校的编号及其得分，中间以空格分隔
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int num = 0;
    cout << "请输入参赛人数：";
    cin >> num;
    
    const int maxn = 100010;
    int inf[maxn] = {0};
    for (int i = 0; i < num; i++) {
        int score;
        int tmp;
        cin >> tmp;
        cin >> score;
        inf[tmp-1] += score;
    }
    
    int max_score = inf[0];
    int k = 1;
    for (int j = 1; j < num; j++) {
        if (inf[j] > max_score) {
            max_score = inf[j];
            k = j + 1;
        }
    }
    
    cout << "总得分最高为:"<< k << " " << max_score << endl;
    return 0;
}


/*
 在C中，使用变量来定义数组长度是，这个数组可以定义，却不能同时进行初始化赋值，需要在之后赋值。
 因为数组作为C++的内置数据类型，其空间分配在栈内存中，这部分空间的大小在编译时就要确定，不能等到运行时再分配。常量的值在编译时就能得到，而变量的值在运行时才能确定。
 但是仍然有办法使用变量作为数组的长度：绕过栈内存，将数组空间开辟在堆空间内：

 int *d = new int[n];

 这样这块内存就是自己开辟的了，可以使用变量初始化数组的长度，内存空间会在运行时动态分配。
*/
