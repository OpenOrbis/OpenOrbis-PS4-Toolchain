#include <stddef.h>
#include "substitute.h"

static struct substitute_hook* sceNpGetState_hook;

static int sceNpGetState_hooked(int unknown, int* out)
{
    SUBSTITUTE_WAIT(sceNpGetState_hook);
    int ans = SUBSTITUTE_CONTINUE(int, sceNpGetState_hook, (int, int*), unknown, out);
    *out = 2;
    return ans;
}

int _init(void)
{
    sceNpGetState_hook = substitute_hook(SUBSTITUTE_MAIN_MODULE, "sceNpGetState", sceNpGetState_hooked, SUBSTITUTE_IAT_NAME);
    return 0;
}
