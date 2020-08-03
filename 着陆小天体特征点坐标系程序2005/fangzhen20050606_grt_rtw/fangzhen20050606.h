/*
 * fangzhen20050606.h
 *
 * Code generation for model "fangzhen20050606".
 *
 * Model version              : 1.221
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Fri Mar 10 19:19:15 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_fangzhen20050606_h_
#define RTW_HEADER_fangzhen20050606_h_
#ifndef fangzhen20050606_COMMON_INCLUDES_
# define fangzhen20050606_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_defines.h"
#endif                                 /* fangzhen20050606_COMMON_INCLUDES_ */

#include "fangzhen20050606_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define fangzhen20050606_rtModel       RT_MODEL_fangzhen20050606

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Constant1[3];                 /* '<S9>/Constant1' */
  real_T Noign[3];                     /* '<S87>/Noign' */
  real_T Sum[3];                       /* '<S87>/Sum' */
  real_T Constant3[4];                 /* '<S10>/Constant3' */
  real_T VectorConcatenate[9];         /* '<S20>/Vector Concatenate' */
  real_T Integrator1[3];               /* '<S36>/Integrator1' */
  real_T RandomNumber[6];              /* '<S85>/Random Number' */
  real_T RandomNumber_i[3];            /* '<S84>/Random Number' */
  real_T e1[3];                        /* '<S91>/e1' */
  real_T e3[3];                        /* '<S91>/e3' */
  real_T Sum_o[3];                     /* '<S94>/Sum' */
  real_T Merge[4];                     /* '<S92>/Merge' */
  real_T SFunction[7];                 /* '<S83>/S-Function' */
  real_T VectorConcatenate_p[9];       /* '<S63>/Vector Concatenate' */
  real_T Integrator1_p[3];             /* '<S82>/Integrator1' */
  real_T e5[3];                        /* '<S91>/e5' */
  real_T SFunction_k[6];               /* '<S86>/S-Function' */
  real_T Sum4[3];                      /* '<S86>/Sum4' */
  real_T Integrator[3];                /* '<S82>/Integrator' */
  real_T Sum1[3];                      /* '<S86>/Sum1' */
  real_T MathFunction;                 /* '<S147>/Math Function' */
  real_T MathFunction1;                /* '<S148>/Math Function1' */
  real_T Product3;                     /* '<S148>/Product3' */
  real_T Product3_l;                   /* '<S149>/Product3' */
  real_T Product4;                     /* '<S149>/Product4' */
  real_T Sum1_j[3];                    /* '<S150>/Sum1' */
  real_T Sum1_a[3];                    /* '<S151>/Sum1' */
  real_T Sum_oq[6];                    /* '<S52>/Sum' */
  real_T Product2[6];                  /* '<S52>/Product2' */
  real_T Sum_h[6];                     /* '<S2>/Sum' */
  real_T Sum1_m[3];                    /* '<S49>/Sum1' */
  real_T Product3_f[3];                /* '<S49>/Product3' */
  real_T Integrator_n[3];              /* '<S36>/Integrator' */
  real_T Gain1[3];                     /* '<S1>/Gain1' */
  real_T Clock_o;                      /* '<S1>/Clock' */
  real_T Clock1;                       /* '<S1>/Clock1' */
  real_T Gain2[3];                     /* '<S1>/Gain2' */
  real_T invJW[4];                     /* '<S25>/invJW' */
  real_T JW[4];                        /* '<S24>/JW' */
  real_T DWN[3];                       /* '<S24>/DWN' */
  real_T IW[4];                        /* '<S24>/IW' */
  real_T DWN2[3];                      /* '<S24>/DWN2' */
  real_T DWN1[3];                      /* '<S24>/DWN1' */
  real_T Sum_e[3];                     /* '<S26>/Sum' */
  real_T Constant1_e[3];               /* '<S50>/Constant1' */
  real_T Product5[3];                  /* '<S50>/Product5' */
  real_T Sum_c[3];                     /* '<S50>/Sum' */
  real_T DiscreteTimeIntegrator[3];    /* '<S50>/Discrete-Time Integrator' */
  real_T Saturation[3];                /* '<S50>/Saturation' */
  real_T Sum_p[4];                     /* '<S25>/Sum' */
  real_T Sum1_p[3];                    /* '<S9>/Sum1' */
  real_T Gain;                         /* '<S10>/Gain' */
  real_T Gain1_a[3];                   /* '<S10>/Gain1' */
  real_T Sum2;                         /* '<S36>/Sum2' */
  real_T Sum1_o[3];                    /* '<S36>/Sum1' */
  real_T Sum_b[3];                     /* '<S36>/Sum' */
  real_T Sum3;                         /* '<S36>/Sum3' */
  real_T Gain1_c[3];                   /* '<S2>/Gain1' */
  real_T Clock_a;                      /* '<S2>/Clock' */
  real_T Gain2_d[3];                   /* '<S2>/Gain2' */
  real_T Gain1_f[3];                   /* '<S51>/Gain1' */
  real_T MathFunction_k[9];            /* '<S82>/Math Function' */
  real_T RandomNumber_i1[3];           /* '<S82>/Random Number' */
  real_T Product1[3];                  /* '<S82>/Product1' */
  real_T Noign1[3];                    /* '<S87>/Noign1' */
  real_T Constant1_b[2];               /* '<S143>/Constant1' */
  real_T Rt[3];                        /* '<S143>/Rt' */
  real_T Sum4_a;                       /* '<S143>/Sum4' */
  real_T Sum1_pf;                      /* '<S146>/Sum1' */
  real_T In1[6];                       /* '<S142>/In1' */
  real_T In1_p[7];                     /* '<S141>/In1' */
  boolean_T LogicalOperator1;          /* '<S36>/Logical Operator1' */
} BlockIO_fangzhen20050606;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunction_DSTATE[7];          /* '<S83>/S-Function' */
  real_T SFunction_DSTATE_h[6];        /* '<S86>/S-Function' */
  real_T Unitdelay_DSTATE[4];          /* '<S24>/Unit delay' */
  real_T DiscreteTimeIntegrator_DSTATE[4];/* '<S25>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_i[3];/* '<S50>/Discrete-Time Integrator' */
  real_T NextOutput[3];                /* '<S87>/Noign' */
  real_T NextOutput_m[6];              /* '<S85>/Random Number' */
  real_T NextOutput_p[3];              /* '<S84>/Random Number' */
  real_T NextOutput_c[4];              /* '<S25>/TWi' */
  real_T NextOutput_n[3];              /* '<S82>/Random Number' */
  real_T NextOutput_nz[3];             /* '<S87>/Noign1' */
  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } R1_PWORK;                          /* '<S1>/R1' */

  struct {
    void *LoggedData;
  } R2_PWORK;                          /* '<S1>/R2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_c;               /* '<S1>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S1>/To Workspace1' */

  struct {
    void *LoggedData;
  } R2_PWORK_g;                        /* '<S3>/R2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S24>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S24>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S24>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S24>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S24>/Scope5' */

  struct {
    void *LoggedData;
  } R3_PWORK;                          /* '<S25>/R3' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S36>/Scope6' */

  struct {
    void *LoggedData;
  } W_PWORK;                           /* '<S36>/W' */

  struct {
    void *LoggedData;
  } R1_PWORK_j;                        /* '<S2>/R1' */

  struct {
    void *LoggedData;
  } R2_PWORK_n;                        /* '<S2>/R2' */

  struct {
    void *LoggedData;
  } R3_PWORK_o;                        /* '<S2>/R3' */

  struct {
    void *LoggedData;
  } R4_PWORK;                          /* '<S2>/R4' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_i;               /* '<S2>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_j;              /* '<S2>/To Workspace1' */

  struct {
    void *LoggedData;
  } R2_PWORK_ga;                       /* '<S50>/R2' */

  struct {
    void *LoggedData;
  } R1_PWORK_p;                        /* '<S51>/R1' */

  struct {
    void *LoggedData;
  } R2_PWORK_o;                        /* '<S51>/R2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_m;               /* '<S51>/To Workspace' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK_o;              /* '<S51>/To Workspace1' */

  struct {
    void *LoggedData;
  } R1_PWORK_i;                        /* '<S91>/R1' */

  struct {
    void *LoggedData;
  } R2_PWORK_gw;                       /* '<S91>/R2' */

  struct {
    void *LoggedData;
  } R2_PWORK_o2;                       /* '<S82>/R2' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S85>/Scope' */

  struct {
    void *LoggedData;
  } Scope5_PWORK_e;                    /* '<S86>/Scope5' */

  struct {
    void *LoggedData;
  } R1_PWORK_d;                        /* '<S52>/R1' */

  struct {
    void *LoggedData;
  } R3_PWORK_m;                        /* '<S52>/R3' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_o;               /* '<S52>/To Workspace' */

  struct {
    void *LoggedData;
  } R_PWORK;                           /* '<S144>/R' */

  uint32_T RandSeed[3];                /* '<S87>/Noign' */
  uint32_T RandSeed_j[6];              /* '<S85>/Random Number' */
  uint32_T RandSeed_i[3];              /* '<S84>/Random Number' */
  uint32_T RandSeed_f[4];              /* '<S25>/TWi' */
  uint32_T RandSeed_g[3];              /* '<S82>/Random Number' */
  uint32_T RandSeed_i2[3];             /* '<S87>/Noign1' */
  struct {
    int_T IcNeedsLoading;
  } Integrator1_IWORK;                 /* '<S9>/Integrator1' */

  struct {
    int_T IcNeedsLoading;
  } Integrator_IWORK;                  /* '<S10>/Integrator' */

  int8_T If_ActiveSubsystem;           /* '<S92>/If' */
  int8_T FindMaximumDiagonalValue_Active;/* '<S95>/Find Maximum Diagonal Value' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S50>/Discrete-Time Integrator' */
  boolean_T Subsystem2_MODE;           /* '<S52>/Subsystem2' */
  boolean_T Subsystem_MODE;            /* '<S52>/Subsystem' */
  boolean_T u_MODE;                    /* '<S52>/轨迹制导2' */
} D_Work_fangzhen20050606;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S9>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S87>/Integrator' */
  real_T Integrator_CSTATE_a[4];       /* '<S10>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S36>/Integrator1' */
  real_T Integrator1_CSTATE_l[3];      /* '<S82>/Integrator1' */
  real_T Integrator_CSTATE_d[3];       /* '<S82>/Integrator' */
  real_T Integrator_CSTATE_do[3];      /* '<S36>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S36>/Integrator2' */
} ContinuousStates_fangzhen20050606;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S9>/Integrator1' */
  real_T Integrator_CSTATE[3];         /* '<S87>/Integrator' */
  real_T Integrator_CSTATE_a[4];       /* '<S10>/Integrator' */
  real_T Integrator1_CSTATE_g[3];      /* '<S36>/Integrator1' */
  real_T Integrator1_CSTATE_l[3];      /* '<S82>/Integrator1' */
  real_T Integrator_CSTATE_d[3];       /* '<S82>/Integrator' */
  real_T Integrator_CSTATE_do[3];      /* '<S36>/Integrator' */
  real_T Integrator2_CSTATE;           /* '<S36>/Integrator2' */
} StateDerivatives_fangzhen20050606;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S9>/Integrator1' */
  boolean_T Integrator_CSTATE[3];      /* '<S87>/Integrator' */
  boolean_T Integrator_CSTATE_a[4];    /* '<S10>/Integrator' */
  boolean_T Integrator1_CSTATE_g[3];   /* '<S36>/Integrator1' */
  boolean_T Integrator1_CSTATE_l[3];   /* '<S82>/Integrator1' */
  boolean_T Integrator_CSTATE_d[3];    /* '<S82>/Integrator' */
  boolean_T Integrator_CSTATE_do[3];   /* '<S36>/Integrator' */
  boolean_T Integrator2_CSTATE;        /* '<S36>/Integrator2' */
} StateDisabled_fangzhen20050606;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            fangzhen20050606_B
#define BlockIO                        BlockIO_fangzhen20050606
#define rtX                            fangzhen20050606_X
#define ContinuousStates               ContinuousStates_fangzhen20050606
#define rtXdot                         fangzhen20050606_Xdot
#define StateDerivatives               StateDerivatives_fangzhen20050606
#define tXdis                          fangzhen20050606_Xdis
#define StateDisabled                  StateDisabled_fangzhen20050606
#define rtP                            fangzhen20050606_P
#define Parameters                     Parameters_fangzhen20050606
#define rtDWork                        fangzhen20050606_DWork
#define D_Work                         D_Work_fangzhen20050606

/* Parameters (auto storage) */
struct Parameters_fangzhen20050606_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S96>/Constant'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S96>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 2
                                        * Referenced by: '<S96>/Gain1'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S111>/Constant'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.5
                                        * Referenced by: '<S99>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S110>/Constant1'
                                        */
  real_T Constant2_Value[2];           /* Expression: [0 1]
                                        * Referenced by: '<S110>/Constant2'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S99>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S99>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S99>/Gain4'
                                        */
  real_T Constant_Value_kg;            /* Expression: 1
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 0.5
                                        * Referenced by: '<S100>/Gain'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0.5
                                        * Referenced by: '<S115>/Constant1'
                                        */
  real_T Constant2_Value_i[2];         /* Expression: [0 1]
                                        * Referenced by: '<S115>/Constant2'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S100>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S100>/Gain2'
                                        */
  real_T Gain3_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S100>/Gain3'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S106>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 0.5
                                        * Referenced by: '<S98>/Gain'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0.5
                                        * Referenced by: '<S105>/Constant1'
                                        */
  real_T Constant2_Value_p[2];         /* Expression: [0 1]
                                        * Referenced by: '<S105>/Constant2'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain2'
                                        */
  real_T Gain3_Gain_k;                 /* Expression: 1
                                        * Referenced by: '<S98>/Gain3'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: [0 0]
                                        * Referenced by: '<S143>/Constant1'
                                        */
  real_T Constant2_Value_o;            /* Expression: T
                                        * Referenced by: '<S143>/Constant2'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<S145>/Gain2'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -2
                                        * Referenced by: '<S145>/Gain1'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: -3
                                        * Referenced by: '<S145>/Gain4'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: -6
                                        * Referenced by: '<S146>/Gain1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: -4
                                        * Referenced by: '<S146>/Gain2'
                                        */
  real_T Gain4_Gain_e;                 /* Expression: 6
                                        * Referenced by: '<S146>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 3
                                        * Referenced by: '<S146>/Gain5'
                                        */
  real_T Noigc_Value[3];               /* Expression: Noise_gc
                                        * Referenced by: '<S87>/Noigc'
                                        */
  real_T Wcc_Gain[3];                  /* Expression: Wcc
                                        * Referenced by: '<S87>/Wcc'
                                        */
  real_T AWcc_Gain[3];                 /* Expression: AWcc
                                        * Referenced by: '<S87>/AWcc'
                                        */
  real_T Constant1_Value_k[3];         /* Expression: HBd0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T InvIBu_Gain[9];               /* Expression: InvIBd
                                        * Referenced by: '<S9>/InvIBu'
                                        */
  real_T Wgmax_UpperSat[3];            /* Expression: Wgmax
                                        * Referenced by: '<S87>/Wgmax'
                                        */
  real_T Wgmax_LowerSat[3];            /* Expression: -Wgmax
                                        * Referenced by: '<S87>/Wgmax'
                                        */
  real_T Noign_Mean[3];                /* Expression: [0 0 0]
                                        * Referenced by: '<S87>/Noign'
                                        */
  real_T Noign_StdDev[3];              /* Computed Parameter: Noign_StdDev
                                        * Referenced by: '<S87>/Noign'
                                        */
  real_T Noign_Seed[3];                /* Expression: [1859 2483 4682]
                                        * Referenced by: '<S87>/Noign'
                                        */
  real_T Integrator_IC[3];             /* Expression: [0;0;0]
                                        * Referenced by: '<S87>/Integrator'
                                        */
  real_T Constant3_Value[4];           /* Expression: Qb0
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 2
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Gain_Gain_ab;                 /* Expression: 2
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 2
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 2
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 2
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 2
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Integrator1_IC[3];            /* Expression: r0
                                        * Referenced by: '<S36>/Integrator1'
                                        */
  real_T Constant_Value_f[3];          /* Expression: TA
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value_f[3];         /* Expression: TB
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_g[3];         /* Expression: TC
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T RandomNumber_Mean[6];         /* Expression: [0 0 0 0 0 0]
                                        * Referenced by: '<S85>/Random Number'
                                        */
  real_T RandomNumber_StdDev[6];       /* Computed Parameter: RandomNumber_StdDev
                                        * Referenced by: '<S85>/Random Number'
                                        */
  real_T RandomNumber_Seed[6];         /* Expression: [15683 12482 12355 15000 12000 12000]
                                        * Referenced by: '<S85>/Random Number'
                                        */
  real_T RandomNumber_Mean_k[3];       /* Expression: [0 0 0]
                                        * Referenced by: '<S84>/Random Number'
                                        */
  real_T RandomNumber_StdDev_n[3];     /* Computed Parameter: RandomNumber_StdDev_n
                                        * Referenced by: '<S84>/Random Number'
                                        */
  real_T RandomNumber_Seed_k[3];       /* Expression: [15683 12482 12355]
                                        * Referenced by: '<S84>/Random Number'
                                        */
  real_T Constant_Value_p;             /* Expression: f
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: f
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: f
                                        * Referenced by: '<S90>/Constant'
                                        */
  real_T Merge_InitialOutput[4];       /* Expression: [1 0 0 0]
                                        * Referenced by: '<S92>/Merge'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 2
                                        * Referenced by: '<S57>/Gain'
                                        */
  real_T Gain_Gain_hx;                 /* Expression: 2
                                        * Referenced by: '<S60>/Gain'
                                        */
  real_T Gain_Gain_ml;                 /* Expression: 2
                                        * Referenced by: '<S55>/Gain'
                                        */
  real_T Gain_Gain_p;                  /* Expression: 2
                                        * Referenced by: '<S61>/Gain'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 2
                                        * Referenced by: '<S56>/Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 2
                                        * Referenced by: '<S59>/Gain'
                                        */
  real_T Constant4_Value;              /* Expression: 100000
                                        * Referenced by: '<S53>/Constant4'
                                        */
  real_T Integrator1_IC_m[3];          /* Expression: rg0
                                        * Referenced by: '<S82>/Integrator1'
                                        */
  real_T Gain_Gain_ac;                 /* Expression: -1
                                        * Referenced by: '<S91>/Gain'
                                        */
  real_T Integrator_IC_k[3];           /* Expression: vg0
                                        * Referenced by: '<S82>/Integrator'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0.0000000001
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T T_Value;                      /* Expression: T
                                        * Referenced by: '<S144>/T'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -6
                                        * Referenced by: '<S147>/Gain'
                                        */
  real_T Constant5_Value[3];           /* Expression: [0;0;0]
                                        * Referenced by: '<S52>/Constant5'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: -12
                                        * Referenced by: '<S147>/Gain1'
                                        */
  real_T Gain1_Gain_ni;                /* Expression: 0.5
                                        * Referenced by: '<S150>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 18
                                        * Referenced by: '<S148>/Gain2'
                                        */
  real_T Gain3_Gain_j;                 /* Expression: 48
                                        * Referenced by: '<S148>/Gain3'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1/6
                                        * Referenced by: '<S150>/Gain3'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: -12
                                        * Referenced by: '<S149>/Gain2'
                                        */
  real_T Gain3_Gain_d3;                /* Expression: -36
                                        * Referenced by: '<S149>/Gain3'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: 1/12
                                        * Referenced by: '<S150>/Gain2'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: 0.5
                                        * Referenced by: '<S151>/Gain3'
                                        */
  real_T Gain1_Gain_dz;                /* Expression: 1/3
                                        * Referenced by: '<S151>/Gain1'
                                        */
  real_T Constant3_Value_n[3];         /* Expression: Rtb
                                        * Referenced by: '<S53>/Constant3'
                                        */
  real_T Constant2_Value_l[3];         /* Expression: [0;0;0]
                                        * Referenced by: '<S52>/Constant2'
                                        */
  real_T Constant3_Value_m;            /* Expression: T
                                        * Referenced by: '<S52>/Constant3'
                                        */
  real_T Constant_Value_m3;            /* Expression: d
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1/2/a
                                        * Referenced by: '<S78>/Gain'
                                        */
  real_T Constant3_Value_c[3];         /* Expression: [(2*a*a0/(a+a0)*b)^0.5;(2*a*a0/(a+a0)*b)^0.5;(2*a*a0/(a+a0)*b)^0.5]
                                        * Referenced by: '<S49>/Constant3'
                                        */
  real_T Gain_Gain_jf;                 /* Expression: -1
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 1/2/a0
                                        * Referenced by: '<S78>/Gain1'
                                        */
  real_T Constant1_Value_e;            /* Expression: d-b
                                        * Referenced by: '<S78>/Constant1'
                                        */
  real_T Gain1_Gain_gz;                /* Expression: -1
                                        * Referenced by: '<S76>/Gain1'
                                        */
  real_T Constant_Value_fr;            /* Expression: -d+b
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T Gain_Gain_ei;                 /* Expression: -1/2/a0
                                        * Referenced by: '<S77>/Gain'
                                        */
  real_T Gain1_Gain_gw;                /* Expression: 1/2/a
                                        * Referenced by: '<S77>/Gain1'
                                        */
  real_T Constant1_Value_fs;           /* Expression: -d
                                        * Referenced by: '<S77>/Constant1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1
                                        * Referenced by: '<S75>/Gain'
                                        */
  real_T Constant_Value_d;             /* Expression: T
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Integrator_IC_e[3];           /* Expression: v0
                                        * Referenced by: '<S36>/Integrator'
                                        */
  real_T Gain2_Gain_aj;                /* Expression: -1
                                        * Referenced by: '<S35>/Gain2'
                                        */
  real_T Gain1_Gain_mr;                /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 180/pi
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Constant_Value_a[3];          /* Expression: We
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Unitdelay_InitialCondition[4];/* Expression: HWw0
                                        * Referenced by: '<S24>/Unit delay'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S25>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC[4]; /* Expression: HWw0
                                        * Referenced by: '<S25>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator_UpperSat[4];/* Expression: Hwmax
                                             * Referenced by: '<S25>/Discrete-Time Integrator'
                                             */
  real_T DiscreteTimeIntegrator_LowerSat[4];/* Expression: -Hwmax
                                             * Referenced by: '<S25>/Discrete-Time Integrator'
                                             */
  real_T invJW_Gain[4];                /* Expression: invJW
                                        * Referenced by: '<S25>/invJW'
                                        */
  real_T JW_Gain[4];                   /* Expression: JW
                                        * Referenced by: '<S24>/JW'
                                        */
  real_T T_Gain;                       /* Expression: 20
                                        * Referenced by: '<S24>/1//T'
                                        */
  real_T DWN_Gain[12];                 /* Expression: DWN
                                        * Referenced by: '<S24>/DWN'
                                        */
  real_T IW_Gain[4];                   /* Expression: IW
                                        * Referenced by: '<S24>/IW'
                                        */
  real_T DWN2_Gain[12];                /* Expression: DWN
                                        * Referenced by: '<S24>/DWN2'
                                        */
  real_T DWN1_Gain[12];                /* Expression: DWN
                                        * Referenced by: '<S24>/DWN1'
                                        */
  real_T TWi_Mean[4];                  /* Expression: [0 0 0 0]
                                        * Referenced by: '<S25>/TWi'
                                        */
  real_T TWi_StdDev[4];                /* Computed Parameter: TWi_StdDev
                                        * Referenced by: '<S25>/TWi'
                                        */
  real_T TWi_Seed[4];                  /* Expression: [0 0 0 0]
                                        * Referenced by: '<S25>/TWi'
                                        */
  real_T CWw_Gain[4];                  /* Expression: CWw
                                        * Referenced by: '<S25>/CWw'
                                        */
  real_T Constant2_Value_op[4];        /* Expression: [0 0 0 0]
                                        * Referenced by: '<S25>/Constant2'
                                        */
  real_T Tf0_Gain[4];                  /* Expression: TWf0
                                        * Referenced by: '<S25>/Tf0'
                                        */
  real_T Constant1_Value_j5[3];        /* Expression: [0 0 0]
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;/* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                          * Referenced by: '<S50>/Discrete-Time Integrator'
                                          */
  real_T Ki_Gain[3];                   /* Expression: Ki
                                        * Referenced by: '<S50>/Ki'
                                        */
  real_T Saturation_UpperSat[3];       /* Expression: [0.01, 0.01, 0.01]
                                        * Referenced by: '<S50>/Saturation'
                                        */
  real_T Saturation_LowerSat[3];       /* Expression: [-0.01, -0.01, -0.01]
                                        * Referenced by: '<S50>/Saturation'
                                        */
  real_T Kp_Gain[3];                   /* Expression: Kp
                                        * Referenced by: '<S50>/Kp'
                                        */
  real_T Kd_Gain[3];                   /* Expression: Kd
                                        * Referenced by: '<S50>/Kd'
                                        */
  real_T Gain_Gain_c2[3];              /* Expression: [-1 -1 -1]
                                        * Referenced by: '<S50>/Gain'
                                        */
  real_T MWN_Gain[12];                 /* Expression: MWN
                                        * Referenced by: '<S50>/MWN'
                                        */
  real_T Saturation_UpperSat_a[4];     /* Expression: Tcmax
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat_o[4];     /* Expression: -Tcmax
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -0.5
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 0.5
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain_Gain_cs;                 /* Expression: F
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T m0_Value;                     /* Expression: m0
                                        * Referenced by: '<S36>/m0'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S36>/Integrator2'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0.1
                                        * Referenced by: '<S36>/Constant2'
                                        */
  real_T Constant_Value_lv;            /* Expression: 5
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0.06
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T MatrixGain_Gain[9];           /* Expression: Tl'
                                        * Referenced by: '<S38>/Matrix Gain'
                                        */
  real_T u0R0_Value[3];                /* Expression: R0
                                        * Referenced by: '<S38>/[0;0;R0]'
                                        */
  real_T MatrixGain1_Gain[9];          /* Expression: Gl
                                        * Referenced by: '<S38>/Matrix Gain1'
                                        */
  real_T Constant4_Value_d;            /* Expression: -Mu
                                        * Referenced by: '<S43>/Constant4'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S43>/Constant3'
                                        */
  real_T Constant2_Value_f;            /* Expression: re^2
                                        * Referenced by: '<S43>/Constant2'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Gain_Gain_ju;                 /* Expression: 5
                                        * Referenced by: '<S43>/Gain'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 3*c20/2
                                        * Referenced by: '<S43>/Gain1'
                                        */
  real_T Constant1_Value_eb;           /* Expression: 2
                                        * Referenced by: '<S43>/Constant1'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S43>/Gain2'
                                        */
  real_T Gain3_Gain_dv;                /* Expression: 5
                                        * Referenced by: '<S43>/Gain3'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 3*c22
                                        * Referenced by: '<S43>/Gain4'
                                        */
  real_T Constant4_Value_a;            /* Expression: -Mu
                                        * Referenced by: '<S44>/Constant4'
                                        */
  real_T Constant3_Value_cb;           /* Expression: 1
                                        * Referenced by: '<S44>/Constant3'
                                        */
  real_T Constant2_Value_pw;           /* Expression: re^2
                                        * Referenced by: '<S44>/Constant2'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Gain_Gain_jw;                 /* Expression: 5
                                        * Referenced by: '<S44>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 3*c20/2
                                        * Referenced by: '<S44>/Gain1'
                                        */
  real_T Constant1_Value_g;            /* Expression: 2
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T Gain2_Gain_gy;                /* Expression: 2
                                        * Referenced by: '<S44>/Gain2'
                                        */
  real_T Gain3_Gain_om;                /* Expression: 5
                                        * Referenced by: '<S44>/Gain3'
                                        */
  real_T Gain4_Gain_a;                 /* Expression: 3*c22
                                        * Referenced by: '<S44>/Gain4'
                                        */
  real_T Constant4_Value_de;           /* Expression: -Mu
                                        * Referenced by: '<S45>/Constant4'
                                        */
  real_T Constant3_Value_g;            /* Expression: 1
                                        * Referenced by: '<S45>/Constant3'
                                        */
  real_T Constant2_Value_n;            /* Expression: re^2
                                        * Referenced by: '<S45>/Constant2'
                                        */
  real_T Constant_Value_e;             /* Expression: 3
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Gain_Gain_jh;                 /* Expression: 5
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 3*c20/2
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real_T Gain2_Gain_pd;                /* Expression: 2
                                        * Referenced by: '<S45>/Gain2'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 15*c22
                                        * Referenced by: '<S45>/Gain4'
                                        */
  real_T MatrixGain2_Gain[9];          /* Expression: Gl'
                                        * Referenced by: '<S38>/Matrix Gain2'
                                        */
  real_T R0_Value[3];                  /* Expression: R0
                                        * Referenced by: '<S39>/R0'
                                        */
  real_T MatrixGain_Gain_o[9];         /* Expression: -A
                                        * Referenced by: '<S39>/Matrix Gain'
                                        */
  real_T MatrixGain_Gain_n[9];         /* Expression: -B
                                        * Referenced by: '<S37>/Matrix Gain'
                                        */
  real_T Gain_Gain_ae;                 /* Expression: 1/Isp
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Gain_Gain_if;                 /* Expression: 2
                                        * Referenced by: '<S72>/Gain'
                                        */
  real_T Gain_Gain_ib;                 /* Expression: 2
                                        * Referenced by: '<S70>/Gain'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 2
                                        * Referenced by: '<S69>/Gain'
                                        */
  real_T Gain1_Gain_j1;                /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain2_Gain_fq;                /* Expression: 180/pi
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain_Gain_lv;                 /* Expression: 2
                                        * Referenced by: '<S138>/Gain'
                                        */
  real_T Gain_Gain_ae0;                /* Expression: 2
                                        * Referenced by: '<S136>/Gain'
                                        */
  real_T Gain_Gain_jk;                 /* Expression: 2
                                        * Referenced by: '<S135>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 180/pi
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real_T Gain_Gain_j5;                 /* Expression: 2
                                        * Referenced by: '<S121>/Gain'
                                        */
  real_T Gain_Gain_li;                 /* Expression: 2
                                        * Referenced by: '<S122>/Gain'
                                        */
  real_T Gain_Gain_dl;                 /* Expression: 2
                                        * Referenced by: '<S123>/Gain'
                                        */
  real_T Gain_Gain_nd;                 /* Expression: 2
                                        * Referenced by: '<S125>/Gain'
                                        */
  real_T Gain_Gain_mz;                 /* Expression: 2
                                        * Referenced by: '<S126>/Gain'
                                        */
  real_T Gain_Gain_a4;                 /* Expression: 2
                                        * Referenced by: '<S127>/Gain'
                                        */
  real_T RandomNumber_Mean_a[3];       /* Expression: [0 0 0]
                                        * Referenced by: '<S82>/Random Number'
                                        */
  real_T RandomNumber_StdDev_k[3];     /* Computed Parameter: RandomNumber_StdDev_k
                                        * Referenced by: '<S82>/Random Number'
                                        */
  real_T RandomNumber_Seed_c[3];       /* Expression: [15683 12482 12355]
                                        * Referenced by: '<S82>/Random Number'
                                        */
  real_T cp_Value[3];                  /* Expression: [0 0 0]
                                        * Referenced by: '<S82>/cp'
                                        */
  real_T Noign1_Mean[3];               /* Expression: [0 0 0]
                                        * Referenced by: '<S87>/Noign1'
                                        */
  real_T Noign1_StdDev[3];             /* Computed Parameter: Noign1_StdDev
                                        * Referenced by: '<S87>/Noign1'
                                        */
  real_T Noign1_Seed[3];               /* Expression: [4983 1983 6943]
                                        * Referenced by: '<S87>/Noign1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_fangzhen20050606 {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[5];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssStatesInfo2 statesInfo2[2];
    struct {
      time_T sfcnPeriod[2];
      time_T sfcnOffset[2];
      int_T sfcnTsMap[2];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[7];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[2];
      time_T sfcnOffset[2];
      int_T sfcnTsMap[2];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[6];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[23];
    real_T odeF[4][23];
    ODE4_IntgData intgData;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    time_T stepSize4;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[5];
    time_T offsetTimesArray[5];
    int_T sampleTimeTaskIDArray[5];
    int_T sampleHitArray[5];
    int_T perTaskSampleHitsArray[25];
    time_T tArray[5];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_fangzhen20050606 fangzhen20050606_P;

/* Block signals (auto storage) */
extern BlockIO_fangzhen20050606 fangzhen20050606_B;

/* Continuous states (auto storage) */
extern ContinuousStates_fangzhen20050606 fangzhen20050606_X;

/* Block states (auto storage) */
extern D_Work_fangzhen20050606 fangzhen20050606_DWork;

/* Model entry point functions */
extern void fangzhen20050606_initialize(void);
extern void fangzhen20050606_output(void);
extern void fangzhen20050606_update(void);
extern void fangzhen20050606_terminate(void);

/* Real-time Model object */
extern RT_MODEL_fangzhen20050606 *const fangzhen20050606_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'fangzhen20050606'
 * '<S1>'   : 'fangzhen20050606/Dynamics System动力系统'
 * '<S2>'   : 'fangzhen20050606/GNC System'
 * '<S3>'   : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态'
 * '<S4>'   : 'fangzhen20050606/Dynamics System动力系统/Direction Cosine Matrix to Euler Angles'
 * '<S5>'   : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道'
 * '<S6>'   : 'fangzhen20050606/Dynamics System动力系统/Transform'
 * '<S7>'   : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix'
 * '<S8>'   : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/反作用飞轮'
 * '<S9>'   : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/姿态动力学模型'
 * '<S10>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/星体运动学'
 * '<S11>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A11'
 * '<S12>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A12'
 * '<S13>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A13'
 * '<S14>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A21'
 * '<S15>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A22'
 * '<S16>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A23'
 * '<S17>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A31'
 * '<S18>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A32'
 * '<S19>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/A33'
 * '<S20>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/Create Transformation Matrix'
 * '<S21>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
 * '<S22>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
 * '<S23>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S24>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/反作用飞轮/Torque'
 * '<S25>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/反作用飞轮/wheelmid'
 * '<S26>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/反作用飞轮/Torque/3x3 Cross Product'
 * '<S27>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/姿态动力学模型/3x3 Cross Product'
 * '<S28>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/星体运动学/3x3 Cross Product'
 * '<S29>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/星体运动学/3x3 Cross Product/Subsystem'
 * '<S30>'  : 'fangzhen20050606/Dynamics System动力系统/Attitude姿态/星体运动学/3x3 Cross Product/Subsystem1'
 * '<S31>'  : 'fangzhen20050606/Dynamics System动力系统/Direction Cosine Matrix to Euler Angles/cos(phi)cos(theta)'
 * '<S32>'  : 'fangzhen20050606/Dynamics System动力系统/Direction Cosine Matrix to Euler Angles/cos(psi)cos(theta)'
 * '<S33>'  : 'fangzhen20050606/Dynamics System动力系统/Direction Cosine Matrix to Euler Angles/sin(phi)cos(theta)'
 * '<S34>'  : 'fangzhen20050606/Dynamics System动力系统/Direction Cosine Matrix to Euler Angles/sin(psi)cos(theta)'
 * '<S35>'  : 'fangzhen20050606/Dynamics System动力系统/Direction Cosine Matrix to Euler Angles/sin(theta)'
 * '<S36>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型'
 * '<S37>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/哥式惯性加速度'
 * '<S38>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度'
 * '<S39>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/离心惯性加速度'
 * '<S40>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力'
 * '<S41>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力/K'
 * '<S42>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力/L'
 * '<S43>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力/Ux'
 * '<S44>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力/Uy'
 * '<S45>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力/Uz'
 * '<S46>'  : 'fangzhen20050606/Dynamics System动力系统/Orbit轨道/轨道动力学模型/小行星引力加速度/小行星引力/rt'
 * '<S47>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix'
 * '<S48>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles'
 * '<S49>'  : 'fangzhen20050606/GNC System/喷嘴控制器'
 * '<S50>'  : 'fangzhen20050606/GNC System/姿态控制器'
 * '<S51>'  : 'fangzhen20050606/GNC System/导航与滤波'
 * '<S52>'  : 'fangzhen20050606/GNC System/轨迹制导0515(2)'
 * '<S53>'  : 'fangzhen20050606/GNC System/障碍规避'
 * '<S54>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A11'
 * '<S55>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A12'
 * '<S56>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A13'
 * '<S57>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A21'
 * '<S58>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A22'
 * '<S59>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A23'
 * '<S60>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A31'
 * '<S61>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A32'
 * '<S62>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/A33'
 * '<S63>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/Create Transformation Matrix'
 * '<S64>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
 * '<S65>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
 * '<S66>'  : 'fangzhen20050606/GNC System/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S67>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Quaternion Normalize'
 * '<S68>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Subsystem'
 * '<S69>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Subsystem1'
 * '<S70>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Subsystem2'
 * '<S71>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Subsystem3'
 * '<S72>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Subsystem4'
 * '<S73>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Quaternion Normalize/Quaternion Modulus'
 * '<S74>'  : 'fangzhen20050606/GNC System/Quaternions to Euler Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S75>'  : 'fangzhen20050606/GNC System/喷嘴控制器/detR+'
 * '<S76>'  : 'fangzhen20050606/GNC System/喷嘴控制器/detR-'
 * '<S77>'  : 'fangzhen20050606/GNC System/喷嘴控制器/detR+/Switch'
 * '<S78>'  : 'fangzhen20050606/GNC System/喷嘴控制器/detR-/Switch'
 * '<S79>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate'
 * '<S80>'  : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix'
 * '<S81>'  : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles'
 * '<S82>'  : 'fangzhen20050606/GNC System/导航与滤波/加速度计'
 * '<S83>'  : 'fangzhen20050606/GNC System/导航与滤波/姿态融合'
 * '<S84>'  : 'fangzhen20050606/GNC System/导航与滤波/激光测距仪'
 * '<S85>'  : 'fangzhen20050606/GNC System/导航与滤波/相机'
 * '<S86>'  : 'fangzhen20050606/GNC System/导航与滤波/轨道融合'
 * '<S87>'  : 'fangzhen20050606/GNC System/导航与滤波/陀螺'
 * '<S88>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/P1'
 * '<S89>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/P2'
 * '<S90>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/P3'
 * '<S91>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3'
 * '<S92>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions'
 * '<S93>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/e2'
 * '<S94>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/e4'
 * '<S95>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace'
 * '<S96>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Positive Trace'
 * '<S97>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/trace(DCM)'
 * '<S98>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)'
 * '<S99>'  : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)'
 * '<S100>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)'
 * '<S101>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/diag(DCM)'
 * '<S102>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S103>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S104>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S105>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/if s~=0; s=0.5//s'
 * '<S106>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(1,1)/u(1) -(u(5)+u(9)) +1'
 * '<S107>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S108>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S109>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/cos(theta)sin(psi) + (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S110>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/if s~=0; s=0.5//s'
 * '<S111>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(2,2)/u(5) -(u(1)+u(9)) +1'
 * '<S112>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) -sin(theta)'
 * '<S113>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(phi) + (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S114>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S115>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/if s~=0; s=0.5//s'
 * '<S116>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Negative Trace/Maximum Value at DCM(3,3)/u(9) -(u(1)+u(5)) +1'
 * '<S117>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(phi)sin(theta)cos(psi) + sin(phi)sin(psi) +sin(theta)'
 * '<S118>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(phi) - (cos(phi)sin(theta)sin(psi) - sin(phi)cos(psi))'
 * '<S119>' : 'fangzhen20050606/GNC System/导航与滤波/Calculate/Subsystem3/Direction Cosine Matrix  to Quaternions/Positive Trace/cos(theta)sin(psi) - (sin(phi)sin(theta)cos(psi) - cos(phi)sin(psi))'
 * '<S120>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A11'
 * '<S121>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A12'
 * '<S122>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A13'
 * '<S123>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A21'
 * '<S124>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A22'
 * '<S125>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A23'
 * '<S126>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A31'
 * '<S127>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A32'
 * '<S128>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/A33'
 * '<S129>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/Create Transformation Matrix'
 * '<S130>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/Quaternion Normalize'
 * '<S131>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus'
 * '<S132>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to  Direction Cosine Matrix/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S133>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Quaternion Normalize'
 * '<S134>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Subsystem'
 * '<S135>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Subsystem1'
 * '<S136>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Subsystem2'
 * '<S137>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Subsystem3'
 * '<S138>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Subsystem4'
 * '<S139>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Quaternion Normalize/Quaternion Modulus'
 * '<S140>' : 'fangzhen20050606/GNC System/导航与滤波/Quaternions to Euler Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
 * '<S141>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/Subsystem'
 * '<S142>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/Subsystem2'
 * '<S143>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导2'
 * '<S144>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导4'
 * '<S145>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导2/r'
 * '<S146>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导2/v'
 * '<S147>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导4/C0'
 * '<S148>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导4/C1'
 * '<S149>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导4/C2'
 * '<S150>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导4/r'
 * '<S151>' : 'fangzhen20050606/GNC System/轨迹制导0515(2)/轨迹制导4/v'
 */
#endif                                 /* RTW_HEADER_fangzhen20050606_h_ */
