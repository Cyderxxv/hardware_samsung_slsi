#
# Copyright (C) 2016 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# settings that apps and OS both want to know about variant

VENDOR := samsung
VARIANT := erd9925
CPU := cortexm4f
CHIP := 9925
PLATFORM := exynos
SOCNAME := s5e9925
BOARD := erd
DEBUG ?= -DDEBUG
BUILD_VARIANT := eng
BLOPTION := NOBL
EVT := 1

# setting TARGET_PRODUCT for app build
TARGET_PRODUCT := $(VARIANT)

# VARIANT_PATH is relative to ANDROID TOP
ifndef VARIANT_BASE
VARIANT_PATH := variant/$(VARIANT)
else
VARIANT_PATH := $(VARIANT_BASE)/$(VARIANT)
endif

EXYNOS_CONTEXTHUB = YES
#SUPPORT_EXT_APP = YES
DMAILBOX_REQUIRED = YES
PDMA_REQUIRED = NO
I3C_REQUIRED = NO
TIMER_REQUIRED = NO
UART_REQUIRED = NO
UTC_REQUIRED = NO
MAILBOX_REQUIRED = YES
# Only one should be YES
SYSTIME_USING_RTC = YES
SYSTIME_USING_DLL = NO
PWM_REQUIRED = YES
SWINT_REQUIRED = NO
MBAPM_REQUIRED = YES
MBCP_REQUIRED = YES
I2CSPI_SFRDUMP_REQUIRED = NO
#HEAP_DEBUG = YES
#DEBUG_MODE = YES
EXYNOS_VSYNC = NO
EXYNOS_VSYNC_WORKAROUND = NO
SLIF_REQUIRED = NO
LOCAL_POWERGATE = YES
USE_LOG_FLUSH_TRSHOLD = YES
EXYNOS_FUSION = YES
HIFI_SENSOR_SUPPORT = YES
ifeq ($(EVT), 0)
MCT_SUPPORT = NO
ALIVE_DVS_SUPPORT = NO
else
MCT_SUPPORT = YES
ALIVE_DVS_SUPPORT = YES
endif
#IF_INTERRUPT_MODE = YES
DFS_SUPPORT = NO
DFS_BOOTING = NO
MAG_CALIBRATION = YES
ACCEL_CALIBRATION = NO
CIPC_USER_ABOX = NO
MPU_SUPPORT = YES
PACKET_SIZE_MAX = 4096
CIPC_DATA_AP2CHUB_SIZE = 1024
LOGBUF_NUM = 230
CIPC_START_OFFSET = 21504 #(21 * 1024)

# BOARD Info
ACC = BMI26X
MAG = AK09918
ALS = TMD3725
BARO = BMP380
#MGR = NULL

ACC_SENSOR = $(shell echo $(ACC) | tr a-z A-Z)
MAG_SENSOR = $(shell echo $(MAG) | tr a-z A-Z)
ALS_SENSOR = $(shell echo $(ALS) | tr a-z A-Z)
BARO_SENSOR = $(shell echo $(BARO) | tr a-z A-Z)
MANAGER = $(shell echo $(MGR) | tr a-z A-Z)

FLAGS += -DPLATFORM_HW_TYPE=0x9925
FLAGS += -DPLATFORM_HW_VER=0
FLAGS += -DPLATFORM_BL_VER=0x1126
FLAGS += -DSUPPORT_MULTIOS

BUILD_VARIANT_NAME = BUILD_VARIANT_$(shell echo $(BUILD_VARIANT) | tr a-z A-Z)

