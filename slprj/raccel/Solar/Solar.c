#include "Solar.h"
#include "rtwtypes.h"
#include <stddef.h>
#include "Solar_private.h"
#include <string.h>
#include "rt_logging_mmi.h"
#include "Solar_capi.h"
#include "Solar_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.8 (R2022b) 13-May-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; ExtY rtY ; MassMatrix rtMassMatrix ; static
SimStruct model_S ; SimStruct * const rtS = & model_S ; void MdlInitialize (
void ) { int_T tmp_e ; int_T tmp_f ; int_T tmp_g ; int_T tmp_i ; int_T tmp_j
; int_T tmp_m ; boolean_T tmp ; boolean_T tmp_p ; SimStruct * S ; void * diag
; tmp = false ; tmp_p = false ; if ( tmp_p || tmp ) { tmp_e = strcmp (
ssGetSolverName ( rtS ) , "daessc" ) ; tmp_i = strcmp ( ssGetSolverName ( rtS
) , "ode14x" ) ; tmp_m = strcmp ( ssGetSolverName ( rtS ) , "ode15s" ) ;
tmp_g = strcmp ( ssGetSolverName ( rtS ) , "ode1be" ) ; tmp_j = strcmp (
ssGetSolverName ( rtS ) , "ode23t" ) ; tmp_f = strcmp ( ssGetSolverName ( rtS
) , "odeN" ) ; if ( ( boolean_T ) ( ( tmp_e != 0 ) & ( tmp_i != 0 ) & ( tmp_m
!= 0 ) & ( tmp_g != 0 ) & ( tmp_j != 0 ) & ( tmp_f != 0 ) ) ) { S = rtS ;
diag = CreateDiagnosticAsVoidPtr (
 "physmod:simscape:engine:sli:SimscapeExecutionBlock:InconsistentSolversInModelRef"
, 2 , 3 , "daessc" , 3 , "{daessc, ode14x, ode15s, ode1be, ode23t, odeN}" ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } } { static int_T modelMassMatrixIr [ 1 ] =
{ 0 } ; static int_T modelMassMatrixJc [ 3 ] = { 0 , 0 , 1 } ; static real_T
modelMassMatrixPr [ 1 ] = { 1.0 } ; ( void ) memcpy ( rtMassMatrix . ir ,
modelMassMatrixIr , 1 * sizeof ( int_T ) ) ; ( void ) memcpy ( rtMassMatrix .
jc , modelMassMatrixJc , 3 * sizeof ( int_T ) ) ; ( void ) memcpy (
rtMassMatrix . pr , modelMassMatrixPr , 1 * sizeof ( real_T ) ) ; } } void
MdlStart ( void ) { CXPtMax * _rtXPerturbMax ; CXPtMin * _rtXPerturbMin ;
NeModelParameters modelParameters ; NeModelParameters modelParameters_p ;
NeslSimulationData * simulationData ; NeslSimulator * tmp ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p
; char * msg ; char * msg_e ; char * msg_p ; real_T tmp_m [ 8 ] ; real_T time
; real_T tmp_e ; int32_T tmp_i ; int_T tmp_g [ 3 ] ; boolean_T tmp_p ;
boolean_T val ; { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} _rtXPerturbMax = ( ( CXPtMax * ) ssGetJacobianPerturbationBoundsMaxVec (
rtS ) ) ; _rtXPerturbMin = ( ( CXPtMin * )
ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ; { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "par1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "par1" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Solar/par1" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU
subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "par1" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 1 , 1 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . n2xwbehmxh . AQHandles = sdiStartAsyncioQueueCreation ( hDT , &
srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"64e305b5-cf09-49c3-8bb9-25c8221e11fb" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "A" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . n2xwbehmxh . AQHandles , hDT , & srcInfo ) ; if ( rtDW . n2xwbehmxh .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . n2xwbehmxh . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
n2xwbehmxh . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n2xwbehmxh .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . n2xwbehmxh . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . n2xwbehmxh . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . n2xwbehmxh . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . n2xwbehmxh . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "par2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "par2" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Solar/par2" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU
subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "par2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 2 ] = { 1 , 1 } ; sigDims .
nDims = 2 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems
= 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo .
SID = ( sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . oqunl2krqg . AQHandles = sdiStartAsyncioQueueCreation ( hDT , &
srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"d87d81db-448c-4c6c-82cf-a67754b7aa2d" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . oqunl2krqg . AQHandles , hDT , & srcInfo ) ; if ( rtDW . oqunl2krqg .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . oqunl2krqg . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
oqunl2krqg . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . oqunl2krqg .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . oqunl2krqg . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . oqunl2krqg . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . oqunl2krqg . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . oqunl2krqg . AQHandles , 2 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "par3" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "par3" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"Solar/par3" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU
subPath = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "par3" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. p0ykozkwg0 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"35c8cb7e-c5c6-41e8-a8d4-61e17f5c49a0" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "1" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . p0ykozkwg0 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . p0ykozkwg0 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . p0ykozkwg0 . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
p0ykozkwg0 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . p0ykozkwg0 .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . p0ykozkwg0 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . p0ykozkwg0 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetSignalDomainType ( rtDW . p0ykozkwg0 . AQHandles , "outport" )
; sdiAsyncRepoSetSignalExportOrder ( rtDW . p0ykozkwg0 . AQHandles , 3 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } tmp = nesl_lease_simulator (
"Solar/Solver Configuration_1" , 0 , 0 ) ; rtDW . bipxskpt45 = ( void * ) tmp
; tmp_p = pointer_is_null ( rtDW . bipxskpt45 ) ; if ( tmp_p ) {
Solar_4a74f551_1_gateway ( ) ; tmp = nesl_lease_simulator (
"Solar/Solver Configuration_1" , 0 , 0 ) ; rtDW . bipxskpt45 = ( void * ) tmp
; } slsaSaveRawMemoryForSimTargetOP ( rtS , "Solar/Solver Configuration_100"
, ( void * * ) ( & rtDW . bipxskpt45 ) , 0U * sizeof ( real_T ) ,
nesl_save_simdata , nesl_restore_simdata ) ; simulationData =
nesl_create_simulation_data ( ) ; rtDW . alcd0k4gkq = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
c15q5nfivf = ( void * ) diagnosticManager ; modelParameters . mSolverType =
NE_SOLVER_TYPE_DAE ; modelParameters . mSolverAbsTol = 0.001 ;
modelParameters . mSolverRelTol = 0.001 ; modelParameters .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_MAYBE ; modelParameters . mStartTime
= 0.0 ; modelParameters . mLoadInitialState = false ; modelParameters .
mUseSimState = false ; modelParameters . mLinTrimCompile = false ;
modelParameters . mLoggingMode = SSC_LOGGING_NONE ; modelParameters .
mRTWModifiedTimeStamp = 6.05808976E+8 ; modelParameters . mZcDisabled = false
; tmp_e = 0.001 ; modelParameters . mSolverTolerance = tmp_e ; tmp_e = 0.0 ;
modelParameters . mFixedStepSize = tmp_e ; tmp_p = true ; modelParameters .
mVariableStepSolver = tmp_p ; tmp_p = false ; modelParameters . mIsUsingODEN
= tmp_p ; tmp_p = slIsRapidAcceleratorSimulating ( ) ; val =
ssGetGlobalInitialStatesAvailable ( rtS ) ; if ( tmp_p ) { val = ( val &&
ssIsFirstInitCond ( rtS ) ) ; } modelParameters . mLoadInitialState = val ;
modelParameters . mZcDisabled = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . c15q5nfivf ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . bipxskpt45 , &
modelParameters , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp_p = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp_p ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS
) ; tmp_p = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U )
; simulationData -> mData -> mIsSolverAssertCheck = tmp_p ; tmp_p =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp_p ; tmp_p = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp_p ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp_p = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp_p ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_g [ 0 ] = 0 ;
tmp_m [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_m [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_m [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_m [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_g [ 1 ] = 4 ; tmp_m [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_m [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_m [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_m [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_g [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_g [ 0 ] ; simulationData -> mData ->
mNumjacDxLo . mN = 2 ; simulationData -> mData -> mNumjacDxLo . mX = &
_rtXPerturbMin -> ckqu0stfib [ 0 ] ; simulationData -> mData -> mNumjacDxHi .
mN = 2 ; simulationData -> mData -> mNumjacDxHi . mX = & _rtXPerturbMax ->
ckqu0stfib [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
c15q5nfivf ; diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. bipxskpt45 , NESL_SIM_NUMJAC_DX_BOUNDS , simulationData , diagnosticManager
) ; if ( tmp_i != 0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus (
rtS ) ) ; if ( tmp_p ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } tmp = nesl_lease_simulator (
"Solar/Solver Configuration_1" , 1 , 0 ) ; rtDW . c3nc4wn3cv = ( void * ) tmp
; tmp_p = pointer_is_null ( rtDW . c3nc4wn3cv ) ; if ( tmp_p ) {
Solar_4a74f551_1_gateway ( ) ; tmp = nesl_lease_simulator (
"Solar/Solver Configuration_1" , 1 , 0 ) ; rtDW . c3nc4wn3cv = ( void * ) tmp
; } slsaSaveRawMemoryForSimTargetOP ( rtS , "Solar/Solver Configuration_110"
, ( void * * ) ( & rtDW . c3nc4wn3cv ) , 0U * sizeof ( real_T ) ,
nesl_save_simdata , nesl_restore_simdata ) ; simulationData =
nesl_create_simulation_data ( ) ; rtDW . dsgtoj40g5 = ( void * )
simulationData ; diagnosticManager = rtw_create_diagnostics ( ) ; rtDW .
fke3k403tp = ( void * ) diagnosticManager ; modelParameters_p . mSolverType =
NE_SOLVER_TYPE_DAE ; modelParameters_p . mSolverAbsTol = 0.001 ;
modelParameters_p . mSolverRelTol = 0.001 ; modelParameters_p .
mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_MAYBE ; modelParameters_p .
mStartTime = 0.0 ; modelParameters_p . mLoadInitialState = false ;
modelParameters_p . mUseSimState = false ; modelParameters_p .
mLinTrimCompile = false ; modelParameters_p . mLoggingMode = SSC_LOGGING_NONE
; modelParameters_p . mRTWModifiedTimeStamp = 6.05808976E+8 ;
modelParameters_p . mZcDisabled = false ; tmp_e = 0.001 ; modelParameters_p .
mSolverTolerance = tmp_e ; tmp_e = 0.0 ; modelParameters_p . mFixedStepSize =
tmp_e ; tmp_p = true ; modelParameters_p . mVariableStepSolver = tmp_p ;
tmp_p = false ; modelParameters_p . mIsUsingODEN = tmp_p ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; val = ssGetGlobalInitialStatesAvailable
( rtS ) ; if ( tmp_p ) { val = ( val && ssIsFirstInitCond ( rtS ) ) ; }
modelParameters_p . mLoadInitialState = val ; modelParameters_p . mZcDisabled
= false ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . fke3k403tp ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . c3nc4wn3cv , & modelParameters_p , diagnosticManager ) ; if ( tmp_i !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus ( rtS
, msg_e ) ; } } MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; NeuDiagnosticTree *
diagnosticTree_p ; char * msg ; char * msg_p ; real_T tmp_m [ 12 ] ; real_T
tmp_p [ 8 ] ; real_T time ; real_T time_e ; real_T time_i ; real_T time_p ;
int32_T tmp_i ; int_T tmp_g [ 4 ] ; int_T tmp_e [ 3 ] ; boolean_T tmp ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . ba4fhlmj5j = ( ssGetTaskTime ( rtS ,
1 ) >= rtP . TestVoltage_start ) ; if ( rtDW . ba4fhlmj5j == 1 ) { rtB .
lyw1jaszff = rtP . TestVoltage_slope ; } else { rtB . lyw1jaszff = rtP .
Step_Y0 ; } } rtB . obukmotbeo = ssGetT ( rtS ) - rtP . TestVoltage_start ;
rtB . f0ecfqt2re = rtB . lyw1jaszff * rtB . obukmotbeo ; rtB . luzianfzgt =
rtB . f0ecfqt2re + rtP . TestVoltage_InitialOutput ; rtB . pp3lsgkzsi [ 0 ] =
rtB . luzianfzgt ; rtB . pp3lsgkzsi [ 1 ] = 0.0 ; rtB . pp3lsgkzsi [ 2 ] =
0.0 ; rtB . pp3lsgkzsi [ 3 ] = 0.0 ; rtB . jhuhg2o5v3 [ 0 ] = rtP .
irradiance ; rtB . jhuhg2o5v3 [ 1 ] = 0.0 ; rtB . jhuhg2o5v3 [ 2 ] = 0.0 ; if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . b2ahp0rfiw [ 0 ] = ! ( rtB .
jhuhg2o5v3 [ 0 ] == rtDW . b2ahp0rfiw [ 1 ] ) ; rtDW . b2ahp0rfiw [ 1 ] = rtB
. jhuhg2o5v3 [ 0 ] ; } rtB . jhuhg2o5v3 [ 0 ] = rtDW . b2ahp0rfiw [ 1 ] ; rtB
. jhuhg2o5v3 [ 3 ] = rtDW . b2ahp0rfiw [ 0 ] ; simulationData = (
NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_p [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_p [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_p [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_p [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_p [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_p [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; simulationData -> mData -> mOutputs .
mN = 4 ; simulationData -> mData -> mOutputs . mX = & rtB . nsafxb3i14 [ 0 ]
; simulationData -> mData -> mTolerances . mN = 0 ; simulationData -> mData
-> mTolerances . mX = NULL ; simulationData -> mData -> mCstateHasChanged =
false ; time_p = ssGetTaskTime ( rtS , 0 ) ; simulationData -> mData -> mTime
. mN = 1 ; simulationData -> mData -> mTime . mX = & time_p ; simulationData
-> mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits .
mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . c15q5nfivf ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . bipxskpt45 ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
if ( ssIsMajorTimeStep ( rtS ) && simulationData -> mData ->
mCstateHasChanged ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
simulationData = ( NeslSimulationData * ) rtDW . dsgtoj40g5 ; time_e = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time_e ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . p4ftbnb1f3 ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . kypyg3mc0h ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; simulationData ->
mData -> mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_g [ 0 ]
= 0 ; tmp_m [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_m [ 1 ] = rtB . pp3lsgkzsi [
1 ] ; tmp_m [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_m [ 3 ] = rtB . pp3lsgkzsi [
3 ] ; tmp_g [ 1 ] = 4 ; tmp_m [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_m [ 5 ] =
rtB . jhuhg2o5v3 [ 1 ] ; tmp_m [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_m [ 7 ] =
rtB . jhuhg2o5v3 [ 3 ] ; tmp_g [ 2 ] = 8 ; tmp_m [ 8 ] = rtB . nsafxb3i14 [ 0
] ; tmp_m [ 9 ] = rtB . nsafxb3i14 [ 1 ] ; tmp_m [ 10 ] = rtB . nsafxb3i14 [
2 ] ; tmp_m [ 11 ] = rtB . nsafxb3i14 [ 3 ] ; tmp_g [ 3 ] = 12 ;
simulationData -> mData -> mInputValues . mN = 12 ; simulationData -> mData
-> mInputValues . mX = & tmp_m [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 4 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_g [ 0 ] ; simulationData -> mData -> mOutputs . mN = 1 ; simulationData
-> mData -> mOutputs . mX = & rtB . miacua0cge ; simulationData -> mData ->
mTolerances . mN = 0 ; simulationData -> mData -> mTolerances . mX = NULL ;
simulationData -> mData -> mCstateHasChanged = false ; time_i = ssGetTaskTime
( rtS , 0 ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData ->
mData -> mTime . mX = & time_i ; simulationData -> mData -> mSampleHits . mN
= 0 ; simulationData -> mData -> mSampleHits . mX = NULL ; simulationData ->
mData -> mIsFundamentalSampleHit = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . fke3k403tp ; diagnosticTree_p =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . c3nc4wn3cv ,
NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) {
tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg_p
= rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus ( rtS , msg_p )
; } } if ( ssIsMajorTimeStep ( rtS ) && simulationData -> mData ->
mCstateHasChanged ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; }
rtY . kaweiuc2yf = rtB . miacua0cge ; rtB . dczfykt4fv = rtB . miacua0cge *
rtB . luzianfzgt ; rtY . imjtojlln4 = rtB . dczfykt4fv ; rtY . c1n2sj3o2b =
rtB . luzianfzgt ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW .
n2xwbehmxh . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
n2xwbehmxh . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
miacua0cge + 0 ) ; } } { if ( rtDW . oqunl2krqg . AQHandles && ssGetLogOutput
( rtS ) ) { sdiWriteSignal ( rtDW . oqunl2krqg . AQHandles , ssGetTaskTime (
rtS , 1 ) , ( char * ) & rtB . dczfykt4fv + 0 ) ; } } { if ( rtDW .
p0ykozkwg0 . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
p0ykozkwg0 . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB .
luzianfzgt + 0 ) ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; char * msg ; real_T
tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [ 3 ] ; boolean_T tmp
; simulationData = ( NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_p [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_p [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_p [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_p [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_p [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_p [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . c15q5nfivf ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . bipxskpt45 , NESL_SIM_UPDATE
, simulationData , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; XDot * _rtXdot ;
char * msg ; real_T tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [
3 ] ; boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ;
simulationData = ( NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_p [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_p [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_p [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_p [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_p [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_p [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN =
2 ; simulationData -> mData -> mDx . mX = & _rtXdot -> ckqu0stfib [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . c15q5nfivf ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . bipxskpt45 ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlProjection ( void ) { } void MdlForcingFunction ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; XDot * _rtXdot ;
char * msg ; real_T tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [
3 ] ; boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ;
simulationData = ( NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_p [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_p [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_p [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_p [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_p [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_p [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN =
2 ; simulationData -> mData -> mDx . mX = & _rtXdot -> ckqu0stfib [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . c15q5nfivf ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . bipxskpt45 ,
NESL_SIM_FORCINGFUNCTION , simulationData , diagnosticManager ) ; if ( tmp_i
!= 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp
) { msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS ,
msg ) ; } } } void MdlMassMatrix ( void ) { NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; char * msg ; real_T tmp_p [ 8 ] ; real_T time ; real_T *
tmp_i ; real_T * tmp_m ; int32_T tmp_g ; int_T tmp_e [ 3 ] ; boolean_T tmp ;
simulationData = ( NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_p [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_p [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_p [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_p [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_p [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_p [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; tmp_i = ssGetMassMatrixPr ( rtS ) ;
tmp_m = double_pointer_shift ( tmp_i , rtDW . ealppa1yju ) ; simulationData
-> mData -> mMassMatrixPr . mN = 1 ; simulationData -> mData -> mMassMatrixPr
. mX = tmp_m ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
c15q5nfivf ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_g = ne_simulator_method ( ( NeslSimulator * ) rtDW
. bipxskpt45 , NESL_SIM_MASSMATRIX , simulationData , diagnosticManager ) ;
if ( tmp_g != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } } void MdlZeroCrossings ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; ZCV * _rtZCSV ; char
* msg ; real_T tmp_p [ 8 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [ 3 ]
; boolean_T tmp ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) ;
_rtZCSV -> jq2cm4gswo = ssGetT ( rtS ) - rtP . TestVoltage_start ;
simulationData = ( NeslSimulationData * ) rtDW . alcd0k4gkq ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 2 ;
simulationData -> mData -> mContStates . mX = & rtX . ckqu0stfib [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 0 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . fxe3vkttrz ; simulationData -> mData ->
mModeVector . mN = 2 ; simulationData -> mData -> mModeVector . mX = & rtDW .
lua3lh5sso [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo (
rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; simulationData -> mData ->
mIsModeUpdateTimeStep = ssIsModeUpdateTimeStep ( rtS ) ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . pp3lsgkzsi [ 0 ] ; tmp_p [ 1 ] = rtB . pp3lsgkzsi [ 1 ] ;
tmp_p [ 2 ] = rtB . pp3lsgkzsi [ 2 ] ; tmp_p [ 3 ] = rtB . pp3lsgkzsi [ 3 ] ;
tmp_e [ 1 ] = 4 ; tmp_p [ 4 ] = rtB . jhuhg2o5v3 [ 0 ] ; tmp_p [ 5 ] = rtB .
jhuhg2o5v3 [ 1 ] ; tmp_p [ 6 ] = rtB . jhuhg2o5v3 [ 2 ] ; tmp_p [ 7 ] = rtB .
jhuhg2o5v3 [ 3 ] ; tmp_e [ 2 ] = 8 ; simulationData -> mData -> mInputValues
. mN = 8 ; simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ;
simulationData -> mData -> mInputOffsets . mN = 3 ; simulationData -> mData
-> mInputOffsets . mX = & tmp_e [ 0 ] ; simulationData -> mData ->
mNonSampledZCs . mN = 2 ; simulationData -> mData -> mNonSampledZCs . mX = &
_rtZCSV -> a5ricxsosm ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
c15q5nfivf ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. bipxskpt45 , NESL_SIM_ZEROCROSSINGS , simulationData , diagnosticManager )
; if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS )
) ; if ( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } } void MdlTerminate ( void ) {
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . c15q5nfivf
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . alcd0k4gkq
) ; nesl_erase_simulator ( "Solar/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . fke3k403tp ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . dsgtoj40g5 ) ; nesl_erase_simulator (
"Solar/Solver Configuration_1" ) ; nesl_destroy_registry ( ) ; { if ( rtDW .
n2xwbehmxh . AQHandles ) { sdiTerminateStreaming ( & rtDW . n2xwbehmxh .
AQHandles ) ; } } { if ( rtDW . oqunl2krqg . AQHandles ) {
sdiTerminateStreaming ( & rtDW . oqunl2krqg . AQHandles ) ; } } { if ( rtDW .
p0ykozkwg0 . AQHandles ) { sdiTerminateStreaming ( & rtDW . p0ykozkwg0 .
AQHandles ) ; } } } static void mr_Solar_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_Solar_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Solar_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_Solar_restoreDataFromMxArray ( void * destData , const mxArray * srcArray
, mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_Solar_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_Solar_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_Solar_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_Solar_extractBitFieldFromMxArray
( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_Solar_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) ; static void
mr_Solar_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int
j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T *
varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j )
) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T
* ) srcData , numBytes ) ; } static void
mr_Solar_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_Solar_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_Solar_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_Solar_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber
( destArray , i , j ) , offset , mxCreateDoubleScalar ( ( double ) fieldVal )
) ; } static uint_T mr_Solar_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_Solar_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_Solar_GetDWork ( ) { static const char * ssDWFieldNames [
3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Solar_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 10 ] = {
"rtDW.b3j4dtgyry" , "rtDW.b2ahp0rfiw" , "rtDW.fxe3vkttrz" , "rtDW.p4ftbnb1f3"
, "rtDW.lua3lh5sso" , "rtDW.kypyg3mc0h" , "rtDW.ba4fhlmj5j" ,
"rtDW.ealppa1yju" , "rtDW.ipwfflkpgw" , "rtDW.dhdenh4pzm" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 10 , rtdwDataFieldNames ) ;
mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW .
b3j4dtgyry ) , sizeof ( rtDW . b3j4dtgyry ) ) ; mr_Solar_cacheDataAsMxArray (
rtdwData , 0 , 1 , ( const void * ) & ( rtDW . b2ahp0rfiw ) , sizeof ( rtDW .
b2ahp0rfiw ) ) ; mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const
void * ) & ( rtDW . fxe3vkttrz ) , sizeof ( rtDW . fxe3vkttrz ) ) ;
mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW .
p4ftbnb1f3 ) , sizeof ( rtDW . p4ftbnb1f3 ) ) ; mr_Solar_cacheDataAsMxArray (
rtdwData , 0 , 4 , ( const void * ) & ( rtDW . lua3lh5sso ) , sizeof ( rtDW .
lua3lh5sso ) ) ; mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const
void * ) & ( rtDW . kypyg3mc0h ) , sizeof ( rtDW . kypyg3mc0h ) ) ;
mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW .
ba4fhlmj5j ) , sizeof ( rtDW . ba4fhlmj5j ) ) ; mr_Solar_cacheDataAsMxArray (
rtdwData , 0 , 7 , ( const void * ) & ( rtDW . ealppa1yju ) , sizeof ( rtDW .
ealppa1yju ) ) ; mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const
void * ) & ( rtDW . ipwfflkpgw ) , sizeof ( rtDW . ipwfflkpgw ) ) ;
mr_Solar_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & ( rtDW .
dhdenh4pzm ) , sizeof ( rtDW . dhdenh4pzm ) ) ; mxSetFieldByNumber ( ssDW , 0
, 1 , rtdwData ) ; } return ssDW ; } void mr_Solar_SetDWork ( const mxArray *
ssDW ) { ( void ) ssDW ; mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtB
) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData =
mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_Solar_restoreDataFromMxArray ( (
void * ) & ( rtDW . b3j4dtgyry ) , rtdwData , 0 , 0 , sizeof ( rtDW .
b3j4dtgyry ) ) ; mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW .
b2ahp0rfiw ) , rtdwData , 0 , 1 , sizeof ( rtDW . b2ahp0rfiw ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . fxe3vkttrz ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . fxe3vkttrz ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . p4ftbnb1f3 ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . p4ftbnb1f3 ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . lua3lh5sso ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . lua3lh5sso ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . kypyg3mc0h ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . kypyg3mc0h ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . ba4fhlmj5j ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . ba4fhlmj5j ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . ealppa1yju ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . ealppa1yju ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . ipwfflkpgw ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . ipwfflkpgw ) ) ;
mr_Solar_restoreDataFromMxArray ( ( void * ) & ( rtDW . dhdenh4pzm ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . dhdenh4pzm ) ) ; } } mxArray *
mr_Solar_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 2 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char * blockType [ 2 ] = { "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , } ; static const char * blockPath [ 2 ] = {
"Solar/Solver Configuration/EVAL_KEY/STATE_1" ,
"Solar/Solver Configuration/EVAL_KEY/OUTPUT_1_0" , } ; static const int
reason [ 2 ] = { 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 2 ; ++ (
subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 ,
subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ]
] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 2 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 3 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 31 ) ;
ssSetNumBlockIO ( rtS , 9 ) ; ssSetNumBlockParams ( rtS , 5 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1392658858U ) ; ssSetChecksumVal ( rtS , 1 ,
475129396U ) ; ssSetChecksumVal ( rtS , 2 , 287096537U ) ; ssSetChecksumVal (
rtS , 3 , 1257556824U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( & rtY , 0 , sizeof (
ExtY ) ) ; ssSetWorkSizeInBytes ( rtS , sizeof ( rtY ) , "YOut" ) ; } {
real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ; ( void )
memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = ( void * ) &
rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 , sizeof
( DW ) ) ; } { rtDW . ealppa1yju = 0 ; } { static DataTypeTransInfo dtInfo ;
( void ) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 23 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } Solar_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"Solar" ) ; ssSetPath ( rtS , "Solar" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 40.370000000000005 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 2 , 2 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 2 , 2 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
} ; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = {
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "Discrete" , "Discrete" }
; static const char_T * rt_LoggedStateBlockNames [ ] = {
"Solar/Controlled Voltage Source" , "Solar/Solar Panel/Solar Cell" ,
"Solar/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"Solar/Solver\nConfiguration/EVAL_KEY/INPUT_2_1_1" } ; static const char_T *
rt_LoggedStateNames [ ] = { "Solar.Controlled_Voltage_Source.i" ,
"Solar.Solar_Panel.Solar_Cell.diode1.i_diode" , "Discrete" , "Discrete" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
int_T rt_LoggedStateIdxList [ ] = { 0 , 0 , 1 } ; static RTWLogSignalInfo
rt_LoggedStateSignalInfo = { 4 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 4 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . ckqu0stfib [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . ckqu0stfib [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . b3j4dtgyry ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) rtDW . b2ahp0rfiw ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; { static void * rt_LoggedOutputSignalPtrs [ ] = { & rtY .
kaweiuc2yf , & rtY . imjtojlln4 , & rtY . c1n2sj3o2b } ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( ( LogSignalPtrsType )
rt_LoggedOutputSignalPtrs ) ) ; } { static int_T rt_LoggedOutputWidths [ ] =
{ 1 , 1 , 1 } ; static int_T rt_LoggedOutputNumDimensions [ ] = { 2 , 2 , 1 }
; static int_T rt_LoggedOutputDimensions [ ] = { 1 , 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedOutputIsVarDims [ ] = { 0 , 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) } ; static int_T rt_LoggedCurrentSignalDimensionsSize [ ] =
{ 4 , 4 , 4 , 4 , 4 } ; static BuiltInDTypeId rt_LoggedOutputDataTypeIds [ ]
= { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedOutputComplexSignals [ ] = { 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , (
NULL ) , ( NULL ) } ; static const char_T * rt_LoggedOutputLabels_0 [ ] = {
"par1" } ; static const char_T * rt_LoggedOutputBlockNames_0 [ ] = {
"Solar/par1" } ; static const char_T * rt_LoggedOutputLabels_1 [ ] = { "par2"
} ; static const char_T * rt_LoggedOutputBlockNames_1 [ ] = { "Solar/par2" }
; static const char_T * rt_LoggedOutputLabels_2 [ ] = { "par3" } ; static
const char_T * rt_LoggedOutputBlockNames_2 [ ] = { "Solar/par3" } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } } ; static RTWLogSignalInfo rt_LoggedOutputSignalInfo [ ] = { { 1 ,
rt_LoggedOutputWidths , rt_LoggedOutputNumDimensions ,
rt_LoggedOutputDimensions , rt_LoggedOutputIsVarDims ,
rt_LoggedCurrentSignalDimensions , rt_LoggedCurrentSignalDimensionsSize ,
rt_LoggedOutputDataTypeIds , rt_LoggedOutputComplexSignals , ( NULL ) ,
rt_LoggingPreprocessingFcnPtrs , { rt_LoggedOutputLabels_0 } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedOutputBlockNames_0 } , { ( NULL ) } , ( NULL )
, rt_RTWLogDataTypeConvert , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 1 ,
rt_LoggedOutputNumDimensions + 1 , rt_LoggedOutputDimensions + 2 ,
rt_LoggedOutputIsVarDims + 1 , rt_LoggedCurrentSignalDimensions + 2 ,
rt_LoggedCurrentSignalDimensionsSize + 2 , rt_LoggedOutputDataTypeIds + 1 ,
rt_LoggedOutputComplexSignals + 1 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 1 , { rt_LoggedOutputLabels_1 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_1 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 1 , ( NULL ) } , { 1 , rt_LoggedOutputWidths + 2 ,
rt_LoggedOutputNumDimensions + 2 , rt_LoggedOutputDimensions + 4 ,
rt_LoggedOutputIsVarDims + 2 , rt_LoggedCurrentSignalDimensions + 4 ,
rt_LoggedCurrentSignalDimensionsSize + 4 , rt_LoggedOutputDataTypeIds + 2 ,
rt_LoggedOutputComplexSignals + 2 , ( NULL ) , rt_LoggingPreprocessingFcnPtrs
+ 2 , { rt_LoggedOutputLabels_2 } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames_2 } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert + 2 , ( NULL ) } } ; rtliSetLogYSignalInfo (
ssGetRTWLogInfo ( rtS ) , rt_LoggedOutputSignalInfo ) ;
rt_LoggedCurrentSignalDimensions [ 0 ] = & rt_LoggedOutputWidths [ 0 ] ;
rt_LoggedCurrentSignalDimensions [ 1 ] = & rt_LoggedOutputWidths [ 0 ] ;
rt_LoggedCurrentSignalDimensions [ 2 ] = & rt_LoggedOutputWidths [ 1 ] ;
rt_LoggedCurrentSignalDimensions [ 3 ] = & rt_LoggedOutputWidths [ 1 ] ;
rt_LoggedCurrentSignalDimensions [ 4 ] = & rt_LoggedOutputWidths [ 2 ] ; }
rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
"tmp_raccel_yout1,tmp_raccel_yout2,tmp_raccel_yout3" ) ; } { static struct
_ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 ) ; } {
static ssPeriodicStatesInfo periodicStatesInfo ; ssSetPeriodicStatesInfo (
rtS , & periodicStatesInfo ) ; } { static ssJacobianPerturbationBounds
jacobianPerturbationBounds ; ssSetJacobianPerturbationBounds ( rtS , &
jacobianPerturbationBounds ) ; } { static ssSolverInfo slvrInfo ; static
struct _ssSFcnModelMethods3 mdlMethods3 ; static struct _ssSFcnModelMethods2
mdlMethods2 ; static boolean_T contStatesDisabled [ 2 ] ; static real_T
absTol [ 2 ] = { 0.001 , 0.001 } ; static uint8_T absTolControl [ 2 ] = { 1U
, 1U } ; static real_T contStateJacPerturbBoundMinVec [ 2 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 2 ] ; static uint8_T zcAttributes [ 3 ] = {
( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P
) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 1 ] = { { 1 * sizeof
( real_T ) , ( char * ) ( & rtB . lyw1jaszff ) , ( NULL ) } } ; { int i ; for
( i = 0 ; i < 2 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 )
; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.80740000000000012 ) ; ssSetSolverMaxOrder ( rtS ,
- 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL
) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
1 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "daessc" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; _ssSetSolverUpdateJacobianAtReset
( rtS , true ) ; ssSetAbsTolVector ( rtS , absTol ) ;
ssSetAbsTolControlVector ( rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete
( rtS , absTol ) ; ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl )
; ssSetJacobianPerturbationBoundsMinVec ( rtS ,
contStateJacPerturbBoundMinVec ) ; ssSetJacobianPerturbationBoundsMaxVec (
rtS , contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0
) ; ( void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) )
; ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetMassMatrixType ( rtS , ( ssMatrixType ) 1 ) ;
ssSetMassMatrixNzMax ( rtS , 1 ) ; ssSetModelMassMatrix ( rtS , MdlMassMatrix
) ; ssSetModelForcingFunction ( rtS , MdlForcingFunction ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 1 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 1 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 3 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 3 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; { int_T
* ir = rtMassMatrix . ir ; int_T * jc = rtMassMatrix . jc ; real_T * pr =
rtMassMatrix . pr ; ssSetMassMatrixIr ( rtS , ir ) ; ssSetMassMatrixJc ( rtS
, jc ) ; ssSetMassMatrixPr ( rtS , pr ) ; ( void ) memset ( ( void * ) ir , 0
, 1 * sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) jc , 0 , ( 2 + 1 ) *
sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) pr , 0 , 1 * sizeof (
real_T ) ) ; } } ssSetChecksumVal ( rtS , 0 , 1392658858U ) ;
ssSetChecksumVal ( rtS , 1 , 475129396U ) ; ssSetChecksumVal ( rtS , 2 ,
287096537U ) ; ssSetChecksumVal ( rtS , 3 , 1257556824U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Solar_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_Solar_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_Solar_SetDWork
) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS
) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
