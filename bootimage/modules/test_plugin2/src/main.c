/*
 * PS Vita custom bootimage test plugin2
 * Copyright (C) 2020, Princess of Sleeping
 */

#include <psp2kern/kernel/debug.h>

void _start() __attribute__ ((weak, alias("module_start")));
int module_start(SceSize args, void *argp){

	ksceDebugPrintf("test_plugin2 starting\n");

	return 0;
}
