#include "testmodel1_D1E3B3D405CB60B382A20109046C7C6D.h"
#include <cvodes/cvodes.h>
#include <cvodes/cvodes_dense.h>
#include <cvodes/cvodes_sparse.h>
#include <nvector/nvector_serial.h>
#include <sundials/sundials_types.h>
#include <sundials/sundials_math.h>
#include <sundials/sundials_sparse.h>
#include <cvodes/cvodes_klu.h>
#include <udata.h>
#include <math.h>
#include <mex.h>
#include <arInputFunctionsC.h>





 void fu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(void *user_data, double t)
{

  return;
}


 void fsu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(void *user_data, double t)
{

  return;
}


 void fv_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->v[0] = p[6]*x_tmp[0];
  data->v[1] = p[4]*x_tmp[2];
  data->v[2] = p[4]*x_tmp[4];
  data->v[3] = p[4]*x_tmp[5];
  data->v[4] = p[7]*x_tmp[6];
  data->v[5] = p[1]*x_tmp[1];
  data->v[6] = p[3]*x_tmp[3];
  data->v[7] = p[3]*x_tmp[7];
  data->v[8] = p[3]*x_tmp[8];
  data->v[9] = p[3]*x_tmp[9];
  data->v[10] = p[3]*x_tmp[10];
  data->v[11] = p[2]*x_tmp[11];

  return;
}


 void dvdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdx[0] = p[6];
  data->dvdx[17] = p[1];
  data->dvdx[25] = p[4];
  data->dvdx[42] = p[3];
  data->dvdx[50] = p[4];
  data->dvdx[63] = p[4];
  data->dvdx[76] = p[7];
  data->dvdx[91] = p[3];
  data->dvdx[104] = p[3];
  data->dvdx[117] = p[3];
  data->dvdx[130] = p[3];
  data->dvdx[143] = p[2];

  return;
}


 void dvdu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data)
{

  return;
}


 void dvdp_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdp[17] = x_tmp[1];
  data->dvdp[35] = x_tmp[11];
  data->dvdp[42] = x_tmp[3];
  data->dvdp[43] = x_tmp[7];
  data->dvdp[44] = x_tmp[8];
  data->dvdp[45] = x_tmp[9];
  data->dvdp[46] = x_tmp[10];
  data->dvdp[49] = x_tmp[2];
  data->dvdp[50] = x_tmp[4];
  data->dvdp[51] = x_tmp[5];
  data->dvdp[72] = x_tmp[0];
  data->dvdp[88] = x_tmp[6];

  return;
}


 int fx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, N_Vector xdot, void *user_data)
{
  UserData data = (UserData) user_data;
  int is;
  double *qpositivex = data->qpositivex;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  double *x_tmp = N_VGetArrayPointer(x);
  double *xdot_tmp = N_VGetArrayPointer(xdot);
  fu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(data, t);
  fv_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  xdot_tmp[0] = -v[0];
  xdot_tmp[1] = v[4]-v[5];
  xdot_tmp[2] = v[0]-v[1];
  xdot_tmp[3] = v[5]-v[6];
  xdot_tmp[4] = v[1]-v[2];
  xdot_tmp[5] = v[2]-v[3];
  xdot_tmp[6] = v[3]-v[4];
  xdot_tmp[7] = v[6]-v[7];
  xdot_tmp[8] = v[7]-v[8];
  xdot_tmp[9] = v[8]-v[9];
  xdot_tmp[10] = v[9]-v[10];
  xdot_tmp[11] = v[10]-v[11];
  for (is=0; is<12; is++) {
    if(mxIsNaN(xdot_tmp[is])) xdot_tmp[is] = 0.0;
    if(qpositivex[is]>0.5 && x_tmp[is]<0.0 && xdot_tmp[is]<0.0) xdot_tmp[is] = -xdot_tmp[is];
  }

  return(*(data->abort));
}


 void fxdouble_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, double *xdot_tmp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  fu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(data, t);
  fv_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  xdot_tmp[0] = -v[0];
  xdot_tmp[1] = v[4]-v[5];
  xdot_tmp[2] = v[0]-v[1];
  xdot_tmp[3] = v[5]-v[6];
  xdot_tmp[4] = v[1]-v[2];
  xdot_tmp[5] = v[2]-v[3];
  xdot_tmp[6] = v[3]-v[4];
  xdot_tmp[7] = v[6]-v[7];
  xdot_tmp[8] = v[7]-v[8];
  xdot_tmp[9] = v[8]-v[9];
  xdot_tmp[10] = v[9]-v[10];
  xdot_tmp[11] = v[10]-v[11];
  for (is=0; is<12; is++) {
    if(mxIsNaN(xdot_tmp[is])) xdot_tmp[is] = 0.0;
  }

  return;
}


 void fx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(N_Vector x0, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x0_tmp = N_VGetArrayPointer(x0);
  x0_tmp[0] = p[0]/p[5];
  x0_tmp[1] = (p[0]*p[7])/(p[1]*p[5]);
  x0_tmp[2] = p[0]/p[5];
  x0_tmp[3] = p[0]/p[5];
  x0_tmp[4] = p[0]/p[5];
  x0_tmp[5] = p[0]/p[5];
  x0_tmp[6] = p[0]/p[5];
  x0_tmp[7] = p[0]/p[5];
  x0_tmp[8] = p[0]/p[5];
  x0_tmp[9] = p[0]/p[5];
  x0_tmp[10] = p[0]/p[5];
  x0_tmp[11] = p[0]/p[5];

  return;
}


 int dfxdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(long int N, realtype t, N_Vector x, 
  	N_Vector fx, DlsMat J, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  for (is=0; is<144; is++) {
    J->data[is] = 0.0;
  }
  J->data[0] = -dvdx[0];
  J->data[2] = dvdx[0];
  J->data[13] = -dvdx[17];
  J->data[15] = dvdx[17];
  J->data[26] = -dvdx[25];
  J->data[28] = dvdx[25];
  J->data[39] = -dvdx[42];
  J->data[43] = dvdx[42];
  J->data[52] = -dvdx[50];
  J->data[53] = dvdx[50];
  J->data[65] = -dvdx[63];
  J->data[66] = dvdx[63];
  J->data[73] = dvdx[76];
  J->data[78] = -dvdx[76];
  J->data[91] = -dvdx[91];
  J->data[92] = dvdx[91];
  J->data[104] = -dvdx[104];
  J->data[105] = dvdx[104];
  J->data[117] = -dvdx[117];
  J->data[118] = dvdx[117];
  J->data[130] = -dvdx[130];
  J->data[131] = dvdx[130];
  J->data[143] = -dvdx[143];
  for (is=0; is<144; is++) {
    if(mxIsNaN(J->data[is])) J->data[is] = 0.0;
  }

  return(0);
}


 int dfxdx_out_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, realtype* J, void *user_data) {
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  for (is=0; is<144; is++) {
    J[is] = 0.0;
  }
  J[0] = -dvdx[0];
  J[2] = dvdx[0];
  J[13] = -dvdx[17];
  J[15] = dvdx[17];
  J[26] = -dvdx[25];
  J[28] = dvdx[25];
  J[39] = -dvdx[42];
  J[43] = dvdx[42];
  J[52] = -dvdx[50];
  J[53] = dvdx[50];
  J[65] = -dvdx[63];
  J[66] = dvdx[63];
  J[73] = dvdx[76];
  J[78] = -dvdx[76];
  J[91] = -dvdx[91];
  J[92] = dvdx[91];
  J[104] = -dvdx[104];
  J[105] = dvdx[104];
  J[117] = -dvdx[117];
  J[118] = dvdx[117];
  J[130] = -dvdx[130];
  J[131] = dvdx[130];
  J[143] = -dvdx[143];
  for (is=0; is<144; is++) {
    if(mxIsNaN(J[is])) J[is] = 0.0;
  }

  return(0);
}


 int dfxdx_sparse_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, 
  	N_Vector fx, SlsMat J, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  SlsSetToZero(J);
    J->rowvals[0] = 0;
    J->rowvals[1] = 2;
    J->rowvals[2] = 1;
    J->rowvals[3] = 3;
    J->rowvals[4] = 2;
    J->rowvals[5] = 4;
    J->rowvals[6] = 3;
    J->rowvals[7] = 7;
    J->rowvals[8] = 4;
    J->rowvals[9] = 5;
    J->rowvals[10] = 5;
    J->rowvals[11] = 6;
    J->rowvals[12] = 1;
    J->rowvals[13] = 6;
    J->rowvals[14] = 7;
    J->rowvals[15] = 8;
    J->rowvals[16] = 8;
    J->rowvals[17] = 9;
    J->rowvals[18] = 9;
    J->rowvals[19] = 10;
    J->rowvals[20] = 10;
    J->rowvals[21] = 11;
    J->rowvals[22] = 11;

    J->colptrs[0] = 0;
    J->colptrs[1] = 2;
    J->colptrs[2] = 4;
    J->colptrs[3] = 6;
    J->colptrs[4] = 8;
    J->colptrs[5] = 10;
    J->colptrs[6] = 12;
    J->colptrs[7] = 14;
    J->colptrs[8] = 16;
    J->colptrs[9] = 18;
    J->colptrs[10] = 20;
    J->colptrs[11] = 22;
    J->colptrs[12] = 23;

  J->data[0] = -dvdx[0];
  J->data[1] = dvdx[0];
  J->data[2] = -dvdx[17];
  J->data[3] = dvdx[17];
  J->data[4] = -dvdx[25];
  J->data[5] = dvdx[25];
  J->data[6] = -dvdx[42];
  J->data[7] = dvdx[42];
  J->data[8] = -dvdx[50];
  J->data[9] = dvdx[50];
  J->data[10] = -dvdx[63];
  J->data[11] = dvdx[63];
  J->data[12] = dvdx[76];
  J->data[13] = -dvdx[76];
  J->data[14] = -dvdx[91];
  J->data[15] = dvdx[91];
  J->data[16] = -dvdx[104];
  J->data[17] = dvdx[104];
  J->data[18] = -dvdx[117];
  J->data[19] = dvdx[117];
  J->data[20] = -dvdx[130];
  J->data[21] = dvdx[130];
  J->data[22] = -dvdx[143];
  for (is=0; is<23; is++) {
    if(mxIsNaN(J->data[is])) J->data[is] = RCONST(0.0);
  }

  return(0);
}


 int fsx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int Ns, realtype t, N_Vector x, N_Vector xdot, 
  	int ip, N_Vector sx, N_Vector sxdot, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sv = data->sv;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *dvdp = data->dvdp;
  double *x_tmp = N_VGetArrayPointer(x);
  double *su = data->su;
  double *sx_tmp = N_VGetArrayPointer(sx);
  double *sxdot_tmp = N_VGetArrayPointer(sxdot);
  fsu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(data, t);
  dvdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  dvdu_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  dvdp_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(t, x, data);
  for (is=0; is<12; is++) {
    sv[is] = 0.0;
  }
  sv[0] = dvdx[0]*sx_tmp[0];
  sv[1] = dvdx[25]*sx_tmp[2];
  sv[2] = dvdx[50]*sx_tmp[4];
  sv[3] = dvdx[63]*sx_tmp[5];
  sv[4] = dvdx[76]*sx_tmp[6];
  sv[5] = dvdx[17]*sx_tmp[1];
  sv[6] = dvdx[42]*sx_tmp[3];
  sv[7] = dvdx[91]*sx_tmp[7];
  sv[8] = dvdx[104]*sx_tmp[8];
  sv[9] = dvdx[117]*sx_tmp[9];
  sv[10] = dvdx[130]*sx_tmp[10];
  sv[11] = dvdx[143]*sx_tmp[11];
  switch (ip) {
    case 0: {

    } break;
    case 1: {
      sv[5] += dvdp[17];
    } break;
    case 2: {
      sv[11] += dvdp[35];
    } break;
    case 3: {
      sv[6] += dvdp[42];
      sv[7] += dvdp[43];
      sv[8] += dvdp[44];
      sv[9] += dvdp[45];
      sv[10] += dvdp[46];
    } break;
    case 4: {
      sv[1] += dvdp[49];
      sv[2] += dvdp[50];
      sv[3] += dvdp[51];
    } break;
    case 5: {

    } break;
    case 6: {
      sv[0] += dvdp[72];
    } break;
    case 7: {
      sv[4] += dvdp[88];
    } break;
  }
  sxdot_tmp[0] = -sv[0];
  sxdot_tmp[1] = sv[4]-sv[5];
  sxdot_tmp[2] = sv[0]-sv[1];
  sxdot_tmp[3] = sv[5]-sv[6];
  sxdot_tmp[4] = sv[1]-sv[2];
  sxdot_tmp[5] = sv[2]-sv[3];
  sxdot_tmp[6] = sv[3]-sv[4];
  sxdot_tmp[7] = sv[6]-sv[7];
  sxdot_tmp[8] = sv[7]-sv[8];
  sxdot_tmp[9] = sv[8]-sv[9];
  sxdot_tmp[10] = sv[9]-sv[10];
  sxdot_tmp[11] = sv[10]-sv[11];
  for (is=0; is<12; is++) {
    if(mxIsNaN(sxdot_tmp[is])) sxdot_tmp[is] = 0.0;
  }

  return(0);
}


 int subfsx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int Ns, realtype t, N_Vector x, N_Vector xdot, 
  	int ip, N_Vector sx, N_Vector sxdot, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2)
 {
   UserData data = (UserData) user_data;
   return fsx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(Ns, t, x, xdot, data->sensIndices[ip], sx, sxdot, user_data, tmp1, tmp2);
 };

 void csv_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, int ip, N_Vector sx, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sv = data->sv;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *dvdp = data->dvdp;
  double *x_tmp = N_VGetArrayPointer(x);
  double *su = data->su;
  double *sx_tmp = N_VGetArrayPointer(sx);
  for (is=0; is<12; is++) {
    sv[is] = 0.0;
  }
  sv[0] = dvdx[0]*sx_tmp[0];
  sv[1] = dvdx[25]*sx_tmp[2];
  sv[2] = dvdx[50]*sx_tmp[4];
  sv[3] = dvdx[63]*sx_tmp[5];
  sv[4] = dvdx[76]*sx_tmp[6];
  sv[5] = dvdx[17]*sx_tmp[1];
  sv[6] = dvdx[42]*sx_tmp[3];
  sv[7] = dvdx[91]*sx_tmp[7];
  sv[8] = dvdx[104]*sx_tmp[8];
  sv[9] = dvdx[117]*sx_tmp[9];
  sv[10] = dvdx[130]*sx_tmp[10];
  sv[11] = dvdx[143]*sx_tmp[11];
  switch (ip) {
    case 0: {

    } break;
    case 1: {
      sv[5] += dvdp[17];
    } break;
    case 2: {
      sv[11] += dvdp[35];
    } break;
    case 3: {
      sv[6] += dvdp[42];
      sv[7] += dvdp[43];
      sv[8] += dvdp[44];
      sv[9] += dvdp[45];
      sv[10] += dvdp[46];
    } break;
    case 4: {
      sv[1] += dvdp[49];
      sv[2] += dvdp[50];
      sv[3] += dvdp[51];
    } break;
    case 5: {

    } break;
    case 6: {
      sv[0] += dvdp[72];
    } break;
    case 7: {
      sv[4] += dvdp[88];
    } break;
  }

  return;
}


 void fsx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int ip, N_Vector sx0, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sx0_tmp = N_VGetArrayPointer(sx0);
  switch (ip) {
    case 0: {
      sx0_tmp[0] = 1.0/p[5];
      sx0_tmp[1] = p[7]/(p[1]*p[5]);
      sx0_tmp[2] = 1.0/p[5];
      sx0_tmp[3] = 1.0/p[5];
      sx0_tmp[4] = 1.0/p[5];
      sx0_tmp[5] = 1.0/p[5];
      sx0_tmp[6] = 1.0/p[5];
      sx0_tmp[7] = 1.0/p[5];
      sx0_tmp[8] = 1.0/p[5];
      sx0_tmp[9] = 1.0/p[5];
      sx0_tmp[10] = 1.0/p[5];
      sx0_tmp[11] = 1.0/p[5];
    } break;
    case 1: {
      sx0_tmp[1] = -(p[0]*1.0/(p[1]*p[1])*p[7])/p[5];
    } break;
    case 5: {
      sx0_tmp[0] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[1] = -(p[0]*1.0/(p[5]*p[5])*p[7])/p[1];
      sx0_tmp[2] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[3] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[4] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[5] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[6] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[7] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[8] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[9] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[10] = -p[0]*1.0/(p[5]*p[5]);
      sx0_tmp[11] = -p[0]*1.0/(p[5]*p[5]);
    } break;
    case 7: {
      sx0_tmp[1] = p[0]/(p[1]*p[5]);
    } break;
  }

  return;
}


 void subfsx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(int ip, N_Vector sx0, void *user_data)
 {
   UserData data = (UserData) user_data;
   fsx0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(data->sensIndices[ip], sx0, user_data);
 };

 void dfxdp0_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, double *dfxdp0, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdp = data->dvdp;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *x_tmp = N_VGetArrayPointer(x);
  dfxdp0[0] = -dvdx[0]/p[5];
  dfxdp0[1] = dvdx[76]/p[5]-(dvdx[17]*p[7])/(p[1]*p[5]);
  dfxdp0[2] = dvdx[0]/p[5]-dvdx[25]/p[5];
  dfxdp0[3] = -dvdx[42]/p[5]+(dvdx[17]*p[7])/(p[1]*p[5]);
  dfxdp0[4] = dvdx[25]/p[5]-dvdx[50]/p[5];
  dfxdp0[5] = dvdx[50]/p[5]-dvdx[63]/p[5];
  dfxdp0[6] = dvdx[63]/p[5]-dvdx[76]/p[5];
  dfxdp0[7] = dvdx[42]/p[5]-dvdx[91]/p[5];
  dfxdp0[8] = dvdx[91]/p[5]-dvdx[104]/p[5];
  dfxdp0[9] = dvdx[104]/p[5]-dvdx[117]/p[5];
  dfxdp0[10] = dvdx[117]/p[5]-dvdx[130]/p[5];
  dfxdp0[11] = dvdx[130]/p[5]-dvdx[143]/p[5];
  dfxdp0[13] = -dvdp[17]+(dvdx[17]*p[0]*1.0/(p[1]*p[1])*p[7])/p[5];
  dfxdp0[15] = dvdp[17]-(dvdx[17]*p[0]*1.0/(p[1]*p[1])*p[7])/p[5];
  dfxdp0[35] = -dvdp[35];
  dfxdp0[39] = -dvdp[42];
  dfxdp0[43] = dvdp[42]-dvdp[43];
  dfxdp0[44] = dvdp[43]-dvdp[44];
  dfxdp0[45] = dvdp[44]-dvdp[45];
  dfxdp0[46] = dvdp[45]-dvdp[46];
  dfxdp0[47] = dvdp[46];
  dfxdp0[50] = -dvdp[49];
  dfxdp0[52] = dvdp[49]-dvdp[50];
  dfxdp0[53] = dvdp[50]-dvdp[51];
  dfxdp0[54] = dvdp[51];
  dfxdp0[60] = dvdx[0]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[61] = -dvdx[76]*p[0]*1.0/(p[5]*p[5])+(dvdx[17]*p[0]*1.0/(p[5]*p[5])*p[7])/p[1];
  dfxdp0[62] = -dvdx[0]*p[0]*1.0/(p[5]*p[5])+dvdx[25]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[63] = dvdx[42]*p[0]*1.0/(p[5]*p[5])-(dvdx[17]*p[0]*1.0/(p[5]*p[5])*p[7])/p[1];
  dfxdp0[64] = -dvdx[25]*p[0]*1.0/(p[5]*p[5])+dvdx[50]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[65] = -dvdx[50]*p[0]*1.0/(p[5]*p[5])+dvdx[63]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[66] = -dvdx[63]*p[0]*1.0/(p[5]*p[5])+dvdx[76]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[67] = -dvdx[42]*p[0]*1.0/(p[5]*p[5])+dvdx[91]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[68] = -dvdx[91]*p[0]*1.0/(p[5]*p[5])+dvdx[104]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[69] = -dvdx[104]*p[0]*1.0/(p[5]*p[5])+dvdx[117]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[70] = -dvdx[117]*p[0]*1.0/(p[5]*p[5])+dvdx[130]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[71] = -dvdx[130]*p[0]*1.0/(p[5]*p[5])+dvdx[143]*p[0]*1.0/(p[5]*p[5]);
  dfxdp0[72] = -dvdp[72];
  dfxdp0[74] = dvdp[72];
  dfxdp0[85] = dvdp[88]-(dvdx[17]*p[0])/(p[1]*p[5]);
  dfxdp0[87] = (dvdx[17]*p[0])/(p[1]*p[5]);
  dfxdp0[90] = -dvdp[88];
  for (is=0; is<96; is++) {
    if(mxIsNaN(dfxdp0[is])) dfxdp0[is] = 0.0;
  }

  return;
}


 void dfxdp_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(realtype t, N_Vector x, double *dfxdp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdp = data->dvdp;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *x_tmp = N_VGetArrayPointer(x);
  dfxdp[13] = -dvdp[17];
  dfxdp[15] = dvdp[17];
  dfxdp[35] = -dvdp[35];
  dfxdp[39] = -dvdp[42];
  dfxdp[43] = dvdp[42]-dvdp[43];
  dfxdp[44] = dvdp[43]-dvdp[44];
  dfxdp[45] = dvdp[44]-dvdp[45];
  dfxdp[46] = dvdp[45]-dvdp[46];
  dfxdp[47] = dvdp[46];
  dfxdp[50] = -dvdp[49];
  dfxdp[52] = dvdp[49]-dvdp[50];
  dfxdp[53] = dvdp[50]-dvdp[51];
  dfxdp[54] = dvdp[51];
  dfxdp[72] = -dvdp[72];
  dfxdp[74] = dvdp[72];
  dfxdp[85] = dvdp[88];
  dfxdp[90] = -dvdp[88];
  for (is=0; is<96; is++) {
    if(mxIsNaN(dfxdp[is])) dfxdp[is] = 0.0;
  }

  return;
}


 void fz_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *z, double *p, double *u, double *x){

  return;
}


 void fsz_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(double t, int nt, int it, int np, double *sz, double *p, double *u, double *x, double *z, double *su, double *sx){

  return;
}


 void dfzdx_testmodel1_D1E3B3D405CB60B382A20109046C7C6D(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *dfzdxs, double *z, double *p, double *u, double *x){

  return;
}


