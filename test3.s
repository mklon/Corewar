.name "test"
.comment "ALIVE"

start:	
		sti r1, %:a, %1
		sti r1, %:b, %23
		sti r1, %:c, %45
		sti r1, %:d, %76
		sti r1, %:e, %26
		sti r1, %:f, %8
		sti r1, %:g, %14
		sti r1, %:h, %56
		sti r1, %:i, %2
		sti r1, %:j, %92
		fork %:z

a:
		live %12345
		ld %1, r10
		fork %:start

b:
		st r5, -12
		ld %0, r16
		st r5, -21
		zjmp %:start
		st r5, -468958269
		st r5, -408345744
		st r5, -976456052615
		st r5, -8934543234
		st r5, -995453335
		st r5, -8113458648
		st r5, -7743455711
		st r5, -53456778
		st r5, -456565
		st r5, -4034571897

c:
		live %13456789
		fork %:b

d:
		st r5, -46895826
		st r5, -408345744
		st r5, -976452615
		st r5, -893454334
		st r5, -99545333
		st r5, -811345864
		st r5, -774345571
		st r5, -5345677
		st r5, -45656
		st r5, -403457897
		st r5, -5140453374
		st r5, -6345895
		ld %1, r10
		ld %1, r10
		st r5, -876
		fork %:start
		zjmp %:a

e:
		live %1987654123
		fork %:d
		ld %1, r10

f:
		live %8745687
		st r5, -98687
		st r5, -42189
		ld %1, r10

g:
		st r5, -8465
		st r5, -34975
		live %198754
		st r5, -93676
		ld %1, r10
		sti r1, %:d, %89
		fork %:e
		st r5, -4685826
		st r5, -40845744
		st r5, -764752615
		st r5, -8934454334
		st r5, -9945333
		st r5, -81145864
		st r5, -774545571
		st r5, -534677
		st r5, -4556
		st r5, -40347897
		ld %0, r16
		zjmp %:a

h:
		st r5, -962746
		st r5, -936565
		live %9789
		live %98412
		zjmp %:b

i:
		live %134567894
		fork %:f
		sti r1, %:h, %89
		st r5, -876546
		ld %0, r16
		st r5, -87165413

j:
		live %198754
		st r5, -345642462
		st r5, -461895826
		st r5, -4018345744
		st r5, -9726452615
		st r5, -8943454334
		st r5, -9955745333
		st r5, -8117345864
		st r5, -7743475571
		st r5, -53456777
		st r5, -456564
		st r5, -4034571897

z:
		ld %0, r16
		live %0
		ld %0, r16
		live %0
