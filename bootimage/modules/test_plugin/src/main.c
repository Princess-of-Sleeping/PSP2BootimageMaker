/*
 * PS Vita custom bootimage test plugin
 * Copyright (C) 2020, Princess of Sleeping
 */

#include <psp2kern/kernel/debug.h>

void _start() __attribute__ ((weak, alias("module_start")));
int module_start(SceSize args, void *argp){

	ksceDebugPrintf("test_plugin starting\n");

	return 0;
}
