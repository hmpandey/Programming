#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector< vi >
void print(int n,vvi arr)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}
vvi naive_multi_no_recursion(int n,vvi arr1,vvi arr2)
{
	vvi arr (n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int sum = 0;
			for(int k=0;k<n;k++)
			{
				sum += arr1[i][k]*arr2[k][j];
			}
			arr[i][j] = sum;
		}
	}
	return arr;
}
vvi add(int n,vvi arr1, vvi arr2)
{
	//arr = arr1 + arr2
	vvi arr(n,vi(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j] = arr1[i][j] + arr2[i][j];

	return arr;
}
vvi substract(int n,vvi arr1, vvi arr2)
{
	//arr = arr1 - arr2
	vvi arr(n,vi(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			arr[i][j] = arr1[i][j] - arr2[i][j];

	return arr;
}
vvi naive_multi_recursive(int n,vvi arr1,vvi arr2)
{
	vvi arr (n,vector<int>(n));
	if(n==1)
	{
		arr[0][0] = arr1[0][0]*arr2[0][0];
	}
	else
	{
		//breaking both arrays in 4-4 parts
		//for arr1
		vvi a1 (n/2,vector<int>(n/2));
		vvi b1 (n/2,vector<int>(n/2));
		vvi c1 (n/2,vector<int>(n/2));
		vvi d1 (n/2,vector<int>(n/2));
		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				a1[row][col] = arr1[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				b1[row][col] = arr1[row][col+n/2];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				c1[row][col] = arr1[row+n/2][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				d1[row][col] = arr1[row+n/2][col+n/2];
		/*	print(n/2,a1);
			print(n/2,b1);
			print(n/2,c1);
			print(n/2,d1);
			// yoo its working :) :) */
		//for arr2
		vvi a2 (n/2,vector<int>(n/2));
		vvi b2 (n/2,vector<int>(n/2));
		vvi c2 (n/2,vector<int>(n/2));
		vvi d2 (n/2,vector<int>(n/2));
		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				a2[row][col] = arr2[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				b2[row][col] = arr2[row][col+n/2];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				c2[row][col] = arr2[row+n/2][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				d2[row][col] = arr2[row+n/2][col+n/2];

			//multiplying pairs and adding them to get arr ke all  4th part
			//f = final
		vvi f1 (n/2,vector<int>(n/2));
		vvi f2 (n/2,vector<int>(n/2));
		vvi f3 (n/2,vector<int>(n/2));
		vvi f4 (n/2,vector<int>(n/2));
		//f1 = a1*a2 + b1*c2
		//f2 = a1*b2 + b1*d2
		//f3 = c1*a2 + d1*c2
		//f4 = c1*b2 + d1*d2
		f1 = add(n/2,naive_multi_recursive(n/2,a1,a2), naive_multi_recursive(n/2,b1,c2));
		f2 = add(n/2,naive_multi_recursive(n/2,a1,b2), naive_multi_recursive(n/2,b1,d2));
		f3 = add(n/2,naive_multi_recursive(n/2,c1,a2), naive_multi_recursive(n/2,d1,c2));
		f4 = add(n/2,naive_multi_recursive(n/2,c1,b2), naive_multi_recursive(n/2,d1,d2));

		//and finally combining them to form a complete matrix

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row][col] = f1[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row][col+n/2] = f2[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row+n/2][col] = f3[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row+n/2][col+n/2] = f4[row][col];
	}
	return arr;
}
vvi strassen_multi_recursive(int n,vvi arr1,vvi arr2)
{
	vvi arr (n,vector<int>(n));
	if(n==1)
	{
		arr[0][0] = arr1[0][0]*arr2[0][0];
	}
	else
	{
		//breaking both arrays in 4-4 parts
		//for arr1
		vvi a1 (n/2,vector<int>(n/2));
		vvi b1 (n/2,vector<int>(n/2));
		vvi c1 (n/2,vector<int>(n/2));
		vvi d1 (n/2,vector<int>(n/2));
		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				a1[row][col] = arr1[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				b1[row][col] = arr1[row][col+n/2];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				c1[row][col] = arr1[row+n/2][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				d1[row][col] = arr1[row+n/2][col+n/2];
		/*	print(n/2,a1);
			print(n/2,b1);
			print(n/2,c1);
			print(n/2,d1);
			// yoo its working :) :) */
		//for arr2
		vvi a2 (n/2,vector<int>(n/2));
		vvi b2 (n/2,vector<int>(n/2));
		vvi c2 (n/2,vector<int>(n/2));
		vvi d2 (n/2,vector<int>(n/2));
		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				a2[row][col] = arr2[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				b2[row][col] = arr2[row][col+n/2];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				c2[row][col] = arr2[row+n/2][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				d2[row][col] = arr2[row+n/2][col+n/2];

			//multiplying pairs and adding/substracting/multiplying them to get array ke all  4 part
			//p=partials
			//p1 = a1(b2-d2)
			//p2 = (a1+b1)d2
			//p3 = (c1+d1)a2
			//p4 = d1(c2-a2)
			//p5 = (a1+d1)(a2+d2)
			//p6 = (b1-d1)(c2+d2)
			//p7 = (a1-c1)(a2+b2)
			//mF*ck now i understand the problem -> matrix multiplication not follow commutative property P<-o->P
			vvi p1 = strassen_multi_recursive(n/2,a1,substract(n/2,b2,d2));
			vvi p2 = strassen_multi_recursive(n/2,add(n/2,a1,b1),d2);
			vvi p3 = strassen_multi_recursive(n/2,add(n/2,c1,d1),a2);
			vvi p4 = strassen_multi_recursive(n/2,d1,substract(n/2,c2,a2));
			vvi p5 = strassen_multi_recursive(n/2,add(n/2,a1,d1),add(n/2,a2,d2));
			vvi p6 = strassen_multi_recursive(n/2,substract(n/2,b1,d1),add(n/2,c2,d2));
			vvi p7 = strassen_multi_recursive(n/2,substract(n/2,a1,c1),add(n/2,a2,b2));
		//f1 = p5+p4-p2+p6
		//f2 = p1+p2
		//f3 = p3+p4
		//f4 = p1+p5-p3-p7
		//f = final
		vvi f1 (n/2,vector<int>(n/2));
		vvi f2 (n/2,vector<int>(n/2));
		vvi f3 (n/2,vector<int>(n/2));
		vvi f4 (n/2,vector<int>(n/2));

		f1 = add(n/2,add(n/2,p5,p4),substract(n/2,p6,p2));
		f2 = add(n/2,p1,p2);
		f3 = add(n/2,p3,p4);
		f4 = substract(n/2,add(n/2,p1,p5),add(n/2,p3,p7));
		//and finally combining them to form a complete matrix

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row][col] = f1[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row][col+n/2] = f2[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row+n/2][col] = f3[row][col];

		for(int row=0;row<n/2;row++)
			for(int col=0;col<n/2;col++)
				arr[row+n/2][col+n/2] = f4[row][col];
	}
	return arr;
}
int determinant(vvi arr,int size)
{
	if(size==1)
		return arr[0][0];
	else
	{
		int sum = 0;
		bool is_to_add = true;
		vi multiplier = arr[0];
		arr.erase(arr.begin());
		//cout<<"******multipliers and corresponding small matrix*****\n";
		for(int i=0;i<size;i++)
		{
			//cout<<"\n\n"<<multiplier[i]<<"\n";
			vvi small_arr = arr;
			//deleting vertical entries
			for(int k=0;k<size-1;k++)
			{
				small_arr[k].erase(small_arr[k].begin()+i);
			}
		/*	for(int row=0;row<size-1;row++)
			{
				for(int col=0;col<size-1;col++)
				{
					cout<<small_arr[row][col]<<" ";
				}
				cout<<"\n";
			}*/
			//calculating determinant of (size-1)*(size-1) and multiplying with its respective multipli
			//finally detecting sign   whether to add or substract
				if(is_to_add)
					sum += multiplier[i]*determinant(small_arr,size-1);
				else
					sum -= multiplier[i]*determinant(small_arr,size-1);
		}
		return sum;
	}
//return 0;
}
int main()
{
	int n;
	//cout<<"Enter N = (in the form of 2^k )?";
	cin>>n;
	vvi arr1(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr1[i][j];
	vvi arr2(n, vector<int>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr2[i][j];
		vvi dragon;
		// naive non- recursive method
		cout<<"\n\nMatrix multiplication for N (form 2^k) = "<<n<<"\n";
		clock_t tstart1 = clock();
		dragon = naive_multi_no_recursion(n,arr1,arr2);
		//print(n,dragon);
		cout<<"\nTotal Time Taken by naive non- recursive method : "<<(double)(-tstart1 + clock())/CLOCKS_PER_SEC<<"sec\n\n";

		// naive recursive method
		clock_t tstart2 = clock();
		dragon = naive_multi_recursive(n,arr1,arr2);
		//print(n,dragon);
		cout<<"\nTotal Time Taken by naive recursive method : "<<(double)(-tstart2 + clock())/CLOCKS_PER_SEC<<"sec\n\n";

		// strassen recursive method
		clock_t tstart3 = clock();
		dragon = strassen_multi_recursive(n,arr1,arr2);
		//print(n,dragon);
		cout<<"\nTotal Time Taken by strassen recursive method : "<<(double)(-tstart3 + clock())/CLOCKS_PER_SEC<<"sec\n\n";
	return  0;
}