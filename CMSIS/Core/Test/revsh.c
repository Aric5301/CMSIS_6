// RUN: %cc% %ccflags% %ccout% %s.o %s; llvm-objdump --mcpu=%mcpu% -d %s.o | FileCheck --allow-unused-prefixes --check-prefixes %prefixes% %s

#include "cmsis_compiler.h"

static volatile uint32_t a = 10u;

void revsh() {
    // CHECK-LABEL: <revsh>:
    // CHECK: revsh {{r[0-9]+}}, {{r[0-9]+}}
    volatile uint32_t c = __REVSH(a);
    // CHECK: {{(bx lr)|(pop {.*pc})}}
}

