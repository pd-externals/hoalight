/* hoalight.c 

Chikashi Miyama  
Copyright 2021 ZKM | Hertz-Lab

See copyright in file with name LICENSE.txt */
#include <stdlib.h>

#include "m_pd.h"  
#include "HoaLightWrapper.h"
 
static t_class *hoalight_class;  
 
typedef struct _hoalight {  
    t_object x_obj;
    t_float azimuth;
    t_float elevation;
    t_float spread;
    t_float* out_buf;
    t_atom* out_list;
    t_outlet *a_out;
  	void* core;
} t_hoalight;  
 
void hoalight_bang(t_hoalight *x) {

	int numSpeakers = getNumberOfSpeakers(x->core);
    getAmplitudes(x->core, x->out_buf);

    for(int i = 0; i < numSpeakers; ++i)
    	SETFLOAT(&x->out_list[i], x->out_buf[i]);

    outlet_list(x->a_out, &s_list, numSpeakers, &x->out_list[0]);
}

void hoalight_azimuth(t_hoalight *x, float value) {
    if(setAzimuth(x->core, value) == 0)
        post("speakers are not defined yet");
}

void hoalight_elevation(t_hoalight *x, float value) {
    if(setElevation(x->core, value) == 0)
        post("speakers are not defined yet");
}

void hoalight_radius(t_hoalight *x, float value) {
    if(setRadius(x->core, value) == 0)
        post("speakers are not defined yet");
}

void hoalight_define_loudspeakers(t_hoalight* x, t_symbol *s, int argc, t_atom *argv){	
	(void)s;

	float* speakerPositions = (float*)malloc(sizeof(float) * argc);
	for(int i = 0; i < argc; i++)
	{
		if(argv[i].a_type != A_FLOAT)
		{
			post("hoalight: invalid data type included as the %dth element of define_loudspeakers ", i);
			free(speakerPositions);
			return;
		}
		speakerPositions[i] = atom_getfloat(&argv[i]);
	}

	defineSpeakers(x->core, argc, speakerPositions);
	free(speakerPositions);

	int numberOfSpeakers = getNumberOfSpeakers(x->core);
	x->out_buf = realloc(x->out_buf, sizeof(float) * numberOfSpeakers);
	x->out_list = realloc(x->out_buf, sizeof(t_atom) * numberOfSpeakers);
}

void *hoalight_new(void) {  
    t_hoalight *x = (t_hoalight *)pd_new(hoalight_class);  

	inlet_new(&x->x_obj, &x->x_obj.ob_pd, gensym("float"), gensym("azimuth"));
    inlet_new(&x->x_obj, &x->x_obj.ob_pd, gensym("float"), gensym("elevation"));
    inlet_new(&x->x_obj, &x->x_obj.ob_pd, gensym("float"), gensym("radius"));

    x->a_out = outlet_new(&x->x_obj, &s_list);
    x->core = createHoaLight();
    x->out_buf = NULL;
    x->out_list = NULL;

    return (void *)x;  
}  

void hoalight_free(t_hoalight *x){
	destroyHoaLight(x->core);
}
 
void hoalight_setup(void) {  
    hoalight_class = class_new(gensym("hoalight"),  
        (t_newmethod)hoalight_new, (t_method)hoalight_free, sizeof(t_hoalight), CLASS_DEFAULT, 0);  
    class_addbang(hoalight_class, hoalight_bang);
    class_addmethod(hoalight_class, (t_method)hoalight_define_loudspeakers, gensym("define_loudspeakers"), A_GIMME, 0);
    class_addmethod(hoalight_class, (t_method)hoalight_azimuth, gensym("azimuth"), A_FLOAT, 0);
    class_addmethod(hoalight_class, (t_method)hoalight_elevation, gensym("elevation"), A_FLOAT, 0);
    class_addmethod(hoalight_class, (t_method)hoalight_radius, gensym("radius"), A_FLOAT, 0);
}
