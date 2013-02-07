#include "x9.h"

#define CHECK_IGNORED(path) !(strcmp(path, ".") == 0 || \
                              strcmp(path, "..") == 0)

static char *obvious_files[] = {
    "autogen.sh",
    "configure",
    "settings.py",
    "settings/__init__.py",
    "tests/__init__.py",
    "setup.py",
    "pom.xml",
    "AndroidManifest.xml",
    "Makefile",
    "requirements.txt",
    ".git",
    ".hg",
    ".travis.yml",
    NULL
};

static char *obvious_projects[] = {
    "C/C++",
    "C/C++",
    "Python/Django",
    "Python/Django",
    "Python Test module",
    "Python/Lib",
    "Java/Maven",
    "Java/Android",
    "Makefile/Compatible",
    "Python/Requirements",
    "Git repository",
    "Hg Repository",
    "Travis-CI user",
    NULL
};

void
    join_paths(char *target, const char *path1, const char *path2)
{
    snprintf(target, MAXPATHLEN, "%s/%s", path1, path2);
}

void
    remove_component(char *path, const char *component)
{
    size_t component_size = strlen(component) + 1; //include "/"
    size_t removal_index = strlen(path) - component_size;
    path[removal_index] = '\0';
}

/*
 * Code from:
 * http://stackoverflow.com/questions/744766/how-to-compare-ends-of-strings-in-c
 */
int
    endswith(const char *str, const char *suffix)
{
    if (!str || !suffix)
        return 0;

    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);

    if (lensuffix >  lenstr)
        return 0;

    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}
/* end */

int
    find_file(char *filename)
{
    int i = 0;
    char *name;

    while ((name = obvious_files[i]) != NULL) {
        if (endswith(filename, name) > 0) {
            return i;
        }
        ++i;
    }
    return -1;
}

void
    search_files(DIR *root,
                 const char *rel_path,
                 char *current_path,
                 int level)
{
    int index = 0;
    struct dirent *current;
    char full_path_name[MAXPATHLEN];

    chdir(rel_path);
    strcpy(full_path_name, current_path);

    while ((current = readdir(root)) != NULL) {
        join_paths(full_path_name, full_path_name, current->d_name);

        if (current->d_type == DT_DIR && CHECK_IGNORED(current->d_name)) {
            search_files(opendir(current->d_name),
                         current->d_name,
                         full_path_name,
                         ++level);

            chdir("..");
        } else if (CHECK_IGNORED(current->d_name)) {
            if ((index = find_file(full_path_name)) >= 0)
                printf("%-20s %s\n", obvious_projects[index],
                                           full_path_name);
        }

        remove_component(full_path_name, current->d_name);

    }

    closedir(root);
}


#ifndef TEST
int
    main(int argc, char *argv[])
{
    DIR *root = opendir(".");

    if (!root) {
        return -1;
    }

    search_files(root, ".", ".", 0);

    return 0;
}
#endif
