#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "Solar_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "Solar.h"
#include "Solar_capi.h"
#include "Solar_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"Solar/Product" ) , TARGET_STRING ( "par2" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0
, TARGET_STRING ( "Solar/Test Voltage/Product" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "Solar/Test Voltage/Step" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"Solar/Test Voltage/Output" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 4 , 0 , TARGET_STRING ( "Solar/Test Voltage/Sum" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"Solar/Solver Configuration/EVAL_KEY/INPUT_1_1_1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"Solar/Solver Configuration/EVAL_KEY/INPUT_2_1_1" ) , TARGET_STRING ( "" ) ,
0 , 0 , 1 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"Solar/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"Solar/Solver Configuration/EVAL_KEY/STATE_1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 9 ,
TARGET_STRING ( "Solar/Test Voltage" ) , TARGET_STRING ( "slope" ) , 0 , 0 ,
0 } , { 10 , TARGET_STRING ( "Solar/Test Voltage" ) , TARGET_STRING ( "start"
) , 0 , 0 , 0 } , { 11 , TARGET_STRING ( "Solar/Test Voltage" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING (
"Solar/Test Voltage/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 0
, ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [
] = { - 1 } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , (
NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals
rtRootOutputs [ ] = { { 13 , 0 , TARGET_STRING ( "Solar/par1" ) ,
TARGET_STRING ( "par1" ) , 1 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"Solar/par2" ) , TARGET_STRING ( "par2" ) , 2 , 0 , 0 , 0 , 0 } , { 15 , 0 ,
TARGET_STRING ( "Solar/par3" ) , TARGET_STRING ( "par3" ) , 3 , 0 , 0 , 0 , 0
} , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 16 , TARGET_STRING (
"irradiance" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . dczfykt4fv , & rtB . f0ecfqt2re ,
& rtB . lyw1jaszff , & rtB . luzianfzgt , & rtB . obukmotbeo , & rtB .
pp3lsgkzsi [ 0 ] , & rtB . jhuhg2o5v3 [ 0 ] , & rtB . miacua0cge , & rtB .
nsafxb3i14 [ 0 ] , & rtP . TestVoltage_slope , & rtP . TestVoltage_start , &
rtP . TestVoltage_InitialOutput , & rtP . Step_Y0 , & rtY . kaweiuc2yf , &
rtY . imjtojlln4 , & rtY . c1n2sj3o2b , & rtP . irradiance , } ; static
int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 4 , 1 } ; static const real_T
rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ; static const rtwCAPI_FixPtMap
rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , (
boolean_T ) 0 } , } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ]
= { { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] ,
( int8_T ) 1 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 9 , rtRootInputs , 0 , rtRootOutputs , 3 } ,
{ rtBlockParameters , 4 , rtModelParameters , 1 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 1392658858U , 475129396U , 287096537U ,
1257556824U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * Solar_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void Solar_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void Solar_host_InitializeDataMapInfo ( Solar_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
