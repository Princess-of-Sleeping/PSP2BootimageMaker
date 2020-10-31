/*
 * PS Vita custom bootimage
 * Copyright (C) 2020, Princess of Sleeping
 */

#include <psp2kern/kernel/debug.h>

typedef struct SceKernelBootimageModules {
	const char *path;
	const void *data;
	SceSize size;
} SceKernelBootimageModules;

typedef struct SceKernelBootimageInfo {
	SceSize number;
	const SceKernelBootimageModules *list;
} SceKernelBootimageInfo;

const
#include "./modules/test_plugin.h"
const
#include "./modules/test_plugin2.h"

#define MODULE_ENTRY(module_path, module_data) { \
		.path = module_path,             \
		.data = module_data,             \
		.size = sizeof(module_data)      \
	}

const SceKernelBootimageModules module_list[] = {
	MODULE_ENTRY("sd0:kd/test_plugin.skprx", ___modules_test_plugin_velf),
	MODULE_ENTRY("sd0:kd/test_plugin2.skprx", ___modules_test_plugin2_velf)
};

const SceKernelBootimageInfo info = {
	.number = sizeof(module_list) / sizeof(SceKernelBootimageModules),
	.list = module_list
};

const int data = (int)&ksceDebugGetPutcharHandler;

void _start() __attribute__ ((weak, alias("module_start")));
int module_start(SceSize args, void *argp){
	return 0;
}
