class Program{

	int fib(int n)
	{
		if(n <= 1)
		{
			return [1];
		}
		return [fib(n - 1) + fib(n - 2)];
	}

	void main()
	{
		int result;
		for i=1, 5
		{		
			result = fib(i);
			callout("printf","%dth fibonacci number is %d\n",i,result);
		}
	}

}