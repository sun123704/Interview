class Solution {
public:
    bool isPowerOfFour(int num) {
        // 是否是2的幂
		if (num < 1) return false;
        if ((num & num-1) != 0) return false;
        if ((num & 0x55555555) == num) return true;   // 注意==优先级高于&
        else return false;
    }
};
