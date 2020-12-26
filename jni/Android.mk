LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := io-ndk
LOCAL_SRC_FILES := helper.c

include $(BUILD_SHARED_LIBRARY)