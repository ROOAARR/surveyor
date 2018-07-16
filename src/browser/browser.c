#include "browser.h"

#include <stdlib.h>

#ifdef __cplusplus 
extern "C" {
#endif

static browser_settings_t s_settings = {
    .path = "/",
    .cb   = NULL
};

static browser_error_t prv_set_settings(const browser_settings_t *);

browser_error_t browser_init(const browser_settings_t * settings)
{
    return prv_set_settings(settings);
}

browser_error_t browser_fini()
{
}

browser_error_t browser_next()
{
}

browser_error_t prv_set_settings(const browser_settings_t * settings)
{
    browser_error_t err = BROWSER_UNKNOWN;

    if (!settings)
    {
        err = BROWSER_BADARG;
    }
    else
    {
        // Set settings
        err = BROWSER_OK;
    }

    return err;
}

#ifdef __cplusplus  
}  
#endif 
