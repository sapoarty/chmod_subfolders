#include "unity.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h> /* POSIX */
#include <sys/stat.h>

void check_files_recur(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    struct stat path_stat;
    stat(basePath, &path_stat);
    DIR *dir = opendir(basePath);

    if (!dir)
    {
        TEST_ASSERT_EQUAL_INT( (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), (path_stat.st_mode & 0x1FF));
        return;
    }
    else
    {
        TEST_ASSERT_EQUAL_INT( (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH), (path_stat.st_mode & 0x1FF) );
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            check_files_recur(path);
        }
    }

    closedir(dir);
}

void test_add( void )
{
    char path[255];

    // Read the testing path from stdin
    scanf("%s", path);

    check_files_recur(path);
}
