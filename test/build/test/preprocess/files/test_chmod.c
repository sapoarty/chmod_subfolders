#include "/Library/Ruby/Gems/2.6.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void check_files_recur(char *basePath)

{

    char path[1000];

    struct dirent *dp;

    struct stat path_stat;

    stat(basePath, &path_stat);

    DIR *dir = opendir(basePath);



    if (!dir)

    {

        UnityAssertEqualNumber((UNITY_INT)(((0000400 | 0000200 | 0000040 | 0000004))), (UNITY_INT)(((path_stat.st_mode & 0x1FF))), (((void*)0)), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

        return;

    }

    else

    {

        UnityAssertEqualNumber((UNITY_INT)(((0000700 | 0000040 | 0000010 | 0000004 | 0000001))), (UNITY_INT)(((path_stat.st_mode & 0x1FF))), (((void*)0)), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

    }



    while ((dp = readdir(dir)) != ((void*)0))

    {

        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)

        {

            printf("%s\n", dp->d_name);





            __builtin___strcpy_chk (path, basePath, __builtin_object_size (path, 2 > 1 ? 1 : 0));

            __builtin___strcat_chk (path, "/", __builtin_object_size (path, 2 > 1 ? 1 : 0));

            __builtin___strcat_chk (path, dp->d_name, __builtin_object_size (path, 2 > 1 ? 1 : 0));



            check_files_recur(path);

        }

    }



    closedir(dir);

}



void test_add( void )

{

    char path[255];





    scanf("%s", path);



    check_files_recur(path);

}
