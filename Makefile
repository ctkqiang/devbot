CC = gcc
CFLAGS = -Wall -Wextra -I.
LIBS = -lcurl

all: dev_bot

dev_bot: main.c deepseek_api.c slack_api.c http_utils.c
    $(CC) $(CFLAGS) -o dev_bot main.c deepseek_api.c slack_api.c http_utils.c $(LIBS)

clean:
    rm -f dev_bot