#ifndef _SYS_C_H
#define _SYS_C_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long syscall_num;

static inline long sys_c_6(const syscall_num n, long a1, long a2, long a3, long a4, long a5, long a6);
static inline long sys_c_5(const syscall_num n, long a1, long a2, long a3, long a4, long a5);
static inline long sys_c_4(const syscall_num n, long a1, long a2, long a3, long a4);
static inline long sys_c_3(const syscall_num n, long a1, long a2, long a3);
static inline long sys_c_2(const syscall_num n, long a1, long a2);
static inline long sys_c_1(const syscall_num n, long a1);
static inline long sys_c_0(const syscall_num n);

#if defined(__x86_64__)

#define SYS_C "syscall"

static inline long sys_c_6(const syscall_num n, long a1, long a2, long a3, long a4, long a5, long a6) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a1;
    register long rsi __asm__("rsi") = a2;
    register long rdx __asm__("rdx") = a3;
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    register long r9 __asm__("r9") = a6;
    __asm__ volatile(SYS_C : "+a"(rax) : "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
    return rax;
}

static inline long sys_c_5(const syscall_num n, long a1, long a2, long a3, long a4, long a5) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a1;
    register long rsi __asm__("rsi") = a2;
    register long rdx __asm__("rdx") = a3;
    register long r10 __asm__("r10") = a4;
    register long r8 __asm__("r8") = a5;
    __asm__ volatile(SYS_C : "+a"(rax) : "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
    return rax;
}

static inline long sys_c_4(const syscall_num n, long a1, long a2, long a3, long a4) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a1;
    register long rsi __asm__("rsi") = a2;
    register long rdx __asm__("rdx") = a3;
    register long r10 __asm__("r10") = a4;
    __asm__ volatile(SYS_C : "+a"(rax) : "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10) : "rcx", "r11", "memory");
    return rax;
}

static inline long sys_c_3(const syscall_num n, long a1, long a2, long a3) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a1;
    register long rsi __asm__("rsi") = a2;
    register long rdx __asm__("rdx") = a3;
    __asm__ volatile(SYS_C : "+a"(rax) : "D"(rdi), "S"(rsi), "d"(rdx) : "rcx", "r11", "memory");
    return rax;
}

static inline long sys_c_2(const syscall_num n, long a1, long a2) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a1;
    register long rsi __asm__("rsi") = a2;
    __asm__ volatile(SYS_C : "+a"(rax) : "D"(rdi), "S"(rsi) : "rcx", "r11", "memory");
    return rax;
}

static inline long sys_c_1(const syscall_num n, long a1) {
    register long rax __asm__("rax") = n;
    register long rdi __asm__("rdi") = a1;
    __asm__ volatile(SYS_C : "+a"(rax) : "D"(rdi) : "rcx", "r11", "memory");
    return rax;
}

static inline long sys_c_0(const syscall_num n) {
    register long rax __asm__("rax") = n;
    __asm__ volatile(SYS_C : "+a"(rax)::"rcx", "r11", "memory");
    return rax;
}

#elif defined(__aarch64__)

#define SYS_C "svc #0"

static inline long sys_c_6(const syscall_num n, long a1, long a2, long a3, long a4, long a5, long a6) {
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

static inline long sys_c_5(const syscall_num n, long a1, long a2, long a3, long a4, long a5) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    register long x3 __asm__("x3") = a4;
    register long x4 __asm__("x4") = a5;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x3), "r"(x4), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_4(const syscall_num n, long a1, long a2, long a3, long a4) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    register long x3 __asm__("x3") = a4;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x3), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_3(const syscall_num n, long a1, long a2, long a3) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    register long x2 __asm__("x2") = a3;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x2), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_2(const syscall_num n, long a1, long a2) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    register long x1 __asm__("x1") = a2;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x1), "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_1(const syscall_num n, long a1) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0") = a1;
    __asm__ volatile(SYS_C : "+r"(x0) : "r"(x8) : "memory");
    return x0;
}

static inline long sys_c_0(const syscall_num n) {
    register long x8 __asm__("x8") = n;
    register long x0 __asm__("x0");
    __asm__ volatile(SYS_C : "=r"(x0) : "r"(x8) : "memory");
    return x0;
}

#elif defined(__i386__)

#define SYS_C "int $0x80"

static inline long sys_c_6(const syscall_num n, long a1, long a2, long a3, long a4, long a5, long a6) {
    register long eax __asm__("eax") = n;
    register long ebx __asm__("ebx") = a1;
    register long ecx __asm__("ecx") = a2;
    register long edx __asm__("edx") = a3;
    register long esi __asm__("esi") = a4;
    register long edi __asm__("edi") = a5;
    register long ebp __asm__("ebp") = a6;
    __asm__ volatile(SYS_C : "+r"(eax) : "r"(ebx), "r"(ecx), "r"(edx), "r"(esi), "r"(edi), "r"(ebp) : "memory");
    return eax;
}

static inline long sys_c_5(const syscall_num n, long a1, long a2, long a3, long a4, long a5) {
    register long eax __asm__("eax") = n;
    register long ebx __asm__("ebx") = a1;
    register long ecx __asm__("ecx") = a2;
    register long edx __asm__("edx") = a3;
    register long esi __asm__("esi") = a4;
    register long edi __asm__("edi") = a5;
    __asm__ volatile(SYS_C : "+r"(eax) : "r"(ebx), "r"(ecx), "r"(edx), "r"(esi), "r"(edi) : "memory");
    return eax;
}

static inline long sys_c_4(const syscall_num n, long a1, long a2, long a3, long a4) {
    register long eax __asm__("eax") = n;
    register long ebx __asm__("ebx") = a1;
    register long ecx __asm__("ecx") = a2;
    register long edx __asm__("edx") = a3;
    register long esi __asm__("esi") = a4;
    __asm__ volatile(SYS_C : "+r"(eax) : "r"(ebx), "r"(ecx), "r"(edx), "r"(esi) : "memory");
    return eax;
}

static inline long sys_c_3(const syscall_num n, long a1, long a2, long a3) {
    register long eax __asm__("eax") = n;
    register long ebx __asm__("ebx") = a1;
    register long ecx __asm__("ecx") = a2;
    register long edx __asm__("edx") = a3;
    __asm__ volatile(SYS_C : "+r"(eax) : "r"(ebx), "r"(ecx), "r"(edx) : "memory");
    return eax;
}

static inline long sys_c_2(const syscall_num n, long a1, long a2) {
    register long eax __asm__("eax") = n;
    register long ebx __asm__("ebx") = a1;
    register long ecx __asm__("ecx") = a2;
    __asm__ volatile(SYS_C : "+r"(eax) : "r"(ebx), "r"(ecx) : "memory");
    return eax;
}

static inline long sys_c_1(const syscall_num n, long a1) {
    register long eax __asm__("eax") = n;
    register long ebx __asm__("ebx") = a1;
    __asm__ volatile(SYS_C : "+r"(eax) : "r"(ebx) : "memory");
    return eax;
}

#elif defined(__arm__)

#define SYS_C "swi 0"

static inline long sys_c_6(const syscall_num n, long a1, long a2, long a3, long a4, long a5, long a6) {
    register long r0 __asm__("r0") = a1;
    register long r1 __asm__("r1") = a2;
    register long r2 __asm__("r2") = a3;
    register long r3 __asm__("r3") = a4;
    register long r4 __asm__("r4") = a5;
    register long r5 __asm__("r5") = a6;
    register long r7 __asm__("r7") = n;
    __asm__ volatile(SYS_C : "+r"(r0) : "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5), "r"(r7) : "memory");
    return r0;
}

static inline long sys_c_5(const syscall_num n, long a1, long a2, long a3, long a4, long a5) {
    register long r0 __asm__("r0") = a1;
    register long r1 __asm__("r1") = a2;
    register long r2 __asm__("r2") = a3;
    register long r3 __asm__("r3") = a4;
    register long r4 __asm__("r4") = a5;
    register long r7 __asm__("r7") = n;
    __asm__ volatile(SYS_C : "+r"(r0) : "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r7) : "memory");
    return r0;
}

static inline long sys_c_4(const syscall_num n, long a1, long a2, long a3, long a4) {
    register long r0 __asm__("r0") = a1;
    register long r1 __asm__("r1") = a2;
    register long r2 __asm__("r2") = a3;
    register long r3 __asm__("r3") = a4;
    register long r7 __asm__("r7") = n;
    __asm__ volatile(SYS_C : "+r"(r0) : "r"(r1), "r"(r2), "r"(r3), "r"(r7) : "memory");
    return r0;
}

static inline long sys_c_3(const syscall_num n, long a1, long a2, long a3) {
    register long r0 __asm__("r0") = a1;
    register long r1 __asm__("r1") = a2;
    register long r2 __asm__("r2") = a3;
    register long r7 __asm__("r7") = n;
    __asm__ volatile(SYS_C : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "memory");
    return r0;
}

static inline long sys_c_2(const syscall_num n, long a1, long a2) {
    register long r0 __asm__("r0") = a1;
    register long r1 __asm__("r1") = a2;
    register long r7 __asm__("r7") = n;
    __asm__ volatile(SYS_C : "+r"(r0) : "r"(r1), "r"(r7) : "memory");
    return r0;
}

static inline long sys_c_1(const syscall_num n, long a1) {
    register long r0 __asm__("r0") = a1;
    register long r7 __asm__("r7") = n;
    __asm__ volatile(SYS_C : "+r"(r0) : "r"(r7) : "memory");
    return r0;
}

#else
#error "Unsupported architecture"
#endif

#ifdef __cplusplus
}
#endif

#endif  // _SYS_C_H