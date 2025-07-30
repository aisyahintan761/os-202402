#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    char buf[16];
    if (randomread(buf, sizeof(buf)) < 0) {
        printf(1, "randomread syscall gagal\n");
        exit();
    }
    for (int i = 0; i < sizeof(buf); i++) {
        printf(1, "%d ", buf[i] & 0xFF);
    }
    printf(1, "\n");
    exit();
}
