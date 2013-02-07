#include <stdio.h>
#include <assert.h>
#include "x9.h"

void
    test_join_paths(void)
{
    char result_path1[100];
    char result_path2[100];
    char result_path3[100];

    const char *path1 = ".";
    const char *path2 = "src";
    const char *path3 = "module";

    join_paths(result_path1, path1, path2);
    join_paths(result_path2, result_path1, path3);
    join_paths(result_path3, path2, path3);

    assert(0 == strcmp(result_path1, "./src"));
    assert(0 == strcmp(result_path2, "./src/module"));
    assert(0 == strcmp(result_path3, "src/module"));
}

void
    test_remove_components(void)
{
    char path[100] = "./path/to/src";

    remove_component(path, "src");
    assert(0 == strcmp("./path/to", path));
    remove_component(path, "to");
    assert(0 == strcmp("./path", path));
    remove_component(path, "path");
    assert(0 == strcmp(".", path));
}

void
    test_endswith(void)
{
    char *filename1 = "Makefile";
    char *filename2 = "autogen.sh";
    char *filename3 = "/Project/settings/__init__.py";

    char *suffix1 = "Makefile";
    char *suffix2 = "settings/__init__.py";

    assert(0 < endswith(filename1, suffix1));
    assert(0 == endswith(filename1, suffix2));
    assert(0 == endswith(filename2, suffix1));
    assert(0 == endswith(filename2, suffix2));
    assert(0 == endswith(filename3, suffix1));
    assert(0 < endswith(filename3, suffix2));
}

void
    test_find_file(void)
{
    char *filename1 = "Makefile";
    char *filename2 = "settings/__init__.py";

    assert(0 <= find_file(filename1));
    assert(0 <= find_file(filename2));
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
    test_endswith();
    test_remove_components();
    test_join_paths();
    test_find_file();
    test_find_file_dont_exist();
    printf("Everything is ok!\n");
    return 0;
}
