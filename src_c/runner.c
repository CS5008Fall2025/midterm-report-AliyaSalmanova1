
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fibonacci.h"

void initiateFile(char* nameOfFile){
	//open or create a file
	FILE *fileW;
    fileW = fopen(nameOfFile, "w");
    //overwrite text of files with labels of columns
    fprintf(fileW, "N,Iterative,Recursive,Dynamic Programming\n");
	//close file!
    fclose(fileW);
	
}

int main(int argc, char** argv){

	//if user does not enter an n number, return 1 so that main runs again
    while (argc < 2){
        printf("Enter desired size of table: ");
        return 1;
    }

	//initiate array of functions
    uint64_t (*funcArray[])(uint64_t n, int* ops) = {fibonacciIterative, fibonacciRecursive, fibonacciRecursiveDynamic};
    
	//convert inputted n number from string to int
    int size = atoi(argv[1]);

	//calls initiateFile so that both ops csv and times csv get emptied and get labelled columns
	initiateFile("times.csv");
	initiateFile("ops.csv");
 
	//open file in append mode
    FILE *fileAtime;
    fileAtime = fopen("times.csv", "a");

	//same for ops file
    FILE *fileAops;	
    fileAops = fopen("ops.csv", "a");

    for (int n = 3; n <= size; n++){
	
		//convert n to a string and print it into csv files
    	char nString[100];
    	sprintf(nString, "%d", n);
    	fprintf(fileAops, "%s,", nString);
    	fprintf(fileAtime, "%s,", nString);
		
		//loops through array of functions
        for (int i = 0; i < 3; i++){
	
			int ops = 0;
			
			//make sure recursive function doesn't try to fun after a certain number
			if (i == 1 && n > 50){
				fprintf(fileAtime, "-");
				fprintf(fileAops, "-");
				
			}else {
				//run function and get time taken
				double time_taken = time_function(funcArray[i], (uint64_t)n, 0, &ops);

				//convert time taken to a string and print into csv files
            	char timeString[100];
            	sprintf(timeString, "%.6f", time_taken);
            	fprintf(fileAtime, "%s", timeString);

				//do the same for ops
				char opsString[100];
				sprintf(opsString, "%d", ops);
            	fprintf(fileAops, "%s", opsString);
			}
            
			//if we are not at last function, print a comma to csv files
            if (i != 2) {
                fprintf(fileAtime, ",");
				fprintf(fileAops, ",");
            }   
 
        }
		//after loop, go to next line in csv files
        fprintf(fileAtime, "\n");
		fprintf(fileAops, "\n");
    }

    //close files
    fclose(fileAtime);
	fclose(fileAops);
    
}