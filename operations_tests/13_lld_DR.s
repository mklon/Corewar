.name "lld_DR"
.comment "lld"

	live %1
	ld %2, r4
	st r4, r5
	zjmp %2900
	