#include <math.h>//to get sin function
#include <limits.h>//for int arrays last element
// function prototypes
void run(asignal * inputsignal);
float analog_signal_generator(asignal signal, int t);
void sampler(float *samples, int interval, asignal signal);
void quantizer1(float *samples, int *pcmpulses, int levels);
void quantizer(float *samples, int *pcmpulses, int levels, float A);
void encoder(int *pcmpulses, int *dsignal, int encoderbits);
int binConverter(int num);
// Implement functions here
void quantizer(float *samples, int *pcmpulses, int levels, float A){return;}
//binary in to digital signal
void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
    //TODO
    int count = 0;
    while(pcmpulses[count] != INT_MAX){
        //printf("%i ",pcmpulses[count]);//debug
        count++;
    }
    int size = count - 1;
    //printf("%i ", size);//debug


    for(int i = 0; i < size; i++){//convert to binary and store it
        dsignal[i] = binConverter(pcmpulses[i]);
        //printf("%02i",binConverter(pcmpulses[i]));
    }
    //prinf("\n");

}
//binary converter
int binConverter(int num){
    int count = 0;
    int result = 0;
    int temp = 0;
    while(num != 0 && num != 1){
        temp = num % 2;
        temp = temp * pow(10, count);
        result += temp;
        count++;
        num = floor(num / 2);
    }
    temp = num * pow(10, count);
    result += temp;
    return result;

}
void quantizer1(float *samples, int *pcmpulses, int levels)
{
	//TODO
    int count = 0;
    for(int i=0; samples[i]!='\0'; i++)
    {
        count++;
    }
    int size = count - 1;

    for(int i = 0; i < size; i++){

        pcmpulses[i] = (int)(floor(samples[i] * levels));
    }
}
//update sample array
void sampler(float *samples, int interval, asignal signal)
{
	//TODO
    int j = 0;
    float i = 0;
    while (i <= signal.duration){
        samples[j] = analog_signal_generator(signal, i);
        j++;
        i+=interval;
    }
}
//input signal which consist of (A, omega, sigma, and t) and output the signal value t given the input values.
float analog_signal_generator(asignal signal, int t)
{

    float x = t;
    x = x * signal.omega;
    x = x + signal.sigma;
    return signal.A * sin(x);

}
//-------------------------------------------------------------

int main()
{
    asignal * inputsignal = (asignal *) malloc(sizeof(asignal));
    run(inputsignal);
    
    //call any other function here

    free(inputsignal);
	return 0;
}

void run(asignal * inputsignal)
{
    //in this implimentation i assume the numbers that are in input, are less than 10

    ////////////////////////////////input in to the inputs array//////////////
    int inputs[6];
    char * input = malloc(sizeof(char) * 10);
    fgets(input, sizeof(input), stdin);
    int j = 0;
    for(int i = 0; i < 10; i++){
        if((int)(input[i]) < 58 && (int)(input[i]) > 47){
            inputs[j] = (int)(input[i]) - 48;
            j++;
        }
    }
    free(input);

    input = malloc(sizeof(char) * 10);
    fgets(input, sizeof(input), stdin);
    for(int i = 0; i < 10; i++){
        if((int)(input[i]) < 58 && (int)(input[i]) > 47){
            inputs[j] = (int)(input[i]) - 48;
            j++;
        }
    }
    free(input);
    inputsignal->A        = inputs[0];
    inputsignal->omega    = inputs[1];
    inputsignal->sigma    = inputs[2];
    inputsignal->duration = inputs[3];

    float interval = inputs[4];
    int siz = (inputsignal->duration / inputs[4]) + 1;//here i assume interval <= 1 and devisible
    float samples[siz + 1];
    samples[siz + 1] = '\0';


    sampler(samples, interval, *inputsignal);//#sampling
    for(int i = 0; i < siz; i++){
        samples[i] = (samples[i] + inputsignal->A)/(2 * inputsignal->A);
        //printf("%f ", samples[i]);
    }

    ////////////implement PCM array////////////////////
    int pcmpulses[siz + 1];
    pcmpulses[siz + 1] = INT_MAX;
    //printf("%i ",siz);
    //////////////////////////////////////////////////////
    int levels = pow(2,inputs[5]);
    quantizer1(samples, pcmpulses, levels);//#quantization

    ////////////implement dsignal array////////////////////
    int *dsignal = malloc(sizeof(int)*siz);
    //printf("%i ",siz);
    //////////////////////////////////////////////////////
    int encoderbits = inputs[5];
    encoder(pcmpulses, dsignal, encoderbits);//#encoding

    for(int i = 0; i < siz; i++){//convert to binary and store it
        printf("%02i", dsignal[i]);
    }
    printf("\n");
   



}