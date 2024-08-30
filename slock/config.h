/* user and group to drop privileges to */

#include"themes/oxocarbon.h"

static const char *user = "nobody";
static const char *group = "nobody";

static const char *colorname[NUMCOLS] = {
    [INIT] = init,   /* after initialization */
    [INPUT] = input,  /* during input */
    [FAILED] = failed, /* wrong password */
    [CAPS] = caps,   /* CapsLock on */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
