#include <string>
#include <stdarg.h>

#include <orbis/libkernel.h>

inline static void Notify(const char* FMT, ...)
{
	OrbisNotificationRequest Buffer;

	va_list args;
	va_start(args, FMT);
	vsprintf(Buffer.message, FMT, args);
	va_end(args);

	Buffer.type = OrbisNotificationRequestType::NotificationRequest;
	Buffer.unk3 = 0;
	Buffer.useIconImageUri = 1;
	Buffer.targetId = -1;
	strcpy(Buffer.iconUri, "cxml://psnotification/tex_icon_champions_league");

	sceKernelSendNotificationRequest(0, &Buffer, 3120, 0);
}

inline static void KernelPrintOut(const char* FMT, ...)
{
	char MessageBuf[1024];
	va_list args;
	va_start(args, FMT);
	vsprintf(MessageBuf, FMT, args);
	va_end(args);

	sceKernelDebugOutText(0, MessageBuf);
}