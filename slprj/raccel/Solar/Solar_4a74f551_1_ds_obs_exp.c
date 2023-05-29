#include "ne_ds.h"
#include "Solar_4a74f551_1_ds_sys_struct.h"
#include "Solar_4a74f551_1_ds_obs_exp.h"
#include "Solar_4a74f551_1_ds.h"
#include "Solar_4a74f551_1_ds_externals.h"
#include "Solar_4a74f551_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Solar_4a74f551_1_ds_obs_exp ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmRealVector out ; (
void ) t1 ; out = t2 -> mOBS_EXP ; out . mX [ 0 ] = 0.0 ; out . mX [ 1 ] =
0.0 ; out . mX [ 2 ] = 0.0 ; out . mX [ 3 ] = 0.0 ; out . mX [ 4 ] = 0.0 ;
out . mX [ 5 ] = 0.0 ; out . mX [ 6 ] = 0.0 ; out . mX [ 7 ] = 0.0 ; out . mX
[ 8 ] = 0.0 ; out . mX [ 9 ] = 0.0 ; out . mX [ 10 ] = 0.0 ; out . mX [ 11 ]
= 0.0 ; out . mX [ 12 ] = 0.0 ; out . mX [ 13 ] = 0.0 ; out . mX [ 14 ] = 0.0
; out . mX [ 15 ] = 0.0 ; out . mX [ 16 ] = 0.0 ; out . mX [ 17 ] = 0.0 ; out
. mX [ 18 ] = 0.0 ; out . mX [ 19 ] = 0.0 ; out . mX [ 20 ] = 0.0 ; out . mX
[ 21 ] = 0.0 ; out . mX [ 22 ] = 0.0 ; out . mX [ 23 ] = 0.0 ; out . mX [ 24
] = 0.0 ; out . mX [ 25 ] = 0.0 ; out . mX [ 26 ] = 298.15 ; out . mX [ 27 ]
= 0.0 ; out . mX [ 28 ] = 0.0 ; out . mX [ 29 ] = 0.0 ; out . mX [ 30 ] = 0.0
; out . mX [ 31 ] = 298.15 ; out . mX [ 32 ] = 0.0 ; out . mX [ 33 ] = 0.0 ;
out . mX [ 34 ] = 0.0 ; out . mX [ 35 ] = 0.0 ; out . mX [ 36 ] = 0.0 ; out .
mX [ 37 ] = 0.0 ; out . mX [ 38 ] = 0.0 ; out . mX [ 39 ] = 0.0 ; out . mX [
40 ] = 0.0 ; out . mX [ 41 ] = 0.0 ; out . mX [ 42 ] = 0.0 ; out . mX [ 43 ]
= 0.0 ; out . mX [ 44 ] = 0.0 ; out . mX [ 45 ] = 0.0 ; out . mX [ 46 ] = 0.0
; out . mX [ 47 ] = 0.0 ; out . mX [ 48 ] = 0.0 ; out . mX [ 49 ] = 0.0 ; out
. mX [ 50 ] = 0.0 ; out . mX [ 51 ] = 0.0 ; out . mX [ 52 ] = 0.0 ; out . mX
[ 53 ] = 0.0 ; out . mX [ 54 ] = 0.0 ; out . mX [ 55 ] = 0.0 ; out . mX [ 56
] = 0.0 ; out . mX [ 57 ] = 298.15 ; out . mX [ 58 ] = 0.0 ; out . mX [ 59 ]
= 0.0 ; out . mX [ 60 ] = 0.0 ; out . mX [ 61 ] = 1.0 ; out . mX [ 62 ] = 0.0
; out . mX [ 63 ] = 0.0 ; out . mX [ 64 ] = 0.0 ; ( void ) sys ; ( void ) t2
; return 0 ; }
