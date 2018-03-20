#include "testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E.h"
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





 void fu_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(void *user_data, double t)
{

  return;
}


 void fsu_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(void *user_data, double t)
{

  return;
}


 void fv_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(realtype t, N_Vector x, void *user_data)
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


 void dvdx_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(realtype t, N_Vector x, void *user_data)
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


 void dvdu_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(realtype t, N_Vector x, void *user_data)
{

  return;
}


 void dvdp_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(realtype t, N_Vector x, void *user_data)
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


 int fx_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(realtype t, N_Vector x, N_Vector xdot, void *user_data)
{
  UserData data = (UserData) user_data;
  int is;
  double *qpositivex = data->qpositivex;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  double *x_tmp = N_VGetArrayPointer(x);
  double *xdot_tmp = N_VGetArrayPointer(xdot);
  fu_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(data, t);
  fv_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(t, x, data);
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


 void fxdouble_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(realtype t, N_Vector x, double *xdot_tmp, void *user_data)
{
  int is;
  UserData data = (UserData) user_data;
  double *p = data->p;
  double *u = data->u;
  double *v = data->v;
  fu_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(data, t);
  fv_testmodel1_8DBEA2AF5EBB3AB997524787AC3C7F8E(t, x, data);
  xdot_tmp[0] = -v[0];
  xdot_tmp[1] = v[4]-v[5];
  xdot_tmp[2] = v[0]-v[1];
  xdot_tmp[3] = v[5]-v[6];
  xdot_tmp[4] = v[1]-v[2];
  xdot_tmp[5] = v[2]-v[3];
  xdot_tmp[6] = v[3]-v[4];
  xdot_tmp[7] = v[6]-v[7];
  xdot_tmp[8] = v[7]-v[8];
  xdot_tmp[9] = v[8]-v[9