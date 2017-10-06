.name "xor_DIR"
.comment "xor"

	live %1
	st r1, 200
	xor %1, 2, r1
	st r1, 191
