################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../0-\ outputs.cpp 

OBJS += \
./0-\ outputs.o 

CPP_DEPS += \
./0-\ outputs.d 


# Each subdirectory must supply rules for building sources it contributes
0-\ outputs.o: ../0-\ outputs.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"0- outputs.d" -MT"0-\ outputs.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


