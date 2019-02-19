#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(0));
    
    const long long int no_of_counters = 10000;
    
    long long int c = 0, true_length = rand(), count[no_of_counters];
    
    for (int i = 0; i < no_of_counters; ++i) {
        count[i] = 0;
    }
    
    for (int i = 1; i < 265000; ++i) {
    
        for (int k = 1; k < no_of_counters; ++k) {
            
            c = count[k];
            
            double x = rand() / (double) RAND_MAX;
            if (x <= pow(2, -c)) {
                c++;
            }
            
            count[k] = c;
        }
        
        
        if (i % 100 == 0) {
        
            long long int avg_count = 0;
            
            for (int i = 0; i < no_of_counters; ++i) {
                avg_count += pow(2, count[i]) - 1;
            }
            
            avg_count /= no_of_counters;
            
            printf("Exact: %lld, Morris: %lld, Error: %3f.\n", i, avg_count, ((double) avg_count - i) / ( (double) i ));
            //sleep(1);
        }
    }

}
