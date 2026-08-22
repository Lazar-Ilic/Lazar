#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
std::vector<double> allgaps;
void parking_problem_cpp(double length) {
    std::vector<double> spots;
    std::vector<std::pair<double, double>> stack;
    stack.push_back({0.0, length});
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr;
    while (!stack.empty()) {
        std::pair<double, double> current_interval = stack.back();
        stack.pop_back();
        double start = current_interval.first;
        double end = current_interval.second;
        if (start >= end) {
            continue;
        }
        distr.param(std::uniform_real_distribution<>::param_type(start, end));
        double spot = distr(gen);
        spots.push_back(spot);
        if (start <= spot - 1.0) {
            stack.push_back({start, spot - 1.0});
        }
        if (spot + 1.0 <= end) {
            stack.push_back({spot + 1.0, end});
        }
    }
    std::sort(spots.begin(), spots.end());
    std::vector<double> gaps;
    if (spots.empty()) {
        allgaps.push_back(length);
    } else {
        allgaps.push_back(spots[0] - 0.0);
        for (size_t i = 0; i < spots.size() - 1; ++i) {
            allgaps.push_back(spots[i+1] - spots[i]);
        }
        allgaps.push_back(length - spots.back());
    }
}

void simulation_cpp(int iterations, double length) {
    for (int i = 0; i < iterations; ++i) {
		if(i%1==0)std::cout<<i<<std::endl;
        parking_problem_cpp(length);
    }
	std::sort(allgaps.begin(),allgaps.end());
	std::cout<<allgaps[allgaps.size()/2]<<std::endl;
	double total=0;
	for(auto dude:allgaps)total+=dude;
	std::cout<<total<<std::endl;
	std::cout<<allgaps.size()<<std::endl;
/*
1.26278
2e+09
1495195780

1.26279
2e+09
1495185655

OK try doubling length again and so on and so on.

1.26277
5e+09
3738001470

Looks pretty OK think if the next also pings in 1.2628 just go with it is OK. I know I could run multiple iterations and somehow just store the counts above and below a few values in that region in O[number of buckets * n] rather than O[n * log[n]] for the sort or whatever but... whatever.
*/
}

int main() {
    simulation_cpp(50,100000000.0);
    return 0;
}