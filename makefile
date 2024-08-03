# Remember to run everything in the parent folder, not in src/ or test/

test_body: test/test_body.c src/body.c src/body.h
	gcc test/test_body.c src/body.c -o test/test_body
	./build/test_body
