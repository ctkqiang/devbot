/**
 * HTTP utility functions
 * Common HTTP-related functionality used across the application
 */

#include "http_utils.h"

/**
 * Generic callback function for handling HTTP response data
 * Used by libcurl to process received data
 *
 * @param contents Pointer to the received data
 * @param size Size of each data element
 * @param nmemb Number of elements
 * @param response Pointer to response buffer
 * @return Total size of processed data
 */
size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                     char **response) {
    size_t realsize = size * nmemb;
    *response = realloc(*response, strlen(*response) + realsize + 1);
    if (*response == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 0;
    }
    strncat(*response, (char *)contents, realsize);
    return realsize;
}