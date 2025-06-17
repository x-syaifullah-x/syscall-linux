# SYSCALL LINUX WITHOUT STDLIB

### Example
```c
#include "sys_c.h"

#define SYS_write 1
#define SYS_exit 60

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

static inline void sys_c_exit(int __status) {
    sys_c_1(SYS_exit, __status);
}

unsigned long strlen(const char *__s) {
    const char *s = __s;
    while (*s) ++s;
    return (s - __s);
}

static inline long sys_c_write(int __fd, const char *__s) {
    return sys_c_3(SYS_write, (__fd), (long)(__s), __builtin_strlen(__s));
}

void _start() {
    const char *message = "Hello, World !";
    sys_c_write(STDOUT_FILENO, message);
    sys_c_exit(0);
}
```

### Compile
```sh
BUILD_DIR=Build
OUT="$BUILD_DIR/sys_c"
mkdir -pv $BUILD_DIR && gcc -static -nostdlib -march=native -mtune=native -Ofast -fno-pie -ffreestanding -ffunction-sections -fdata-sections -fno-stack-protector -flto -s -o $OUT sys_c.c -Wl,--gc-sections && $OUT
```