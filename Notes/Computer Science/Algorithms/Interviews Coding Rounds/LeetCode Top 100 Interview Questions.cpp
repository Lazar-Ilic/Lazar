/*
I might soon process through the uh Elite Code Top 100 Interview Questions corpus and dig up super fast AC code for all of the tasks uh Focusing on a mixture between legibility terseness and also super low latency details uh not too too too low latency. I might come back to this another day soon uh compose some codes and copy and past and analyse some after uh trying to secure uh strong MCS admission and so on and so on ugh I just feel absolutely terrible for not securing 18 units off of ACC to optimise my MCS admissions chances ugh.
*/

class Solution {
	public:
	vector<int> twoSum(vector<int>& nums,int target){
		unordered_map<int,int> vtoi;
		for(int a=0;a<nums.size();a++){
			if(vtoi.count(target-nums[a]))return {vtoi[target-nums[a]],a};
			vtoi[nums[a]]=a;
		}
		return {-1,-1};
	}
};