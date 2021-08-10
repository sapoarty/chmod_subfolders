#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void chmod_files_rec(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    struct stat sb;
    DIR *dir = opendir(basePath);
    stat(basePath, &sb);

    // Unable to open directory stream
    if (!dir)
    {
        chmod(basePath, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
        return;
    }
    else
        chmod(basePath, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);


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

int main()
{
    // Directory path to list files
    char path[255];
    struct stat sb;

    // Input path from user
    printf("Path to list files: ");
    scanf("%s", path);
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        chmod_files_rec(path);
        printf("All file permissions have been changed\n")
    }
    else
        printf("Directory doesn't exist\n");

    return 0;
}

