# DevBot - AI-Powered Code Review Assistant

DevBot is an intelligent system that automatically generates insightful comments for code commits and sends notifications through Slack. It leverages the DeepSeek AI model to provide meaningful code review assistance.

## System Architecture
![system_arch]("https://github.com/ctkqiang/devbot/blob/main/images/system_arch.png?raw=true")

## How It Works


### 1. Data Flow

![sdata_flow]("https://github.com/ctkqiang/devbot/blob/main/images/flow.png?raw=true")


### 2. Mathematical Model

The system processes commit messages using the following approach:

1. **Memory Allocation**:

   ```math
   M_{total} = M_{base} + (N_{chars} × S_{char})
   ```

   where:

   - M\_{total} = Total memory required
   - M\_{base} = Base memory allocation
   - N\_{chars} = Number of characters
   - S\_{char} = Size per character

2. **Buffer Sizing**:
   ```math
   B_{size} = min(4096, max(1024, L_{input} × 2))
   ```
   where:
   - B\_{size} = Buffer size
   - L\_{input} = Input length

## Core Components

### 1. HTTP Utilities

- Handles all HTTP communications
- Implements memory-safe callback mechanisms
- Manages response buffers dynamically

### 2. DeepSeek AI Integration

- Connects to DeepSeek's AI model
- Processes natural language inputs
- Generates contextual code comments

### 3. Slack Integration

- Manages webhook communications
- Formats and delivers messages
- Handles delivery confirmation

## Code Examples

### Event Processing

```c
void handlePushEvent(const PushEvent* event) {
    // Process each commit in the push event
    for (int i = 0; i < event->commitCount; i++) {
        // Generate AI comment
        char* comment = generateComment(event->commits[i].message);
        // Send to Slack
        sendMessage(slackMessage);
    }
}
```

## Configuration

The system requires the following environment variables:

- `OPENROUTER_API_KEY`: DeepSeek API authentication
- `SLACK_WEBHOOK_URL`: Slack integration endpoint

## Technical Details

### Memory Management

The system employs a careful memory management strategy:

1. **Dynamic Allocation**:

   - Uses `calloc` for initial allocations
   - Implements `realloc` for growing buffers
   - Ensures proper memory cleanup

2. **Buffer Safety**:
   ```c
   *response = realloc(*response, strlen(*response) + realsize + 1);
   ```
   This ensures:
   - No buffer overflows
   - Proper null termination
   - Memory leak prevention

### Error Handling

The system implements robust error handling:

- HTTP response validation
- Memory allocation checks
- API response verification

## Creative Implementation

DevBot acts as your silent coding companion, watching over your commits like a vigilant guardian. When you push your code, it springs into action:

1. 🔍 **The Observer**: DevBot carefully reads each commit message, understanding the context and purpose of your changes.

2. 🤖 **The Analyzer**: Using advanced AI, it processes your commit messages through DeepSeek's neural networks, generating insightful observations.

3. 📬 **The Messenger**: Like a digital courier, it delivers these insights directly to your Slack channel, keeping your team informed and engaged.

## Future Enhancements

1. **Enhanced AI Processing**

   - Multiple model support
   - Context-aware analysis
   - Learning from feedback

2. **Integration Expansion**
   - Additional chat platforms
   - Code hosting services
   - CI/CD pipeline integration

## Building and Running

```bash
# Clone the repository
git clone https://github.com/yourusername/devbot.git

# Build the project
make

# Run the application
./dev_bot
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

