#pragma warning(disable:4996)
#include <iostream>
#include "SimpleVector.h"
using namespace std;
int main() {
	//checking Constructors
	SimpleVector sv1;
	SimpleVector sv2(20);

	//checking both are empty and of size 0
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 0 and empty is true
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 0 and empty is true

	//checking push_back and pop_back
	sv1.push_back(5);
	sv2.pop_back();// this should not crash 
	sv1.print();// this should print Element at position 0 is 5
	sv2.print();//nothing should be printed here
	cout << "done \n";
	cout << "adding 0-9 to sv1 and sv2" << endl;
	for (int i = 0; i < 10; i++) {
		sv1.push_back(i);
		sv2.push_back(i);
	}
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 11 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out sv2 is size 10 and empty is false
	sv1.print();// should contain 5 then 0-9
	cout << endl;
	sv2.print();// should contain 0-9          DOES NOT INCLUDE 0???    FIXEDDDDDDDDDDDD
	cout << endl;

	//checking insert
	cout << "popping elements off sv1 and sv2 then inserting elements" << endl;
	for (int i = 0; i < 5; i++) {
		sv1.pop_back();
		sv2.pop_back();
	}
	
	cout<<"this should be 0 "<<sv1.insert(-999, 0)<<endl;// should not error should print out 0
	cout << "this should be 1 "<<sv2.insert(-999, 5) << endl;// should not error should print out 1
															 // ^^ THIS IS PRINTING INDEXT OUT OF BOUNDS THEN 1 --- THat works because you are returning 1

	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 7 and empty is false          
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out sv2 is size 5 and empty is false
			// ^^PRINING SIZE 4 AND AND EMPTY IS FALSE     --> Fixed probably because pop_back was fixed 


	cout << "sv1 is now" << endl;
	sv1.print();// should be -999 then 5 then 0-4
				//INSTEAD OF 5, -999 IS PRINTED

	cout << "sv2 is now" << endl;
	sv2.print();// should be 0-4

	//checking set and [] operator
	cout << "setting elements" << endl;
	sv1.set(-777, 0);//start of sv1 should now be -777
			//^^PRINTING INDEX OUT OF BOUNDS   ---> not anymore 

	sv2.set(-777, 4);//end of sv2 should now be -777
	sv1[sv1.size() - 1] = -777;//end of sv1 should now be -777
	sv2[0] = -777;//end of sv2 should now be -777
			//^^NOT SHOWING  ---> Working 

	sv1.print();
	cout << endl;
	sv2.print();

	//checking clear
	sv1.clear();
	sv2.clear();
	cout << "there should be nothing but this sentence here"<<endl<<endl;
	sv1.print();
	sv2.print();
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 0 and empty is true
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 0 and empty is true

	cout << endl;
	
	//checking reverse
	for (int i = 0; i < 10; i++) {
		sv1.push_back(i);
		sv2.push_back(i);
	}
	sv1.reverse();
	sv2.reverse();
	cout << "these should be backwards order" << endl;
	sv1.print();
	cout << endl;
	sv2.print();
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 10 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 10 and empty is false

	//making large to check to make sure extend is being called properly
	sv1.clear();
	sv2.clear();
	for (int i = 0; i < 1000; i++) {
		sv1.push_back(i);
		sv2.push_back(i);
	}
	printf("SV1 is size %d and empty is %s\n", sv1.size(), sv1.empty() ? "true" : "false");// should print out SV1 is size 1000 and empty is false
	printf("SV2 is size %d and empty is %s\n", sv2.size(), sv2.empty() ? "true" : "false");//should print out SV2 is size 1000 and empty is false

	cout << "if we got here with no errors we are probably ok" << endl;
}