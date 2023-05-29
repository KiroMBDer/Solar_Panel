#ifndef RTW_HEADER_Solar_h_
#define RTW_HEADER_Solar_h_
#ifndef Solar_COMMON_INCLUDES_
#define Solar_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "Solar_4a74f551_1_gateway.h"
#endif
#include "Solar_types.h"
#include <string.h>
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Solar
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (3)     
#define NBLOCKIO (9) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (2)   
#elif NCSTATES != 2
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T lyw1jaszff ; real_T obukmotbeo ; real_T f0ecfqt2re ;
real_T luzianfzgt ; real_T pp3lsgkzsi [ 4 ] ; real_T jhuhg2o5v3 [ 4 ] ;
real_T nsafxb3i14 [ 4 ] ; real_T miacua0cge ; real_T dczfykt4fv ; } B ;
typedef struct { real_T b3j4dtgyry [ 2 ] ; real_T b2ahp0rfiw [ 2 ] ; real_T
fxe3vkttrz ; real_T p4ftbnb1f3 ; void * bipxskpt45 ; void * alcd0k4gkq ; void
* c15q5nfivf ; void * oo3jx2kqnt ; void * icnxaqzux2 ; void * c3nc4wn3cv ;
void * dsgtoj40g5 ; void * fke3k403tp ; void * pcmmzetobh ; void * nzvr1akl4a
; struct { void * AQHandles ; } n2xwbehmxh ; struct { void * AQHandles ; }
oqunl2krqg ; struct { void * AQHandles ; } p0ykozkwg0 ; int_T lua3lh5sso [ 2
] ; int_T kypyg3mc0h ; int_T ba4fhlmj5j ; int32_T ealppa1yju ; boolean_T
ipwfflkpgw ; boolean_T dhdenh4pzm ; } DW ; typedef struct { real_T ckqu0stfib
[ 2 ] ; } X ; typedef struct { real_T ckqu0stfib [ 2 ] ; } XDot ; typedef
struct { boolean_T ckqu0stfib [ 2 ] ; } XDis ; typedef struct { real_T
ckqu0stfib [ 2 ] ; } CStateAbsTol ; typedef struct { real_T ckqu0stfib [ 2 ]
; } CXPtMin ; typedef struct { real_T ckqu0stfib [ 2 ] ; } CXPtMax ; typedef
struct { real_T jq2cm4gswo ; real_T a5ricxsosm ; real_T j30c14vrzc ; } ZCV ;
typedef struct { int_T ir [ 1 ] ; int_T jc [ 3 ] ; real_T pr [ 1 ] ; }
MassMatrix ; typedef struct { real_T kaweiuc2yf ; real_T imjtojlln4 ; real_T
c1n2sj3o2b ; } ExtY ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T irradiance ; real_T
TestVoltage_InitialOutput ; real_T TestVoltage_slope ; real_T
TestVoltage_start ; real_T Step_Y0 ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern ExtY rtY ; extern MassMatrix rtMassMatrix ; extern P rtP ; extern
mxArray * mr_Solar_GetDWork ( ) ; extern void mr_Solar_SetDWork ( const
mxArray * ssDW ) ; extern mxArray * mr_Solar_GetSimStateDisallowedBlocks ( )
; extern const rtwCAPI_ModelMappingStaticInfo * Solar_GetCAPIStaticMap ( void
) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
