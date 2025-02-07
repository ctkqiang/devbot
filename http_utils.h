#ifndef HTTP_UTILS_H
#define HTTP_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     char **response);

#endif