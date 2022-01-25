#include <stdio.h>
#include <alerter_stub.h>

#define YES 	(bool)1
#define NO      (bool)0

bool networkIsEnable = YES;
int alertFailureCount = 0;

void bypassNetwork ()
{
	networkIsEnable = NO;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
	int returnCode = 0;
	if (networkIsEnable){
		//Add network alert API here
	}
	else{
		returnCode = networkAlertStub(celcius);
	}
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}
