/**
 * Implementation of DeepSeek API integration
 * This file handles communication with the DeepSeek AI service
 */

#include "deepseek_api.h"

#include <curl/curl.h>

#include "config.h"
#include "http_utils.h"

/**
 * Callback function for handling HTTP response data
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

/**
 * Generates an AI comment for a given input text using DeepSeek API
 * @param input The text to generate a comment for
 * @return Generated comment string (caller must free)
 */
char *generateComment(const char *input) {
    CURL *curl;
    CURLcode res;
    char *readBuffer = calloc(1, sizeof(char));

    curl = curl_easy_init();

    if (curl) {
        // Prepare the JSON request body
        char request[4096];
        snprintf(request, sizeof(request),
                 "{\"model\": \"deepseek-ai/deepseek-chat-70b\", "
                 "\"messages\": [{\"role\": \"user\", \"content\": \"%s\"}]}",
                 input);

        // Set up CURL options
        curl_easy_setopt(curl, CURLOPT_URL, OPENROUTER_API_URL);

        // Set up HTTP headers
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        // Add authorization header
        char authHeader[1024];
        snprintf(authHeader, sizeof(authHeader), "Authorization: Bearer %s",
                 OPENROUTER_API_KEY);
        headers = curl_slist_append(headers, authHeader);

        // Add additional required headers
        headers = curl_slist_append(headers,
                                    "HTTP-Referer: https://your-website.com");
        headers = curl_slist_append(headers, "X-Title: DevBot");

        // Configure request settings
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        // Clean up
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);

        // Parse the JSON response
        char *content_start = strstr(readBuffer, "\"content\": \"");
        if (content_start) {
            content_start += strlen("\"content\": \"");
            char *content_end = strchr(content_start, '\"');

            if (content_end) {
                size_t content_len = content_end - content_start;
                char *content = calloc(content_len + 1, sizeof(char));
                strncpy(content, content_start, content_len);
                free(readBuffer);
                return content;
            }
        }
    }

    return readBuffer;
}