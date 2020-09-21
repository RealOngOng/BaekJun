//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef struct Data {
//	int num, maxpos, nowpos;
//};
//
//int main() {
//
//	int n, s; cin >> n;
//	vector<int> arr(n);
//	for (int i = 0; i < n; i++) cin >> arr[i];
//	cin >> s;
//
//	for (int pivot = 0; pivot < n; pivot++) {
//
//		if (s <= 0) break;
//		
//		vector<Data> vec;
//		for (int i = pivot + 1; i < n; i++)
//			if(arr[pivot] < arr[i])
//				vec.push_back({arr[i], max(pivot, i - s), i});
//
//		//for (Data d : vec)
//		//	cout << d.num << " " << d.maxpos << " " << d.nowpos << "\n";
//		//cout << "\n";
//
//		sort(vec.begin(), vec.end(), [](const Data& d1, const Data& d2) -> bool {
//			if (d1.maxpos != d2.maxpos) return d1.maxpos < d2.maxpos;
//			return d1.num > d2.num;
//		});
//
//		if (vec.empty()) continue;
//
//		Data top = vec[0];
//		if (top.maxpos > pivot) continue;
//
//		swap(arr[top.maxpos], arr[top.nowpos]);
//		s -= top.nowpos - pivot;
//
//	}
//	
//	for (int w : arr)
//		cout << w << " ";
//
//	return 0;
//
//}