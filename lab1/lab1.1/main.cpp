// This program implements the Monte Carlo Method for estimating the value of PI.
	   
#include <iostream>
#include <cstdlib>
#include <cmath>
   
using namespace std;
   
// given the coordinates of a point (x,y) computes if the point is inside or on the circle 
// centered at origin with radius r. Returns 'true' if it is inside or on the circle, 'false' otherwise.
// DO NOT use the sqrt function here. Just compare to r squared.
bool isInside(double x, double y, double r) {

   //x^2+y^2 = r^2
   // cout << "x*x: " << x*x <<endl;
   // cout << "y*y: " << y*y <<endl;
   // cout << "sum: " << x*x + y*y <<endl;
   // cout << "r*r: " << r*r <<endl;
   if ((x*x) + (y*y) <= (r*r)){
      return true;
   }
   else{
      return false;
   }
}

// given s, the size of the side of a square that is centered at the origin, 
// chooses a random coordinates inside the square, and calls isInside function 
// to test if the point is inside the circle or not.
bool throwDart(int s) {
   //cout << "from throwDart()! \n";
   int x, y; 
   // assign x and y to two random integers between -s/2 and s/2 
   x = (rand() % (s+1)) + (-s/2) ;
   //cout << x << endl;
   y = (rand() % (s+1)) + (-s/2);
   //cout<< y << endl;
   //Call the isInside function and return its output. 
   if (isInside(x, y, (s/2))){
      return true;
   }
   else{
      return false;
   }
   //You do not have to cast x & y to doubles, it is done automatically.
 
}

int main() {
   srand(333);
   int side; // this is the side of the square and is also our resolution. 
   int tries;  // this is the number of tries.

   //Ask the user for the size (integer) of a side of the square
   cout << "Enter the size of a side of the square: ";
   
   //Get the users input using cin
   cin >> side;
   //side = 1000;
   cout << side << endl;

   //Ask the user for the number of tries using cout.
   cout << "Enter the number of tries: ";
 
   //Get the users input using cin.
   cin >> tries;
   //tries = 1000000;
   cout << tries << endl;
 
   int inCount = 0; //counter to track number of throws that fall inside the circle

   for(int i = 0; i < tries; ++i) {
      //throw a dart using throwDart method and increment the counter depending on its output.
      if (throwDart(side)){
         ++inCount;
      }

   }
   //cout << "inCount: " << inCount << endl;

   //Compute and display the estimated value of PI. Make sure you are not using integer division.
   double pi = 0.0;
   pi = (4.0) * inCount / tries;

   cout << "pi = " << pi << endl;

   return 0;
}
