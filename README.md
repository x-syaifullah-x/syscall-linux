# SYSCALL LINUX WITHOUT STDLIB

### Dependencies
```sh
sudo apt install --no-install-suggests --no-install-recommends gcc
```

### Example
```c
#include <syscall.h>
#include <unistd.h>

#include "sys_c.h"

static inline void sys_c_exit(int __status) {
    sys_c_1(SYS_exit, __status);
}

size_t strlen(const char *__s) {
    const char *s = __s;
    while (*s) ++s;
    return (s - __s);
}

static inline ssize_t sys_c_write(int __fd, const char *__s) {
    return sys_c_3(SYS_write, (__fd), (long)(__s), __builtin_strlen(__s));
}

void _start() {
    const char *message = "Hello, World !";
    sys_c_write(STDOUT_FILENO, "a");
    sys_c_exit(0);
}
```

### Compile
```sh
gcc -static -nostdlib -march=native -mtune=native -Ofast -fno-pie -ffreestanding -ffunction-sections -fdata-sections -fno-stack-protector -flto -s -o Build/test sys_c.c -Wl,--gc-sections && Build/test
```