# CLEM C and C++ Plugin Template

User defined closed-loop programs are treated as “plugins” that can be written in any programing language that can produce a standard Window dynamic link library (DLL). These DLLs must conform to certain specifications as described below. DLLs are loaded, activated, stopped and unloaded dynamically by the user. When running, plugin routines have full access to all data stored in central repositories, can use these data to calculate actions (or lack thereof) and then generate output requests, which are thereafter handled by suitable core function threads. User-defined closed-loop routines are developed independently from the main application, allowing the experimenter to write, debug and test these without exiting the main application. These plugins can also generate and store, if so desired, two streams of analog values (User data events) which are displayed on the GUI, representing, for example, control values related to closed-loop procedures (e.g. stimulation intensity) or values calculated on the fly (e.g. spike rates, measures of synchrony, etc.).


```C++
#include <path> GlobalVar.h
#define EXPORT __declspec(dllexport)

// pointer to all global system variables; accessible to all functions within DLL
CoreFunc_Global_var* Global_Var;	

// Called upon loading the user written plugin (DLL)
EXPORT void DLL_Init(CoreFunc_Global_var *corefunc_global_var, char *str){    
    // Store a local copy of the pointer to all systems global variables
    Global_Var = corefunc_global_var;
    // define the call repeat rate for the slow periodic close loop procedure
    Global_Var->DLL_Slow_Process_Running_Freq = 1.0; 
}

// called once upon engaging the closed loop procedures
EXPORT void DLL_Engage(int argc, char **argv, char *str){
    // initialize local variables, etc.
}

// called once upon disengaging the closed loop procedures
EXPORT void DLL_Disengage(char *str){
   // clean up, close files, etc.
}

// Real time closed loop procedure 
EXPORT void RealTime_CL (double *A_out, float *U_out, unsigned short *D_Out, char *str){
    // perform real-time closed loop operations
    // send data to output devices and display
}  

// Slow, periodic closed loop procedure 
EXPORT void SlowPeriodic_CL (double *A_out, float *U_out, unsigned short *D_Out, char *str){
    // perform slow, periodic closed loop operations
    // send data to output devices and display
}
```
