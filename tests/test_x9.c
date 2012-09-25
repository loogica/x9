#include <stdio.h>
#include <assert.h>
#include "x9.h"

void
    test_find_file(void)
{
    char *filename = "Makefile";
    assert(0 <= find_file(filename));
}

void
    test_find_file_dont_exist(void)
{
    char *filename = "settings.pyc";
    assert(-1 == find_file(filename));
}

int
    main(int argc, char *argv[])
{
    test_find_file();
    test_find_file_dont_exist();
    printf("Everything is ok!\n");
    return 0;
}
