#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<int>loadTestCases(int n){
	std::vector<int> elems;
	for(int i=0;i<n;i++){
		int cases;
		std::cin >> cases;
		elems.push_back(cases);
	}
	return elems;
}

int main(){
	int n;
	std::cin >> n;

	std::vector<int> teamStrengths = loadTestCases(n);

	sort(teamStrengths.begin(),teamStrengths.end());

	long long left = 0;
	long long right = 0;

	for(int i=0;i<n;i++){
		left = (teamStrengths.at(i) * (n-1-i))+left;
		right = (teamStrengths.at(n-1-i) * (n-1-i))+right;
	}

	long long revenue = std::abs(left -right);

	std::cout << revenue << std::endl;
	return 0;
}
