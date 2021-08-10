#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "chmod_files_rec.h"

void chmod_files_rec(char *basePath)
{
    char path[PATH_MAX_LNG];
    struct dirent *dp;
    struct stat sb;
    DIR *dir = opendir(basePath);
    stat(basePath, &sb);

    //If it's file - change it's permission and stop searching in this branch
    if (!dir)
    {
        chmod(basePath, FILE_PERMISSIONS);
        return;
    }
    else
        chmod(basePath, FOLDER_PERMISSIONS);

    // If it's folder - construct new paths and check them recursively
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            chmod_files_rec(path);
        }
    }

    closedir(dir);
}