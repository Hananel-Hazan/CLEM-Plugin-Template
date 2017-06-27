#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../../2015/CLEM/CLEM/CoreFunction/GlobalVar.h"	

#define EXPORT __declspec(dllexport)

CoreFunc_Global_var* Global_Var;			//pointer to all global variables in CLEM

BOOL APIENTRY 
DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

EXPORT void 
DLL_Init(CoreFunc_Global_var *corefunc_global_var, char* str){
	Global_Var = corefunc_global_var;
	Global_Var->DLL_Slow_Process_Running_Freq = 1.0; // Slow process call frequency
	
	// Write initialization code here

	strcpy_s(str, MAXTEXTMESSAGELEN, "Initialized OK\n");
	
}

EXPORT void 
DLL_Engage(int argc, char** argv, char* str){
	
	// Write your pre-closed loop run code here
	
	strcpy_s(str, MAXTEXTMESSAGELEN, "Engaged OK\n");
}

EXPORT void DLL_Disengage(char* str){

	// Write your post-closed loop run code here

	strcpy_s(str, MAXTEXTMESSAGELEN, "Disengaged OK\n");
}

EXPORT void RealTime_CL(double* A_out, float *U_out, unsigned short *D_Out, char* str){
	
	// Write your real-time closed loop code here

}

EXPORT void SlowPeriodic_CL(double* A_out, float *U_out, unsigned short *D_Out, char* str){
	
	// Write your slow periodic closed loop code here

}

