
#define S_FUNCTION_NAME CIRV_kf_C
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

#define U(element) (*uPtrs[element])  /* Pointer to Input Port0 */


 

/*====================*
 * S-function methods *
 *====================*/

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)//这个函数是用来设置输入输出和参数的
{
    ssSetNumSFcnParams(S, 0);  /* Number of expected parameters设置参数个数，这里为0 */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    ssSetNumContStates(S, 0);//设置连续状态的个数，缺省为0
    ssSetNumDiscStates(S, 6);//设置离散状态的个数，缺省为6？

    if (!ssSetNumInputPorts(S, 1)) return;//设置变量的个数，这里为1
    ssSetInputPortWidth(S, 0, 6);//设置变量0的维数为6
    ssSetInputPortDirectFeedThrough(S, 0, 1);//设置输入端口的信号是否mdlOutputs函数中使用，这里设置为True

    if (!ssSetNumOutputPorts(S, 1)) return;//设置输出变量的个数
    ssSetOutputPortWidth(S, 0, 6);//设置输出变量0的维数是6

    ssSetNumSampleTimes(S, 2);//设置采样时间，此处为2秒
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
//下面可以写全局变量的初始化程序
    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
        ssSetOptions(S,
                 SS_OPTION_WORKS_WITH_CODE_REUSE |
                 SS_OPTION_EXCEPTION_FREE_CODE |
                 SS_OPTION_USE_TLC_WITH_ACCELERATOR);

}



/* Function: mdlInitializeSampleTimes =========================================
*/
static void mdlInitializeSampleTimes(SimStruct *S)
{   ssSetSampleTime(S, 0, 0.5);
    ssSetSampleTime(S, 1, 0.05);
	ssSetOffsetTime(S, 0, 0.0);
    ssSetOffsetTime(S, 1, 0.0);

}



#define MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ========================================
*/
static void mdlInitializeConditions(SimStruct *S)
{
    real_T *x0 = ssGetRealDiscStates(S);
    int_T  lp;

    for (lp=0;lp<6;lp++) { 
        *x0++=0.0; 
    }
}



/* Function: mdlOutputs =======================================================
*/
static void mdlOutputs(SimStruct *S, int_T tid)//这里填入相关的运算和算法等
{
    real_T            *y    = ssGetOutputPortRealSignal(S,0);
    real_T            *x    = ssGetRealDiscStates(S);
    InputRealPtrsType uPtrs= ssGetInputPortRealSignalPtrs(S,0);
 /* not used in single tasking mode */
   if (ssIsSampleHit(S, 0, tid)) {

        y[0]  = x[0]+0.28140538279349*(U(0)-U(3)-x[0]);
        y[1]  = x[1]+0.28140538279349*(U(1)-U(4)-x[1]);
		y[2]  = x[2]+0.28140538279349*(U(2)-U(5)-x[2]);
		y[3]  = x[3]+0.0390476218820*(U(0)-U(3)-x[0]);
		y[4]  = x[4]+0.0390476218820*(U(1)-U(4)-x[1]);
		y[5]  = x[5]+0.0260476218820*(U(2)-U(5)-x[2]);

    } 
   else if (ssIsSampleHit(S, 1, tid)) {
        y[0]  = x[0];
        y[1]  = x[1];
		y[2]  = x[2];
		y[3]  = x[3];
		y[4]  = x[4];
		y[5]  = x[5];}
}



#define MDL_UPDATE
/* Function: mdlUpdate ======================================================
*/
static void mdlUpdate(SimStruct *S, int_T tid)
{
    real_T            *x       = ssGetRealDiscStates(S);
    InputRealPtrsType uPtrs   = ssGetInputPortRealSignalPtrs(S,0);
    real_T            tempx[6]={0,0,0,0,0,0};
    real_T            temp1x[6]={0,0,0,0,0,0};
    real_T            temp2x[6]={0,0,0,0,0,0};
 /* not used in single tasking mode */
if (ssIsSampleHit(S, 0, tid)) {

        temp1x[0]  = x[0]+0.28140538279349*(U(0)-U(3)-x[0]);
        temp1x[1]  = x[1]+0.28140538279349*(U(1)-U(4)-x[1]);
		temp1x[2]  = x[2]+0.28140538279349*(U(2)-U(5)-x[2]);
		temp1x[3]  = x[3]+0.0390476218820*(U(0)-U(3)-x[0]);
		temp1x[4]  = x[4]+0.0390476218820*(U(1)-U(4)-x[1]);
		temp1x[5]  = x[5]+0.0260476218820*(U(2)-U(5)-x[2]); 
        tempx[0]  = temp1x[0]+0.05*temp1x[3];
        tempx[1]  = temp1x[1]+0.05*temp1x[4];
		tempx[2]  = temp1x[2]+0.05*temp1x[5];
		tempx[3]  = temp1x[3];
		tempx[4]  = temp1x[4];
		tempx[5]  = temp1x[5];
		x[0]  = tempx[0];
        x[1]  = tempx[1];
		x[2]  = tempx[2];
		x[3]  = tempx[3];
		x[4]  = tempx[4];
		x[5]  = tempx[5]; 
    } 
   else if (ssIsSampleHit(S, 1, tid)) {
        temp2x[0]  = x[0]+0.05*x[3];
        temp2x[1]  = x[1]+0.05*x[4];
		temp2x[2]  = x[2]+0.05*x[5];
		temp2x[3]  = x[3];
		temp2x[4]  = x[4];
		temp2x[5]  = x[5];
		x[0]  = temp2x[0];
        x[1]  = temp2x[1];
		x[2]  = temp2x[2];
		x[3]  = temp2x[3];
		x[4]  = temp2x[4];
		x[5]  = temp2x[5];

    }


 
}



/* Function: mdlTerminate =====================================================
 * Abstract:
 *    No termination needed, but we are required to have this routine.
 */
static void mdlTerminate(SimStruct *S)//这里需要把global变量全部初始化，否则下次运行程序时，全局变量还是之前的值
{
/* unused input argument */
}

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
