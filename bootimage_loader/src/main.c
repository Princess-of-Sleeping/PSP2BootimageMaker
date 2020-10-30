/*
 * PS Vita bootimage loader
 * Copyright (C) 2020, Princess of Sleeping
 */

#include <psp2kern/kernel/modulemgr.h>
#include <psp2kern/kernel/debug.h>

void _start() __attribute__ ((weak, alias("module_start")));
int module_start(SceSize args, void *argp){

	int res;

	ksceDebugPrintf("Bootimage loader starting\n");

	res = ksceKernelMountBootfs("sd0:bootimage.skprx");
	if(res < 0)
		res = ksceKernelMountBootfs("ux0:bootimage.skprx");

	ksceDebugPrintf("sceKernelMountBootfs : 0x%X\n", res);

	SceUID modid;

	modid = ksceKernelLoadStartModule("sd0:kd/test_plugin.skprx", 0, NULL, 0x800, NULL, NULL);
	ksceDebugPrintf("modid : 0x%X\n", modid);

	modid = ksceKernelLoadStartModule("sd0:kd/test_plugin2.skprx", 0, NULL, 0x800, NULL, NULL);
	ksceDebugPrintf("modid : 0x%X\n", modid);

	res = ksceKernelUmountBootfs();
	ksceDebugPrintf("sceKernelUmountBootfs : 0x%X\n", res);

	return SCE_KERNEL_START_NO_RESIDENT;
}
