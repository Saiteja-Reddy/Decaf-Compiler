class Program
{
// max size of array 100
	int n;
	int i;
	int flag;
	int temp;
	int fin;

	void main()
	{		
		n = 12;

		flag = 0;
		fin = n - 1;

		if (n <= 1)
		{
				callout("printf", "Use the numbers between 2 and inf\n");
		}
		else
		{
			if (n == 2)
			{
				callout("printf", "Prime\n");
			}
			else
			{
				for i = 2, fin
				{
					temp = n%i;
					if(temp == 0)
					{
						flag = 1;
						callout("printf", "Not Prime\n");
						break;
					}
				}

				if(flag == 0)			
				{
						callout("printf", "Prime\n");
				}
			}

		}

	}

}