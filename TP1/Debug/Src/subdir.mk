################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/aux_main.c \
../Src/calculate.c \
../Src/errors.c \
../Src/input_lib.c \
../Src/my_system.c \
../Src/steart.c \
../Src/values_interpretation.c 

OBJS += \
./Src/aux_main.o \
./Src/calculate.o \
./Src/errors.o \
./Src/input_lib.o \
./Src/my_system.o \
./Src/steart.o \
./Src/values_interpretation.o 

C_DEPS += \
./Src/aux_main.d \
./Src/calculate.d \
./Src/errors.d \
./Src/input_lib.d \
./Src/my_system.d \
./Src/steart.d \
./Src/values_interpretation.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/plainsight/eclipse-workspace/TP1/Heathers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


