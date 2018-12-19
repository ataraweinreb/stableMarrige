#include<iostream>
using namespace std;

bool ok(int q[], int c) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		
// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		
// Woman#1's preferences
							{ 2,0,1 } };	 
// Woman#2's preferences
    for(int i=0; i<c; i++){
        if(q[c]==q[i]) return false; //same women is married to two different men
        if(mp[i][q[c]]<mp[i][q[i]] && wp[q[c]][i]<wp[q[c]][c]) return false; //if man i likes woman i best and woman c likes man c best
        if(wp[q[i]][c]<wp[q[i]][i] && mp[c][q[i]]<mp[c][q[c]]) return false; //if woman i likes man i best and man c likes woman c best
    }
	//if we pass the loop, return true!
	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for (int i=0; i<3; i++){    //for loop to print out which man is married to which woman
		cout << "Man " << i <<"   " << "Woman " << q[i] << endl;
	}
	cout << endl;
}	

int main() {
    //declare a 1D array, set to 0. Initialize c to 0
	int q[3]={};
        int c=0;
        while (c>=0){ //while loop to go through columns of the array
                if (c==3){
                        print(q); //print the couples
                        c--; //backtrack to find another solution
                } else {
                        q[c]=-1; //start at the top of the rows
                }       
                while (c>=0){ //while loop to go down the rows
					q[c]++; //increment rows
                    if (q[c]==3){ //if you have gone through all the rows of a column
                            c--; //backtrack
                    } else{
                            if (ok(q, c)){ //call check function to see if the marrige is stable or not
                                    break; //break out of the loop
                            }
                	}	
                }       
                if (c==-1){ //if you have backtracked all the way, you have found all solutions
					break; //exit the column loop
				}
				c++; //otherwise, move to the next column
		}
		return 0;
}
