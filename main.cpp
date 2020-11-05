#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "l:hvV:";

	const struct option long_options[] = {
		{"list",	required_argument,	NULL,'l'},
		{"help",	no_argument,		NULL,'h'},
		{"version",	no_argument,		NULL,'v'},
		{"Value",	required_argument,	NULL,'V'},
		{NULL,		0,					NULL, 0}
	};

	int parse, option_index = -1;

	bool arr[4] = {false, false, false, false};

	while ((parse=getopt_long(argc, argv, 
							short_options, 
							long_options, 
							&option_index))!=-1){
		switch(parse){
			case 'V': {
				if (!arr[0]){
					printf("Value= %s\n",optarg);
					arr[0] = true;
				}
				break;
			}
			case 'l': {
				if (!arr[1]){
					printf("list= %s\n",optarg);
					arr[1] = true;
				}
				break;
			}
			case 'h': {
				if (!arr[2]){
					printf("help\n");
					arr[2] = true;
				}
				break;
			}
			case 'v': {
				if (!arr[3]){
					printf("version is 1.0\n");
					arr[3] = true;
				}
				break;
			}
			case '?': default: {
				printf("unknown option\n");
				break;
			}
		}
		option_index = -1;
	}
	return 0;
}