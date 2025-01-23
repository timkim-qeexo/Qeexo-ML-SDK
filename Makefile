# Compiler and archiver
CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar

# Compiler flags
CFLAGS = -mcpu=cortex-m4 -mthumb -O2 -Wall -Wextra -I./Hal -I./ML -I./CMSIS/Core/Include -I./CMSIS/DSP/Include

# Source files
SRCS = Hal/QxModel.c Hal/QxML.c Hal/QxOS.c Hal/QxSensorHal.c Hal/QxTransceiverHal.c

# Object files
OBJS = $(SRCS:.c=.o)

# Static library
LIB = libQxModel.a

# CMSIS repository URL
CMSIS_URL = https://github.com/ARM-software/CMSIS_5.git

# Default target
all: cmsis $(LIB)

# Download and install CMSIS
cmsis:
    if [ ! -d "CMSIS" ]; then \
        git clone $(CMSIS_URL); \
    fi

# Build the static library
$(LIB): $(OBJS)
    $(AR) rcs $@ $^

# Compile source files to object files
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
    rm -f $(OBJS) $(LIB)
    rm -rf CMSIS

.PHONY: all clean cmsis