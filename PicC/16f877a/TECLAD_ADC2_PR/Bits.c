int bit_clear(unsigned short var ,int b){//pone a cero bit en posicion b 
	var &= ~(1<<b);                      //AND con var=var&0b11111110
	return var;
	}
int bit_set(unsigned short var ,int b){//pone a uno bit en posicion b 
	var |= (1<<b);                     //AND con var=var&0b11111110
	return var;
	}
int bit_var(unsigned short var ,int b){//valor de bit en posicion b
	var=(var>>b);//muevo el bit a la posicion cero
	var=1&var; //var se limpia y se deja deja solo el bit de posicion b
    if(b==0)return 0;
	if(b==1)return 1; 	
	}
int comp_var(unsigned short var ,int b){// complemento del bit en posicion b
	var=var^(1<<b);
	return var;
	}