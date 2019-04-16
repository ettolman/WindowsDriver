//
//  Driver.c
//  
//
//  Created by Erin Tolman
//
#include <ntdd.h>
#include <wdf.h>

DRIVER_INITIALIZE DriveEntery;
EVT_WDF_DRIVER_ADD KmdfHelloWorldEvtDeviceAdd;

// DriverEntry
// The entry point for all drivers, it initializes all driver
// structures and resources.
NTSTATUS
DriverEntry(_In_ PDRIVER_OBJECT DriverObject,
            _In_ PUNICODE_STRING RegistryPath)
{
    // Records success or failure
    NTSTATUS status = STATUS_SUCCESS;
    
    // Allocate the driver configuration object
    WDF_DRIVER_CONFIG config;
    
    // Print to DriverEntry
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry\n"));
    
    // Initialize drive object to register the EvtDeviceAdd callback entry point
    WDF_DRIVER_CONFIG_INIT(&config, EvtDeviceAdd);
    
    // Create the driver object
    status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES,
                             &config, WDF_NO_HANDLE);
    return status;
}


// EvtDeviceAdd
// Called on by the system when it detects the driver has arrived.
// It initializes the resources and structure for that device.
NTSTATUS
EvtDeviceAdd(_In_ WDFDRIVER Driver,
                           _Inout_ PWDFDEVICE_INIT DeviceInit)
{
    // Mark driver object as unreferenced because we are not
    // currently using it
    UNREFERENCED_PARAMETER(Driver);
    
    NTSTATUS status;
    
    // Allocate the device object
    WDFDEVICE hDevice;
    
    // Print "Hello, world!
    KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL,
               "KmdfHelloWorld: EvtDeviceAdd\n"));
    
    // Create the device object
    status = WdfDriverCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES,
                             &hDevice);
    return status;
}
