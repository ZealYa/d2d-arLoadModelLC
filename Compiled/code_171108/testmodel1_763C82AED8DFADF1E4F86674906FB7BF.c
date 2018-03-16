#include "testmodel1_763C82AED8DFADF1E4F86674906FB7BF.h"
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





 void fu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(void *user_data, double t)
{

  return;
}


 void fsu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(void *user_data, double t)
{

  return;
}


 void fv_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->v[0] = p[6]*x_tmp[0];
  data->v[1] = p[6]*x_tmp[2];
  data->v[2] = p[6]*x_tmp[3];
  data->v[3] = p[6]*x_tmp[4];
  data->v[4] = p[7]*x_tmp[5];
  data->v[5] = p[5]*x_tmp[1];

  return;
}


 void dvdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdx[0] = p[6];
  data->dvdx[11] = p[5];
  data->dvdx[13] = p[6];
  data->dvdx[20] = p[6];
  data->dvdx[27] = p[6];
  data->dvdx[34] = p[7];

  return;
}


 void dvdu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, void *user_data)
{

  return;
}


 void dvdp_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x_tmp = N_VGetArrayPointer(x);
  data->dvdp[35] = x_tmp[1];
  data->dvdp[36] = x_tmp[0];
  data->dvdp[37] = x_tmp[2];
  data->dvdp[38] = x_tmp[3];
  data->dvdp[39] = x_tmp[4];
  data->dvdp[46] = x_tmp[5];

  return;
}


 int fx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, N_Vector xdot, void *user_data)
{
  UserData data = (UserData) user_data;
  int is;
  double *qpositivex = data->qpositivex;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  double *x_tmp = N_VGetArrayPointer(x);
  double *xdot_tmp = N_VGetArrayPointer(xdot);
  fu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(data, t);
  fv_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  xdot_tmp[0] = -v[0];
  xdot_tmp[1] = v[4]-v[5];
  xdot_tmp[2] = v[0]-v[1];
  xdot_tmp[3] = v[1]-v[2];
  xdot_tmp[4] = v[2]-v[3];
  xdot_tmp[5] = v[3]-v[4];
  for (is=0; is<6; is++) {
    if(mxIsNaN(xdot_tmp[is])) xdot_tmp[is] = 0.0;
    if(qpositivex[is]>0.5 && x_tmp[is]<0.0 && xdot_tmp[is]<0.0) xdot_tmp[is] = -xdot_tmp[is];
  }

  return(*(data->abort));
}


 void fxdouble_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, double *xdot_tmp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  fu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(data, t);
  fv_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  xdot_tmp[0] = -v[0];
  xdot_tmp[1] = v[4]-v[5];
  xdot_tmp[2] = v[0]-v[1];
  xdot_tmp[3] = v[1]-v[2];
  xdot_tmp[4] = v[2]-v[3];
  xdot_tmp[5] = v[3]-v[4];
  for (is=0; is<6; is++) {
    if(mxIsNaN(xdot_tmp[is])) xdot_tmp[is] = 0.0;
  }

  return;
}


 void fx0_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(N_Vector x0, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *x0_tmp = N_VGetArrayPointer(x0);
  x0_tmp[0] = p[0]/p[6];
  x0_tmp[1] = (p[0]*p[7])/(p[5]*p[6]);
  x0_tmp[2] = p[1];
  x0_tmp[3] = p[2];
  x0_tmp[4] = p[3];
  x0_tmp[5] = p[4];

  return;
}


 int dfxdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(long int N, realtype t, N_Vector x, 
  	N_Vector fx, DlsMat J, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  for (is=0; is<36; is++) {
    J->data[is] = 0.0;
  }
  J->data[0] = -dvdx[0];
  J->data[2] = dvdx[0];
  J->data[7] = -dvdx[11];
  J->data[14] = -dvdx[13];
  J->data[15] = dvdx[13];
  J->data[21] = -dvdx[20];
  J->data[22] = dvdx[20];
  J->data[28] = -dvdx[27];
  J->data[29] = dvdx[27];
  J->data[31] = dvdx[34];
  J->data[35] = -dvdx[34];
  for (is=0; is<36; is++) {
    if(mxIsNaN(J->data[is])) J->data[is] = 0.0;
  }

  return(0);
}


 int dfxdx_out_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, realtype* J, void *user_data) {
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  for (is=0; is<36; is++) {
    J[is] = 0.0;
  }
  J[0] = -dvdx[0];
  J[2] = dvdx[0];
  J[7] = -dvdx[11];
  J[14] = -dvdx[13];
  J[15] = dvdx[13];
  J[21] = -dvdx[20];
  J[22] = dvdx[20];
  J[28] = -dvdx[27];
  J[29] = dvdx[27];
  J[31] = dvdx[34];
  J[35] = -dvdx[34];
  for (is=0; is<36; is++) {
    if(mxIsNaN(J[is])) J[is] = 0.0;
  }

  return(0);
}


 int dfxdx_sparse_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, 
  	N_Vector fx, SlsMat J, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2, N_Vector tmp3)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdx = data->dvdx;
  dvdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  SlsSetToZero(J);
    J->rowvals[0] = 0;
    J->rowvals[1] = 2;
    J->rowvals[2] = 1;
    J->rowvals[3] = 2;
    J->rowvals[4] = 3;
    J->rowvals[5] = 3;
    J->rowvals[6] = 4;
    J->rowvals[7] = 4;
    J->rowvals[8] = 5;
    J->rowvals[9] = 1;
    J->rowvals[10] = 5;

    J->colptrs[0] = 0;
    J->colptrs[1] = 2;
    J->colptrs[2] = 3;
    J->colptrs[3] = 5;
    J->colptrs[4] = 7;
    J->colptrs[5] = 9;
    J->colptrs[6] = 11;

  J->data[0] = -dvdx[0];
  J->data[1] = dvdx[0];
  J->data[2] = -dvdx[11];
  J->data[3] = -dvdx[13];
  J->data[4] = dvdx[13];
  J->data[5] = -dvdx[20];
  J->data[6] = dvdx[20];
  J->data[7] = -dvdx[27];
  J->data[8] = dvdx[27];
  J->data[9] = dvdx[34];
  J->data[10] = -dvdx[34];
  for (is=0; is<11; is++) {
    if(mxIsNaN(J->data[is])) J->data[is] = RCONST(0.0);
  }

  return(0);
}


 int fsx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(int Ns, realtype t, N_Vector x, N_Vector xdot, 
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
  fsu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(data, t);
  dvdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  dvdu_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  dvdp_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(t, x, data);
  for (is=0; is<6; is++) {
    sv[is] = 0.0;
  }
  sv[0] = dvdx[0]*sx_tmp[0];
  sv[1] = dvdx[13]*sx_tmp[2];
  sv[2] = dvdx[20]*sx_tmp[3];
  sv[3] = dvdx[27]*sx_tmp[4];
  sv[4] = dvdx[34]*sx_tmp[5];
  sv[5] = dvdx[11]*sx_tmp[1];
  switch (ip) {
    case 0: {

    } break;
    case 1: {

    } break;
    case 2: {

    } break;
    case 3: {

    } break;
    case 4: {

    } break;
    case 5: {
      sv[5] += dvdp[35];
    } break;
    case 6: {
      sv[0] += dvdp[36];
      sv[1] += dvdp[37];
      sv[2] += dvdp[38];
      sv[3] += dvdp[39];
    } break;
    case 7: {
      sv[4] += dvdp[46];
    } break;
  }
  sxdot_tmp[0] = -sv[0];
  sxdot_tmp[1] = sv[4]-sv[5];
  sxdot_tmp[2] = sv[0]-sv[1];
  sxdot_tmp[3] = sv[1]-sv[2];
  sxdot_tmp[4] = sv[2]-sv[3];
  sxdot_tmp[5] = sv[3]-sv[4];
  for (is=0; is<6; is++) {
    if(mxIsNaN(sxdot_tmp[is])) sxdot_tmp[is] = 0.0;
  }

  return(0);
}


 int subfsx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(int Ns, realtype t, N_Vector x, N_Vector xdot, 
  	int ip, N_Vector sx, N_Vector sxdot, void *user_data, 
  	N_Vector tmp1, N_Vector tmp2)
 {
   UserData data = (UserData) user_data;
   return fsx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(Ns, t, x, xdot, data->sensIndices[ip], sx, sxdot, user_data, tmp1, tmp2);
 };

 void csv_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, int ip, N_Vector sx, void *user_data)
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
  for (is=0; is<6; is++) {
    sv[is] = 0.0;
  }
  sv[0] = dvdx[0]*sx_tmp[0];
  sv[1] = dvdx[13]*sx_tmp[2];
  sv[2] = dvdx[20]*sx_tmp[3];
  sv[3] = dvdx[27]*sx_tmp[4];
  sv[4] = dvdx[34]*sx_tmp[5];
  sv[5] = dvdx[11]*sx_tmp[1];
  switch (ip) {
    case 0: {

    } break;
    case 1: {

    } break;
    case 2: {

    } break;
    case 3: {

    } break;
    case 4: {

    } break;
    case 5: {
      sv[5] += dvdp[35];
    } break;
    case 6: {
      sv[0] += dvdp[36];
      sv[1] += dvdp[37];
      sv[2] += dvdp[38];
      sv[3] += dvdp[39];
    } break;
    case 7: {
      sv[4] += dvdp[46];
    } break;
  }

  return;
}


 void fsx0_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(int ip, N_Vector sx0, void *user_data)
{
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *sx0_tmp = N_VGetArrayPointer(sx0);
  switch (ip) {
    case 0: {
      sx0_tmp[0] = 1.0/p[6];
      sx0_tmp[1] = p[7]/(p[5]*p[6]);
    } break;
    case 1: {
      sx0_tmp[2] = 1.0;
    } break;
    case 2: {
      sx0_tmp[3] = 1.0;
    } break;
    case 3: {
      sx0_tmp[4] = 1.0;
    } break;
    case 4: {
      sx0_tmp[5] = 1.0;
    } break;
    case 5: {
      sx0_tmp[1] = -(p[0]*1.0/(p[5]*p[5])*p[7])/p[6];
    } break;
    case 6: {
      sx0_tmp[0] = -p[0]*1.0/(p[6]*p[6]);
      sx0_tmp[1] = -(p[0]*1.0/(p[6]*p[6])*p[7])/p[5];
    } break;
    case 7: {
      sx0_tmp[1] = p[0]/(p[5]*p[6]);
    } break;
  }

  return;
}


 void subfsx0_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(int ip, N_Vector sx0, void *user_data)
 {
   UserData data = (UserData) user_data;
   fsx0_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(data->sensIndices[ip], sx0, user_data);
 };

 void dfxdp0_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, double *dfxdp0, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdp = data->dvdp;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *x_tmp = N_VGetArrayPointer(x);
  dfxdp0[0] = -dvdx[0]/p[6];
  dfxdp0[1] = -(dvdx[11]*p[7])/(p[5]*p[6]);
  dfxdp0[2] = dvdx[0]/p[6];
  dfxdp0[8] = -dvdx[13];
  dfxdp0[9] = dvdx[13];
  dfxdp0[15] = -dvdx[20];
  dfxdp0[16] = dvdx[20];
  dfxdp0[22] = -dvdx[27];
  dfxdp0[23] = dvdx[27];
  dfxdp0[25] = dvdx[34];
  dfxdp0[29] = -dvdx[34];
  dfxdp0[31] = -dvdp[35]+(dvdx[11]*p[0]*1.0/(p[5]*p[5])*p[7])/p[6];
  dfxdp0[36] = -dvdp[36]+dvdx[0]*p[0]*1.0/(p[6]*p[6]);
  dfxdp0[37] = (dvdx[11]*p[0]*1.0/(p[6]*p[6])*p[7])/p[5];
  dfxdp0[38] = dvdp[36]-dvdp[37]-dvdx[0]*p[0]*1.0/(p[6]*p[6]);
  dfxdp0[39] = dvdp[37]-dvdp[38];
  dfxdp0[40] = dvdp[38]-dvdp[39];
  dfxdp0[41] = dvdp[39];
  dfxdp0[43] = dvdp[46]-(dvdx[11]*p[0])/(p[5]*p[6]);
  dfxdp0[47] = -dvdp[46];
  for (is=0; is<48; is++) {
    if(mxIsNaN(dfxdp0[is])) dfxdp0[is] = 0.0;
  }

  return;
}


 void dfxdp_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(realtype t, N_Vector x, double *dfxdp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *dvdp = data->dvdp;
  double *dvdx = data->dvdx;
  double *dvdu = data->dvdu;
  double *x_tmp = N_VGetArrayPointer(x);
  dfxdp[31] = -dvdp[35];
  dfxdp[36] = -dvdp[36];
  dfxdp[38] = dvdp[36]-dvdp[37];
  dfxdp[39] = dvdp[37]-dvdp[38];
  dfxdp[40] = dvdp[38]-dvdp[39];
  dfxdp[41] = dvdp[39];
  dfxdp[43] = dvdp[46];
  dfxdp[47] = -dvdp[46];
  for (is=0; is<48; is++) {
    if(mxIsNaN(dfxdp[is])) dfxdp[is] = 0.0;
  }

  return;
}


 void fz_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *z, double *p, double *u, double *x){

  return;
}


 void fsz_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(double t, int nt, int it, int np, double *sz, double *p, double *u, double *x, double *z, double *su, double *sx){

  return;
}


 void dfzdx_testmodel1_763C82AED8DFADF1E4F86674906FB7BF(double t, int nt, int it, int nz, int nx, int nu, int iruns, double *dfzdxs, double *z, double *p, double *u, double *x){

  return;
}


