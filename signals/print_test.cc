#include "print_mask.h"
#include <signal.h>
#include <errorHandle.h>

int
main()
{
	sigset_t mask;
	sigfillset(&mask);

	if(sigprocmask(SIG_BLOCK, &mask, NULL) < 0)
		err_sys("sigprocmask error: %d", __LINE__);

	PrintMask("test:\n");
}
