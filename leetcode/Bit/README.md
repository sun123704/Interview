## 程序说明

* reverseBits：反转32位无符号整型数字；易错点：for循环32次，而不是while(n>0);前面的0bit需考虑
知识点：n&1表示末位为1或0；
知识迁移：二进制表示中1的个数，循环条件变为while(n>0)

* power-of-four[leetcode342]: 进阶做法（不使用循环或递归）：4的幂满足的条件：①是2的幂，即二进制仅1个1位;②且1在奇数位上

* sum-of-two-integers[leetcode371]:不用加减法求两整数之和
知识点：考虑位运算：加法即异或、进位即与运算左移

### 知识点整理
* n&1表示末位为1或0；
* 如果一个数字n是2的幂次方，那么 n & (n - 1) 一定等于0
* 