#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/param.h>

int
    find_file(char *filename);

void
    join_paths(char *target, const char *path1, const char *path2);

void
    remove_component(char *target, const char *component);

int
    endswith(const char *str, const char *suffix);

void
    search_files(DIR *root,
                 const char *rel_path,
                 char *current_path,
                 int level);
