#include <stdio.h>
#include <assert.h>

#define YES 	(bool)1
#define NO      (bool)0

typedef int (*networkAlert)(float);

int alertFailureCount = 0;

int networkAlertStubFailure(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 500;
}

int networkAlertStubSuccess(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit, networkAlert sendAlert) {
    float celcius = (farenheit - 32) * 5 / 9;
	int returnCode = 0;
	
	returnCode = sendAlert(celcius);
	
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
	
    alertInCelcius(400.5, networkAlertStubFailure);
    alertInCelcius(303.6, networkAlertStubSuccess);
	assert (alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
