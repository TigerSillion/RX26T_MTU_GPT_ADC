################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_DA/Config_DA.c \
../src/smc_gen/Config_DA/Config_DA_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_DA/Config_DA.obj \
src/smc_gen/Config_DA/Config_DA_user.obj 

C_DEPS += \
src/smc_gen/Config_DA/Config_DA.d \
src/smc_gen/Config_DA/Config_DA_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_DA/%.obj: ../src/smc_gen/Config_DA/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	@echo src\smc_gen\Config_DA\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_DA\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_DA\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\Config_DA\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_DA\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_DA\cSubCommand.tmp" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo ''

