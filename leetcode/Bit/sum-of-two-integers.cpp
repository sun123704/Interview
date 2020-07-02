class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
		if (b == 0) return a;		

		return getSum(a^b, (unsigned int)(a&b) << 1);   // 注意优先级
    }
};

/*
加法：异或
1 0 1
0 0 1
-----
1 0 0

进位：与 左移
1 0 1        1 0 1
0 0 1        0 0 1
-----  ==》  -----
0 0 1        0 1 0
*/