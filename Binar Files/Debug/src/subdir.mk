################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Binar\ Files.cpp 

OBJS += \
./src/Binar\ Files.o 

CPP_DEPS += \
./src/Binar\ Files.d 


# Each subdirectory must supply rules for building sources it contributes
src/Binar\ Files.o: ../src/Binar\ Files.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Binar Files.d" -MT"src/Binar\ Files.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


