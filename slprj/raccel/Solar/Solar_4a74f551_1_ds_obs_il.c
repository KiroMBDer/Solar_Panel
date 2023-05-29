#include "ne_ds.h"
#include "Solar_4a74f551_1_ds_sys_struct.h"
#include "Solar_4a74f551_1_ds_obs_il.h"
#include "Solar_4a74f551_1_ds.h"
#include "Solar_4a74f551_1_ds_externals.h"
#include "Solar_4a74f551_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Solar_4a74f551_1_ds_obs_il ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t1 , NeDsMethodOutput * t2 ) { PmBoolVector out ; (
void ) t1 ; out = t2 -> mOBS_IL ; out . mX [ 0 ] = true ; out . mX [ 1 ] =
true ; out . mX [ 2 ] = false ; out . mX [ 3 ] = false ; out . mX [ 4 ] =
false ; out . mX [ 5 ] = true ; out . mX [ 6 ] = true ; out . mX [ 7 ] =
false ; out . mX [ 8 ] = false ; out . mX [ 9 ] = true ; out . mX [ 10 ] =
true ; out . mX [ 11 ] = false ; out . mX [ 12 ] = false ; out . mX [ 13 ] =
true ; out . mX [ 14 ] = true ; out . mX [ 15 ] = true ; out . mX [ 16 ] =
false ; out . mX [ 17 ] = false ; out . mX [ 18 ] = false ; out . mX [ 19 ] =
true ; out . mX [ 20 ] = false ; out . mX [ 21 ] = false ; out . mX [ 22 ] =
false ; out . mX [ 23 ] = true ; out . mX [ 24 ] = false ; out . mX [ 25 ] =
false ; out . mX [ 26 ] = true ; out . mX [ 27 ] = false ; out . mX [ 28 ] =
true ; out . mX [ 29 ] = false ; out . mX [ 30 ] = false ; out . mX [ 31 ] =
true ; out . mX [ 32 ] = true ; out . mX [ 33 ] = true ; out . mX [ 34 ] =
true ; out . mX [ 35 ] = true ; out . mX [ 36 ] = true ; out . mX [ 37 ] =
false ; out . mX [ 38 ] = false ; out . mX [ 39 ] = false ; out . mX [ 40 ] =
true ; out . mX [ 41 ] = false ; out . mX [ 42 ] = false ; out . mX [ 43 ] =
true ; out . mX [ 44 ] = false ; out . mX [ 45 ] = false ; out . mX [ 46 ] =
false ; out . mX [ 47 ] = false ; out . mX [ 48 ] = true ; out . mX [ 49 ] =
true ; out . mX [ 50 ] = true ; out . mX [ 51 ] = false ; out . mX [ 52 ] =
true ; out . mX [ 53 ] = false ; out . mX [ 54 ] = false ; out . mX [ 55 ] =
false ; out . mX [ 56 ] = false ; out . mX [ 57 ] = true ; out . mX [ 58 ] =
true ; out . mX [ 59 ] = false ; out . mX [ 60 ] = false ; out . mX [ 61 ] =
true ; out . mX [ 62 ] = true ; out . mX [ 63 ] = false ; out . mX [ 64 ] =
true ; ( void ) sys ; ( void ) t2 ; return 0 ; }
