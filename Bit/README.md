## 程序说明

* reverseBits：反转32位无符号整型数字；易错点：for循环32次，而不是while(n>0);前面的0bit需考虑
知识点：n&1表示末位为1或0；
知识迁移：二进制表示中1的个数，循环条件变为while(n>0)

* TODO
leetcode342：power-of-four