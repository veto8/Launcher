#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#else
    #include <unistd.h>
    #include <limits.h>
    #ifdef __APPLE__
        #include <mach-o/dyld.h>
    #endif
#endif
static char *exe_dir(void) {
#ifdef _WIN32
  char path[MAX_PATH];
  DWORD len = GetModuleFileNameA(NULL, path, MAX_PATH);
  if (len == 0)
    return NULL;
  char *sep = strrchr(path, '\\');
  if (sep)
    *sep = '\0';
  return strdup(path);
#elif defined(__APPLE__)
  uint32_t size = 0;
  _NSGetExecutablePath(NULL, &size);
  char *path = malloc(size);
  if (_NSGetExecutablePath(path, &size) != 0) {
    free(path);
    return NULL;
  }
  char *sep = strrchr(path, '/');
  if (sep)
    *sep = '\0';
  return path;
#else
  char buf[PATH_MAX];
  ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
  if (len == -1)
    return NULL;
  buf[len] = '\0';
  char *sep = strrchr(buf, '/');
  if (sep)
    *sep = '\0';
  return strdup(buf);
#endif
}
int main(void) {
  char *dir = exe_dir();
  if (!dir) {
    perror("exe_dir");
    return 1;
  }
  printf("%s\n", dir);
  char *dir2 = "C:/tamuz/applic/"; 
  char arg[4096];
  snprintf(arg, sizeof(arg), "/[MAGIC_LOGICAL_NAMES]ROOT=%s/", dir);
  printf("%s\n", arg);

  //char *args[] = {"helloc_linux", arg, NULL};
  //execv("helloc_linux", args);
  char *args[] = {"uniRTE.exe", arg, NULL};
  execv("uniRTE.exe", args);
    
  perror("execv");
  free(dir);
  return 1;

  free(dir);
  return 0;
}
