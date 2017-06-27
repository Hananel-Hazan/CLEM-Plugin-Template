#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif
#include "../../../2015/CLEM/CLEM/CoreFunction/GlobalVar.h"	
#ifdef __cplusplus
}
#endif

#define EXPORT __declspec(dllexport)

CoreFunc_Global_var* Global_Var;			// pointer to all global variables in CLEM

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
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

// Get rid of name mangling
extern "C"
{

	EXPORT void 
	DLL_Init(CoreFunc_Global_var *corefunc_global_var, char* str){
		std::string st;

		Global_Var = corefunc_global_var;
		Global_Var->DLL_Slow_Process_Running_Freq = 1.0; // Slow process running speed
		
		// Write initialization code here

		st += "Initialized OK\n";

		strcpy_s(str, MAXTEXTMESSAGELEN, st.c_str());
	}

	EXPORT void 
	DLL_Engage(int argc, char** argv, char* str){
		std::string st;
		
		// Write your pre-closed loop run code here

		st += "Engaged OK\n";
		
		strcpy_s(str, MAXTEXTMESSAGELEN, st.c_str());
	}

	EXPORT void 
	DLL_Disengage(char* str){
		std::string st;
		
		// Write your post-closed loop run code here

		st += "Disengaged OK\n";

		strcpy_s(str, MAXTEXTMESSAGELEN, st.c_str());
	}

	EXPORT void 
	RealTime_CL(double* A_out, float *U_out, unsigned short *D_Out, char* str) {

		// Write your real-time closed loop code here
	}

	EXPORT void SlowPeriodic_CL(double* A_out, float *U_out, unsigned short *D_Out, char* str){

		// Write your slow periodic closed loop code here

	}

}