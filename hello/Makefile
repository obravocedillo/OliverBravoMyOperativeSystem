libhello: libhello.c
	gcc -c libhello.c
hello: hello.c libhello
	gcc hello.c libhello.o -o hello
test: hello
	./hello oliver bravo cedilo
c