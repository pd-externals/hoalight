/* vbap.c 

Chikashi Miyama  
Copyright 2021 ZKM | Hertz-Lab

See copyright in file with name LICENSE.txt */

#include "m_pd.h"  
 
static t_class *hoalight_class;  
 
typedef struct _hoalight {  
    t_object x_obj;
} t_hoalight;  
 
void hoalight_bang(t_hoalight *x) {
    (void)x; // silence unused variable warning
    post("Hello world!");
}  
 
void *hoalight_new(void) {  
    t_hoalight *x = (t_hoalight *)pd_new(hoalight_class);  
    return (void *)x;  
}  
 
void hoalight_setup(void) {  
    hoalight_class = class_new(gensym("hoalight"),  
        (t_newmethod)hoalight_new, NULL,
        sizeof(t_hoalight), CLASS_DEFAULT, 0);  
    class_addbang(hoalight_class, hoalight_bang);  
}
