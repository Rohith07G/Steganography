#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

/* Check operation type */
OperationType check_operation_type(char *argv[]) // decide whether encoding or decoding 
{
	if(strcmp(argv[1], "-e") == 0)
	{
		printf("STATUS: selected encoding\n");
		return e_encode;
	}
	else if(strcmp(argv[1], "-d") == 0)
	{
		printf("STATUS: Selected decoding\n");
		return e_decode;
	}
	else
	{
		return e_unsupported;
	}
}
int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		printf("Invalid arguments passed, please provide the operation (-e or -d), source image name(beautiful.bmp), secret file name(secret.txt), (optional)destination image file name(new.bmp)\n");
	}
	else
	{
		printf("\nOPERATION: Checking operation type by calling check operation type function\n");
		if(check_operation_type(argv)== e_encode)
		{
			
			EncodeInfo encInfo;		//declaring the variable name for the struct datatype EncodeInfo which is located in encode.h
				
			printf("OPERATION: Calling read and validate function\n");
			if(read_and_validate_encode_args(argv, &encInfo) == e_failure)//call the read and validate encode arguments function
			{
				printf("Read and validate function failed\n");
				return 0;
			}
			else
			{
				//call the next function do_encoding function
				printf("STATUS: Read and validation successfull thus Calling do encoding function\n");
				do_encoding(&encInfo);
			}
		}
		else if(check_operation_type(argv)== e_decode)
		{
			
			DecodeInfo decInfo;
			//call the read and validate decode arguments function
			//we are passing firstly -d (for decoding) and source file name(output image)
			printf("OPERATION: Calling read and validate function\n");
			if(read_and_validate_decode_args(argv, &decInfo) == e_failure)
			{
				printf("STATUS: Read and validate function failed\n");
				return 0;
			}
			else
			{
				//call the next function do_decoding function
				printf("STATUS: Read and validation successfull thus Calling do decoding function\n");
				do_decoding(&decInfo);
			}
		}
		else
		{
			printf("Invalid operation! mention -e(encoding) or -d(decoding)\n");
			return 0;
		}
	}
}


//declare a character array 