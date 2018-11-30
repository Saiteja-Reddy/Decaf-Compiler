class Program
{
	int x[10];

	void main()
	{
		int val;
		x[2] = 4;
		val = callout("get_pow", x[2], 3);
		callout("printf","power is %d \n", val);
	}
}