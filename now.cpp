class Program{

	int a[10];
	boolean c;

	int ab(int n)
	{
		callout("printf", "%d - printed\n", n);
		return [1];
	}

	void main()
	{
		int c;
		int i;
		i = 100;
		for i=0, 4
		{
			ab(i*i+1);
		}
		callout("printf", "%d - printed\n", i);
		i = callout("read_integer");
		callout("printf", "%d - printed\n", i);
	}

}