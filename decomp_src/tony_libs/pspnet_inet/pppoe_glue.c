/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

int func_0002B640(int arg);
void func_0002A980(void);
int func_0002B564(void);
void func_0002A850(void);
int func_00009968(int (*f)(void));
void func_00009984(void);
int _sce_pspnet_start_of_pppoe_module_in_netintr(void (*f)(void));
void _sce_pspnet_stop_of_pppoe_module_in_netintr(void);

int
sceNetInet_lib_7CB1D9E3(int arg)
{
	int s, s2, error;

	s = _sce_pspnet_spllock();
	if ((error = func_0002B640(arg)) < 0)
		goto out;
	if ((error = _sce_pspnet_start_of_pppoe_module_in_netintr(func_0002A980)) < 0)
		goto fail;
	if ((error = func_00009968(func_0002B564)) < 0)
		goto fail;
	_sce_pspnet_splunlock(s);
	return 0;
fail:
	s2 = _sce_pspnet_spllock();
	func_00009984();
	_sce_pspnet_stop_of_pppoe_module_in_netintr();
	func_0002A850();
	_sce_pspnet_splunlock(s2);
out:
	_sce_pspnet_splunlock(s);
	return error;
}

int
sceNetInet_lib_4C13BE10(void)
{
	int s;

	s = _sce_pspnet_spllock();
	func_00009984();
	_sce_pspnet_stop_of_pppoe_module_in_netintr();
	func_0002A850();
	_sce_pspnet_splunlock(s);
	return 0;
}
