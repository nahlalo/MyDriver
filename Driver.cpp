#include <ntddk.h> // المكتبة الأساسية لكل الدرايفرات

// هذه الوظيفة يتم استدعاؤها عند إلغاء تحميل الدرايفر
VOID DriverUnload(PDRIVER_OBJECT DriverObject) {
    UNREFERENCED_PARAMETER(DriverObject);
    // نطبع رسالة في شاشة الديباج لنعرف أن الدرايفر تم إلغاء تحميله
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "MyDriver: Unloaded\n"));
}

// هذه هي نقطة البداية للدرايفر، مثل main() في البرامج العادية
extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    // نحدد وظيفة إلغاء التحميل
    DriverObject->DriverUnload = DriverUnload;

    // نطبع رسالة في شاشة الديباج لنعرف أن الدرايفر بدأ بنجاح
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "MyDriver: Hello from the Kernel!\n"));

    return STATUS_SUCCESS;
}
