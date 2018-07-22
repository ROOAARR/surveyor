#include "surveyor.h"

#include <stdio.h>

#include "browser/browser.h"

#ifdef __cplusplus 
extern "C" {
#endif

static void prv_browser_cb(const char *);

surveyor_error_t surveyor_init(const char * path)
{
    surveyor_error_t err = SURVEYOR_UNKNOWN;

    if (!path)
    {
        err = SURVEYOR_BADARG;
    }
    else
    {
        const browser_settings_t settings = {
            .path = path,
            .cb   = prv_browser_cb
        };

        if (SURVEYOR_OK != (err = browser_init(&settings)))
        {
            // Cleanup
        }
    }

    return err;
}

surveyor_error_t surveyor_fini()
{
    surveyor_error_t err = SURVEYOR_UNKNOWN;

    err = browser_fini();

    return err;
}

void prv_browser_cb(const char * path)
{
    printf("Path: %s", path ? path : "NULL");
}

#ifdef __cplusplus  
}  
#endif 
