.name "or_DIR"
.comment "or"

	live %1
	st r1, 190
	or %1, 1024, r1
	st r1, 301
