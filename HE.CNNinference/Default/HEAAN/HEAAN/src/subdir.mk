################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Define the project root path
PROJECT_ROOT := $(abspath $(dir $(firstword $(MAKEFILE_LIST)))/..)

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HEAAN/HEAAN/src/action/Scheme.cpp \
../HEAAN/HEAAN/src/action/TestScheme.cpp \
../HEAAN/HEAAN/src/model/BigInteger.cpp \
../HEAAN/HEAAN/src/model/Ciphertext.cpp \
../HEAAN/HEAAN/src/model/Key.cpp \
../HEAAN/HEAAN/src/model/Plaintext.cpp \
../HEAAN/HEAAN/src/model/Ring.cpp \
../HEAAN/HEAAN/src/model/RingPair.cpp \
../HEAAN/HEAAN/src/model/SecretKey.cpp \
../HEAAN/HEAAN/src/service/AdditionManager.cpp \
../HEAAN/HEAAN/src/service/BootstrappingManager.cpp \
../HEAAN/HEAAN/src/service/DecryptionManager.cpp \
../HEAAN/HEAAN/src/service/EncryptionManager.cpp \
../HEAAN/HEAAN/src/service/MultiplicationManager.cpp \
../HEAAN/HEAAN/src/service/RotationManager.cpp \
../HEAAN/HEAAN/src/service/SubstractionManager.cpp \
../HEAAN/HEAAN/src/util/EvaluatorUtils.cpp \
../HEAAN/HEAAN/src/util/FFT.cpp \
../HEAAN/HEAAN/src/util/NumUtils.cpp \
../HEAAN/HEAAN/src/util/SerializationUtils.cpp \
../HEAAN/HEAAN/src/util/StringUtils.cpp \
../HEAAN/HEAAN/src/util/TimeUtils.cpp 

OBJS += \
../HEAAN/HEAAN/src/action/Scheme.o\
../HEAAN/HEAAN/src/action/TestScheme.o\
../HEAAN/HEAAN/src/model/BigInteger.o\
../HEAAN/HEAAN/src/model/Ciphertext.o\
../HEAAN/HEAAN/src/model/Key.o\
../HEAAN/HEAAN/src/model/Plaintext.o\
../HEAAN/HEAAN/src/model/Ring.o\
../HEAAN/HEAAN/src/model/RingPair.o\
../HEAAN/HEAAN/src/model/SecretKey.o\
../HEAAN/HEAAN/src/service/AdditionManager.o\
../HEAAN/HEAAN/src/service/BootstrappingManager.o\
../HEAAN/HEAAN/src/service/DecryptionManager.o\
../HEAAN/HEAAN/src/service/EncryptionManager.o\
../HEAAN/HEAAN/src/service/MultiplicationManager.o\
../HEAAN/HEAAN/src/service/RotationManager.o\
../HEAAN/HEAAN/src/service/SubstractionManager.o\
../HEAAN/HEAAN/src/util/EvaluatorUtils.o\
../HEAAN/HEAAN/src/util/FFT.o\
../HEAAN/HEAAN/src/util/NumUtils.o\
../HEAAN/HEAAN/src/util/SerializationUtils.o\
../HEAAN/HEAAN/src/util/StringUtils.o\
../HEAAN/HEAAN/src/util/TimeUtils.o

CPP_DEPS += \
../HEAAN/HEAAN/src/action/Scheme.d\
../HEAAN/HEAAN/src/action/TestScheme.d\
../HEAAN/HEAAN/src/model/BigInteger.d\
../HEAAN/HEAAN/src/model/Ciphertext.d\
../HEAAN/HEAAN/src/model/Key.d\
../HEAAN/HEAAN/src/model/Plaintext.d\
../HEAAN/HEAAN/src/model/Ring.d\
../HEAAN/HEAAN/src/model/RingPair.d\
../HEAAN/HEAAN/src/model/SecretKey.d\
../HEAAN/HEAAN/src/service/AdditionManager.d\
../HEAAN/HEAAN/src/service/BootstrappingManager.d\
../HEAAN/HEAAN/src/service/DecryptionManager.d\
../HEAAN/HEAAN/src/service/EncryptionManager.d\
../HEAAN/HEAAN/src/service/MultiplicationManager.d\
../HEAAN/HEAAN/src/service/RotationManager.d\
../HEAAN/HEAAN/src/service/SubstractionManager.d\
../HEAAN/HEAAN/src/util/EvaluatorUtils.d\
../HEAAN/HEAAN/src/util/FFT.d\
../HEAAN/HEAAN/src/util/NumUtils.d\
../HEAAN/HEAAN/src/util/SerializationUtils.d\
../HEAAN/HEAAN/src/util/StringUtils.d\
../HEAAN/HEAAN/src/util/TimeUtils.d

	
# Each subdirectory must supply rules for building sources it contributes
HEAAN/HEAAN/src/%.o: ../HEAAN/HEAAN/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler 4 Testing'
	g++ -I"$(PROJECT_ROOT)/HEAAN/HEAAN/src" -I"$(PROJECT_ROOT)/include" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


