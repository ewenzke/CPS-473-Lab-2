#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma bss_seg()

int main(void) {
	char* str12;
	char* str14;
	char* str15;
	char* str4;



//Copy 12 bytes from BSS to the Stack

	//The BSS stores uninitialized global and static variables, so create one here:
		static char BSS12Bytes[12];

	//Create twelve bytes of information to retrieve and place it into the uninitialized variable's space:
		str12 = "Twelve here!";
		memcpy(&BSS12Bytes, str12, 12);

	//Create a local variable, to be placed on the stack, and place the information into the stack variable:
		char BSStoStack[13] = "000000000000";
		memcpy(BSStoStack, &BSS12Bytes, 12);

//Copy 13 bytes from the Heap to the Data

	//The heap stores dynamically allocated memory, and can be called using malloc:
		char *Heap13Bytes = (char *)malloc(13);

	//Copy thirteen bytes of information to retrieve and place it into the heap-stored variable:
		memcpy(Heap13Bytes, "Thirteen here", 13);	

	//The data stores initialized global and static variables, so create one of appropriate space and move the information:
		static char DATA13Bytes[14] = "0000000000000";
		memcpy(DATA13Bytes, Heap13Bytes, 13);


//Copy 14 bytes from the Stack to the Heap

	//The stack stores local variables, so create fourteen bytes of information to track:
		str14 = "Fourteen here!";

	//Create an object on the heap of the appropriate size using malloc, and move the information into it:
		char *Heap14Bytes = (char *)malloc(14);
		memcpy(Heap14Bytes, str14, 14);


//Copy 15 bytes from the Data to the BSS

	//The data stores initialized global and static variables, make one:
		static char DATA15Bytes[16] = "000000000000000";

	//The BSS stores uninitialized global and static variables, make one:
		static char BSS15Bytes[15];

	//Create fifteen bytes of information to track, and place it into the data variable:
		str15 = "Fifteen is here";
		memcpy(DATA15Bytes, str15, 15);

	//Copy the information from the data variable to the BSS variable:
		memcpy(&BSS15Bytes, DATA15Bytes, 15);

//Copy 4 bytes from the Text section to the Data section
		//I'm not very confident on this one
		//I know to put it in the data section, initialized global/static variables:
			static char DATA4Bytes[5] = "0000";
		//Take four bytes from where printf is stored?
			memcpy(DATA4Bytes, &printf, 4);



//Debug print values
	printf("%s\n", BSS12Bytes);
	printf("%s\n", DATA13Bytes);
	printf("%s\n", Heap14Bytes);
	printf("%s\n", BSS15Bytes);
	printf("%s\n", DATA4Bytes);



	free(Heap13Bytes);
	free(Heap14Bytes);
	return 0;
}