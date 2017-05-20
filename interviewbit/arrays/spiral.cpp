/*   Spiral Order Matrix I
*    https://www.interviewbit.com/problems/spiral-order-matrix-i/
*/

#define isfull() result.size()==n
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	int n=A.size()*A[0].size();
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	int a1=0,a2=A[0].size()-1,b1=0,b2=A.size()-1;
	while(!(isfull()))
	{
	    for(int i=a1;i<=a2;i++)result.push_back(A[b1][i]);
	    b1++;
	    if(isfull())break;
	    for(int i=b1;i<=b2;i++)result.push_back(A[i][a2]);
	    a2--;
	    if(isfull())break;
	    for(int i=a2;i>=a1;i--)result.push_back(A[b2][i]);
	    b2--;
	    if(isfull())break;
	    for(int i=b2;i>=b1;i--)result.push_back(A[i][a1]);
	    a1++;
	}
	return result;
}
