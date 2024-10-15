// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
//Add any necessary headers here

// user-defined header files
#include "mypcm.h" // do not modify this file

// put your function prototypes for additional helper functions below:


// implementation
float analog_signal_generator(asignal signal, int t)
{
	//TODO
	float A = signal.A;
	float omega = signal.omega;
	float sigma = signal.sigma;
	int duration = signal.duration;
	return A * sin(omega * t + sigma);
}

void sampler(float *samples, int interval, asignal signal)
{
	//TODO
	for(int t = 0; t < signal.duration; t=t+interval)
	{
		samples[t] = analog_signal_generator(signal, t * interval);
	}
}

void quantizer(float *samples, int *pcmpulses, int levels)
{
	//TODO
	float max = samples[0];
	float min = samples[0];
	for(int i = 0; i < sizeof(samples); i++)
	{
		if(samples[i] > max)
		{
			max = samples[i];
		}
		if(samples[i] < min)
		{
			min = samples[i];
		}
	}
	float step = (max - min) / levels;
	for(int i = 0; i < sizeof(samples); i++)
	{
		pcmpulses[i] = (samples[i] - min) / step;
	}
}

void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
	//TODO
	
}