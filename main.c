#include <stdio.h>
#include <sys/stat.h>
#include "chmod_files_rec.h"

int main()
{
    char path[PATH_MAX_LNG];
    struct stat sb;

    printf(PATH_REQUEST_MSG);
    scanf("%s", path);
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        // If folder is exist start the process
        chmod_files_rec(path);
        printf(SUCESS_MSG);
    }
    else
        printf(FAIL_MSG);

    return 0;
}

