class Program
{
// max size of array 100
	int v1[100];
	int v2[100];
	int sum[100];
	int i;
	int n;

	void main()
	{
		callout("printf", "Enter the size of vectors: ");
		
		n = scanInt();

		callout("printf", "Enter the elements in the first vector: \n");

		for i = 1, n
		{
			v1[i] = scanInt();
		}

		callout("printf", "Enter the elements in the second vector: \n");

		for i = 1, n
		{
			v2[i] = scanInt();
		}


		for i = 1, n
		{
			sum[i] = v1[i] + v2[i];
		}		


		callout("printf", "The sum of given vectors is : \n");
		
		for i = 1, n
		{
			callout("printf", "%d, " , sum[i]);
		}
		
		callout("printf", "\n");

		return;

	}

}