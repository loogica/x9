all:
	gcc src/x9.c -o x9
debug:
	gcc src/x9.c -g -o x9
leak:
	gcc src/x9.c -g -o x9
	valgrind --leak-check=full x9
install:
	cp x9 /usr/local/bin
uninstall:
	rm -f /usr/local/bin/x9
test:
	gcc -Isrc/ src/x9.c tests/test_x9.c -o test_x9 -DTEST
	./test_x9
clean:
	rm -f test_x9
	rm -f x9
