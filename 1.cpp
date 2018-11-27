class Program{
	int arr[100];
	int size;
	int partition(int l, int r)
	{
		int pivot;
		int retVal;
		int temp;
		pivot = arr[r];
		retVal = l - 1;

		for it = l,r
		{

			if(pivot >= arr[it])
			{
				retVal = retVal + 1;
				temp = arr[it];
				arr[it] = arr[retVal];
				arr[retVal] = temp;
			}
		}
		temp = arr[retVal + 1];
		arr[retVal + 1] = arr[r];
		arr[r] = temp;
		retVal = retVal + 1;
		return [retVal];
	}

	void quickSort(int l, int r){

		if(l < r)
		{
			int pivotIndex;
			pivotIndex = partition(l,r);
			quickSort(l,pivotIndex - 1);
			quickSort(pivotIndex+1,r);
		}

	}

	void main(){
		size = 100;
		for i = 0,size{
			arr[i] = size - i;
		}
		quickSort(0,size - 1);

		callout("printf","sorted array : ");

		for i = 0,size{
			callout("printf", "%d ",arr[i]);
		}

		callout("printf","\n");
	}


}