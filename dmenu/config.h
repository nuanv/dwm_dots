/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

#include"themes/oxocarbon.h"

static int topbar = 1;      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;    /* -c option; centers dmenu on screen */
static int min_width = 500; /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {"Jetbrains Mono NerdFont:size=12:style=Bold"};
static const char *prompt =
    NULL; /* -p  option; prompt to the left of input field */

static const char *colors[SchemeLast][2] = {
    /*     fg         bg       */
    [SchemeNorm] = {col_gray1, col_gray4},
    [SchemeSel] = {col_text, col_maccntD},
    [SchemeOut] = {col_gray2, col_maccnt},
};
/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines = 8;
static unsigned int columns = 1;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 2;
