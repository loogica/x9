all:
	gcc src/x9.c -o x9
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
