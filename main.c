#include <fftw3.h>

#define N 16

void main(void) {
	double in[N] = { 3, 12, 23, 12, 1, 8, 19, 16, 5, 5, 12, 22, 12, 0, 8, 16 };
	fftw_complex out[N/2+1];
	double power_spectrum[N/2+1];

	printf("Input: ");
	for (int i=0; i<N; i++)
		printf("%.0f ", in[i]);
	printf("\n");


	fftw_plan plan = fftw_plan_dft_r2c_1d(N, in , out, FFTW_R2HC );

	fftw_execute(plan);

	for (int i = 0; i < N/2+1; i++)
		power_spectrum[i] = out[i][0] * out[i][0] + out[i][1] * out[i][1];

	printf("Output: ");
	for (int i=0; i<N/2+1; i++)
		printf("%.0f ", power_spectrum[i]);
	printf("\n\nWhere DC-Component: %.0f\n", out[0][0]*out[0][0]);

	fftw_destroy_plan(plan);
}
