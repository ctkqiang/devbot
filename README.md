# DevBot 🤖

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Spring Boot](https://img.shields.io/badge/Spring%20Boot-2.7.5-green.svg)](https://spring.io/projects/spring-boot)

> An intelligent system that automatically generates insightful comments for code commits and sends notifications through Slack, powered by DeepSeek AI.

## 📚 Table of Contents
- [Features](#-features)
- [System Architecture](#-system-architecture)
- [Installation](#-installation)
- [Usage](#-usage)
- [Technical Details](#-technical-details)
- [Contributing](#-contributing)
- [Support](#-support)
- [Connect](#-connect)

## ✨ Features
- 🔄 Real-time commit analysis
- 🤖 AI-powered code review comments
- 💬 Slack integration
- 🛡️ Robust error handling
- 💾 Efficient memory management
- 🔒 Secure API handling

## 🏗 System Architecture
![system_arch](https://github.com/ctkqiang/devbot/blob/main/images/system_arch.png?raw=true)

### Data Flow
![data_flow](https://github.com/ctkqiang/devbot/blob/main/images/flow.png?raw=true)

### Mathematical Model
```math
M_{total} = M_{base} + (N_{chars} × S_{char})
B_{size} = min(4096, max(1024, L_{input} × 2))
````

## 🚀 Installation

### Prerequisites

- C Compiler (GCC recommended)
- Make
- libcurl

### Quick Start

```bash
# Clone the repository
git clone https://github.com/ctkqiang/devbot.git

# Build the project
make

# Run the application
./dev_bot
```

## 💻 Usage

### Environment Setup

```bash
export OPENROUTER_API_KEY="your-api-key"
export SLACK_WEBHOOK_URL="your-webhook-url"
```

### Example Implementation

```c
void handlePushEvent(const PushEvent* event) {
    for (int i = 0; i < event->commitCount; i++) {
        char* comment = generateComment(event->commits[i].message);
        sendMessage(slackMessage);
    }
}
```

## 🔧 Technical Details

### Core Components

1. **HTTP Utilities**

   - Memory-safe callback mechanisms
   - Dynamic buffer management
   - Robust error handling

2. **DeepSeek AI Integration**

   - Natural language processing
   - Contextual code analysis
   - Intelligent comment generation

3. **Slack Integration**
   - Real-time notifications
   - Webhook communication
   - Message formatting

### Memory Management

```c
*response = realloc(*response, strlen(*response) + realsize + 1);
```

## 🤝 Contributing

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Open a Pull Request

## 🔮 Future Enhancements

- Multiple AI model support
- Enhanced context awareness
- Additional platform integrations
- CI/CD pipeline integration

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 💝 Support

If you find this project helpful and would like to support its continued development and maintenance, 🥰 I deeply appreciate your generosity.
Your donation will help me continue to improve and add new features to this project. Through financial contributions, you'll help ensure
this project remains free and open to everyone. Even a small donation can make a big impact and serves as personal encouragement.

You can scan the following Alipay QR codes to make a personal donation:

<br />
<div style="display: flex; justify-content: space-between; margin-bottom: 20px;">
  <img src="https://github.com/ctkqiang/ctkqiang/blob/main/assets/IMG_9863.jpg?raw=true" style="height: 500px !important; width: 350px !important;">
 
  <img src="https://github.com/ctkqiang/ctkqiang/blob/main/assets/IMG_9859.JPG?raw=true" style="height: 500px !important; width: 350px !important;">
</div>

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/F1F5VCZJU)

## Donations

<a href="https://qr.alipay.com/fkx19369scgxdrkv8mxso92"><img src="https://img.shields.io/badge/alipay-00A1E9?style=for-the-badge&logo=alipay&logoColor=white"></a> <a href="https://ko-fi.com/F1F5VCZJU"><img src="https://img.shields.io/badge/Ko--fi-F16061?style=for-the-badge&logo=ko-fi&logoColor=white"></a> <a href="https://www.paypal.com/paypalme/ctkqiang"><img src="https://img.shields.io/badge/PayPal-00457C?style=for-the-badge&logo=paypal&logoColor=white"></a> <a href="https://donate.stripe.com/00gg2nefu6TK1LqeUY"><img src="https://img.shields.io/badge/Stripe-626CD9?style=for-the-badge&logo=Stripe&logoColor=white"></a>

</div>

## 🔗 Connect

<div align="center">
  <a href="https://twitch.tv/ctkqiang"><img src="https://img.shields.io/badge/Twitch-9146FF?style=for-the-badge&logo=twitch&logoColor=white"></a>
  <a href="https://github.com/ctkqiang"><img src="https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white"></a>
  <a href="https://www.linkedin.com/in/ctkqiang/"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"></a>
  <a href="https://linktr.ee/ctkqiang.official"><img src="https://img.shields.io/badge/linktree-39E09B?style=for-the-badge&logo=linktree&logoColor=white"></a>
</div>

---

<p align="center">Made with ❤️ by <a href="https://github.com/ctkqiang">钟智强</a></p>
