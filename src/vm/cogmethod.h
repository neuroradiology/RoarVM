/* Automatically generated by
	CCodeGenerator VMMaker-oscog.16 uuid: f8b8c00f-be77-4358-a537-ac5dd4e27747
 */

typedef struct {
	sqInt	objectHeader;
	unsigned		cmNumArgs : 8;
	unsigned		cmType : 3;
	unsigned		cmRefersToYoung : 1;
	unsigned		cmIsUnlinked : 1;
	unsigned		cmUsageCount : 3;
	unsigned		stackCheckOffset : 16;
 } CogBlockMethod;

typedef struct {
	sqInt	objectHeader;
	unsigned		cmNumArgs : 8;
	unsigned		cmType : 3;
	unsigned		cmRefersToYoung : 1;
	unsigned		cmIsUnlinked : 1;
	unsigned		cmUsageCount : 3;
	unsigned		stackCheckOffset : 16;
	unsigned short	blockSize;
	unsigned short	blockEntryOffset;
	sqInt	methodObject;
	sqInt	methodHeader;
	sqInt	selector;
 } CogMethod;
