CC = gcc
CFLAGS = -Wall -Wextra -I.
LIBS = -lcurl

all: dev_bot

dev_bot: main.c deepseek_api.c slack_api.c
    $(CC) $(CFLAGS) -o dev_bot main.c deepseek_api.c slack_api.c $(LIBS)

clean:
    rm -f dev_bot