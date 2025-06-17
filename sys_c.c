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

unsigned long get_args_from_stack(char ***argv_out) {
    long *rsp;
    __asm__ volatile("mov %%rsp, %0" : "=r"(rsp));
    if (argv_out)
        *argv_out = (char **)(&rsp[1]);
    return rsp[0] /* argc */;
}

void _start() {
    // char **argv;
    // long argc = get_args_from_stack(&argv);

    // for (size_t i = 0; i < argc; i++) {
    //     sys_c_write(STDOUT_FILENO, argv[i]);
    //     sys_c_write(STDOUT_FILENO, "\n");
    // }

    const char *message = "Hello, World!";
    sys_c_write(STDOUT_FILENO, message);

    sys_c_exit(0);
}