/**
 * Implementation of Slack API integration
 * Handles sending messages to Slack channels
 */

#include "slack_api.h"

#include <curl/curl.h>

#include "config.h"
#include "http_utils.h"

/**
 * Sends a message to Slack using webhook URL
 * @param message The message to send to Slack
 */
void sendMessage(const char *message) {
    CURL *curl;
    CURLcode res;
    char *readBuffer = calloc(1, sizeof(char));

    curl = curl_easy_init();
    if (curl) {
        // Prepare JSON payload
        char request[1024];
        snprintf(request, sizeof(request), "{\"text\": \"%s\"}", message);

        // Set up CURL options
        curl_easy_setopt(curl, CURLOPT_URL, SLACK_WEBHOOK_URL);

        // Set up headers
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        // Configure request
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        // Check response code
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if (http_code != 200) {
            fprintf(stderr, "Failed to send Slack message. Status code: %ld\n",
                    http_code);
        }

        // Clean up
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
        free(readBuffer);
    }
}