#include "ne_ds.h"
#include "Solar_4a74f551_1_ds_sys_struct.h"
#include "Solar_4a74f551_1_ds_obs_all.h"
#include "Solar_4a74f551_1_ds.h"
#include "Solar_4a74f551_1_ds_externals.h"
#include "Solar_4a74f551_1_ds_external_struct.h"
#include "ssc_ml_fun.h"
int32_T Solar_4a74f551_1_ds_obs_all ( const NeDynamicSystem * sys , const
NeDynamicSystemInput * t8 , NeDsMethodOutput * t9 ) { PmRealVector out ;
real_T Solar_Panel_Current_Controlled_Current_Source_i1 ; real_T
Solar_Panel_Solar_Cell_CCS_tail_v ; real_T
Solar_Panel_Solar_Cell_remaining_N_minus_one_cells_power_dissip ; real_T
U_idx_0 ; real_T U_idx_1 ; real_T X_idx_0 ; real_T X_idx_1 ; real_T t3 ;
real_T t4 ; real_T t5 ; U_idx_0 = t8 -> mU . mX [ 0 ] ; U_idx_1 = t8 -> mU .
mX [ 1 ] ; X_idx_0 = t8 -> mX . mX [ 0 ] ; X_idx_1 = t8 -> mX . mX [ 1 ] ;
out = t9 -> mOBS_ALL ; Solar_Panel_Current_Controlled_Current_Source_i1 =
X_idx_0 * 0.33333333333333331 ; Solar_Panel_Solar_Cell_CCS_tail_v = U_idx_0 *
0.98333333333333328 ; t3 = U_idx_0 * 0.016666666666666718 ; t4 = U_idx_0 -
Solar_Panel_Solar_Cell_CCS_tail_v ; t5 = X_idx_0 * - 0.33333333333333331 ;
Solar_Panel_Solar_Cell_remaining_N_minus_one_cells_power_dissip = - ( ( 0.0 *
t5 + X_idx_1 * t4 ) * 0.001 ) / - 0.016949152542372881 ; out . mX [ 0 ] =
X_idx_0 ; out . mX [ 1 ] = 0.0 ; out . mX [ 2 ] = U_idx_0 ; out . mX [ 3 ] =
U_idx_0 ; out . mX [ 4 ] = U_idx_0 ; out . mX [ 5 ] = X_idx_0 ; out . mX [ 6
] = X_idx_0 ; out . mX [ 7 ] = U_idx_0 ; out . mX [ 8 ] = U_idx_0 ; out . mX
[ 9 ] = X_idx_0 ; out . mX [ 10 ] = 0.0 ; out . mX [ 11 ] = U_idx_1 ; out .
mX [ 12 ] = U_idx_0 ; out . mX [ 13 ] = 0.0 ; out . mX [ 14 ] =
Solar_Panel_Current_Controlled_Current_Source_i1 ; out . mX [ 15 ] =
Solar_Panel_Current_Controlled_Current_Source_i1 * - 2.0 ; out . mX [ 16 ] =
U_idx_0 ; out . mX [ 17 ] = U_idx_0 ; out . mX [ 18 ] = U_idx_0 ; out . mX [
19 ] = 0.0 ; out . mX [ 20 ] = U_idx_0 ; out . mX [ 21 ] = U_idx_1 ; out . mX
[ 22 ] = U_idx_1 ; out . mX [ 23 ] = 0.0 ; out . mX [ 24 ] = U_idx_0 ; out .
mX [ 25 ] = U_idx_1 ; out . mX [ 26 ] = 298.15 ; out . mX [ 27 ] = U_idx_0 ;
out . mX [ 28 ] = X_idx_0 * 0.33333333333333331 + X_idx_1 ; out . mX [ 29 ] =
Solar_Panel_Solar_Cell_CCS_tail_v ; out . mX [ 30 ] =
Solar_Panel_Solar_Cell_CCS_tail_v - U_idx_0 ; out . mX [ 31 ] = 298.15 ; out
. mX [ 32 ] = 0.0 ; out . mX [ 33 ] = X_idx_1 ; out . mX [ 34 ] = 0.0 ; out .
mX [ 35 ] = X_idx_1 ; out . mX [ 36 ] = X_idx_1 ; out . mX [ 37 ] = t3 ; out
. mX [ 38 ] = Solar_Panel_Solar_Cell_CCS_tail_v ; out . mX [ 39 ] =
Solar_Panel_Solar_Cell_CCS_tail_v ; out . mX [ 40 ] = X_idx_1 ; out . mX [ 41
] = U_idx_0 ; out . mX [ 42 ] = U_idx_0 ; out . mX [ 43 ] = 0.0 ; out . mX [
44 ] = U_idx_0 ; out . mX [ 45 ] = U_idx_0 ; out . mX [ 46 ] = X_idx_1 * t3 *
0.001 * 1000.0 ; out . mX [ 47 ] = t4 ; out . mX [ 48 ] = 0.0 ; out . mX [ 49
] = 0.0 ; out . mX [ 50 ] = t5 ; out . mX [ 51 ] =
Solar_Panel_Solar_Cell_CCS_tail_v ; out . mX [ 52 ] = 0.0 ; out . mX [ 53 ] =
U_idx_0 ; out . mX [ 54 ] = Solar_Panel_Solar_Cell_CCS_tail_v ; out . mX [ 55
] = Solar_Panel_Solar_Cell_remaining_N_minus_one_cells_power_dissip * 1000.0
; out . mX [ 56 ] =
Solar_Panel_Solar_Cell_remaining_N_minus_one_cells_power_dissip *
16.949152542372882 ; out . mX [ 57 ] = 298.15 ; out . mX [ 58 ] = t5 ; out .
mX [ 59 ] = U_idx_0 ; out . mX [ 60 ] = U_idx_0 ; out . mX [ 61 ] = 0.0 * t5
* 0.001 * 1000.0 ; out . mX [ 62 ] = 0.0 ; out . mX [ 63 ] = U_idx_0 ; out .
mX [ 64 ] = 0.0 ; ( void ) sys ; ( void ) t9 ; return 0 ; }
