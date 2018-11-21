class Program{

	int fib(int n)
	{
		if(n<=1)
		{
			return [1];
		}
		return [fib(n - 1) + fib(n - 2)];
	}

	void main()
	{
		int result;
		int hell;
		hell = 'A';
		for i=1, 5
		{		
			result += fib(i);
			callout("printf","%d\n", -hell);
			callout("printf","%d th fibonacci number is %d\n",i,result);
		}
	}

}