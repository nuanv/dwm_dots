// clang-format off
/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "?";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      uname -r                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */

static const struct arg args[] = {
    // uses https://dwm.suckless.org/patches/status2d patch ^c#[HEX]^ to set color and ^d^ to reset color

    // oxocarbon col_text #f2f4f8 col_batt #ff7eb6
    // biscuit   col_text #B6A8A5 col_batt #EAB471

    /* function       format                          argument */   
    { cpu_perc,		    " ^c#f2f4f8^ %s%% |^d^ ",        NULL },
    //{ keyboard_indicators,      "",                        "c?"},
    { ram_perc,       "^c#f2f4f8^ %s%% |^d^ ",		      NULL },
    { keymap,		      "^c#f2f4f8^ %s |^d^ ",		        NULL },
    { wifi_essid,     "^c#f2f4f8^󰢾 %s^d^ ",             "wlan0" },
    { netspeed_rx,     "^c#f2f4f8^ %s |^d^ ",             "wlan0" },
    //{ netspeed_tx,     "^c#ffffff^ %s |^d^ ",             "wlan0" },
    //{ battery_state,  "^c#f43f5e^%s^d^ ",           "BAT1" },
    //{ battery_perc,   "^c#f43f5e^ %s%%^d^",         "BAT1" },
    //{ battery_state,  "^c#f43f5e^%s^d^ ",           "BAT1" },
    { datetime,       "^c#f2f4f8^󰸗 %s | ^d^",            "%a, %d %m %Y" },
    { datetime,       "^c#f2f4f8^ %s | ^d^",            "%I:%M %p" },
    { battery_perc,   "^c#ff7eb6^ %s%%^d^ ",         "BAT1" },

};

