#include <iostream>

// a beginner programmer's challenge found on the youtubes (v anton spraul)
//------------------------------------------------------------------------------------------------------
// when i was in high school many years ago, i was in a contest that had a similar sort of problem on it
// i threw this together for fun and a trip down memory lane
//------------------------------------------------------------------------------------------------------
// city planners want you to write a program that will
// assign numbers to the fire, police, and sanitation departments
//
// conditions that must be met
//
// 1.  valid department numbers are in the range 1-7 inclusive
// 2.  each department must have a unique number
// 3.  the sum of the assigned numbers for fire + police + sanitation must equal 12
// 4.  the police department must be assigned an even number
//
// display a list of all valid permutations
//

// set up the valid min/max range of the department numbers
#define MIN_DEPT_NUM 1
#define MAX_DEPT_NUM 7

bool IsValidDeptNum(const int f, const int p, const int s)
{
	// return true only if the generated department numbers do not match
	return ((f != p) && (f != s) && (p != s));
}

bool IsPoliceEven(const int p)
{
	// ensure that the police number is even
	return p % 2 == 0; 
}

bool IsSumValid(const int f, const int p, const int s)
{
	// return true only if department numbers sum to 12
	return f + p + s == 12;
}

bool IsValid(const int f, const int p, const int s)
{
	// return true only if all problem conditions are satisfied
	return IsValidDeptNum(f, p, s) && IsPoliceEven(p) && IsSumValid(f, p, s);
}

int main()
{

	for (int fire = MIN_DEPT_NUM; fire <= MAX_DEPT_NUM; ++fire)
		for (int police = MIN_DEPT_NUM; police <= MAX_DEPT_NUM; ++police)
			for (int sanitation = MIN_DEPT_NUM; sanitation <= MAX_DEPT_NUM; ++sanitation)
			{
				if (IsValid(fire, police, sanitation))
					// we only print those permutations that meet the conditions presented in the problem
					std::cout << "Fire: " << fire << "\t\tPolice:" << police << "\t\tSanitation: " << sanitation << std::endl;
			
			}

	//system("PAUSE");
	return 0;
}