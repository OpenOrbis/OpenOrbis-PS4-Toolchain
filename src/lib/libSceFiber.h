#pragma once

// Params should go here....

// code goes here
// example ABI_SYSV int test(int input);
void _sceFiberAttachContextAndRun();
void _sceFiberAttachContextAndSwitch();
void _sceFiberGetThreadFramePointerAddress();
void _sceFiberInitializeImpl();
void _sceFiberInitializeWithInternalOptionImpl();
void sceFiberFinalize();
void sceFiberGetInfo();
void sceFiberGetSelf();
void sceFiberOptParamInitialize();
void sceFiberRename();
void sceFiberReturnToThread();
void sceFiberRun();
void sceFiberStartContextSizeCheck();
void sceFiberStopContextSizeCheck();
void sceFiberSwitch();
