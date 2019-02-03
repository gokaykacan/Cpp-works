################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Custom\ Objects\ as\ Map\ Keys.cpp 

OBJS += \
./src/Custom\ Objects\ as\ Map\ Keys.o 

CPP_DEPS += \
./src/Custom\ Objects\ as\ Map\ Keys.d 


# Each subdirectory must supply rules for building sources it contributes
src/Custom\ Objects\ as\ Map\ Keys.o: ../src/Custom\ Objects\ as\ Map\ Keys.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Custom Objects as Map Keys.d" -MT"src/Custom\ Objects\ as\ Map\ Keys.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


