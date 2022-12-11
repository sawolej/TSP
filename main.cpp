#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include "TSP.h"


using namespace std;
//TODO
// 1.przeniesc wszytsko do klasy
// 2. greedy
// 3. christofides
//






int main() {
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::milliseconds ms;
	typedef std::chrono::duration<float> fsec;
	auto start = Time::now(); 
	auto finish = Time::now();
	double long duration1, duration2, duration3;
	double x;

	fstream FileName;
	fstream TimeRaport;
	FileName.open("raport.txt", ios::out);
	TimeRaport.open("raportTime.txt", ios::out);
	if (!FileName||!TimeRaport) {
		cout << "Error while creating the file";
	}
	
	
	FileName << "RAPORT \n\n";
	for (int i = 3; i < 11; i++) {
		duration1 = 0, duration2 = 0, duration3 = 0;
		TSP problem(i);
		FileName << "Raport for " << i << "nodes. \n";
		cout<<  "Raport for " << i << " nodes. \n";
		for (int i = 0; i < 500; i++) {
			
			problem.GenRandomGraphs();

			 start =  Time::now();
			FileName << problem.brutalForce() << " ";
			 finish = Time::now();
			 x = ((finish - start).count());
			 duration1 += x;

			 start = Time::now();
			FileName << problem.NN() << " ";
			 finish = Time::now();
			 x = ((finish - start).count());
			// cout << x / 1000000 << "\n";
			 duration2 += x;

			 start = Time::now();
			FileName << problem.greedy() << "\n ";
			 finish = Time::now();
			 x = ((finish - start).count());
			 duration3 += x;

		}
		cout << " average duration for one run BF: " << (duration1 / 1000000)/500 << " ms.\n";
		cout << " average duration for one run NN: " << (duration2 / 1000000)/500 << " ms.\n";
		cout << " average duration for one run GH: " << (duration3 / 1000000)/500 << " ms.\n";
		TimeRaport << i<<" "<<(duration1 / 1000000) / 500 << " " << (duration2 / 1000000) / 500 << " " << (duration3 / 1000000) / 500 << "\n";
	}
	

	FileName.close();
	return 0;
}
