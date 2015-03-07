################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DFA.cpp \
../src/LexicalAnalyzerGenerator.cpp \
../src/NFA.cpp \
../src/Node.cpp \
../src/Operation.cpp 

OBJS += \
./src/DFA.o \
./src/LexicalAnalyzerGenerator.o \
./src/NFA.o \
./src/Node.o \
./src/Operation.o 

CPP_DEPS += \
./src/DFA.d \
./src/LexicalAnalyzerGenerator.d \
./src/NFA.d \
./src/Node.d \
./src/Operation.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


