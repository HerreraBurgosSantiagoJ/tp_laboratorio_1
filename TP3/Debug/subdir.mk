################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Employee.c \
../errors.c \
../input_lib.c \
../main.c \
../my_system.c \
../parser.c \
../steart.c \
../vallib.c 

OBJS += \
./Controller.o \
./Employee.o \
./errors.o \
./input_lib.o \
./main.o \
./my_system.o \
./parser.o \
./steart.o \
./vallib.o 

C_DEPS += \
./Controller.d \
./Employee.d \
./errors.d \
./input_lib.d \
./main.d \
./my_system.d \
./parser.d \
./steart.d \
./vallib.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


