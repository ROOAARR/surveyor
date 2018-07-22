#ifndef BROWSER_H
#define BROWSER_H

#include "surveyor_types.h"

typedef void (*browser_cb)(const char *);

typedef struct {
    char * path;
    browser_cb cb;
} browser_settings_t;

surveyor_error_t browser_init(const browser_settings_t * settings);
surveyor_error_t browser_fini(void);
surveyor_error_t browser_next(void);

#endif
