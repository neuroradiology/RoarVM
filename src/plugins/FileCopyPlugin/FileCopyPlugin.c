/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99
   from
	FileCopyPlugin VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99
 */
static char __buildInfo[] = "FileCopyPlugin VMMaker-oscog.40 uuid: 637db40c-33c6-4263-816e-1b8cc19e3c99 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
/*  The virtual machine proxy definition */
#include "sqVirtualMachine.h"
/* Configuration options */
#include "sqConfig.h"
/* Platform specific definitions */
#include "sqPlatformSpecific.h"

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
#undef EXPORT
// was #undef EXPORT(returnType) but screws NorCroft cc
#define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Constants ***/


/*** Function Prototypes ***/
static VirtualMachine * getInterpreter(void);
EXPORT(const char*) getModuleName(void);
static sqInt halt(void);
static sqInt msg(char *s);
EXPORT(sqInt) primitiveFileCopyNamedTo(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
static void sqAssert(sqInt aBool);


/*** Variables ***/

#ifdef SQUEAK_BUILTIN_PLUGIN
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"FileCopyPlugin VMMaker-oscog.40 (i)"
#else
	"FileCopyPlugin VMMaker-oscog.40 (e)"
#endif
;



/*	Note: This is coded so that plugins can be run from Squeak. */

static VirtualMachine *
getInterpreter(void)
{
	return interpreterProxy;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

static sqInt
halt(void)
{
	;
	return 0;
}

static sqInt
msg(char *s)
{
	fprintf(stderr, "\n%s: %s", moduleName, s);
	return 0;
}

EXPORT(sqInt)
primitiveFileCopyNamedTo(void)
{
	char *dstName;
	sqInt dstSz;
	sqInt ok;
	char *srcName;
	sqInt srcSz;

	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(1)));
	srcName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(1))));
	interpreterProxy->success(interpreterProxy->isBytes(interpreterProxy->stackValue(0)));
	dstName = ((char *) (interpreterProxy->firstIndexableField(interpreterProxy->stackValue(0))));
	if (interpreterProxy->failed()) {
		return null;
	}
	srcSz = interpreterProxy->slotSizeOf(((sqInt)(long)(srcName) - 4));
	dstSz = interpreterProxy->slotSizeOf(((sqInt)(long)(dstName) - 4));
	ok = sqCopyFilesizetosize(srcName, srcSz, dstName, dstSz);
	if (!(ok)) {
		interpreterProxy->primitiveFail();
	}
	if (interpreterProxy->failed()) {
		return null;
	}
	interpreterProxy->pop(2);
	return null;
}


/*	Note: This is coded so that is can be run from Squeak. */

EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = interpreterProxy->majorVersion() == VM_PROXY_MAJOR;
	if (ok == 0) {
		return 0;
	}
	ok = interpreterProxy->minorVersion() >= VM_PROXY_MINOR;
	return ok;
}

static void
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

void* FileCopyPlugin_exports[][3] = {
	{"FileCopyPlugin", "getModuleName", (void*)getModuleName},
	{"FileCopyPlugin", "primitiveFileCopyNamedTo", (void*)primitiveFileCopyNamedTo},
	{"FileCopyPlugin", "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#endif /* ifdef SQ_BUILTIN_PLUGIN */
