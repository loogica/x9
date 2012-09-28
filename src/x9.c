#include <stdio.h>
#include <dirent.h>

#include "x9.h"

static char *obvious_files[] = {
    "autogen.sh",
    "configure",
    "settings.py",
    "setup.py",
    "pom.xml",
    "AndroidManifest.xml",
    "Makefile",
    "requirements.txt",
    ".git",
    ".hg",
    NULL
};

static char *obvious_projects[] = {
    "C/C++",
    "C/C++",
    "Python/Django",
    "Python/Lib",
    "Java/Maven",
    "Java/Android",
    "Makefile/Compatible",
    "Python/Requirements",
    "Git repository",
    "Hg Repository",
    NULL
};

int
    find_file(char *filename)
{
    int i = 0;
    char *name;
    while ((name = obvious_files[i]) != NULL) {
        if (strcmp(name, filename) == 0) {
            return i;
        }
        ++i;
    }
    return -1;
}


#ifndef TEST
int
    main(int argc, char *argv[])
{
    int index = 0;
    struct dirent *current;
    DIR* root = opendir(".");
    
    if (!root) {
        return -1;
    }

    while ((current = readdir(root)) != NULL) {
        if ((index = find_file(current->d_name)) >= 0) {
            printf("%s\n", obvious_projects[index]);
        } 
    }

    closedir(root);
    return 0;
}
#endif
