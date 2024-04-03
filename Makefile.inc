HEADER_DIR = headers
HEADERS := $(shell find $(HEADER_DIR) -name '*.hpp')

SRC_DIR := src
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

ifneq (,$(findstring d, $(MAKEFLAGS)))
	DEBUGFLAGS := -g -Og
	OBJ_DIR := obj/debug
	BINARY_DIR := bin/debug
else
	DEBUGFLAGS := -O3
	OBJ_DIR := obj
	BINARY_DIR := bin
endif

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

BINARY := $(BINARY_DIR)/shmup

CXX := clang++
CPPFLAGS := -I$(HEADER_DIR)
CXXFLAGS := -Wall -Werror -Wpedantic $(DEBUGFLAGS)
LDFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio
