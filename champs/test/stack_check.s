.name "stayin' alive"
.comment "Ha, Ha, Ha"

sti	r1, %:live, %1
add r3, r4, r3

forkkkkk:
fork %3

live:
live %4
zjmp %:live
