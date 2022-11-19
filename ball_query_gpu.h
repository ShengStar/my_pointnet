#ifndef _BALL_QUERY_GPU_H
#define _BALL_QUERY_GPU_H

#include <torch/serialize/tensor.h>
#include <vector>
#include <cuda.h>
#include <cuda_runtime_api.h>

int ball_query_wrapper_fast(int b, int n, int m, float radius, int nsample, 
	at::Tensor new_xyz_tensor, at::Tensor xyz_tensor, at::Tensor idx_tensor);

void ball_query_kernel_launcher_fast(int b, int n, int m, float radius, int nsample, 
	const int16_t *xyz, const int16_t *new_xyz, int *idx);

int ball_query_dilated_wrapper_fast(int b, int n, int m, float max_radius, float min_radius, int nsample, 
	at::Tensor new_xyz_tensor, at::Tensor xyz_tensor, at::Tensor idx_tensor);

void ball_query_dilated_kernel_launcher_fast(int b, int n, int m, float max_radius, float min_radius, int nsample, 
	const float *xyz, const float *new_xyz, int *idx);
#endif
