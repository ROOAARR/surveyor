#include <stdlib.h>
#include <stdio.h>

#include "surveyor.h"

int main(int argc, char ** argv)
{
    int err = EXIT_FAILURE;

    if (argc < 2)
    {
        printf("Syntax: ./testapp /path/to/your/directory\n");
    }
    else
    {
        printf("Surveyor started: %d\n", surveyor_init(argv[1]));
        printf("Surveyor stopped: %d\n", surveyor_fini());

        err = EXIT_SUCCESS;
    }

    return err;
}
