
class Program{
	int x;
	void main(){
		int x;
		x = 0;
		for i=0, 99{
			if(i == 20){
				continue;
			}
			x = x+1;
			if(i == 30){
				break;
			}
		}
		callout("printf","%d",x);
	}

}