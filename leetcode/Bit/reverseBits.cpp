uint32_t reverseNum(uint32_t n) {
	auto result = 0;
	for (auto i = 0; i < 32; i++) {
		result = (result << 1) + (n & 1);
		n >>= 1;
	}
	return result;
}
