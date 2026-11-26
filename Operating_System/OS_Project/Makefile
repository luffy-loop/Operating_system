CC = gcc
CFLAGS = -Wall -Wextra -g -std=gnu99
TARGET = shellforge
SRC = src/week5_navigation.c
MILESTONES = build/week1 build/week2 build/week3 build/week4 build/week5

.PHONY: all milestones clean
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

milestones: $(MILESTONES)

build/week1: src/week1_repl.c
build/week2: src/week2_tokenizer.c
build/week3: src/week3_organizer.c
build/week4: src/week4_process.c
build/week5: src/week5_navigation.c

$(MILESTONES):
	mkdir -p build
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET) $(MILESTONES)
