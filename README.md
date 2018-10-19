# power_spectrum
This example computes the power spectrum of a signal using fftw.

## Dependencies
- fftw

## Building
```Shell
make
```

## Verification with octave:
```Shell
x = fft([3 12 23 12 1 8 19 16 5 5 12 22 12 0 8 16]);
round((real(x).^2+imag(x).^2))(1:9)
30276 35 249 1441 3362 827 99 16 64
```
