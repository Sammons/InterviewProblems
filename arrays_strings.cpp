
namespace Arrays_and_Strings {

	/* implemented with straight chars */
	#define ASCII_SIZE 128
	/* detects if all characters in a null terminated string are unique, returns 1 for unique, 0 for not */
	int detect_if_all_unique_characters(char* null_terminated_string) {
		char set[ASCII_SIZE] = {0};
		int i = 0;
		while ( *(null_terminated_string+i) != '\0' ) {
			if (set[ *(null_terminated_string+i) ]) return 0;
			set[ *(null_terminated_string+i) ] = 1;
			i++;
		}
		return 1;
	}
	/*reverses the null terminated string*/
	void reverse_null_terminated_string(char* null_terminated_string) {
		int length = 0;
		while ( *(null_terminated_string + length ) != '\0' ) {
			length ++;
		}
		for (int i = 0, j = length-1 ; i < j; i++, j--) {
			char tmp = null_terminated_string[i];
			null_terminated_string[i] = null_terminated_string[j];
			null_terminated_string[j] = tmp;
		} 
	}
	/*find if one string is a possible perm of the other*/
	int check_for_matching_permutation(char* stringA, char* stringB) {
		char setA[ASCII_SIZE] = {0};
		char setB[ASCII_SIZE] = {0};
		int positionA = 0;
		int positionB = 0;
 
		while (stringA[positionA] != '\0' && stringB[positionB] != '\0') {
			printf("setting %c and  %c\n",stringA[positionA], stringB[positionB] );
			setA[stringA[positionA]] ++;
			setB[stringB[positionB]] ++;
			if (stringA[positionA] != '\0') positionA++;
			if (stringB[positionB] != '\0') positionB++;

		}
		for (int i = 0; i < ASCII_SIZE; i++) {
			if (setA[i] != setB[i]) {
			printf("%d%d\n", setA[i], setB[i] );
				return 0;
			}
		}
		return 1;
	}
	/*replace spaces with %20, assume enough space*/
	void replace_spaces_with_percent_20s(char string_with_enough_space[], int length) {
		char* buffer = (char*)malloc(length * sizeof(char));
		char* pos = buffer;
		for (int i = 0; i < length; i++) {
			if (string_with_enough_space[i] == ' ') {
				memcpy(pos, "%20", 3);
				pos += 3;
			}
			else {
				pos[0] = string_with_enough_space[i];
				pos++;
			}
		}
		memcpy(string_with_enough_space, buffer, length);
		free(buffer);
		pos = NULL;
		buffer = NULL;
	}
	/*replaces repeating characters with counts */
	void compress_string(char* string) {
		int runner = 0;
		char cur = '\0';
		int i = 2, len = 0;
		int better = 0;
		while (string[ i ] != '\0') {

			if (string[i] == string[i-1] && string[i-1] == string[i-2]) better = 1;
			i++;
		}
		len = i;
		if (!better) return;
		char* buffer = (char*)malloc(sizeof(char)*len);
		memset(buffer, 0, len);
		char* bufferpos = buffer;
		i = 0;
		while ( string[ i ] != '\0' ) {
			cur = string[ i ];
			runner = i+1;
			while ( string[ runner ] == cur ) runner++;
			sprintf(bufferpos, "%c%d", cur, runner - i);
			bufferpos += 2;
			i = runner;
		}
		memset(string, 0, len);
		sprintf(string, "%s", buffer);
	}
}