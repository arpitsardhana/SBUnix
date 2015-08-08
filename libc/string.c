/* © Copyright 2015, ggehlot@cs.stonybrook.edu
	 arpsingh@cs.stonybrook.edu,smehra@stonybrook.edu
	 Everyone is permitted to copy and distribute verbatim copies
	of this license document, but changing it is not allowed.
*/
#include <stdio.h>
#include <string.h>

//static char *token = NULL;

const char*
strcpy(
	char *dest,
	const char *src)
{
	const char *saved = dest; 

	while(*src){
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';

	return saved;
}

const char*
strncpy(
	char *dest,
	const char *src,
	int count)
{
	const char *saved = dest;

	while(count && *src) {
		*dest = *src;
		src++;
		dest++;
		count--;
	}
	*dest = '\0';

	return saved;
}

int
strcmp(
	const char *str1,
	const char *str2)
{
	while(*str1 && *str2 && *str1 == *str2) {
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

int
strncmp(
        const char *str1,
        const char *str2,
	int count)
{
        while(count) {
		if(*str1 && *str2 && *str1 == *str2) {
                str1++;
                str2++;
		} else {
			return *str1-*str2;
			break;
		}
		count--;
		
        }

        return 0;
}


int
strlen(
	const char *str)
{
	int len = 0;

	while(*str++ )
		len++;

	return len;
}

void
strcat(
	char *new,
	const char *orig)
{
	while (*new!= '\0')
        	new++;
	do
    	{
	        *new++ = *orig++;

    	}
    	while (*orig != '\0') ;
}

void
strncat(
	char *new,
	const char *orig,
	int count)
{
	if(count) {
		while(*++new);

		while(count && *orig){
			*new++ = *orig++;
			count--;
		}
		
		*new = '\0';
	}
}

/*
 *  look for the index of a character in the given string
 */

char*
index(
	char *str,
	char chr)
{
	while(*str) {
  		if (*str == chr)
    			return (char *) str;

		str++;
	}

	return NULL;
}	

/*
 * set the specified bytes as zero
 */

void
bzero(
	void *string,
	unsigned bytes)
{
	char *res = string;

	while (bytes != 0) {
		*res++ = 0;
		bytes--;
	}
}


/*
 * strtok -  tokenize the string based on the given
 * delimiters
 */

char* strtok(
	char* parse_str,
	const char* delims)
{

	static char *token = NULL;
	char *str_ptr = NULL;
	int index = 0;
	int str_len = strlen(delims);
 
	if(!parse_str && !token)
		return NULL;
 
	if(parse_str && !token)
        	token = parse_str;
 
	/*
	 * skip delimiters
	 */

	str_ptr = token;
	while(1) {
        	for(index = 0; index < str_len; index ++) {
            		if(*str_ptr == delims[index]) {
                		str_ptr ++;
                		break;
            		}
        	}
 
		if(index == str_len) {
               		token = str_ptr;
               		break;
        	}
    	}
 

	/*
	 * End of String 
	 */

	if(*token == '\0') {
		token = NULL;
		return token;
	}

	while(*token != '\0') {
		for(index = 0; index < str_len; index ++) {
			if(*token == delims[index]) {
				*token = '\0';
                		break;
            		}
        	}
 
        	token ++;
        	
		if (index < str_len)
            		break;
    	}
    	return str_ptr;
}


int str_to_int(char *str)
{
	 int pos = 0;
        char buffer[10] = {'\0'};
        strcpy(buffer,str);
        while ((buffer[pos] != '\0') && (buffer[pos] != '\n' ) ){
        pos++;
        }
        pos--;
        int val = 0;
        int io =1;
        while (pos >= 0) {
                buffer[pos] = buffer[pos] - 48;
                val = val + buffer[pos]*io;
                pos--;
                io= io*10;
        }

        return val;

}
int atoi(char *str)
{

        int ret = str_to_int(str);
        return ret;
}
void memset(void *ptr, int value, uint64_t num)
{
        int i = 0;
        for(; i < num; i++)
                ((char *)ptr)[i] = value;
}

void *memcpy(void *dest, const void *src, uint64_t n)
{
    unsigned char *pd = (unsigned char *)dest;
    const unsigned char *ps = (unsigned char *)src;
    if ( ps < pd )
        for (pd += n, ps += n; n--;)
            *--pd = *--ps;
    else
        while(n--)
            *pd++ = *ps++;
    return dest;
}




