#include <iostream>
using namespace std;
int arr[1000001];
int *temp;
int n;

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end){
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}

	int t = i > mid ? j : i;
	while (k <= end) {
		temp[k++] = arr[t++];
	}

	for (int l = start; l <= end; l++) {
		arr[l] = temp[l];
	}
}



void mergesort(int start, int end) {
	int mid;
	if (start < end) {
		mid = (end + start) / 2;
		mergesort(start, mid);
		mergesort(mid + 1, end);
		merge(start, end);
	}
}

int main(){
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;	
	temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	if (n == 1)
		cout << arr[0];
	else{
		mergesort(0, n - 1);
		for (int j = 0; j < n; j++){
			cout << temp[j] << "\n";
		}
	}

	return 0;

}