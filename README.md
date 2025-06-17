# SYSCALL LINUX WITHOUT STDLIB

### Dependencies
```sh
GCC_VERSION=12
LIBC_VERSION=6
sudo apt install --no-install-suggests --no-install-recommends gcc-$GCC_VERSION libc$LIBC_VERSION-dev
```

### Example
```c
#include "sys_c.h"

#include <sys/syscall.h>
#include <unistd.h>

static inline void sys_c_exit(long __status) {
    sys_c_1(SYS_exit, __status);
}

size_t strlen(const char *s) {
    const char *start = s;
    while (*s) ++s;
    return s - start;
}

static inline long sys_c_write(long __fd, const char *__s) {
    return sys_c_3(SYS_write, __fd, (long)__s, __builtin_strlen(__s));
}

void _start() {
    const char *message = "Hello, World!";
    sys_c_write(STDOUT_FILENO, message);

    sys_c_exit(0);
}
```

### Compile
```sh
BUILD_DIR=Build
OUT="$BUILD_DIR/sys_c"
mkdir -pv $BUILD_DIR && gcc-$GCC_VERSION -static -nostdlib -march=native -mtune=native -Ofast -fno-asynchronous-unwind-tables -fno-ident -fno-pie -ffreestanding -ffunction-sections -fdata-sections -fno-stack-protector -flto -s -o $OUT sys_c.c -Wl,--build-id=none,--gc-sections -m64 && $OUT
```