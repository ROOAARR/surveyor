#include "browser.h"

#include <stdlib.h>
#include <errno.h>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#ifdef __cplusplus 
extern "C" {
#endif

static browser_settings_t s_settings = {
    .path = NULL,
    .cb   = NULL
};

static DIR * s_DIR = NULL;

static surveyor_error_t prv_get_error(void);

surveyor_error_t browser_init(const browser_settings_t * settings)
{
    surveyor_error_t err = SURVEYOR_UNKNOWN;

    if (!settings || !settings->path || !settings->cb)
    {
        err = SURVEYOR_BADARG;
    }
    else if (!(s_DIR = opendir(settings->path)))
    {
        err = prv_get_error();
    }
    else
    {
        size_t   sz  = strlen(settings->path);
        char   * buf = (char *)calloc(sz + 1, sizeof(char));

        if (!buf)
        {
            err = SURVEYOR_NOMEMORY;
            browser_fini();
        }
        else
        {
            s_settings.path = strncpy(buf, settings->path, sz);
            s_settings.cb   = settings->cb;

            err = SURVEYOR_OK;
        }
    }

    return err;
}

surveyor_error_t browser_fini()
{
    if (s_DIR)
    {
        closedir(s_DIR);
        s_DIR = NULL;
    }

    if (s_settings.path)
    {
        free(s_settings.path);
        s_settings.path = NULL;
    }

    s_settings.cb = NULL;

    return SURVEYOR_OK;
}

surveyor_error_t browser_next()
{
}

surveyor_error_t prv_get_error()
{
    surveyor_error_t err = SURVEYOR_UNKNOWN;

    switch(errno)
    {
        case EACCES:
            err = SURVEYOR_NOACCESS;
            break;

        case ENOENT:
        case ENOTDIR:
            err = SURVEYOR_NODIR;
            break;

        case ENOMEM:
            err = SURVEYOR_NOMEMORY;
            break;

        default:
            err = SURVEYOR_ERROR;
            break;
    }

    return err;
}

#ifdef __cplusplus  
}  
#endif 
