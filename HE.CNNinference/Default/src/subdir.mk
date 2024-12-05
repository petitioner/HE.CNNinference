################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CNNinference.cpp \
../src/Methods.cpp \
../src/Tools.cpp 

OBJS += \
./src/CNNinference.o \
./src/Methods.o \
./src/Tools.o 

CPP_DEPS += \
./src/CNNinference.d \
./src/Methods.d \
./src/Tools.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler [CNNinference/Default/src/subdir.mk]'
	g++ -I$(INCLUDE_DIR) -I$(HEAAN_INCLUDE_DIR) -I$(HEAAN_INCLUDE_DIR1) -I$(HEAAN_INCLUDE_DIR2) -I$(HEAAN_INCLUDE_DIR3) -I$(HEAAN_INCLUDE_DIR4) -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



