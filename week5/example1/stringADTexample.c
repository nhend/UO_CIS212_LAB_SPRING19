#include "stringADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Program illustrating usage of String and ArrayList abstract data types. Run the associated executable, stringADTexample, on 
 the command line to see the output of this program. */

int main(){
	char *str = "I used to be legit. In fact, I was too legit. I was too legit to quit. But now Im not legit. Im un-legit. And for that reason I must quit.";
	//str = "";

	const String *st = String_create(str); // call stringADT constructor

	st->upper(st); // convert all letters in st to upper

	const ArrayList *al = st->split(st," "); // split st on spaces and return ArrayList containing resulting fragments
	//_exit(-1);
	int i;
	for(i = 0; i < al->size(al); i++){
		char *s;
		al->get(al, i, (void **)&s); // must cast &s to pointer to void pointer because that's what the get method accepts
		printf("%s\n", s);
	}
	//_exit(-1);

	st->destroy(st); // free up space used by st on heap
	al->destroy(al, free); // free up space used by al on heap

	return 0;
}
