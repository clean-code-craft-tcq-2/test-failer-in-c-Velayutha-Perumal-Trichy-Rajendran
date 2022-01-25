#include <stdio.h>
#include <assert.h>
#include <alerter.h>

int main() {
	
	bypassNetwork();
    alertInCelcius(400.5);
    alertInCelcius(303.6);
	alertInCelcius(0);
	assert (alertFailureCount == 1);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}