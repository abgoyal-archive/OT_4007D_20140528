

#ifndef FOTA_H_
#define FOTA_H_


int find_fota_delta_package(const char *root_path);
int install_fota_delta_package(const char *root_path);
void remove_fota_delta_files(const char *root_path);

char *get_error_string(int err_code);

#endif  // FOTA_H_
