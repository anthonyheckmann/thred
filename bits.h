static inline bool bt(unsigned *v, unsigned bit) {
	unsigned offset = bit >> 5;
	bit &= 31;
	unsigned mask = 1 << bit;

	return v[offset] & mask;
}

static inline bool bts(unsigned *v, unsigned bit) {
	unsigned offset = bit >> 5;
	bit &= 31;
	unsigned mask = 1 << bit;

	bool ret = v[offset] & mask;
	v[offset] |= mask;

	return ret;
}

static inline bool btr(unsigned *v, unsigned bit) {
	unsigned offset = bit >> 5;
	bit &= 31;
	unsigned mask = 1 << bit;

	bool ret = v[offset] & mask;
	v[offset] &= ~mask;

	return ret;
}

static inline bool btc(unsigned *v, unsigned bit) {
	unsigned offset = bit >> 5;
	bit &= 31;
	unsigned mask = 1 << bit;

	bool ret = v[offset] & mask;
	v[offset] ^= mask;

	return ret;
}

static inline int bsr(unsigned v) {
	return __builtin_clz(v) ^ 31;
}

static inline int bsf(unsigned v) {
	return __builtin_ffs(v) - 1;
}
