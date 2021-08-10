#ifndef CHMOD_SUBFOLDERS_CHMOD_FILES_REC_H
#define CHMOD_SUBFOLDERS_CHMOD_FILES_REC_H

void chmod_files_rec(char *basePath);

#define PATH_MAX_LNG                        256
#define FILE_PERMISSIONS                    (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define FOLDER_PERMISSIONS                  (S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH)
#define PATH_REQUEST_MSG                    "Path to list files (\".\" to use current folder): "
#define SUCESS_MSG                          "All file permissions have been changed\n"
#define FAIL_MSG                            "Directory doesn't exist\n"
#endif
