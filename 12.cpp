void ShellsSort(BaseType *A, unsigned N)
{
	unsigned i,j,k;
	BaseType t;
	for(k = N/2; k > 0; k /=2)
        for(i = k; i < N; i++)
        {
            t = A[i];
            for(j = i; j>=k; j-=k)
            {
                if(t < A[j-k])
                    A[j] = A[j-k];
                else
                    break;
            }
            A[j] = t;
        }
}



public class Heap<T>
{
	private T[] _array; //������ ����������� ���������
	private int heapsize;//����� �������������� ���������
	private IComparer<T> _comparer;
	public Heap(T[] a, IComparer<T> comparer){
		_array = a;
		heapsize = a.Length;
		_comparer = comparer;
	}

	public void HeapSort(){
		build_max_heap();//���������� ��������
		for(int i = _array.Length - 1; i > 0; i--){

			T temp = _array[0];//���������� ������� ������������ ������� �� ������� ������� � ����� �������
			_array[0] = _array[i];
			_array[i] = temp;

			heapsize--;//�������� ����� �������������� ���������
			max_heapify(0);//�������������� �������� ��������
		}
	}

	private int parent (int i) { return (i-1)/2; }//������ ������������� ����
	private int left (int i) { return 2*i+1; }//������ ������ �������
	private int right (int i) { return 2*i+2; }//������ ������� �������

	//����� ����������������� �������� �������� ��� �������,
        //��� ������� � �������� i ������ ���� �� ������ �� ����� ��������, ������� ��� ����� �������� �������������� ��������
	private void max_heapify(int i){
		int l = left(i);
		int r = right(i);
		int lagest = i;
		if (l<heapsize && _comparer.Compare(_array[l], _array[i])>0)
			lagest = l;
		if (r<heapsize && _comparer.Compare(_array[r], _array[lagest])>0)
			lagest = r;
		if (lagest != i)
		{
			T temp = _array[i];
			_array[i] = _array[lagest];
			_array[lagest] = temp;

			max_heapify(lagest);
		}
	}

	//����� ������ �������������� ��������
	private void build_max_heap(){
		int i = (_array.Length-1)/2;

		while(i>=0){
			max_heapify(i);
			i--;
		}
	}

}

public class IntComparer : IComparer<int>
{
	public int Compare(int x, int y) {return x-y;}
}

public static void Main (string[] args)
{
	int[] arr = Console.ReadLine().Split(' ').Select(s=>int.Parse(s)).ToArray();//������ �������� ������� ����� ������
	IntComparer myComparer = new IntComparer();//�����, ����������� ���������
	Heap<int> heap = new Heap<int>(arr, myComparer);
	heap.HeapSort();
}
