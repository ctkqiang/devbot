/**
 * Main application entry point
 * Handles GitHub push events and generates AI comments
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "deepseek_api.h"
#include "slack_api.h"

/**
 * Structure to represent a single commit
 */
typedef struct {
    char message[1024];  // Commit message
} Commit;

/**
 * Structure to represent a GitHub push event
 */
typedef struct {
    char repoName[1024];  // Repository name
    Commit commits[10];   // Array of commits (max 10)
    int commitCount;      // Number of commits in the event
} PushEvent;

/**
 * Handles a GitHub push event by generating AI comments and sending to Slack
 * @param event Pointer to the push event structure
 */
void handlePushEvent(const PushEvent* event) {
    for (int i = 0; i < event->commitCount; i++) {
        // Generate AI comment for each commit
        char* comment = generateComment(event->commits[i].message);

        // Prepare Slack message
        char slackMessage[2048];
        snprintf(slackMessage, sizeof(slackMessage),
                 "New commit in %s: %s\nComment: %s", event->repoName,
                 event->commits[i].message, comment);

        // Send to Slack
        sendMessage(slackMessage);
        free(comment);
    }
}

/**
 * Main function - entry point of the application
 * Currently sets up a mock event for testing
 */
int main() {
    // Create mock push event
    PushEvent mockEvent;
    strcpy(mockEvent.repoName, "test-repo");
    strcpy(mockEvent.commits[0].message, "Added new feature");
    mockEvent.commitCount = 1;

    // Process the mock event
    handlePushEvent(&mockEvent);

    return 0;
}