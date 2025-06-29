#ifndef _SYS_C_H
#define _SYS_C_H

#ifdef __cplusplus
extern "C" {
#endif

static inline long sys_c_6(long n, long a1, long a2, long a3, long a4, long a5, long a6);
static inline long sys_c_5(long n, long a1, long a2, long a3, long a4, long a5);
static inline long sys_c_4(long n, long a1, long a2, long a3, long a4);
static inline long sys_c_3(long n, long a1, long a2, long a3);
static inline long sys_c_2(long n, long a1, long a2);
static inline long sys_c_1(long n, long a1);
static inline long sys_c_0(long n);

#if defined(__x86_64__)

#define SYS_C ".byte 0x0f, 0x05"

static inline long sys_c_6(long n, long a1, long a2, long a3, long a4, long a5, long a6) {
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    register long r9 __asm__("r9") = a6;
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_c_5(long n, long a1, long a2, long a3, long a4, long a5) {
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_c_4(long n, long a1, long a2, long a3, long a4) {
    register long r10 __asm__("r10") = a4;
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3), "r"(r10) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_c_3(long n, long a1, long a2, long a3) {
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n), "D"(a1), "S"(a2), "d"(a3) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_c_2(long n, long a1, long a2) {
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n), "D"(a1), "S"(a2) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_c_1(long n, long a1) {
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
    return ret;
}

static inline long sys_c_0(long n) {
    register long ret __asm__("rax");
    __asm__ volatile(SYS_C : "=a"(ret) : "a"(n) : "rcx", "r11", "memory");
    return ret;
}
#elif defined(__aarch64__)

#define SYS_C "svc #0"

static inline long sys_c_6(const long n, long a1, long a2, long a3, long a4, long a5, long a6) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    register long x3 __asm__("x3") = a4;
    register long x4 __asm__("x4") = a5;
    register long x5 __asm__("x5") = a6;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x5), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_5(const long n, long a1, long a2, long a3, long a4, long a5) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    register long x3 __asm__("x3") = a4;
    register long x4 __asm__("x4") = a5;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_4(const long n, long a1, long a2, long a3, long a4) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    register long x3 __asm__("x3") = a4;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x3), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_0(const long n) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0");
    __asm__ volatile(SYS_C : "=r"(x0) : "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_3(const long n, long a1, long a2, long a3) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_2(const long n, long a1, long a2) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_1(const long n, long a1) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x8) : "memory");
    return x0;
}
#else
#error "Unsupported architecture"
#endif

#ifdef __cplusplus
}
#endif

#endif  // _SYS_C_H