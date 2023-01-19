#include <vector>
#include<iostream>
using namespace std;
//bool inList(int itemIndex, vector<int> array);
//int sum(vector<int>array);
vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
	// Write your code here.
	// Replace return below.
	vector<int>maxValue;
	vector<int>weight;
	vector<int>value;
	vector<vector<int>>maxWeight;
	vector<int>eachCut;
	int i;
	int itemSize = items.size();
	for (i = 0; i < capacity + 1; i++) {
		maxValue.push_back(0);
		maxWeight.push_back(eachCut);
	}
	for (i = 0; i < itemSize; i++) {
		weight.push_back(items[i][1]);
		value.push_back(items[i][0]);
		//cout << weight[i] << " " << value[i] << "\t";
	}
	for (int j = 0; j < itemSize; j++) {
		vector<int>oldMaxValue = maxValue;
		vector<vector<int>>oldMaxWeight = maxWeight;
		for (i = 1; i < capacity + 1; i++) {
		//maxValue[i] = maxValue[i - 1];
		
			if (weight[j] > i) {
				continue;
			}
			//int itemIndex = inList(weight[j], weight);
			//cout <<i <<" "<<itemIndex<<"\t";
			if (maxValue[i] < oldMaxValue[i - weight[j]] + value[j]){
				maxValue[i] = oldMaxValue[i - weight[j]] + value[j];
				//cout <<i<<"\t"<<maxValue[i]<<" = "<< maxValue[i - weight[j]] <<" + "<<value[j]<<endl;
				vector<int>eachWeightCopy = oldMaxWeight[i - weight[j]];
				eachWeightCopy.push_back(j);
				maxWeight[i] = eachWeightCopy;
			}
		}
	}
	vector<vector<int>> answer;
	answer.push_back({ maxValue[capacity] });
	vector<int>answerWeight = maxWeight[capacity];
	
	answer.push_back(answerWeight);
	return answer;
}
/*
bool inList(int itemIndex, vector<int> array) {
	//int i = 0;
	for (int each : array) {
		if (each == itemIndex)return true;
		//i++;
	}
	return false;
}
*/
/*
int sum(vector<int>array) {
	int sum = 0;
	for (int each : array) {
		sum += each;
	}
	return sum;
}
*/
int main() {
	vector<vector<int>>answer = knapsackProblem({{ 465, 100 }, { 400,85 }, { 255,55 }, { 350,45 },
		{ 650,130 }, { 1000,190 }, {455,100},{100,25},{1200,190},{320,65},{750,100},{50,45}, {550,65},{100,50},{600,70},{240,40} }, 200);
	cout << endl;
	cout << answer[0][0] << endl;
	for (int each : answer[1]) {
		cout << each << "\t";
	}
	
}

/*{
  "capacity": 200,
  "items": [
    [465, 100],
    [400, 85],
    [255, 55],
    [350, 45],
    [650, 130],
    [1000, 190],
    [455, 100],
    [100, 25],
    [1200, 190],
    [320, 65],
    [750, 100],
    [50, 45],
    [550, 65],
    [100, 50],
    [600, 70],
    [240, 40]
  ]
}*/