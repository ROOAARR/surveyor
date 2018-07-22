#ifndef SURVEYOR_H
#define SURVEYOR_H

#include "surveyor_types.h"

surveyor_error_t surveyor_init(const char * path);
surveyor_error_t surveyor_fini(void);

#endif
