#include "source.h"
int main(){
	RG_Array<int(*)()> funcs;
	funcs.append(RR_Menu);
	funcs.append(RR_Settings);
	funcs.append(RR_Game);
	return RG_EX_Start(funcs);
}
