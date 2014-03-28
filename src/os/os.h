#ifndef NEOVIM_OS_OS_H
#define NEOVIM_OS_OS_H

#include "vim.h"

/// Change to the given directory.
///
/// @return `0` on success, a libuv error code on failure.
int os_chdir(const char *path);

/// Get the name of current directory.
///
/// @param buf Buffer to store the directory name.
/// @param len Length of `buf`.
/// @return `OK` for success, `FAIL` for failure.
int os_dirname(char_u *buf, size_t len);

/// Expand a given file to its absolute path.
///
/// @param fname The filename which should be expanded.
/// @param buf Buffer to store the absolute path of `fname`.
/// @param len Length of `buf`.
/// @param force Also expand when `fname` is already absolute.
/// @return `FAIL` for failure, `OK` for success.
int os_get_absolute_path(char_u *fname, char_u *buf, int len, int force);

/// Check if the given file is absolute.
///
/// This just checks if the file name starts with '/' or '~'.
/// @return `TRUE` if "fname" is absolute.
int os_is_absolute_path(const char_u *fname);

/// Check if the given path is a directory or not.
///
/// @return `TRUE` if `fname` is a directory.
int os_isdir(const char_u *name);

/// Check if the given path represents an executable file.
///
/// @return `TRUE` if `name` is executable and
///   - can be found in $PATH,
///   - is relative to current dir or
///   - is absolute.
///
/// @return `FALSE` otherwise.
int os_can_exe(const char_u *name);

/// Get the file permissions for a given file.
///
/// @return `-1` when `name` doesn't exist.
int32_t os_getperm(const char_u *name);

/// Set the permission of a file.
///
/// @return `OK` for success, `FAIL` for failure.
int os_setperm(const char_u *name, int perm);

/// Check if a file exists.
///
/// @return `TRUE` if `name` exists.
int os_file_exists(const char_u *name);

long_u os_total_mem(int special);
const char *os_getenv(const char *name);
int os_setenv(const char *name, const char *value, int overwrite);
char *os_getenvname_at_index(size_t index);
int os_get_usernames(garray_T *usernames);
int os_get_user_name(char *s, size_t len);
int os_get_uname(uid_t uid, char *s, size_t len);
char *os_get_user_directory(const char *name);

#endif  // NEOVIM_OS_OS_H
