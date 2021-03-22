/* vbap.c 

Chikashi Miyama  
Copyright 2021 ZKM | Hertz-Lab

See copyright in file with name LICENSE.txt */

#include "m_pd.h"  
 
static t_class *hoalight_class;  
 
typedef struct _hoalight {  
    t_object x_obj;
    t_float azimuth;
    t_float elevation;
    t_float spread;
    t_outlet *a_out;
} t_hoalight;  
 
void hoalight_bang(t_hoalight *x) {
    (void)x; 

    t_atom output[3];
    
    SETFLOAT(&output[0], x->azimuth);
    SETFLOAT(&output[1], x->elevation);
    SETFLOAT(&output[2], x->spread);

    outlet_list(x->a_out, &s_list, 3, &output[0]);

}  
 

void *hoalight_new(void) {  
    t_hoalight *x = (t_hoalight *)pd_new(hoalight_class);  

	floatinlet_new(&x->x_obj, &x->azimuth);
	floatinlet_new(&x->x_obj, &x->elevation);
	floatinlet_new(&x->x_obj, &x->spread);

    x->a_out = outlet_new(&x->x_obj, &s_list);

    return (void *)x;  
}  
 
void hoalight_setup(void) {  
    hoalight_class = class_new(gensym("hoalight"),  
        (t_newmethod)hoalight_new, NULL,
        sizeof(t_hoalight), CLASS_DEFAULT, 0);  
    class_addbang(hoalight_class, hoalight_bang);  
}
