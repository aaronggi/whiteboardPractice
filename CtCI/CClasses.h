#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h> 
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif
    struct Class{
    	size_t size;
    	void * (*constructor)(void *self, va_list *addtnl);
    	void * (*destructor)(void *self);
    };

    typedef struct CString{
    	const void *classptr;
    	char *text;
    } Cstring;

    void *string_ctor(void *selfptr, va_list *addtnl){
    	struct CString *self = (struct CString *)selfptr;
    	const char *str = va_arg(*addtnl, const char*);

    	self->text = (char *)calloc(strlen(str) + 1, sizeof(char));
    	strcpy(self->text, str);
    	return self;
    };

    void *string_dtor(void *selfptr){
    	struct CString *self = (struct CString *)selfptr;

    	if(self->text)
    		free(self->text);
    };

    static const struct Class _String = {
    	.size = sizeof(struct CString),
    	.constructor = string_ctor,
    	.destructor = string_dtor,
    };

    const void *String = &_String;

    void * New(const void *classdef, ...){
    	const struct Class *classptr = (const struct Class*)classdef;

        //treating thisptr as a pointer to a derived class struct (e.g. CString)
    	void *thisptr = (void*)calloc(1, classptr->size);

        //thisptr points to derived class struct with pointer to a vtable
        //so we can cast it as a struct Class double pointer, 
        //and set the class vtable
    	*(const struct Class**)thisptr = classptr;
    	if (classptr->constructor){ 
    		va_list ap;	
    		va_start(ap, classdef);
            thisptr = classptr->constructor(thisptr, &ap);
    		va_end(ap);
    	}
	return thisptr;
    }
    
    //finna implement a C smart pointer class just because
     
#ifdef __cplusplus	  
}
#endif
